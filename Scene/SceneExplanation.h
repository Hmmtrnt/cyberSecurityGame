#pragma once
#include "SceneBase.h"
#include <vector>

class SceneExplanation : public SceneBase
{
public:
	SceneExplanation();
	virtual ~SceneExplanation() {}


	virtual void init() override;
	virtual void end() override;

	virtual SceneBase* update() override;
	virtual void draw() override;
private:
	// �L�[�{�[�h�̓��͏��
	int m_key[256];
	// �t�H���g�̃n���h��
	int m_fontHandle;
	// �L�����N�^�[�̃n���h��
	int m_hChar;
	// �I�u�W�F�N�g�̃n���h��
	int m_hObject;
	// �����o���̃n���h��
	int m_hSpeechBubble;
	// �t�F�[�h����
	int m_fadeBright;
	// �t�F�[�h���x
	int m_fadeSpeed;
};