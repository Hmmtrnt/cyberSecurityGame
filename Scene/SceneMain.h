#pragma once
#include "SceneBase.h"
#include "Box.h"
#include "Mouse.h"

class SceneMain : public SceneBase
{
public:
	SceneMain();
	virtual ~SceneMain() {}

	// 初期化
	virtual void init() override;
	// 修了
	virtual void end() override;

	// 更新処理
	virtual SceneBase* update() override;

	// 描画
	virtual void draw() override;

	// 当たり判定
	bool CheckHit(Vec2* pos, Vec2* size, int mousePosX, int mousePosY, int mouseSizeX, int mouseSizeY);

protected:
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
	// 残りのプッシュ出来る回数
	int m_pushNum;

	Box* m_box;
	Mouse* m_mouse;
};