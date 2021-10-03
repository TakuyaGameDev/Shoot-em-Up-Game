#include <DxLib.h>
#include "TitleScene.h"
#include "GameScene.h"
#include "Application.h"
#include "InputBase.h"

#include "ImageManager.h"

TitleScene::TitleScene()
{
	// ������
	Init();
}

TitleScene::~TitleScene()
{
}

UniqueScene TitleScene::Update(const std::shared_ptr<InputBase>& input, UniqueScene own)
{
	// �G���^�[�L�[����������GameScene�Ɉڍs
	if (input->GetState("start")[static_cast<int>(TRG::NOW)] &&
		!input->GetState("start")[static_cast<int>(TRG::OLD)])
	{
		return std::make_unique<GameScene>();
	}

	// �`��֌W�͂��̂悤�ɕ\�L
	// �܂����̊֐��ő䎆���܂�����ɂ���
	ClsDrawScreen();
	// �`��
	Draw();
	// �`�扺��ʂ̕\�����t���b�v������
	ScreenFlip();
	// �������g��Ԃ�
	return move(own);
}

bool TitleScene::Init(void)
{
	// ImageManager�̐���
	lpImageManager.Create();
	return true;
}

void TitleScene::Draw(void)
{
	// �����̕`��
	DrawFormatString(lpApplication.GetViewport(VIEWPORTNO::SCR).x / 2,
		lpApplication.GetViewport(VIEWPORTNO::SCR).y/2, 0xffffff, "Title");
}
