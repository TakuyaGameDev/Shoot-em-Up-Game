#include <DxLib.h>
#include "TitleScene.h"
#include "Application.h"
#include "KeyInput.h"

void Application::Run(void)
{
    // DxLib�̏�����������ɏI���Ȃ�������
    // �Q�[�����[�v�ɂ͓���Ȃ�
    if (!SysInit())
    {
        return;
    }
    while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0)
    {
        // ���̓f�[�^�̍X�V
        (*inputData_)();
        // �V�[���̍X�V
        scene_ = scene_->Update(inputData_, move(scene_));
    }
}

void Application::Exit(void)
{
    // DxLib�̏I��
    DxLib_End();
}

Application::~Application()
{
}

bool Application::SysInit(void)
{
    // �e��ʃT�C�Y�̐ݒ�
    SetViewPorts(VIEWPORTNO::SCR, { 480,640 });
    SetViewPorts(VIEWPORTNO::GSCR, { 480,600 });
    // �ݒ肵����ʃT�C�Y�ŉ�ʕ\��
    SetGraphMode(viewports_[static_cast<int>(VIEWPORTNO::SCR)].x,
        viewports_[static_cast<int>(VIEWPORTNO::SCR)].y, 16);
    ChangeWindowMode(true);
    SetWindowText("barrageShooting");
    // DxLib�̏�����������ɏI�����Ȃ�������false
    if (DxLib_Init() == -1)
    {
        return false;
    }
    // ���̓f�[�^�̃C���X�^���X
    inputData_ = std::make_shared<KeyInput>();

    // �R�}���h�ǉ�
    inputData_->AddCommand("start", KEY_INPUT_RETURN);
    // �����V�[���̃C���X�^���X
    scene_ = std::make_unique<TitleScene>();
    return true;
}

void Application::SetViewPorts(VIEWPORTNO vNo, Vector2I size)
{
    // ��ʃT�C�Y�����܂����z��̒��g�Ɋi�[���Ă���
    viewports_[static_cast<int>(vNo)] = size;
}
