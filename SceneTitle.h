#pragma once
#include "SceneBase.h"
#include "Vec2.h"

class SceneTitle : public SceneBase
{
public:
	SceneTitle();
	virtual ~SceneTitle() {}


	virtual void init();
	virtual void end() {}

	virtual void update();
	virtual void draw();

	virtual bool isPushEnable(Vec2 pos);
	virtual bool isEnd() const { return m_isEnd; }
	virtual bool isPush() const { return m_isPush; }

private:
	
	bool m_isEnd;

	bool m_isPush;
	Vec2 m_catdhOffset;
};