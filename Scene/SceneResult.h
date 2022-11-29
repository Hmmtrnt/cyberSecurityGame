// ���U���g���
#pragma once
#include "SceneBase.h"

namespace Result
{
	constexpr int kKeyMax = 256;
}

class SceneResult : public SceneBase
{
public:
	SceneResult();
	virtual ~SceneResult() {}

	// ����������
	virtual void init() override;
	// �I������
	virtual void end() override;
	// �X�V����
	virtual SceneBase* update() override;
	// �`�揈��
	virtual void draw() override;
private:
	// �L�[�{�[�h�̓��͏��
	int m_key[Result::kKeyMax];
	// �t�F�[�h
	int m_fadeBright;		// ����
	int m_fadeSpeed;		// ���x
	// �n���h��
	int m_hBackGround;		// �w�i�̃O���t�B�b�N
	int m_fontHandle;		// �t�H���g
	// �e�L�X�g�_�ŗp�t���[���J�E���g
	int m_textBlinkFrame;
};