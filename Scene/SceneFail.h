// 失敗画面
#pragma once
#include "SceneBase.h"

namespace Fail
{
	constexpr int kKeyMax = 256;
}

class SceneFail : public SceneBase
{
public:
	SceneFail();
	virtual ~SceneFail();

	// 初期化処理
	virtual void init() override;
	// 終了処理
	virtual void end() override;
	// 更新処理
	virtual SceneBase* update() override;
	// 描画処理
	virtual void draw() override;
private:
	// キーボードの入力状態
	int m_key[Fail::kKeyMax];
	// フェード
	int m_fadeBright;		// 処理
	int m_fadeSpeed;		// 速度
	// ハンドル
	int m_hBackGround;		// 背景のグラフィック
	int m_fontHandle;		// フォント
	// テキスト点滅用フレームカウント
	int m_textBlinkFrame;
};