//Aastha Gupta

// Java program for Knight Tour problem
class BackTrackingSolution {
	static int N = 8;

	//To check validity of indexes for N*N chessboard
	static boolean isSafe(int x, int y, int sol[][]){
		return (x >= 0 && x < N && y >= 0 && y < N && sol[x][y] == -1);
	}

	// Print resultant matrix sol[N][N]
	static void printMatrix(int sol[][])
	{
		for (int x = 0; x < N; x++) {
			for (int y = 0; y < N; y++)
				System.out.print(sol[x][y] + "  ");
			System.out.println();
		}
	}

	//Function returns false if no complete tour is possible, otherwise return true and prints the tour.
	static boolean fun()
	{
		int sol[][] = new int[8][8];

		//matrix initialization
		for (int x = 0; x < N; x++)
			for (int y = 0; y < N; y++)
				  sol[x][y] = -1;

		// xn[] is next x coordinate and yn[] is next y coordinate
   		int xn[] = { 2, 1, -1, -2, -2, -1, 1, 2 };
		int yn[] = { 1, 2, 2, 1, -1, -2, -2, -1 };

		// Since the Knight is initially at the first block.
		sol[0][0] = 0;

		// Start from 0,0 and explore all tours using solve()
    
		if (!solve(0, 0, 1, sol, xn, yn)) {
			System.out.println("Solution does not exist");
			return false;
		}
		else
			printMatrix(sol);

		return true;
	}

	// to solve Knight Tour problem
  
	static boolean solve(int x, int y, int m, int sol[][], int xn[], int yn[]){
		int k, nextx, nexty;
		if (m == N * N)
			return true;

		// Try all next moves from the current coordinate x, y
    
		for (k = 0; k < 8; k++) {
			nextx = x + xn[k];
			nexty = y + yn[k];
			if (isSafe(nextx, nexty, sol)) {
				sol[nextx][nexty] = m;
				if (solve(nextx, nexty, m+ 1, sol, xn, yn))
					return true;
				else
					sol[nextx][nexty]	= -1;
			}
		}
		return false;
	}
  
	public static void main(String args[])
	{
		fun();
	}
}
