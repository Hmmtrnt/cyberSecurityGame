#pragma once
#include "SceneBase.h"
#include <vector>

class SceneExplanation : public SceneBase
{
public:
	SceneExplanation();
	virtual ~SceneExplanation() {}


	virtual void init() override;
	virtual void end() override;

	virtual SceneBase* update() override;
	virtual void draw() override;
private:
	// キーボードの入力状態
	int m_key[256];
	// フォントのハンドル
	int m_fontHandle;
	// キャラクターのハンドル
	int m_hChar;
	// オブジェクトのハンドル
	int m_hObject;
	// 吹き出しのハンドル
	int m_hSpeechBubble;
	// フェード処理
	int m_fadeBright;
	// フェード速度
	int m_fadeSpeed;
};