#pragma once

#include "Vec2.h"

class Mouse
{
public:
	Mouse();
	~Mouse();

	void init();
	void end();
	void update();
	void draw();
private:
	// 押されたり離され足りするボタンの値
	int m_button;
	// クリックした座標
	int m_clickX;	// X
	int m_clickY;	// Y
	// ボタンが押されたのかまたは離されたのかの情報取得
	int m_logType;
	// 描画するかどうか
	int m_drawFlag;
	// 描画座標
	int	m_drawX;		// X
	int	m_drawY;		// Y
	// 描画色
	int m_drawColor;
};