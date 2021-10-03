#pragma once
#include <memory>
// 各シーンの親クラス

// 個々の中でも自分を使用するので
// 自分のクラス宣言
class BaseScene;
// InputBaseクラスのクラス宣言
struct InputBase;
// BaseSceneのunique_ptr
using UniqueScene = std::unique_ptr<BaseScene>;

class BaseScene
{
public:
	// コンストラクタ
	BaseScene();
	// デストラクタ
	virtual ~BaseScene();
	// 更新関数
	virtual UniqueScene Update(const std::shared_ptr<InputBase>& input, UniqueScene own) = 0;
	// 初期化関係
	virtual bool Init(void) = 0;
	// 描画関係
	virtual void Draw(void) = 0;

private:

};

