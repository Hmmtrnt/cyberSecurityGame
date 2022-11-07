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
	// �L�[�{�[�h�̓��͏��
	int m_key[256];
	// 
	int m_hChar1;
	// �t�H���g�̃n���h��
	int m_fontHandle;
};