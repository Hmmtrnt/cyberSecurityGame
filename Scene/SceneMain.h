#pragma once
#include "SceneBase.h"
#include "Box.h"
#include "Mouse.h"

class SceneMain : public SceneBase
{
public:
	SceneMain();
	virtual ~SceneMain() {}

	// ������
	virtual void init() override;
	// �C��
	virtual void end() override;

	// �X�V����
	virtual SceneBase* update() override;

	// �`��
	virtual void draw() override;

	// �����蔻��
	bool CheckHit(Vec2* pos, Vec2* size, int mousePosX, int mousePosY, int mouseSizeX, int mouseSizeY);

protected:
	// �L�[�{�[�h�̓��͏��
	int m_key[256];
	// �w�i�̃n���h��
	int m_hBackGround;
	// �t�H���g�̃n���h��
	int m_fontHandle;
	// �t�F�[�h����
	int m_fadeBright;
	// �t�F�[�h���x
	int m_fadeSpeed;
	// �c��̃v�b�V���o�����
	int m_pushNum;

	Box* m_box;
	Mouse* m_mouse;
};