#include <DxLib.h>
#include "Application.h"

int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_  HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine, _In_ int nShowCmd)
{
	// ゲームループ
	lpApplication.Run();
	// アプリケーション終了
	lpApplication.Exit();
}