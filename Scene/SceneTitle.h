#pragma once
#include "SceneBase.h"
#include <vector>

class Vec2;

namespace
{
	constexpr int keyMax = 256;
}

class SceneTitle : public SceneBase
{
public:
	SceneTitle();
	virtual ~SceneTitle() {}


	virtual void init() override;
	virtual void end() override;

	virtual SceneBase* update() override;
	virtual void draw() override;
private:
	// キーボードの入力状態
	int m_key[keyMax];
	// タイトル画面のキャラクター１
	int m_hChar1;
	// タイトル画面のキャラクター２
	int m_hChar2;
	// フォントのハンドル
	int m_fontHandle;
	int m_fontHandle2;
	// テキスト点滅用フレームカウント
	int m_textBlinkFrame;
	// フェード処理
	int m_fadeBright;
	// フェード速度
	int m_fadeSpeed;
};