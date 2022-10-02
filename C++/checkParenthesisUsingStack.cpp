#include<bits/stdc++.h>
using namespace std;
#define test int t;cin>>t;while(t-->0)
#define mod 1000000007

// Function to return if the paranthesis are balanced or not
bool ispar(string x)
{
    stack< int >s;
    int n=x.length(),i;
    for(i=0;i<n;i++){
        if(x[i]=='{' || x[i]=='[' ||x[i]=='(' ){
        s.push(x[i]);
        }
        else{
            if(s.empty()==true){
                return false;
            }
            else if(x[i]=='}' && s.top()!='{' ||
                    x[i]==')' && s.top()!='(' ||
                    x[i]==']' && s.top()!='[' ){
                return false;
            }
            else{
                s.pop();
            }
        }
    }
    return (s.empty()==true);
    // Your code here
}

int main(){
test{
string a;
cin>>a;
if(ispar(a)){
    cout<<"Balanced"<<"\n";
}
else{
    cout<<"Not Balanced"<<"\n";
}
}
}


