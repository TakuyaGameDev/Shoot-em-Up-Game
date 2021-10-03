#pragma once
#include <array>
#include "InputBase.h"
// キーボード入力関係

using KeyArray = std::array<char, 256>;

class KeyInput :
    public InputBase
{
public:
    KeyInput();
    ~KeyInput();
    // 更新
    void Update(void);
private:
    // キー入力配列を格納しているarray配列
    KeyArray keyData_;
};

