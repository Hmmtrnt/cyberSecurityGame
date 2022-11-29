// �^�C�g�����
#pragma once
#include "SceneBase.h"

class Vec2;

namespace Title
{
	constexpr int kKeyMax = 256;
}

class SceneTitle : public SceneBase
{
public:
	SceneTitle();
	virtual ~SceneTitle();

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
	int m_key[Title::kKeyMax];
	// �^�C�g����ʂ̃L�����N�^�[�P
	int m_hChar1;
	// �^�C�g����ʂ̃L�����N�^�[�Q
	int m_hChar2;
	// �t�H���g�̃n���h��
	int m_fontHandle1;
	int m_fontHandle2;
	// �e�L�X�g�_�ŗp�t���[���J�E���g
	int m_textBlinkFrame;
	// �t�F�[�h
	int m_fadeBright;		// ����
	int m_fadeSpeed;		// ���x
};