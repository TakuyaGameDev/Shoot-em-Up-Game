#pragma once
#include "BaseScene.h"

class TitleScene :
    public BaseScene
{

public:
    TitleScene();
    ~TitleScene();

    UniqueScene Update(const std::shared_ptr<InputBase>& input, UniqueScene own);
    bool Init(void);
    void Draw(void);
private:
};

