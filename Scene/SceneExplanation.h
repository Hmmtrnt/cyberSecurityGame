#pragma once
#include "SceneBase.h"

class SceneExplanation : public SceneBase
{
public:
	SceneExplanation();
	virtual ~SceneExplanation() {}


	virtual void init() override;
	virtual void end() override {}

	virtual SceneBase* update() override;
	virtual void draw() override;

	virtual bool isEnd() { return m_isEnd; }
private:
	// �L�[�{�[�h�̓��͏��
	int key[256];

	bool m_isEnd;
};