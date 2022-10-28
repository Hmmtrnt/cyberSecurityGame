#pragma once

#include "SceneTitle.h"
#include "SceneExplanation.h"
#include "SceneMain.h"
#include "SceneResult.h"
#include "SceneFail.h"

class SceneManager
{
public:
	// ƒV[ƒ“‚Ìí—Ş’è‹`
	typedef enum SceneKind
	{
		kSceneKindTitle,
		kSceneKindExplanation,
		kSceneKindMain,
		kSceneKindResult,
		kSceneKindFail,

		kSceneKindNum
	}SceneKind;

public:
	SceneManager();
	virtual ~SceneManager();

	void init(SceneKind kind = kSceneKindTitle);
	void end();

	void update();
	void draw();

private:
	SceneKind	m_kind;

	SceneTitle			m_title;
	SceneExplanation	m_explanation;
	SceneMain			m_main;
	SceneResult			m_result;
	SceneFail			m_fail;
};