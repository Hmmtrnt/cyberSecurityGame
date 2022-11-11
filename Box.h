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

	// 情報取得
	Vec2 getPos() const { return m_pos; }	// 座標
	Vec2 getVec() const { return m_vec; }	// サイズ

protected:
	// ボックスの座標
	Vec2 m_pos;
	// ボックスのサイズ
	Vec2 m_vec;

};