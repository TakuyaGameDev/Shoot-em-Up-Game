#include "InputBase.h"

void InputBase::AddCommand(std::string cmName,int command)
{
	// コマンドの追加
	cmTable_[cmName] = command;
}
