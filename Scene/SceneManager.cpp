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

// ����������
void SceneManager::init()
{
	m_pScene = new SceneTitle;
	m_pScene->init();
}

// �I������
void SceneManager::end()
{
	assert(m_pScene);
	if (!m_pScene)	return;

	m_pScene->end();
	delete m_pScene;
}

// �X�V����
void SceneManager::update()
{
	assert(m_pScene);
	if (!m_pScene)	return;

	SceneBase* pScene = m_pScene->update();
	if (pScene != m_pScene)
	{
		// �O�̃V�[���̏I������
		m_pScene->end();
		delete m_pScene;
		// ���̃V�[���̏�����
		m_pScene = pScene;
		m_pScene->init();
	}
}

// �`�揈��
void SceneManager::draw()
{
	assert(m_pScene);
	if (!m_pScene)	return;
	m_pScene->draw();
}