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
	const char* const kText5 = "チャンスは３回だ!";
	const char* const kText6 = "ご入会ありがとうございます！";
	const char* const kText7 = "動画見放題プラン";
	const char* const kText8 = "一週間以内にご入金ください";
	const char* const kText9 = "金額は２万４０００円です";
	const char* const kText10 = "スペースキーを押してスタート！";
	// 背景色
	const int kBackgroundColor = GetColor(200, 200, 200);	// 灰
	// 文字色
	const int kFontColorB = GetColor(0, 0, 0);				// 黒
	const int kFontColorY = GetColor(200, 0, 0);			// 黄
	// フォントの位置
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
	// キャラの座標
	constexpr int kCharWidth = 50;
	constexpr int kCharHeight = 330;
	// キャラの大きさ
	constexpr int kCharSizeWidth = 150;
	constexpr int kCharSizeHeight = 190;
	// オブジェクトの座標
	constexpr int kObjectWidth = 150;
	constexpr int kObjectHeight = 480;
	// オブジェクトの大きさ
	constexpr int kObjectSizeWidth = 70;
	constexpr int kObjectSizeHeight = 60;
	// 吹き出しの座標
	constexpr int kSBubbleWidth = 200;
	constexpr int kSBubbleHeight = 230;
	// 吹き出しの大きさ
	constexpr int kSBubbleSizeWidth = 500;
	constexpr int kSBubbleSizeHeight = 270;
	// フェード関連
	constexpr int kFadeBright = 0;	// 処理
	constexpr int kFadeSpeed = 7;	// 速度
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
	m_fadeBright = kFadeBright;	// フェード処理
	m_fadeSpeed = kFadeSpeed;	// フェード速度
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
	// オブジェクト(スマホ)
	DrawExtendGraph(kObjectWidth, kObjectHeight, kObjectWidth + kObjectSizeWidth, kObjectHeight + kObjectSizeHeight, m_hObject, true);
	// 吹き出し
	DrawExtendGraph(kSBubbleWidth, kSBubbleHeight, kSBubbleWidth + kSBubbleSizeWidth, kSBubbleHeight + kSBubbleSizeHeight, m_hSpeechBubble, true);
	// 文字列
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