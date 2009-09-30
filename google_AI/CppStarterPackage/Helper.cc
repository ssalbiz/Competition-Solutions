#include "Helper.h"
#include <cstdlib>

std::vector<int> Helper::myMoves;
std::vector<int> Helper::opponentMoves;
int Helper::wins, Helper::draws, Helper::losses;
int Helper::lastOutcome;

void Helper::Init()
{
	wins = 0;
	draws = 0;
	losses = 0;
	lastOutcome = 0;
}

int Helper::NumWins()
{
	return wins;
}

int Helper::NumDraws()
{
	return draws;
}

int Helper::NumLosses()
{
	return losses;
}

int Helper::LastOutcome()
{
	return lastOutcome;
}

std::string Helper::WaitForMessage()
{
	char buf[1024];
	std::cin.getline(buf, 1024);
	return std::string(buf);
}

bool Helper::StartsWith(const std::string& s, const std::string prefix)
{
	if (prefix.length() > s.length())
	{
		return false;
	}

	for (int i = 0 ; i < prefix.length() ; ++i)
	{
		if (prefix[i] != s[i])
		{
			return false;
		}
	}

	return true;
}

std::vector<std::string> Helper::Split(const std::string& s)
{
	std::vector<std::string> v;
	std::string buf;
	
	for (int i = 0 ; i < s.length() ; ++i)
	{
		if (s[i] == ' ')
		{
			if (buf.length() > 0)
			{
				v.push_back(buf);
				buf = std::string();
			}
		}
		else
		{
			buf += s[i];
		}
	}
	
	if (buf.length() > 0)
	{
		v.push_back(buf);
	}
	
	return v;
}

bool Helper::WaitForMyTurn()
{
	while (true)
	{
		std::string message = WaitForMessage();
		
		if (StartsWith(message, "go"))
		{
			return true;
		}
		else if (StartsWith(message, "outcome"))
		{
			std::vector<std::string> fields = Split(message);

			if (fields.size() == 4)
			{
				int myMove = atoi(fields[1].c_str());
				int opponentMove = atoi(fields[2].c_str());
				myMoves.push_back(myMove);
				opponentMoves.push_back(opponentMove);
				std::string outcome = fields[3];

				if (outcome == "WIN")
				{
					++wins;
					lastOutcome = 1;
				}
				else if (outcome == "DRAW")
				{
					++draws;
					lastOutcome = 0;
				}
				else if (outcome == "LOSS")
				{
					++losses;
					lastOutcome = -1;
				}
			}
		}
		else
		{
			return false;
		}
	}
}

int Helper::NumPastMoves()
{
	return myMoves.size();
}

int Helper::MyMove(int n)
{
	if (n >= 0 && n < myMoves.size())
	{
		return myMoves[n];
	}
	else
	{
		return -1;
	}
}

int Helper::OpponentMove(int n)
{
	if (n >= 0 && n < opponentMoves.size())
	{
		return opponentMoves[n];
	}
	else
	{
		return -1;
	}
}

void Helper::Move(int move)
{
	std::cout << move << std::endl;
	std::cout.flush();
}

void Helper::Move(std::string move)
{
	std::cout << move << std::endl;
	std::cout.flush();
}
