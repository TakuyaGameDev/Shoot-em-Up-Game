#pragma once
#include "BaseScene.h"

class GameScene :
    public BaseScene
{
public:
    GameScene();
    ~GameScene();
    // XV
    UniqueScene Update(const std::shared_ptr<InputBase>& input, UniqueScene own);
    // ‰Šú‰»
    bool Init(void);
    // •`‰æ
    void Draw(void);

private:

};

