#pragma once
#include "SceneBase.h"
#include <vector>

class Vec2;

namespace
{
	constexpr int keyMax = 256;
}

class SceneTitle : public SceneBase
{
public:
	SceneTitle();
	virtual ~SceneTitle() {}


	virtual void init() override;
	virtual void end() override;

	virtual SceneBase* update() override;
	virtual void draw() override;
private:
	// �L�[�{�[�h�̓��͏��
	int m_key[keyMax];
	// �^�C�g����ʂ̃L�����N�^�[�P
	int m_hChar1;
	// �^�C�g����ʂ̃L�����N�^�[�Q
	int m_hChar2;
	// �t�H���g�̃n���h��
	int m_fontHandle;
	int m_fontHandle2;
	// �e�L�X�g�_�ŗp�t���[���J�E���g
	int m_textBlinkFrame;
	// �t�F�[�h����
	int m_fadeBright;
	// �t�F�[�h���x
	int m_fadeSpeed;
};