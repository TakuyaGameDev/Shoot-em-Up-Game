#pragma once
#include <array>
#include "InputBase.h"
// �L�[�{�[�h���͊֌W

using KeyArray = std::array<char, 256>;

class KeyInput :
    public InputBase
{
public:
    KeyInput();
    ~KeyInput();
    // �X�V
    void Update(void);
private:
    // �L�[���͔z����i�[���Ă���array�z��
    KeyArray keyData_;
};

