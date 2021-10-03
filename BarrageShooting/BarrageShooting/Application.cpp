#include <DxLib.h>
#include "TitleScene.h"
#include "Application.h"
#include "KeyInput.h"

void Application::Run(void)
{
    // DxLibの初期化が正常に終わらなかったら
    // ゲームループには入らない
    if (!SysInit())
    {
        return;
    }
    while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0)
    {
        // 入力データの更新
        (*inputData_)();
        // シーンの更新
        scene_ = scene_->Update(inputData_, move(scene_));
    }
}

void Application::Exit(void)
{
    // DxLibの終了
    DxLib_End();
}

Application::~Application()
{
}

bool Application::SysInit(void)
{
    // 各画面サイズの設定
    SetViewPorts(VIEWPORTNO::SCR, { 480,640 });
    SetViewPorts(VIEWPORTNO::GSCR, { 480,600 });
    // 設定した画面サイズで画面表示
    SetGraphMode(viewports_[static_cast<int>(VIEWPORTNO::SCR)].x,
        viewports_[static_cast<int>(VIEWPORTNO::SCR)].y, 16);
    ChangeWindowMode(true);
    SetWindowText("barrageShooting");
    // DxLibの初期化が正常に終了しなかったらfalse
    if (DxLib_Init() == -1)
    {
        return false;
    }
    // 入力データのインスタンス
    inputData_ = std::make_shared<KeyInput>();

    // コマンド追加
    inputData_->AddCommand("start", KEY_INPUT_RETURN);
    // 初期シーンのインスタンス
    scene_ = std::make_unique<TitleScene>();
    return true;
}

void Application::SetViewPorts(VIEWPORTNO vNo, Vector2I size)
{
    // 画面サイズを決まった配列の中身に格納している
    viewports_[static_cast<int>(vNo)] = size;
}
