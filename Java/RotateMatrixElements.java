
public class GFG {

	
	static final int P = 3;
	static final int Q = 3;


	static void rotate_Matrix(int mat[][], int K)
	{

		int tempo[] = new int[P];

	
		K = K % P;

		for (int j = 0; j < Q; j++) {

		
			for (int l = 0; l < P - K; l++)
				tempo[l] = mat[j][l];

		
			for (int x = P - K; x < P; x++)
				mat[j][x - P + K] = mat[j][x];

		
			for (int x = K; x < P; x++)
				mat[j][x] = tempo[x - K];
		}
	}


	static void show_Matrix(int mat[][])
	{
		for (int j = 0; j < Q; j++) {
			for (int x = 0; x < P; x++)
				System.out.print(mat[j][x] + " ");
			System.out.println();
		}
	}

	public static void main(String[] args)
	{
		
		int mat[][]
			= { { 1, 2, 5 }, { 3, 4, 6 }, { 8, 10, 9 } };

	
		int K = 2;

	
		rotate_Matrix(mat, K);

	
		show_Matrix(mat);
	}
}
