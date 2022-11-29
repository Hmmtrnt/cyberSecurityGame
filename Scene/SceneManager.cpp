#include "SceneManager.h"
#include <cassert>
#include "SceneTitle.h"
#include "SceneExplanation.h"
#include "SceneMain.h"
#include "SceneResult.h"
#include "SceneFail.h"

SceneManager::SceneManager()
{
	m_pScene = nullptr;
}

SceneManager::~SceneManager()
{
}

// 初期化処理
void SceneManager::init()
{
	m_pScene = new SceneTitle;
	m_pScene->init();
}

// 終了処理
void SceneManager::end()
{
	assert(m_pScene);
	if (!m_pScene)	return;

	m_pScene->end();
	delete m_pScene;
}

// 更新処理
void SceneManager::update()
{
	assert(m_pScene);
	if (!m_pScene)	return;

	SceneBase* pScene = m_pScene->update();
	if (pScene != m_pScene)
	{
		// 前のシーンの終了処理
		m_pScene->end();
		delete m_pScene;
		// 次のシーンの初期化
		m_pScene = pScene;
		m_pScene->init();
	}
}

// 描画処理
void SceneManager::draw()
{
	assert(m_pScene);
	if (!m_pScene)	return;
	m_pScene->draw();
}