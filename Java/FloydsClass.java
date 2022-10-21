import java.util.Scanner;
public class FloydsClass {
	final static int MAX =20;
	static int cost[][];
	static int n;
	static Scanner scan = new Scanner(System.in);
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		cost = new int[MAX][MAX];
		ReadMatrix();
		Floyd();
		PrintMatrix();
	}
	
	static void ReadMatrix()
	{
		int i,j;
		cost= new int[MAX][MAX];//initialize cost matrix
		System.out.println("Enter the number of nodes");
		n=scan.nextInt();
		System.out.println("Enter the matrix elements:");
		for(i=1;i<=n;i++)
			for(j=1;j<=n;j++)
				cost[i][j]=scan.nextInt();
	}

	static void Floyd()
	{
		for(int k=1;k<=n;k++)
			for(int i=1;i<=n;i++)
				for(int j=1;j<=n;j++)
					if(cost[i][k]+cost[k][j]<cost[i][j])
						cost[i][j]=cost[i][k]+cost[k][j];
			
	}
	static void PrintMatrix()
	{
		int i,j;
		System.out.println("Output graph:");
		for(i=1;i<=n;i++)
			{
				for(j=1;j<=n;j++)
					System.out.print(cost[i][j]+" ");
				System.out.println("\n");
			}
	}
}
