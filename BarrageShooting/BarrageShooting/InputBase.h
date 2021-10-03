#pragma once
#include <map>
#include <array>
#include <string>
#include <vector>
// �e���̓f�o�C�X�̐e�N���X

// �{�^�����̓^�C�~���O�Ɋւ���enum
enum class TRG
{
	NOW,
	OLD,
	MAX
};

using TrgBool = std::array<bool, static_cast<int>(TRG::MAX)>;
// ���͏��𕶎���Ŋi�[��������ɂ���
using CommandData = std::map<std::string, TrgBool>;
// ����ð���
using CommandTable = std::map<std::string, int>;

struct InputBase
{
	// �X�V�������Ă���
	void operator()()
	{
		Update();
	}
	// �X�V
	virtual void Update(void) = 0;
	// �R�}���h�̒ǉ�����
	// param@ cmName:�R�}���h�� param@ command:���̓f�[�^
	void AddCommand(std::string cmName,int command);
	// �������̏�Ԃ̎擾
	const TrgBool& GetState(std::string cmName)
	{
		return cmData_[cmName];
	}
private:

protected:
	// �R�}���h���̓f�[�^
	CommandData cmData_;
	// �R�}���h���̓e�[�u��
	CommandTable cmTable_;
};

