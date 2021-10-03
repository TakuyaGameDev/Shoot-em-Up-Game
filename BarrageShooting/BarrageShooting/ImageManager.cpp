#include <DxLib.h>
#include "ImageManager.h"

ImageManager* ImageManager::instance_ = nullptr;

void ImageManager::Create(void)
{
    if (!instance_)
    {
        instance_ = new ImageManager();
    }
}

void ImageManager::Destroy(void)
{
    if (instance_)
    {
        delete instance_;
    }
    instance_ = nullptr;
}

bool ImageManager::Load(std::string name)
{
    if (handles_.count(name) <= 0)
    {
        handles_[name].resize(1);
        handles_[name][0] = LoadGraph(("Images/" + name).c_str());
    }
    // エラー
    if (handles_[name][0] <= 0)
    {
        return false;
    }
    return true;
}

bool ImageManager::Load(std::string name, Vector2I divCnt, Vector2I divSize)
{
    if (handles_.count(name) <= 0)
    {
        handles_[name].resize(divCnt.x * divCnt.y);
        LoadDivGraph(("Images/" + name).c_str(), divCnt.x * divCnt.y,
            divCnt.x, divCnt.y, divSize.x, divSize.y, &handles_[name][0]);
    }
    // エラー
    if (handles_[name][0] <= 0)
    {
        return false;
    }
    return true;
}

ImageManager::~ImageManager()
{
}
