#pragma once
#include "SceneBase.h"

class SceneFail : public SceneBase
{
public:
	SceneFail();
	virtual ~SceneFail() {}


	virtual void init() override;
	virtual void end() override;

	virtual SceneBase* update() override;
	virtual void draw() override;
private:
	// キーボードの入力状態
	int m_key[256];
	// フェード処理
	int m_fadeBright;
	// フェード速度
	int m_fadeSpeed;
	// フォントのハンドル
	int m_fontHandle;
	// テキスト点滅用フレームカウント
	int m_textBlinkFrame;
};