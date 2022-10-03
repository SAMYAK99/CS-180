#include<bits/stdc++.h>
using namespace std;


 vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int n = mat.size()-1;
        int m = mat[0].size()-1;
        
         vector<pair<int,int>>arr;
        
        for(int j = n;j>=0;j--){
            arr.push_back({j,0});
        }
        for(int i = 1;i<=m;i++){
            arr.push_back({0,i});
        }
        vector<vector<int>>sol;
        for(auto i = 0;i<arr.size();i++){
            int x = arr[i].first;
            int y = arr[i].second;
           // cout<<x<<" "<<y<<" \n";
            vector<int>temp;
            while(x<=n && y<=m){
                temp.push_back(mat[x][y]);
                x++;
                y++;
            }
            sort(temp.begin(),temp.end());
            sol.push_back(temp);
        }
        
         for(auto i = 0;i<arr.size();i++){
            int x = arr[i].first;
            int y = arr[i].second;
             vector<int>c = sol[i];
             int k = 0;
            while(x<=n && y<=m && k<c.size()){
              mat[x][y] = c[k];
                x++;
                y++;
                k++;
            }
        }
        
       
        return mat;
    }


void print(vector<vector<int>>&matrix){
	for(auto x : matrix){
		for(auto y : x){
			cout<<y<<" ";
		}
		cout<<"\n";
	}
}


int main(){
    vector<vector<int>>matrix;
    int n;
    cin>>n;
    for(int i = 0;i<n;i++){
    	vector<int>temp;
    	for(int j = 0;j<n;j++){
    		int val ;
    		cin>>val;
    		temp.push_back(val);
		}
		matrix.push_back(temp);
	}
	cout<<"Before sort : \n";
	print(matrix);
	matrix = diagonalSort(matrix);
	cout<<"After Sort : \n";
	print(matrix);
	return 0;
}

