#include "SceneExplanation.h"
#include "SceneMain.h"
#include "DxLib.h"
#include "game.h"

namespace
{
	// �\������e�L�X�g
	const char* const kText1 = "������A�ˑR���[���������B";
	const char* const kText2 = "���u���挩����H�����m��Ȃ����ǁv";
	const char* const kText3 = "���̃��[���͍��\���[���ł���A";
	const char* const kText4 = "�ǂ�����������|�C���g���T����";
	const char* const kText5 = "�`�����X�͂R��";
	// �w�i�F
	const int kBackgroundColor = GetColor(200, 200, 200);	// �D�F
	// �����F
	const int kFontColor = GetColor(0, 0, 0);				// ��
	// �t�H���g�̈ʒu
	constexpr int kFontWidth1 = 100;
	constexpr int kFontHeight1 = 90;
	constexpr int kFontWidth2 = 100;
	constexpr int kFontHeight2 = 130;
	constexpr int kFontWidth3 = 100;
	constexpr int kFontHeight3 = 170;
	constexpr int kFontWidth4 = 100;
	constexpr int kFontHeight4 = 210;
	constexpr int kFontWidth5 = 100;
	constexpr int kFontHeight5 = 250;
	// �L�����̍��W
	constexpr int kCharWidth = 50;
	constexpr int kCharHeight = 300;
	// �L�����̑傫��
	constexpr int kCharSizeWidth = 150;
	constexpr int kCharSizeHeight = 190;
	// �I�u�W�F�N�g�̍��W
	constexpr int kObjectWidth = 150;
	constexpr int kObjectHeight = 450;
	// �I�u�W�F�N�g�̑傫��
	constexpr int kObjectSizeWidth = 50;
	constexpr int kObjectSizeHeight = 60;
	// �t�F�[�h�֘A
	constexpr int kFadeBright = 0;	// ����
	constexpr int kFadeSpeed = 7;	// ���x
}

SceneExplanation::SceneExplanation() :
	m_fontHandle(-1),
	m_hChar(-1),
	m_hObject(-1),
	m_fadeBright(0),
	m_fadeSpeed(0)
{

}

void SceneExplanation::init()
{
	m_fontHandle = CreateFontToHandle(NULL, 30, 4);
	m_hChar = LoadGraph("data/watasi.png");
	m_hObject = LoadGraph("data/smartphone.png");
	m_fadeBright = kFadeBright;	// �t�F�[�h����
	m_fadeSpeed = kFadeSpeed;	// �t�F�[�h���x
}

void SceneExplanation::end()
{
	DeleteFontToHandle(m_fontHandle);
}

SceneBase* SceneExplanation::update()
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
		return (new SceneMain);
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

void SceneExplanation::draw()
{
	// �`��̋P�x
	SetDrawBright(m_fadeBright, m_fadeBright, m_fadeBright);
	// �w�i
	DrawBox(0, 0, Game::kScreenWidth, Game::kScreenHeight, kBackgroundColor, true);
	// �L����
	DrawExtendGraph(kCharWidth, kCharHeight, kCharWidth + kCharSizeWidth, kCharHeight + kCharSizeHeight, m_hChar, true);
	// �I�u�W�F�N�g
	DrawExtendGraph(kObjectWidth, kObjectHeight, kObjectWidth + kObjectSizeWidth, kObjectHeight + kObjectSizeHeight, m_hObject, true);
	// ������
	DrawStringToHandle(kFontWidth1, kFontHeight1, kText1, kFontColor, m_fontHandle);
	DrawStringToHandle(kFontWidth2, kFontHeight2, kText2, kFontColor, m_fontHandle);
	DrawStringToHandle(kFontWidth3, kFontHeight3, kText3, kFontColor, m_fontHandle);
	DrawStringToHandle(kFontWidth4, kFontHeight4, kText4, kFontColor, m_fontHandle);
	DrawStringToHandle(kFontWidth5, kFontHeight5, kText5, kFontColor, m_fontHandle);
}