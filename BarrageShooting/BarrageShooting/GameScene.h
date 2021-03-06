#pragma once
#include "BaseScene.h"

class GameScene :
    public BaseScene
{
public:
    GameScene();
    ~GameScene();
    // 更新
    UniqueScene Update(const std::shared_ptr<InputBase>& input, UniqueScene own);
    // 初期化
    bool Init(void);
    // 描画
    void Draw(void);

private:

};

