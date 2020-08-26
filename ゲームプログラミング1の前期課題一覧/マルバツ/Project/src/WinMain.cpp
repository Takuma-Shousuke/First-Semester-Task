
// ==============================
// 2020年 前期 
// ゲームプログラミング１
// 制作課題 その２
// ==============================

/**
■説明
	以下のプログラムは [ 〇×(三目並べ) ] というゲームをコーディングし、
	実行を確認したうえでその一部分を削除したものです。

	削除した部分は　※※　と記載し、
	本来入るべき処理の内容をコメントしてあります。

	コメント内容や他のコードを読み解き、ゲームを完成させなさい。

	※Hit And Blowに比べてコメントのヒントが少ないので
	　どのような処理を書けばよいか良く考えましょう
 */

/**
■制作環境
	このプログラムは、[ ＤＸライブラリ ] というライブラリを用いて作られています。
		ホームページ：https://dxlib.xsrv.jp/
		リファレンス：https://dxlib.xsrv.jp/dxfunc.html

	ＤＸライブラリについて興味のある人は、
	ホームページ、リファレンスページ（用意されている関数の説明）を見てみてください。
*/

/**
■〇×(三目並べ)のルール
	ルールについては、自分で調べて把握するようにしてください
*/

#include "WinMain.h"
#include "InputManager.h"
#include "DrawManager.h"
#include "KeyDefionition.h"
#include <stdio.h>
#include <time.h>

// ==============================
// グローバル変数
// ==============================
// 横:STAGE_WIDTH、縦:STAGE_HEIGHTのint型２次元配列 map を宣言

int map[STAGE_WIDTH][STAGE_HEIGHT];

// ==============================
// 関数プロトタイプ宣言
// ==============================
// 盤面の x, y の位置に石が置けるかどうか

// bool型の戻り値、int型の引数x,yを持つIsPutStone関数を宣言

// int IsPutStone(boolの戻り値);

// 勝者が居るかを調べる
 // int型の戻り値を持つCheckWinner関数を宣言
int CheckWinner();

// ==============================
// Main関数
// ==============================
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	// ＤＸライブラリを使う上での初期化処理
	// ----------------------------------------------------
	SetOutApplicationLogValidFlag(FALSE);
	ChangeWindowMode(TRUE);
	SetGraphMode(WINDOW_W, WINDOW_H, 32);
	SetBackgroundColor(125, 125, 255);
	SetMainWindowText("マルバツ");
	if (DxLib_Init() == -1) { return -1; }

	SetDrawScreen(DX_SCREEN_BACK);

	// ローカル変数宣言
	// ----------------------------------------------------
	// 整数型の変数pos_xを宣言し、0で初期化		// X座標選択位置

		int pos_x = 0;

	// 整数型の変数pos_yを宣言し、0で初期化		// Y座標選択位置

		int pos_y = 0;

	// 整数型の変数turnを宣言し、STONE_WHITEで初期化	// 現在の手番

		int turn = STONE_WHITE;

	// 整数型の変数winnerを宣言し、WINNER_NONで初期化	// 勝利者

		int winner = WINNER_NON;


	// 各種初期化処理
	// ----------------------------------------------------
	InputInit();			// 入力処理初期化関数の呼び出し
	DrawInit();				// 描画処理初期化関数の呼び出し

	// mapの初期化
	// 二次元配列mapの全要素を STONE_MAX で初期化する

		map[STAGE_WIDTH][STAGE_HEIGHT] = STONE_MAX;

	// ゲームのメインループ
	// 画面を１回表示する毎にwhile分を１回処理する
	// ----------------------------------------------------
	while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0)
	{
		// ＤＸライブラリを使う上で、１フレーム分の処理を始めるためのお約束
		// ----------------------------------------------------
		ClearDrawScreen();
		clsDx();

		// 以下、毎フレーム更新する処理
		// ----------------------------------------------------
		InputUpdate();			// 入力処理更新関数の呼び出し
		// winner に勝利者情報を代入	// 勝利者のチェック



		// --- 入力状況をチェックして、適切な処理を行う
		// 決着がついてない時だけ入力を受け付けるように if文 でチェックする
		if( CheckWinner == false )
		{
			// 上下左右の入力があった時の処理
			if(IsPushKey(MY_INPUT_UP))
			{
				// pos_yの値を 1 減らす

				pos_y--;
			}
			else if(IsPushKey(MY_INPUT_DOWN))
			{
				// pos_yの値を 1 増やす

				pos_y++;
			}
			else if(IsPushKey(MY_INPUT_LEFT))
			{
				// pos_xの値を 1 減らす

				pos_x--;
			}
			else if(IsPushKey(MY_INPUT_RIGHT))
			{
				// pos_xの値を 1 増やす

				pos_x++;
			}
			// 決定(=エンターキー)が押された時の処理
			else if(IsPushKey(MY_INPUT_ENTER))
			{
				// 現在の座標が有効か if文 でチェックし、
				// 結果が true の時、以下の処理を行う
				if (IsPutStone int x,int y == true)
				{
					
					// 以下の処理を実装する

					// 選択されている座標と対応するmap配列の要素へturnの値を代入

					map[STAGE_WIDTH][STAGE_HEIGHT] = turn;

					// 次のターンに回すため、turnの値を変更する

					turn++;

				}
			}
		}

		// 以下、描画処理
		// ----------------------------------------------------
		// 情報文章を描画

			void DrawInformation(int turn);

		// ゲームクリアの文字を描画

			void DrawGameClear(int winner);

				// 枠線を描画

			void DrawBgLine();

		// ２重for文を使って盤面の石を描画する

			void DrawStone(int x, int y, int stone);
			for (int x = 0; x < 3; x++)
			{
				const int center_x = DRAW_OFFSET_X + (x * CELLSIZE) + int(CELLSIZE * 0.5);

				for (int y = 0; y < 3; y++)
				{
					const int center_y = DRAW_OFFSET_Y + (y * CELLSIZE) + int(CELLSIZE * 0.5);

					switch (stone)
					{
					case STONE_WHITE:
						DrawCircle(center_x, center_y, CIRCLE_R, GetColor(0xFF, 0xFF, 0xFF), TRUE);
						break;

					case STONE_BLACK:
						DrawCircle(center_x, center_y, CIRCLE_R, GetColor(0x00, 0x00, 0x00), TRUE);
						break;
					}
				}
			}
				
			

		// カーソルを描画

			void DrawCursor(int x, int y);


		// ＤＸライブラリを使う上で、モニターへゲーム画面を表示するためのお約束
		// 必ずループの最後で呼び出す
		// ----------------------------------------------------
		ScreenFlip();
	}

	// 後始末
	// ----------------------------------------------------
	DrawEnd();		// 描画処理終了

	// ＤＸライブラリを使う上での終了処理
	// ----------------------------------------------------
	DxLib_End();
	return 0;
}

// ==============================
// 盤面の x, y の位置に石が置けるかどうか
// true = 置ける
// false = 置けない
// ==============================
bool IsPutStone( int x, int y )
{
	// 盤面の x, y の位置に石が置けるならtrue,置けないならfalseを返す処理
	
}

// ==============================
// 勝者が居るかを調べる
// ==============================
int CheckWinner()
{
	// 以下の処理を実装する
	// 縦、横、斜めが同じ石かどうかを調べる
	// STONE_WHITE, STONE_BLACK, STONE_MAXを上手く使いましょう

	// もし、まだ揃っていなかったら、盤面に置かれている石の数を調べる
		 
	// 全てのマスに石が置かれていたら引き分け
	
	// 上記のいずれかでも無かったらWINNER_NONを返す
	return WINNER_NON;
}
