#include "Helper.h"
#include <string>

std::string MakeMove()
{
	// Always choose rock, no matter what.
	return "rock";
}

// Ignore this function. It is just taking care of communicating with the
// tournament software.
int main(int argc, char *argv[])
{
	Helper::Init();
	while (Helper::WaitForMyTurn()) Helper::Move(MakeMove());
}
