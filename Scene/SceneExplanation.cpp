#include "SceneExplanation.h"
#include "SceneMain.h"
#include "DxLib.h"
#include "game.h"

namespace
{
	// 表示するテキスト
	const char* const kText1 = "ある日、突然メールが来た。";
	const char* const kText2 = "私「動画見放題？何も知らないけど」";
	const char* const kText3 = "このメールは詐欺メールである、";
	const char* const kText4 = "どこが見分けるポイントか探そう";
	const char* const kText5 = "チャンスは３回だ";
	// 背景色
	const int kBackgroundColor = GetColor(200, 200, 200);	// 灰色
	// 文字色
	const int kFontColor = GetColor(0, 0, 0);				// 黒
	// フォントの位置
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
	// キャラの座標
	constexpr int kCharWidth = 50;
	constexpr int kCharHeight = 300;
	// キャラの大きさ
	constexpr int kCharSizeWidth = 150;
	constexpr int kCharSizeHeight = 190;
	// オブジェクトの座標
	constexpr int kObjectWidth = 150;
	constexpr int kObjectHeight = 450;
	// オブジェクトの大きさ
	constexpr int kObjectSizeWidth = 50;
	constexpr int kObjectSizeHeight = 60;
	// フェード関連
	constexpr int kFadeBright = 0;	// 処理
	constexpr int kFadeSpeed = 7;	// 速度
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
	m_fadeBright = kFadeBright;	// フェード処理
	m_fadeSpeed = kFadeSpeed;	// フェード速度
}

void SceneExplanation::end()
{
	DeleteFontToHandle(m_fontHandle);
}

SceneBase* SceneExplanation::update()
{
	// フェードアウト処理
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
		// フェードアウト開始
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
	// 描画の輝度
	SetDrawBright(m_fadeBright, m_fadeBright, m_fadeBright);
	// 背景
	DrawBox(0, 0, Game::kScreenWidth, Game::kScreenHeight, kBackgroundColor, true);
	// キャラ
	DrawExtendGraph(kCharWidth, kCharHeight, kCharWidth + kCharSizeWidth, kCharHeight + kCharSizeHeight, m_hChar, true);
	// オブジェクト
	DrawExtendGraph(kObjectWidth, kObjectHeight, kObjectWidth + kObjectSizeWidth, kObjectHeight + kObjectSizeHeight, m_hObject, true);
	// 文字列
	DrawStringToHandle(kFontWidth1, kFontHeight1, kText1, kFontColor, m_fontHandle);
	DrawStringToHandle(kFontWidth2, kFontHeight2, kText2, kFontColor, m_fontHandle);
	DrawStringToHandle(kFontWidth3, kFontHeight3, kText3, kFontColor, m_fontHandle);
	DrawStringToHandle(kFontWidth4, kFontHeight4, kText4, kFontColor, m_fontHandle);
	DrawStringToHandle(kFontWidth5, kFontHeight5, kText5, kFontColor, m_fontHandle);
}