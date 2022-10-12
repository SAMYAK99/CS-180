//Hamiltonian Cycle

#include<stdio.h>

void next_value(int g[][100],int x[],int k, int n)
{
	int j;
    do
    {
        x[k]=(x[k]+1)%(n+1);

        if(x[k]==0)
            return;

        if(g[x[k-1]][x[k]]!=0)
        {
            for(j=1;j<=k-1;j++)
                if(x[j]==x[k])
                    break;
            
            if(j==k)
                if((k<n) || ((k==n) && g[x[n]][x[1]]!=0))
                    return;
        }
    } while (1);
    
}

void hamiltonian(int g[][100],int x[], int k, int n)
{
	int i;

    do
    {
        next_value(g,x,k,n);
        if(x[k]==0)
            return;
        if(k==n)
        {
			printf("Hamiltonian cycle is :");
		    for(i=1;i<=n;i++)
                printf("\t%d",x[i]);
			printf("\t%d\n",x[1]);
		}
        else
            hamiltonian(g,x,k+1,n);
    } while (1);
    
}

int main()
{
    int a[100][100],n,u,v,i,j,ne;
	int x[100],m;

	printf("Enter no. of vertices : ");
	scanf("%d",&n);

	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
			a[i][j]=0;

	printf("Enter no. of edges : ");
	scanf("%d",&ne);

	for(i=1;i<=ne;i++)
	{
		printf("\nEnter first terminal of edge %d : ",i);
		scanf("%d",&u);
		
		printf("\nEnter end terminal of edge %d : ",i);
		scanf("%d",&v);
		
		a[u][v]=1;
		a[v][u]=1;
	}

	printf("\n");
	
	x[1]=1;
	for(i=2;i<=n;i++)
		x[i]=0;
	
	hamiltonian(a,x,2,n);

	return 0;
}