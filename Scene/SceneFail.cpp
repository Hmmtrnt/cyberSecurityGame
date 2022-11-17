#include "SceneFail.h"
#include "SceneTitle.h"
#include "DxLib.h"

namespace
{
	// �\������e�L�X�g
	const char* const kGuideText = "�X�y�[�X�L�[�������ă^�C�g����";
	// �t�F�[�h�֘A
	constexpr int kFadeBright = 0;	// ����
	constexpr int kFadeSpeed = 7;	// ���x
	// ������̓_��
	constexpr int kTextDispFrame = 45;	// �\��
	constexpr int kTextHideFrame = 20;	// �B���
	// �F
	const int kColorB = GetColor(0, 0, 0);	// ��
	const int kColorW = GetColor(255, 255, 255);	// ��
	// �K�C�h�t�H���g�̈ʒu
	constexpr int kFontGuideWidth = 280;
	constexpr int kFontGuideHeight = 500;
}

SceneFail::SceneFail() :
	m_fadeBright(0),
	m_fadeSpeed(0),
	m_fontHandle(-1),
	m_textBlinkFrame(0)
{
}

void SceneFail::init()
{
	m_fadeBright = kFadeBright;	// �t�F�[�h����
	m_fadeSpeed = kFadeSpeed;	// �t�F�[�h���x
	m_fontHandle = CreateFontToHandle("BIZ UDP�S�V�b�N", 30, 4);
}

void SceneFail::end()
{

}

SceneBase* SceneFail::update()
{
	// �t�F�[�h�A�E�g����
	m_fadeBright += m_fadeSpeed;
	if (m_fadeBright >= 255)
	{
		m_fadeBright = 255;
		m_fadeSpeed = 0;
	}
	if ((m_fadeBright <= 0) && (m_fadeSpeed < 0))
	{
		m_fadeBright = 0;
		return (new SceneTitle);
	}

	// �e�L�X�g�̓_��
	m_textBlinkFrame++;
	if (m_textBlinkFrame >= kTextDispFrame + kTextHideFrame)
	{
		m_textBlinkFrame = 0;
	}

	if (m_fadeSpeed == 0)
	{
		// �t�F�[�h�A�E�g�J�n
		inputKey(m_key);
		if (m_key[KEY_INPUT_SPACE] == 1)
		{
			m_fadeSpeed = -kFadeSpeed;
		}
	}
	/*inputKey(key);
	if (key[KEY_INPUT_SPACE] == 1)
	{
		return (new SceneTitle);
	}*/
	return this;
}

void SceneFail::draw()
{
	// �`��̋P�x
	SetDrawBright(m_fadeBright, m_fadeBright, m_fadeBright);
	DrawString(0, 0, "���s���", GetColor(255, 255, 255));
	if (m_textBlinkFrame < kTextDispFrame)
	{
		DrawStringToHandle(kFontGuideWidth, kFontGuideHeight, kGuideText, kColorW, m_fontHandle);
	}
}