#pragma once
#include <memory>
// �e�V�[���̐e�N���X

// �X�̒��ł��������g�p����̂�
// �����̃N���X�錾
class BaseScene;
// InputBase�N���X�̃N���X�錾
struct InputBase;
// BaseScene��unique_ptr
using UniqueScene = std::unique_ptr<BaseScene>;

class BaseScene
{
public:
	// �R���X�g���N�^
	BaseScene();
	// �f�X�g���N�^
	virtual ~BaseScene();
	// �X�V�֐�
	virtual UniqueScene Update(const std::shared_ptr<InputBase>& input, UniqueScene own) = 0;
	// �������֌W
	virtual bool Init(void) = 0;
	// �`��֌W
	virtual void Draw(void) = 0;

private:

};

