#include "InputBase.h"

void InputBase::AddCommand(std::string cmName,int command)
{
	// �R�}���h�̒ǉ�
	cmTable_[cmName] = command;
}
