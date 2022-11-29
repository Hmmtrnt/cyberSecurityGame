// �������
#pragma once
#include "SceneBase.h"
#include <vector>

namespace Explanation
{
	constexpr int kKeyMax = 256;
}

class SceneExplanation : public SceneBase
{
public:
	SceneExplanation();
	virtual ~SceneExplanation();

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
	int m_key[Explanation::kKeyMax];
	// �n���h��
	int m_fontHandle;		// �t�H���g
	int m_hChar;			// �L�����N�^�[
	int m_hObject;			// �I�u�W�F�N�g
	int m_hSpeechBubble;	// �����o��
	// �t�F�[�h
	int m_fadeBright;		// ����
	int m_fadeSpeed;		// ���x
};