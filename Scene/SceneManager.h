// �V�[���}�l�[�W���[
#pragma once
#include "SceneBase.h"

class SceneManager
{
public:
	SceneManager();
	virtual ~SceneManager();

	// ����������
	void init();
	// �I������
	void end();
	// �X�V����
	void update();
	// �`�揈��
	void draw();

	// ���N���X�̃|�C���^
	SceneBase* m_pScene;
};