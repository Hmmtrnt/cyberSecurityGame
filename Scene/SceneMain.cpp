#include "SceneMain.h"
#include "SceneResult.h"
#include "SceneFail.h"
#include "DxLib.h"
#include "game.h"

namespace
{
	// ������
	const char* const kURL = "URL ��";
	const char* const kText = "�{����";
	// �F
	const int kColorG = GetColor(200, 200, 200);	// �D�F
	const int kColorB = GetColor(0, 0, 0);			// ��
	// URL�̘g�̍��W
	constexpr int kURLFrameX = 350;
	constexpr int kURLFrameY = 50;
	// URL�̘g�̃T�C�Y
	constexpr int kSizeURLFrameX = 400;
	constexpr int kSizeURLFrameY = 130;
	// �{���̘g�̍��W
	constexpr int kTextFrameX = 350;
	constexpr int kTextFrameY = 230;
	// �{���̘g�̃T�C�Y
	constexpr int kSizeTextFrameX = 400;
	constexpr int kSizeTextFrameY = 300;
	// �t�F�[�h�֘A
	constexpr int kFadeBright = 0;	// ����
	constexpr int kFadeSpeed = 7;	// ���x
}

SceneMain::SceneMain() :
	m_hBackGround(-1),
	m_fontHandle(-1),
	m_fadeBright(0),
	m_fadeSpeed(0)
{
}

void SceneMain::init()
{
	m_hBackGround = LoadGraph("data/SceneMain.png");
	m_fontHandle = CreateFontToHandle(NULL, 30, 4);
	m_fadeBright = kFadeBright;	// �t�F�[�h����
	m_fadeSpeed = kFadeSpeed;	// �t�F�[�h���x
}

void SceneMain::end()
{
	DeleteFontToHandle(m_fontHandle);
}

SceneBase* SceneMain::update()
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
		return (new SceneResult);
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
	if (key[KEY_INPUT_RETURN] == 1)
	{
		return (new SceneFail);
	}
	else if (key[KEY_INPUT_SPACE] == 1)
	{
		return (new SceneResult);
	}
	else if (key[KEY_INPUT_TAB] == 1)
	{
		return (new SceneExplanation);
	}*/
	return this;
}

void SceneMain::draw()
{
	// �`��̋P�x
	SetDrawBright(m_fadeBright, m_fadeBright, m_fadeBright);
	// �w�i
	DrawGraph(0, 0, m_hBackGround, true);
}