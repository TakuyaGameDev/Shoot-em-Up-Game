#include <DxLib.h>
#include "KeyInput.h"

KeyInput::KeyInput()
{

}

KeyInput::~KeyInput()
{
}

void KeyInput::Update(void)
{
	// キー全体の押下情報の格納
	GetHitKeyStateAll(&keyData_[0]);

	// コマンド入力データで回す
	for (auto& data : cmData_)
	{
		// トリガー処理を実行するための処理
		data.second[static_cast<int>(TRG::OLD)] =
			data.second[static_cast<int>(TRG::NOW)];
		// 今現在の押下情報を格納
		data.second[static_cast<int>(TRG::NOW)] =
			keyData_[cmTable_[data.first]];
	}
}
