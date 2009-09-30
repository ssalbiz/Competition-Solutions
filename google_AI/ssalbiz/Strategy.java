public class Strategy
{

  private static int[][][] move_weighting = new int[3][5][3];
  public static String MakeMove()
  {
    int num_moves = Helper.NumPastMoves();
    if (num_moves <= 0) 
      return 0;
    int move = Helper.OpponentMove(num_moves-1);
    int past_move = Helper.MyMove(num_moves-1);

    move_weighting[past_move][num_moves % 5][move]++;
    int turn_weighting[] = move_weighting[past_move][num_moves % 5];
    int next_turn = Math.max(Math.max(turn_weighting[0], turn_weighting[1]), 
                             turn_weighting[2]);
    String next = (next_turn == turn_weighting[0]) ? "rock":(next_turn == turn_weighting[1]) ? "paper":"scissors";
    return next_turn;

		// Just return rock, no matter what.
		//return "rock";
  }

	// Ignore this function. It is just taking care of communicating with the
	// tournament software.
	public static void main(String[] args)
	{
		while (Helper.WaitForMyTurn()) Helper.Move(MakeMove());
	}
}
