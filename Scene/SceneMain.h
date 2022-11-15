#pragma once
#include "SceneBase.h"
#include "Box.h"
#include "Mouse.h"

class SceneMain : public SceneBase
{
public:
	SceneMain();
	virtual ~SceneMain() {}


	virtual void init() override;
	virtual void end() override;

	virtual SceneBase* update() override;
	virtual void draw() override;

	bool CheckHit(Vec2* pos, Vec2* size, int mousePosX, int mousePosY, int mouseSizeX, int mouseSizeY);

private:
	// キーボードの入力状態
	int m_key[256];
	// 背景のハンドル
	int m_hBackGround;
	// フォントのハンドル
	int m_fontHandle;
	// フェード処理
	int m_fadeBright;
	// フェード速度
	int m_fadeSpeed;

	Box* m_box;
	Mouse* m_mouse;
};