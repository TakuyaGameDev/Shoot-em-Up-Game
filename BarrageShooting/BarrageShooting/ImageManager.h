#pragma once
#include <vector>
#include <string>
#include <map>

#include "Geometory.h"
// �摜�Ǘ��N���X
// �摜��ǂݍ��񂾂�A���̉摜�n���h�����擾�����肷��N���X
// �������V���O���g��(���I)

// int�^���l�ߍ���ł���vector�R���e�i
using VecInt = std::vector<int>;

#define lpImageManager ImageManager::getInstance()

class ImageManager
{
public:
	static ImageManager& getInstance(void)
	{
		return *instance_;
	}
	// ����
	static void Create(void);
	// �j��
	void Destroy(void);
	// �摜�P�����[�h(�G���[���ɂ�false���Ԃ�)
	bool Load(std::string name);
	// �摜�A�ԃ��[�h(�G���[���ɂ�false���Ԃ�)
	bool Load(std::string name, Vector2I divCnt, Vector2I divSize);

	// �摜�n���h���擾
	const VecInt& GetHandle(std::string name)
	{
		return handles_[name];
	}
private:
	ImageManager() = default;
	~ImageManager();

	static ImageManager* instance_;
	// �摜�n���h���i�[��
	std::map<std::string, VecInt> handles_;
};

