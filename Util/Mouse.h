#pragma once

#include "Vec2.h"

//// マウスの入力状態を取得する
//namespace Mouse
//{
//	// マウスの入力状態取得
//	void update();
//
//	// 現在のマウス位置取得
//	Vec2 getPos();
//
//	// 押し下げ判定
//	bool isPressLeft();
//	// トリガー判定
//	bool isTriggerLeft();
//	// 離した判定
//	bool isRelaseLeft();
//}

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