//c++ program to implement matrix chain multiplication
#include<iostream>
using namespace std;
int S[20][20],M[20][20];
int PRINT_OPTIMAL_PARENS(int i,int j){
     if(i==j)
        cout<<" A"<<i;
     else{
        cout<<"(";
        PRINT_OPTIMAL_PARENS(i,S[i][j]);
        PRINT_OPTIMAL_PARENS(S[i][j]+1,j);
        cout<<")";
     }}
void MATRIX_CHAIN_ORDER(int p[],int length){
    int q,i,j,k,l;int n=length;
        for(i=1;i<=n;i++){
            M[i][i]=0;
        }
            for(l=2;l<=n;l++){
                    for(i=1;i<=n-l+1;i++){
                        j=i+l-1;
                            M[i][j]=999;
                            for(k=i;k<=j-1;k++){
                                q=((M[i][k]+M[k+1][j])+p[i-1]*p[k]*p[j]);
                                if(q<M[i][j]){
                                    M[i][j]=q;
                                    S[i][j]=k;}
                            }
                    }

            }
            cout<<"Total no of scaler multiplication needed is:"<<M[1][length]<<"\n";
            PRINT_OPTIMAL_PARENS(1,length);

    }



    int main(){
    int i,j,n;
        int p[99];
        cout<<"HOW MANY MATRICES U WANT TO KNOW ABOUT\n";
        cin>>n;
        cout<<"ENTER THE ORDER OF THE"<< n <<" MATRICES\n";
        for(i=0;i<=n;i++){
            cin>>p[i];}
            MATRIX_CHAIN_ORDER(p,n);
            return 0;

}





