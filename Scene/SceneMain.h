#pragma once
#include "SceneBase.h"

class Box;
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
	//bool CheckHit();

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
	// �}�E�X�̍��W
	int m_mouseX;
	int m_mouseY;
//	Vec2* m_mouse;

	// �����ꂽ�u�Ԃ̃t���[��
	int m_pushFlame;

	Box* m_box;
};