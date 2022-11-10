#pragma once
#include "SceneBase.h"

class SceneResult : public SceneBase
{
public:
	SceneResult();
	virtual ~SceneResult() {}


	virtual void init() override;
	virtual void end() override {}

	virtual SceneBase* update() override;
	virtual void draw() override;
private:
	// キーボードの入力状態
	int m_key[256];
	// フェード処理
	int m_fadeBright;
	// フェード速度
	int m_fadeSpeed;
};