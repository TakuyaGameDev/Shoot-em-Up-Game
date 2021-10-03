#pragma once
#include <map>
#include <array>
#include <string>
#include <vector>
// 各入力デバイスの親クラス

// ボタン入力タイミングに関するenum
enum class TRG
{
	NOW,
	OLD,
	MAX
};

using TrgBool = std::array<bool, static_cast<int>(TRG::MAX)>;
// 入力情報を文字列で格納する方式にした
using CommandData = std::map<std::string, TrgBool>;
// 入力ﾃｰﾌﾞﾙ
using CommandTable = std::map<std::string, int>;

struct InputBase
{
	// 更新をかけている
	void operator()()
	{
		Update();
	}
	// 更新
	virtual void Update(void) = 0;
	// コマンドの追加処理
	// param@ cmName:コマンド名 param@ command:入力データ
	void AddCommand(std::string cmName,int command);
	// 押下時の状態の取得
	const TrgBool& GetState(std::string cmName)
	{
		return cmData_[cmName];
	}
private:

protected:
	// コマンド入力データ
	CommandData cmData_;
	// コマンド入力テーブル
	CommandTable cmTable_;
};

