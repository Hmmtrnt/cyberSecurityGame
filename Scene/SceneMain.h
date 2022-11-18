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

	// 初期化
	virtual void init();
	// 修了
	virtual void end();

	// 更新処理
	virtual SceneBase* update();

	// 描画
	virtual void draw();

	// 当たり判定
	bool CheckHit(Vec2* pos, Vec2* size, int mousePosX, int mousePosY, int mouseSizeX, int mouseSizeY);

	int GetPushNum() const { return m_pushNum; }

protected:
	// 背景のハンドル
	int m_hBackGround;
	// フォントのハンドル
	int m_fontHandle;
	// フェード処理
	int m_fadeBright;
	// フェード速度
	int m_fadeSpeed;
	// 残りのプッシュ出来る回数
	int m_pushNum;

	Box* m_box;
	Mouse* m_mouse;
};