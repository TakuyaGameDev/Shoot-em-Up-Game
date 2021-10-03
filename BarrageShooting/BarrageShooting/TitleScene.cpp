#include <DxLib.h>
#include "TitleScene.h"
#include "GameScene.h"
#include "Application.h"
#include "InputBase.h"

#include "ImageManager.h"

TitleScene::TitleScene()
{
	// 初期化
	Init();
}

TitleScene::~TitleScene()
{
}

UniqueScene TitleScene::Update(const std::shared_ptr<InputBase>& input, UniqueScene own)
{
	// エンターキーを押したらGameSceneに移行
	if (input->GetState("start")[static_cast<int>(TRG::NOW)] &&
		!input->GetState("start")[static_cast<int>(TRG::OLD)])
	{
		return std::make_unique<GameScene>();
	}

	// 描画関係はこのように表記
	// まずこの関数で台紙をまっさらにする
	ClsDrawScreen();
	// 描画
	Draw();
	// 描画下画面の表裏をフリップさせる
	ScreenFlip();
	// 自分自身を返す
	return move(own);
}

bool TitleScene::Init(void)
{
	// ImageManagerの生成
	lpImageManager.Create();
	return true;
}

void TitleScene::Draw(void)
{
	// 文字の描画
	DrawFormatString(lpApplication.GetViewport(VIEWPORTNO::SCR).x / 2,
		lpApplication.GetViewport(VIEWPORTNO::SCR).y/2, 0xffffff, "Title");
}
