#pragma once

class Mouse
{
public:
	Mouse();
	~Mouse();

	virtual void init();
	virtual void end();
	virtual void update(int& pushNum);

	int getPosX() const { return m_drawX - 2; }		// 座標
	int getPosY() const { return m_drawY - 2; }		// 座標
	int getSizeX() const { return m_drawX + 2; }	// サイズ
	int getSizeY() const { return m_drawY + 2; }	// サイズ

protected:
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
	int	m_drawX;	// X
	int	m_drawY;	// Y
	// 描画色
	int m_drawColor;
};