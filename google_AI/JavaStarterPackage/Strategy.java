public class Strategy
{
	public static String MakeMove()
	{
		// Just return rock, no matter what.
		return "rock";
	}
	
	// Ignore this function. It is just taking care of communicating with the
	// tournament software.
	public static void main(String[] args)
	{
		while (Helper.WaitForMyTurn()) Helper.Move(MakeMove());
	}
}
