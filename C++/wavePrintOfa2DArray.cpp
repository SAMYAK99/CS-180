#include<iostream>

using namespace std;

int main(){
    int arr[100][100];
    int m,n;
    cin>>n>>m;
    int val=1;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            arr[i][j]=val;
            val+=1;
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
    for(int j=0;j<m;j++){
        for(int i=0;i<n;i++){
            if(j%2==0){
                cout<<arr[i][j]<<" ";
            }else{
                cout<<arr[n-i-1][j]<<" ";
            }
        }
    }

    return 0;
}