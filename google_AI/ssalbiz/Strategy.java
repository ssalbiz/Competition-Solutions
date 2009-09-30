public class Strategy
{
  //move_weightings segmented by number of moves % n = ??(5?), (n-1)th move
  private static int[][][] move_weighting = new int[3][5][3];
  public static int MakeMove()
  {
  // Just return rock, no matter what.
    int num_moves = Helper.NumPastMoves();
    if (num_moves <= 0) 
      return 0;
    int move = Helper.OpponentMove(num_moves);
    int past_move = Helper.MyMove(num_moves-1);

    move_weighting[past_move][num_moves % 5][move]++;
    int turn_weighting[] = move_weighting[past_move][num_moves % 5];
    int next_turn = Math.max(Math.max(turn_weighting[0], turn_weighting[1]), turn_weighting[2]);
    next_turn = (next_turn == turn_weighting[0]) ? 0:(next_turn == turn_weighting[1]) ? 1:2;
    return next_turn;
  }
	
  // Ignore this function. It is just taking care of communicating with the
  // tournament software.
  public static void main(String[] args)
  {
    while (Helper.WaitForMyTurn()) Helper.Move(MakeMove());
  }
}
