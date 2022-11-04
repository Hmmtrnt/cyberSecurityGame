#pragma once
#include "SceneBase.h"
#include "Vec2.h"

class SceneTitle : public SceneBase
{
public:
	SceneTitle();
	virtual ~SceneTitle() {}


	virtual void init() override;
	virtual void end() override {}

	virtual SceneBase* update() override;
	virtual void draw() override;

	virtual bool isEnd() const { return m_isEnd; }
private:
	// キーボードの入力状態
	int key[256];

	bool m_isEnd;
};