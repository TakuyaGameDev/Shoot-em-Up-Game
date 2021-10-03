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
	// �L�[�S�̂̉������̊i�[
	GetHitKeyStateAll(&keyData_[0]);

	// �R�}���h���̓f�[�^�ŉ�
	for (auto& data : cmData_)
	{
		// �g���K�[���������s���邽�߂̏���
		data.second[static_cast<int>(TRG::OLD)] =
			data.second[static_cast<int>(TRG::NOW)];
		// �����݂̉��������i�[
		data.second[static_cast<int>(TRG::NOW)] =
			keyData_[cmTable_[data.first]];
	}
}
