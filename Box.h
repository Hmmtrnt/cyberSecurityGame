#pragma once

#include "Vec2.h"

class Box
{
public:
	Box();
	~Box();

	// 初期化
	void init();
	// 修了
	void end();
	// 処理
	void update();
	// 描画
	void draw();
	// 表示位置の設定
	void setPos(Vec2 pos) { m_pos = pos; }

	// 押したかどうか
	bool isPushEnable(Vec2 pos);

protected:
	// ボックスの座標
	Vec2 m_pos;

};