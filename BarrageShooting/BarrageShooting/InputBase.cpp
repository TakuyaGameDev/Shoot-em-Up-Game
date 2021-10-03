#include "InputBase.h"

void InputBase::AddCommand(std::string cmName,int command)
{
	// ƒRƒ}ƒ“ƒh‚Ì’Ç‰Á
	cmTable_[cmName] = command;
}
