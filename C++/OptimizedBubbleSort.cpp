// Time Complexity
// Worst Case O(n^2)
// Average Case θ(n^2)
// Best Case Ω(n)

// Space Complexity O(1)

#include<bits/stdc++.h>
using namespace std;

void file_i_o() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  #ifndef ONLINE_JUDGE
    freopen("../Input.txt","r",stdin);
    freopen("../Output.txt","w",stdout);
  #endif
}

void OptimizedBubbleSort(vector<int>&arrayInt) {
  for(int i=0; i<arrayInt.size(); i++) {
    int swap = 0;
    for(int j=0; j<arrayInt.size()-i-1; j++) {
      if(arrayInt[j] > arrayInt[j+1]) {
        int temp = arrayInt[j];
        arrayInt[j] = arrayInt[j+1];
        arrayInt[j+1] = temp;
        swap = 1;
      }
    }
    if(swap == 0)
      break;
  }
}

void printArray(vector<int>arrayInt) {
  for(int i=0; i<arrayInt.size(); i++) 
    cout<<arrayInt[i]<<" ";
}

int main(int argc, char** argv) {   
  file_i_o();
  //write your code here Als
 	int size;
 	cin>>size;
 	vector<int>arrayInt(size);
 	for(int i=0; i<size; i++) 
 		cin>>arrayInt[i];

  OptimizedBubbleSort(arrayInt);
  printArray(arrayInt);
  return 0;
}