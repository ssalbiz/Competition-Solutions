#include <iostream>
#include <vector>
#include <string>

class Helper
{
private:
	static std::vector<int> myMoves;
	static std::vector<int> opponentMoves;
	static int wins, draws, losses;
	static int lastOutcome;

public:
	static void Init();
	static int NumWins();
	static int NumDraws();
	static int NumLosses();
	static int LastOutcome();
	static std::string WaitForMessage();
	static bool StartsWith(const std::string& s, const std::string prefix);
	static std::vector<std::string> Split(const std::string& s);
	static bool WaitForMyTurn();
	static int NumPastMoves();
	static int MyMove(int n);
	static int OpponentMove(int n);
	static void Move(int move);
	static void Move(std::string move);
};
