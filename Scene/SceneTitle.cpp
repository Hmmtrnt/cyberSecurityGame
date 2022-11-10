#include "SceneTitle.h"
#include "DxLib.h"
#include "game.h"
#include "Mouse.h"
#include "SceneMain.h"
#include "SceneExplanation.h"

namespace
{
	// �\������e�L�X�g
	const char* const kTitleText = "���\���[�����������b�I";
	const char* const kGuideText = "�X�y�[�X�L�[�������Ă�������";
	// �^�C�g���t�H���g�̈ʒu
	constexpr int kFontWidth = 100;
	constexpr int kFontHeight = 200;
	// �K�C�h�t�H���g�̈ʒu
	constexpr int kFontGuideWidth = 170;
	constexpr int kFontGuideHeight = 400;
	// �L�����P�̍��W
	constexpr int kCharWidth1 = 50;
	constexpr int kCharHeight1 = 300;
	// �L�����P�̑傫��
	constexpr int kCharSizeWidth1 = 150;
	constexpr int kCharSizeHeight1 = 190;
	// �L�����Q�̍��W
	constexpr int kCharWidth2 = 600;
	constexpr int kCharHeight2 = 300;
	// �L�����Q�̑傫��
	constexpr int kCharSizeWidth2 = 170;
	constexpr int kCharSizeHeight2 = 210;
	// ������̓_��
	constexpr int kTextDispFrame = 45;	// �\��
	constexpr int kTextHideFrame = 20;	// �B���
	// �w�i�F
	const int kBackgroundColor = GetColor(200, 200, 200);	// �D�F
	// �����F
	const int kFontColor = GetColor(0, 0, 0);				// ��
	// �t�F�[�h�֘A
	constexpr int kFadeBright = 0;	// ����
	constexpr int kFadeSpeed = 7;	// ���x
}

SceneTitle::SceneTitle() :
	m_hChar1(-1),
	m_hChar2(-1),
	m_fontHandle(-1),
	m_fontHandle2(-1),
	m_textBlinkFrame(0),
	m_fadeBright(0),
	m_fadeSpeed(0)
{
}

void SceneTitle::init()
{
	m_hChar1 = LoadGraph("data/TitleCharWaru_1.png");
	m_hChar2 = LoadGraph("data/TitleCharOdoroki1.png");
	m_fontHandle = CreateFontToHandle(NULL, 56, 4);
	m_fontHandle2 = CreateFontToHandle(NULL, 30, 4);
	m_textBlinkFrame = 0;
	m_fadeBright = kFadeBright;	// �t�F�[�h����
	m_fadeSpeed = kFadeSpeed;	// �t�F�[�h���x
}

void SceneTitle::end()
{
	DeleteGraph(m_hChar1);
	DeleteGraph(m_hChar2);
	DeleteFontToHandle(m_fontHandle);
	DeleteFontToHandle(m_fontHandle2);
	SetDrawBright(255, 255, 255);
}

SceneBase* SceneTitle::update()
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
		return (new SceneExplanation);
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

void SceneTitle::draw()
{
	// �`��̋P�x
	SetDrawBright(m_fadeBright, m_fadeBright, m_fadeBright);
	// �w�i
	DrawBox(0, 0, Game::kScreenWidth, Game::kScreenHeight, kBackgroundColor, true);
	// �������L����
	DrawExtendGraph(kCharWidth2, kCharHeight2, kCharWidth2 + kCharSizeWidth2, kCharHeight2 + kCharSizeHeight2, m_hChar2, true);
	// �������ȃL����
	DrawExtendGraph(kCharWidth1, kCharHeight1, kCharWidth1 + kCharSizeWidth1, kCharHeight1 + kCharSizeHeight1, m_hChar1, true);
	// ������
	DrawStringToHandle(kFontWidth, kFontHeight, kTitleText, kFontColor, m_fontHandle);
	if (m_textBlinkFrame < kTextDispFrame)
	{
		DrawStringToHandle(kFontGuideWidth, kFontGuideHeight, kGuideText, kFontColor, m_fontHandle2);
	}

}