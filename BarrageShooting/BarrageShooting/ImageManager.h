#pragma once
#include <vector>
#include <string>
#include <map>

#include "Geometory.h"
// 画像管理クラス
// 画像を読み込んだり、その画像ハンドルを取得したりするクラス
// もちろんシングルトン(動的)

// int型を詰め込んでいくvectorコンテナ
using VecInt = std::vector<int>;

#define lpImageManager ImageManager::getInstance()

class ImageManager
{
public:
	static ImageManager& getInstance(void)
	{
		return *instance_;
	}
	// 生成
	static void Create(void);
	// 破棄
	void Destroy(void);
	// 画像単発ロード(エラー時にはfalseが返る)
	bool Load(std::string name);
	// 画像連番ロード(エラー時にはfalseが返る)
	bool Load(std::string name, Vector2I divCnt, Vector2I divSize);

	// 画像ハンドル取得
	const VecInt& GetHandle(std::string name)
	{
		return handles_[name];
	}
private:
	ImageManager() = default;
	~ImageManager();

	static ImageManager* instance_;
	// 画像ハンドル格納先
	std::map<std::string, VecInt> handles_;
};

