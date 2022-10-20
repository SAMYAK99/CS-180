import java.util.Scanner;

public class Hamiltonian {
	boolean found=false;
	int G[][];
	int X[];
	int n;
	public static void main(String[] args) {
		Hamiltonian ham =new Hamiltonian();
		ham.getData();
		System.out.println("Solution:");
		ham.HamiltonianMethod(2);
		ham.printNoSoln();
	}
	
	public void getData()
	{
		Scanner scan = new Scanner(System.in);
		System.out.println("\tHamiltonian Cycle");
		System.out.println("Enter the number of vertices");
		n=scan.nextInt();
		G=new int[n+1][n+1];
		X=new int [n+1];
		System.out.println("If edge is present 1 else 0:");
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
			{
				if((i!=j)&&(i<j))
				{
					System.out.print(i+ " and "+j+ " :");
					System.out.println();
					G[j][i]=G[i][j]=scan.nextInt();
				}
				if(i==j)
					G[i][j]=0;
			}
		for(int i=1;i<=n;i++)
			X[i]=0;
		X[1]=1;
		scan.close();
	}
	
	public void printNoSoln()
	{
		if(found==false)
			System.out.println("No solutions possible");
	}
	
	public void HamiltonianMethod(int k)
	{
		while(true)
		{
			NextValue(k,G,X,n);
			if(X[k]==0)
				return;
			if(k==n)
			{
				for(int i=1;i<=k;i++)
					System.out.print(X[i]+"--> ");
				System.out.println(X[1]);
				System.out.println();
				found=true;
				return;
			}
			else HamiltonianMethod(k+1);
			
		}
	}
	
	void NextValue(int k,int G[][],int X[],int n)
	{
		while(true)
		{
			X[k]=(X[k]+1)%(n+1);
			if(X[k]==0)
				return;
			if(G[X[k-1]][X[k]]!=0)
			{
				int j;
				for(j=1;j<k;j++)
					if(X[k]==X[j])
						break;
				if(j==k)
					if((k<n)||((k==n)&&G[X[n]][X[1]]==1))
						return;
			}
		}
	}
	
	
	

}
