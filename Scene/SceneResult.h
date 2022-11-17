#pragma once
#include "SceneBase.h"

namespace Result
{
	constexpr int kKeyMax = 256;
}

class SceneResult : public SceneBase
{
public:
	SceneResult();
	virtual ~SceneResult() {}


	virtual void init() override;
	virtual void end() override;

	virtual SceneBase* update() override;
	virtual void draw() override;
private:
	// キーボードの入力状態
	int m_key[Result::kKeyMax];
	// フェード処理
	int m_fadeBright;
	// フェード速度
	int m_fadeSpeed;
	// 背景のグラフィックハンドル
	int m_hBackGround;
	// フォントのハンドル
	int m_fontHandle;
	// テキスト点滅用フレームカウント
	int m_textBlinkFrame;
};