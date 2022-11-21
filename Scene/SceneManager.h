#pragma once
#include "SceneBase.h"

class SceneManager
{
public:
	SceneManager();
	virtual ~SceneManager();

	void init();
	void end();
	void update();
	void draw();

	//SceneBase* GetScene() { return m_pScene; }
	SceneBase* m_pScene;

protected:
};