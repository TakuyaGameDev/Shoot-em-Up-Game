#include <DxLib.h>
#include "GameScene.h"
#include "Application.h"

GameScene::GameScene()
{
	// ������
	Init();
}

GameScene::~GameScene()
{
}

UniqueScene GameScene::Update(const std::shared_ptr<InputBase>& input, UniqueScene own)
{

	ClsDrawScreen();
	Draw();
	ScreenFlip();
	return move(own);
}

bool GameScene::Init(void)
{
	return true;
}

void GameScene::Draw(void)
{
	// �����̕`��
	DrawFormatString(lpApplication.GetViewport(VIEWPORTNO::SCR).x / 2,
		lpApplication.GetViewport(VIEWPORTNO::SCR).y / 2, 0xffffff, "Game");
}
