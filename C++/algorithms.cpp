#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main()
{
    vector<int> v;

    v.push_back(1);
    v.push_back(3);
    v.push_back(6);
    v.push_back(7);

    cout<<"Finding 6=>"<<binary_search(v.begin(),v.end(),6)<<endl;

    int a=3;
    int b=5;

    cout<<"Max =>"<<max(a,b)<<endl;

    cout<<"Min =>"<<min(a,b)<<endl;;

    swap(a,b);
    cout<<"a=> "<<a<<endl;

    string s = "abcd";

    reverse(s.begin(),s.end());
    cout<<"Reverse of string=> "<<s<<endl;

    rotate(v.begin(),v.begin()+1,v.end());

    cout<<"After rotation"<<endl;
    for(int i:v){
        cout<<i<<" ";
    }cout<<endl;


    sort(v.begin(),v.end());
    cout<<"After sorting"<<endl;
     for(int i:v){
        cout<<i<<" ";
    }cout<<endl;



}
