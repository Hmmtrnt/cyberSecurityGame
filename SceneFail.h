#pragma once
#include "SceneBase.h"

class SceneFail : public SceneBase
{
public:
	SceneFail();
	virtual ~SceneFail() {}


	virtual void init();
	virtual void end() {}

	virtual void update();
	virtual void draw();

	virtual bool isEnd() { return m_isEnd; }
private:

	bool m_isEnd;
};