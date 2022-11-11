#include "SceneMain.h"
#include "SceneResult.h"
#include "SceneFail.h"
#include "DxLib.h"
#include "game.h"
#include "Mouse.h"

namespace
{
	// �F
	const int kColorG = GetColor(200, 200, 200);	// �D�F
	const int kColorB = GetColor(0, 0, 0);			// ��
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
	box.init();
	mouse.init();
}

void SceneMain::end()
{
	DeleteFontToHandle(m_fontHandle);
}

SceneBase* SceneMain::update()
{
	mouse.update();
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
	// �����ƂȂ铖���蔻��
	box.draw();
	mouse.draw();
}