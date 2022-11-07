#pragma once
#include "SceneBase.h"
#include "Vec2.h"
#include <vector>

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
	int m_key[256];
	// 
	int m_hChar1;
	// フォントのハンドル
	int m_fontHandle;
};