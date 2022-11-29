// 説明画面
#pragma once
#include "SceneBase.h"
#include <vector>

namespace Explanation
{
	constexpr int kKeyMax = 256;
}

class SceneExplanation : public SceneBase
{
public:
	SceneExplanation();
	virtual ~SceneExplanation();

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
	int m_key[Explanation::kKeyMax];
	// ハンドル
	int m_fontHandle;		// フォント
	int m_hChar;			// キャラクター
	int m_hObject;			// オブジェクト
	int m_hSpeechBubble;	// 吹き出し
	// フェード
	int m_fadeBright;		// 処理
	int m_fadeSpeed;		// 速度
};