#include "SceneMain.h"
#include "SceneResult.h"
#include "SceneFail.h"
#include "DxLib.h"
#include "Box.h"

namespace
{
	// �F
	const int kColorB = GetColor(0, 0, 0);			// ��
	const int kColorR = GetColor(255, 0, 0);		// ��
	// �c��񐔂̍��W
	constexpr int kFontPosX = 15;	// X���W
	constexpr int kFontPosY = 400;	// Y���W
	// �t�F�[�h�֘A
	constexpr int kFadeBright = 0;	// ����
	constexpr int kFadeSpeed = 7;	// ���x
}

SceneMain::SceneMain() :
	m_hBackGround(-1),
	m_fontHandle(-1),
	m_fadeBright(0),
	m_fadeSpeed(0),
	m_pushNum(0),
	m_mouseX(0),
	m_mouseY(0),
	m_pushFlame(0),
	m_box(nullptr)
{
	// �������̎擾
	m_box = new Box;
}

SceneMain::~SceneMain()
{
	// �������̊J��
	delete m_box;
}

// ����������
void SceneMain::init()
{
	m_hBackGround = LoadGraph("data/SceneMain.png");				// �w�i
	m_fontHandle = CreateFontToHandle("BIZ UDP�S�V�b�N", 100, 4);	// �t�H���g
	m_fadeBright = kFadeBright;										// �t�F�[�h����
	m_fadeSpeed = kFadeSpeed;										// �t�F�[�h���x
	m_pushNum = 3;													// �������
	m_box->init();
}

// �I������
void SceneMain::end()
{
	DeleteGraph(m_hBackGround);
	DeleteFontToHandle(m_fontHandle);
}

// �X�V����
SceneBase* SceneMain::update()
{	
	// �t�F�[�h����
	m_fadeBright += m_fadeSpeed;
	if (m_fadeBright >= 255)
	{
		m_fadeBright = 255;
		m_fadeSpeed = 0;
	}
	// �Q�[���I�[�o�[
	if ((m_fadeBright <= 0) && (m_fadeSpeed < 0) && (m_pushNum <= 0))
	{
		m_fadeBright = 0;
		return (new SceneFail);
	}
	// �Q�[���N���A
	else if ((m_fadeBright <= 0) && (m_fadeSpeed < 0))
	{
		m_fadeBright = 0;
		return (new SceneResult);
	}
	if (m_fadeSpeed == 0)
	{
		// �t�F�[�h�A�E�g�J�n
		if (m_box->isTouchEnable())
		{
			m_fadeSpeed = -kFadeSpeed;
		}
		else if (m_pushNum <= 0)
		{
			m_fadeSpeed = -kFadeSpeed;
		}
	}
	m_box->update(m_pushNum, m_fadeBright);
	return this;
}

void SceneMain::draw()
{
	// �`��̋P�x
	SetDrawBright(m_fadeBright, m_fadeBright, m_fadeBright);
	// �w�i
	DrawGraph(0, 0, m_hBackGround, true);

	if (m_pushNum >= 2)
	{
		DrawFormatStringToHandle(15, 400, kColorB, m_fontHandle, "��%d��", m_pushNum);
	}
	// �c��񐔂����Ńt�H���g���ԂɂȂ�
	else if (m_pushNum <= 1)
	{
		DrawFormatStringToHandle(15, 400, kColorR, m_fontHandle, "��%d��", m_pushNum);
	}
}