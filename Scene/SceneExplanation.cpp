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
	const char* const kText5 = "�`�����X�͂R��!";
	const char* const kText6 = "������肪�Ƃ��������܂��I";
	const char* const kText7 = "���挩����v����";
	const char* const kText8 = "��T�Ԉȓ��ɂ�������������";
	const char* const kText9 = "���z�͂Q���S�O�O�O�~�ł�";
	const char* const kText10 = "�X�y�[�X�L�[�������ăX�^�[�g�I";
	// �w�i�F
	const int kBackgroundColor = GetColor(200, 200, 200);	// �D
	// �����F
	const int kFontColorB = GetColor(0, 0, 0);				// ��
	const int kFontColorY = GetColor(200, 0, 0);			// ��
	// �t�H���g�̈ʒu
	constexpr int kFontWidth1 = 100;
	constexpr int kFontHeight1 = 30;
	constexpr int kFontWidth2 = 100;
	constexpr int kFontHeight2 = 70;
	constexpr int kFontWidth3 = 100;
	constexpr int kFontHeight3 = 110;
	constexpr int kFontWidth4 = 100;
	constexpr int kFontHeight4 = 150;
	constexpr int kFontWidth5 = 100;
	constexpr int kFontHeight5 = 190;
	constexpr int kFontWidth6 = 240;
	constexpr int kFontHeight6 = 280;
	constexpr int kFontWidth7 = 240;
	constexpr int kFontHeight7 = 320;
	constexpr int kFontWidth8 = 240;
	constexpr int kFontHeight8 = 360;
	constexpr int kFontWidth9 = 240;
	constexpr int kFontHeight9 = 400;
	constexpr int kFontWidth10 = 240;
	constexpr int kFontHeight10 = 510;
	// �L�����̍��W
	constexpr int kCharWidth = 50;
	constexpr int kCharHeight = 330;
	// �L�����̑傫��
	constexpr int kCharSizeWidth = 150;
	constexpr int kCharSizeHeight = 190;
	// �I�u�W�F�N�g�̍��W
	constexpr int kObjectWidth = 150;
	constexpr int kObjectHeight = 480;
	// �I�u�W�F�N�g�̑傫��
	constexpr int kObjectSizeWidth = 70;
	constexpr int kObjectSizeHeight = 60;
	// �����o���̍��W
	constexpr int kSBubbleWidth = 200;
	constexpr int kSBubbleHeight = 230;
	// �����o���̑傫��
	constexpr int kSBubbleSizeWidth = 500;
	constexpr int kSBubbleSizeHeight = 270;
	// �t�F�[�h�֘A
	constexpr int kFadeBright = 0;	// ����
	constexpr int kFadeSpeed = 7;	// ���x
}

SceneExplanation::SceneExplanation() :
	m_fontHandle(-1),
	m_hChar(-1),
	m_hObject(-1),
	m_hSpeechBubble(-1),
	m_fadeBright(0),
	m_fadeSpeed(0)
{

}

void SceneExplanation::init()
{
	m_fontHandle = CreateFontToHandle(NULL, 30, 4);
	m_hChar = LoadGraph("data/watasi.png");
	m_hObject = LoadGraph("data/smartphone.png");
	m_hSpeechBubble = LoadGraph("data/speechBubble.png");
	m_fadeBright = kFadeBright;	// �t�F�[�h����
	m_fadeSpeed = kFadeSpeed;	// �t�F�[�h���x
}

void SceneExplanation::end()
{
	DeleteFontToHandle(m_fontHandle);
	DeleteGraph(m_hChar);
	DeleteGraph(m_hObject);
	DeleteGraph(m_hSpeechBubble);
	SetDrawBright(255, 255, 255);
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
	// �I�u�W�F�N�g(�X�}�z)
	DrawExtendGraph(kObjectWidth, kObjectHeight, kObjectWidth + kObjectSizeWidth, kObjectHeight + kObjectSizeHeight, m_hObject, true);
	// �����o��
	DrawExtendGraph(kSBubbleWidth, kSBubbleHeight, kSBubbleWidth + kSBubbleSizeWidth, kSBubbleHeight + kSBubbleSizeHeight, m_hSpeechBubble, true);
	// ������
	DrawStringToHandle(kFontWidth1, kFontHeight1, kText1, kFontColorB, m_fontHandle);
	DrawStringToHandle(kFontWidth2, kFontHeight2, kText2, kFontColorB, m_fontHandle);
	DrawStringToHandle(kFontWidth3, kFontHeight3, kText3, kFontColorB, m_fontHandle);
	DrawStringToHandle(kFontWidth4, kFontHeight4, kText4, kFontColorB, m_fontHandle);
	DrawStringToHandle(kFontWidth5, kFontHeight5, kText5, kFontColorB, m_fontHandle);
	DrawStringToHandle(kFontWidth6, kFontHeight6, kText6, kFontColorY, m_fontHandle);
	DrawStringToHandle(kFontWidth7, kFontHeight7, kText7, kFontColorB, m_fontHandle);
	DrawStringToHandle(kFontWidth8, kFontHeight8, kText8, kFontColorB, m_fontHandle);
	DrawStringToHandle(kFontWidth9, kFontHeight9, kText9, kFontColorB, m_fontHandle);
	DrawStringToHandle(kFontWidth10, kFontHeight10, kText10, kFontColorB, m_fontHandle);
}