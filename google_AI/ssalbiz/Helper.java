import java.io.*;
import java.util.*;

public class Helper
{
	private static Vector<Integer> myMoves;
	private static Vector<Integer> opponentMoves;
	private static int wins = 0, draws = 0, losses = 0;
	private static int lastOutcome = 0;
	
	public static int NumWins()
	{
		return wins;
	}
	
	public static int NumDraws()
	{
		return draws;
	}
	
	public static int NumLosses()
	{
		return losses;
	}
	
	public static int LastOutcome()
	{
		return lastOutcome;
	}
	
	private static String WaitForMessage()
	{
		try
		{
			InputStreamReader converter = new InputStreamReader(System.in);
			BufferedReader in = new BufferedReader(converter);
			return in.readLine();
		} catch (Exception e)
		{
			return null;
		}
	}
	
	public static boolean WaitForMyTurn()
	{
		while (true)
		{
			String message = WaitForMessage();
			
			if (message.startsWith("go"))
			{
				return true;
			}
			else if (message.startsWith("outcome"))
			{
				try
				{
					String[] fields = message.split(" ");
					int myMove = Integer.parseInt(fields[1]);
					int opponentMove = Integer.parseInt(fields[2]);
					
					if (myMoves == null)
					{
						myMoves = new Vector<Integer>();
					}
					
					myMoves.add(new Integer(myMove));
					
					if (opponentMoves == null)
					{
						opponentMoves = new Vector<Integer>();
					}
					
					opponentMoves.add(new Integer(opponentMove));
					String outcome = fields[3].trim().toLowerCase();
					if (outcome.startsWith("win"))
					{
						++wins;
						lastOutcome = 1;
					}
					else if (outcome.startsWith("draw"))
					{
						++draws;
						lastOutcome = 0;
					}
					else if (outcome.startsWith("loss"))
					{
						++losses;
						lastOutcome = -1;
					}
				}
				catch (Exception e)
				{
					// do nothing
				}
			}
			else
			{
				return false;
			}
		}
	}

	public static int NumPastMoves()
	{
		if (myMoves == null)
		{
			return 0;
		}
		else
		{
			return myMoves.size();
		}
	}

	public static int MyMove(int n)
	{
		if (myMoves == null)
		{
			return -1;
		}
		else
		{
			if (n >= 0 && n < myMoves.size())
			{
				return myMoves.get(n).intValue();
			}
			else
			{
				return -1;
			}
		}
	}

	public static int OpponentMove(int n)
	{
		if (opponentMoves == null)
		{
			return -1;
		}
		else
		{
			if (n >= 0 && n < opponentMoves.size())
			{
				return opponentMoves.get(n).intValue();
			}
			else
			{
				return -1;
			}
		}
	}
	
	public static void Move(int move)
	{
		System.out.println(move);
		System.out.flush();
	}
	
	public static void Move(String move)
	{
		System.out.println(move);
		System.out.flush();
	}
}
