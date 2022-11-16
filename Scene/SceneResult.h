#pragma once
#include "SceneBase.h"

class SceneResult : public SceneBase
{
public:
	SceneResult();
	virtual ~SceneResult() {}


	virtual void init() override;
	virtual void end() override;

	virtual SceneBase* update() override;
	virtual void draw() override;
private:
	// �L�[�{�[�h�̓��͏��
	int m_key[256];
	// �t�F�[�h����
	int m_fadeBright;
	// �t�F�[�h���x
	int m_fadeSpeed;
	// �w�i�̃O���t�B�b�N�n���h��
	int m_hBackGround;
	// �t�H���g�̃n���h��
	int m_fontHandle;
	// �e�L�X�g�_�ŗp�t���[���J�E���g
	int m_textBlinkFrame;
};