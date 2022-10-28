#include "SceneManeger.h"
#include <cassert>
#include "Mouse.h"

SceneManager::SceneManager() :
	m_kind(kSceneKindTitle)
{
}

SceneManager::~SceneManager()
{
}

void SceneManager::init(SceneKind kind)
{
	m_kind = kind;
	switch (m_kind)
	{
	case SceneManager::kSceneKindTitle:
		m_title.init();
		break;
	case SceneManager::kSceneKindExplanation:
		m_explanation.init();
		break;
	case SceneManager::kSceneKindMain:
		m_main.init();
		break;
	case SceneManager::kSceneKindResult:
		m_result.init();
		break;
	case SceneManager::kSceneKindFail:
		m_fail.init();
		break;
	case SceneManager::kSceneKindNum:
	default:
		assert(false);
		break;
	}
}

void SceneManager::end()
{
	switch (m_kind)
	{
	case SceneManager::kSceneKindTitle:
		m_title.end();
		break;
	case SceneManager::kSceneKindExplanation:
		m_explanation.end();
		break;
	case SceneManager::kSceneKindMain:
		m_main.end();
		break;
	case SceneManager::kSceneKindResult:
		m_result.end();
		break;
	case SceneManager::kSceneKindFail:
		m_fail.end();
		break;
	case SceneManager::kSceneKindNum:
	default:
		assert(false);
		break;
	}
}

void SceneManager::update()
{
	Mouse::update();
	bool isEnd = false;
	switch (m_kind)
	{
	case SceneManager::kSceneKindTitle:
		m_title.update();
		break;
	case SceneManager::kSceneKindExplanation:
		m_explanation.update();
		break;
	case SceneManager::kSceneKindMain:
		m_main.update();
		break;
	case SceneManager::kSceneKindResult:
		m_result.update();
		break;
	case SceneManager::kSceneKindFail:
		m_fail.update();
		break;
	case SceneManager::kSceneKindNum:
	default:
		assert(false);
		break;
	}
	// ƒV[ƒ“I—¹
	if (isEnd)
	{
		switch (m_kind)
		{
		case SceneManager::kSceneKindTitle:
			m_title.end();
			m_explanation.init();
			m_kind = kSceneKindExplanation;
			break;
		case SceneManager::kSceneKindExplanation:
			m_explanation.end();
			m_main.init();
			m_kind = kSceneKindMain;
			break;
		case SceneManager::kSceneKindMain:
			m_main.end();
			m_result.init();
			m_kind = kSceneKindResult;
			break;
		case SceneManager::kSceneKindResult:
			m_result.end();
			m_fail.init();
			m_kind = kSceneKindFail;
			break;
		case SceneManager::kSceneKindFail:
			m_fail.end();
			m_title.init();
			m_kind = kSceneKindTitle;
			break;
		case SceneManager::kSceneKindNum:
		default:
			assert(false);
			break;
		}
	}
}

void SceneManager::draw()
{
	switch (m_kind)
	{
	case SceneManager::kSceneKindTitle:
		m_title.draw();
		break;
	case SceneManager::kSceneKindExplanation:
		m_explanation.draw();
		break;
	case SceneManager::kSceneKindMain:
		m_main.draw();
		break;
	case SceneManager::kSceneKindResult:
		m_result.draw();
		break;
	case SceneManager::kSceneKindFail:
		m_fail.draw();
		break;
	case SceneManager::kSceneKindNum:
	default:
		assert(false);
		break;
	}
}