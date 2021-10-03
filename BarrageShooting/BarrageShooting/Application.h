#pragma once
#include <array>
#include <memory>
#include "Geometory.h"
#include "BaseScene.h"

// シングルトンインスタンスを簡単に出来るように#defineで定義している
#define lpApplication Application::getInstane()
// InputBaseのクラス宣言
// これをしておく事によってshared_ptrで使用することが可能になる
// 無駄なincludeをしたくないときに使用
struct InputBase;
// 各画面の番号
enum class VIEWPORTNO
{
	// 画面全体
	SCR,
	// ゲーム画面
	GSCR,
	MAX
};
// 各画面サイズの格納先配列
using ViewPorts = std::array<Vector2I, static_cast<int>(VIEWPORTNO::MAX)>;

class Application
{
public:
	// このクラスのポインタの取得
	static Application& getInstane(void)
	{
		static Application instance_;
		return instance_;
	}
	// ゲームループ
	void Run(void);
	// アプリケーション終了
	void Exit(void);
	// 各画面サイズの取得
	const Vector2I& GetViewport(VIEWPORTNO vNo)
	{
		return viewports_[static_cast<int>(vNo)];
	}

private:
	Application() = default;
	~Application();
	// DxLib関係の初期化
	bool SysInit(void);
	// 各画面のサイズ設定
	void SetViewPorts(VIEWPORTNO vNo, Vector2I size);
	// 各画面サイズの格納先
	ViewPorts viewports_;
	// 入力情報
	std::shared_ptr<InputBase> inputData_;
	// シーン
	UniqueScene scene_;
};

