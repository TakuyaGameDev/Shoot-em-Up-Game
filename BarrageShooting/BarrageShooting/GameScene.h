#pragma once
#include "BaseScene.h"

class GameScene :
    public BaseScene
{
public:
    GameScene();
    ~GameScene();
    // �X�V
    UniqueScene Update(const std::shared_ptr<InputBase>& input, UniqueScene own);
    // ������
    bool Init(void);
    // �`��
    void Draw(void);

private:

};

