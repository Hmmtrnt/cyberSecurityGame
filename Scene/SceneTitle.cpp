#include "SceneTitle.h"
#include "DxLib.h"
#include "game.h"
#include "Mouse.h"
#include "SceneMain.h"
#include "SceneExplanation.h"

namespace
{
	// �\������e�L�X�g
	const char* const kTitleText = "���\���[����������";
	const char* const kGuideText = "�X�y�[�X�L�[�������Ă�������";
	// �T�C�Y
	constexpr int kRadius = 64;
	// �t�H���g�̈ʒu
	constexpr int kFontWidth = 100;
	constexpr int kFontHeight = 200;
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
	constexpr int kTextDixpFrame = 45;	// �����
	constexpr int kTextHideFrame = 15;	// �B���
	// �w�i�F
	const int kBackgroundColor = GetColor(200, 200, 200);
	// �����F
	const int kFontColor = GetColor(0, 0, 0);
}

SceneTitle::SceneTitle() :
	m_hChar1(-1),
	m_hChar2(-1),
	m_fontHandle(-1)
{
}

void SceneTitle::init()
{
	m_hChar1 = LoadGraph("data/TitleCharWaru_1.png");
	m_hChar2 = LoadGraph("data/TitleCharOdoroki1.png");
	m_fontHandle = CreateFontToHandle(NULL, 56, 4);
}

void SceneTitle::end()
{
	DeleteGraph(m_hChar1);
	DeleteGraph(m_hChar2);
	DeleteFontToHandle(m_fontHandle);
}

SceneBase* SceneTitle::update()
{
	inputKey(m_key);
	if (m_key[KEY_INPUT_SPACE] == 1)
	{
		return(new SceneExplanation);
	}
	return this;
}

void SceneTitle::draw()
{
	DrawBox(0, 0, Game::kScreenWidth, Game::kScreenHeight, kBackgroundColor, true);
	DrawExtendGraph(kCharWidth2, kCharHeight2, kCharWidth2 + kCharSizeWidth2, kCharHeight2 + kCharSizeHeight2, m_hChar2, true);
	DrawExtendGraph(kCharWidth1, kCharHeight1, kCharWidth1 + kCharSizeWidth1, kCharHeight1 + kCharSizeHeight1, m_hChar1, true);
	DrawStringToHandle(kFontWidth, kFontHeight, "���\���[�����������b�I", GetColor(0, 0, 0), m_fontHandle);
}