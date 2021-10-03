#pragma once
#include <array>
#include <memory>
#include "Geometory.h"
#include "BaseScene.h"

// �V���O���g���C���X�^���X���ȒP�ɏo����悤��#define�Œ�`���Ă���
#define lpApplication Application::getInstane()
// InputBase�̃N���X�錾
// ��������Ă������ɂ����shared_ptr�Ŏg�p���邱�Ƃ��\�ɂȂ�
// ���ʂ�include���������Ȃ��Ƃ��Ɏg�p
struct InputBase;
// �e��ʂ̔ԍ�
enum class VIEWPORTNO
{
	// ��ʑS��
	SCR,
	// �Q�[�����
	GSCR,
	MAX
};
// �e��ʃT�C�Y�̊i�[��z��
using ViewPorts = std::array<Vector2I, static_cast<int>(VIEWPORTNO::MAX)>;

class Application
{
public:
	// ���̃N���X�̃|�C���^�̎擾
	static Application& getInstane(void)
	{
		static Application instance_;
		return instance_;
	}
	// �Q�[�����[�v
	void Run(void);
	// �A�v���P�[�V�����I��
	void Exit(void);
	// �e��ʃT�C�Y�̎擾
	const Vector2I& GetViewport(VIEWPORTNO vNo)
	{
		return viewports_[static_cast<int>(vNo)];
	}

private:
	Application() = default;
	~Application();
	// DxLib�֌W�̏�����
	bool SysInit(void);
	// �e��ʂ̃T�C�Y�ݒ�
	void SetViewPorts(VIEWPORTNO vNo, Vector2I size);
	// �e��ʃT�C�Y�̊i�[��
	ViewPorts viewports_;
	// ���͏��
	std::shared_ptr<InputBase> inputData_;
	// �V�[��
	UniqueScene scene_;
};

