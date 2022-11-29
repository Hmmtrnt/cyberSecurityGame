// タイトル画面
#pragma once
#include "SceneBase.h"

class Vec2;

namespace Title
{
	constexpr int kKeyMax = 256;
}

class SceneTitle : public SceneBase
{
public:
	SceneTitle();
	virtual ~SceneTitle();

	// 初期化処理
	virtual void init() override;
	// 終了処理
	virtual void end() override;
	// 更新処理
	virtual SceneBase* update() override;
	// 描画処理
	virtual void draw() override;
private:
	// キーボードの入力状態
	int m_key[Title::kKeyMax];
	// タイトル画面のキャラクター１
	int m_hChar1;
	// タイトル画面のキャラクター２
	int m_hChar2;
	// フォントのハンドル
	int m_fontHandle1;
	int m_fontHandle2;
	// テキスト点滅用フレームカウント
	int m_textBlinkFrame;
	// フェード
	int m_fadeBright;		// 処理
	int m_fadeSpeed;		// 速度
};