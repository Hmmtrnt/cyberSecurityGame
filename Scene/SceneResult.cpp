#include "SceneResult.h"
#include "SceneTitle.h"
#include "DxLib.h"

namespace
{
	// �t�F�[�h�֘A
	constexpr int kFadeBright = 0;	// ����
	constexpr int kFadeSpeed = 7;	// ���x
	// ������̓_��
	constexpr int kTextDispFrame = 45;	// �\��
	constexpr int kTextHideFrame = 20;	// �B���
}

SceneResult::SceneResult() :
	m_fadeBright(0),
	m_fadeSpeed(0),
	m_hBackGround(-1),
	m_textBlinkFrame(0)
{
}

void SceneResult::init()
{
	m_fadeBright = kFadeBright;								// �t�F�[�h����
	m_fadeSpeed = kFadeSpeed;								// �t�F�[�h���x
	m_hBackGround = LoadGraph("data/SceneResult.png");	// �w�i�̃O���t�B�b�N�n���h��
}

void SceneResult::end()
{
	DeleteGraph(m_hBackGround);
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
	//DrawString(0, 0, "���U���g���", GetColor(255, 255, 255));
	DrawGraph(0, 0, m_hBackGround, true);
}