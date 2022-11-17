#include "SceneResult.h"
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
	// �t�H���g�̐F
	const int kColorB = GetColor(0, 0, 0);	// ��
	// �K�C�h�t�H���g�̈ʒu
	constexpr int kFontGuideWidth = 280;
	constexpr int kFontGuideHeight = 500;
}

SceneResult::SceneResult() :
	m_fadeBright(0),
	m_fadeSpeed(0),
	m_hBackGround(-1),
	m_fontHandle(-1),
	m_textBlinkFrame(0)
{
}

void SceneResult::init()
{
	m_fadeBright = kFadeBright;								// �t�F�[�h����
	m_fadeSpeed = kFadeSpeed;								// �t�F�[�h���x
	m_hBackGround = LoadGraph("data/SceneResult.png");	// �w�i�̃O���t�B�b�N�n���h��
	m_fontHandle = CreateFontToHandle("BIZ UDP�S�V�b�N", 30, 4);
}

void SceneResult::end()
{
	DeleteGraph(m_hBackGround);
	DeleteFontToHandle(m_fontHandle);
}

SceneBase* SceneResult::update()
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
	return this;
}

void SceneResult::draw()
{
	// �`��̋P�x
	SetDrawBright(m_fadeBright, m_fadeBright, m_fadeBright);
	DrawGraph(0, 0, m_hBackGround, true);
	if (m_textBlinkFrame < kTextDispFrame)
	{
		DrawStringToHandle(kFontGuideWidth, kFontGuideHeight, kGuideText, kColorB, m_fontHandle);
	}
}