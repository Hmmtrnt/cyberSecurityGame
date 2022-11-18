#pragma once
#include "SceneBase.h"

class Box;
class Mouse;
class Vec2;

class SceneMain : public SceneBase
{
public:
	SceneMain();
	virtual ~SceneMain();

	// ������
	virtual void init();
	// �C��
	virtual void end();

	// �X�V����
	virtual SceneBase* update();

	// �`��
	virtual void draw();

	// �����蔻��
	bool CheckHit(Vec2* pos, Vec2* size, int mousePosX, int mousePosY, int mouseSizeX, int mouseSizeY);

	int GetPushNum() const { return m_pushNum; }

protected:
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