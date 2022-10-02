#define _GLIBCXX_DEBUG  //debug mode, remove when submitting code due to time complexity issues
#include<iostream>
#include<vector>
#include<set>
#include <map>
#include<algorithm>
#include <list>
using namespace std;
#pragma GCC optimize "trapv"    //in case of int overflow, codechef will give RE instead of WA
bool f(int x, int y)
{
    return x>y;
}

void vectorDemo()
{
    cout<<"\t___Vector Demo___\n";
    vector<int> num = {2,4,29,5,6,12,11,10};
    cout<<"hello competitive coding!"<<endl;
    sort(num.begin(),num.end());
    //num.sort(); //syntax error
    for(int i=0;i<num.size();i++)
        cout<<num[i]<<" ";
    cout<<endl;
    cout<<"Max ele: "<<*max_element(num.begin(), num.end())<<endl;

    //num.clear();                  //it will delete all elements of vector
    //num.empty();                  //returns True or False if the vector is empty or not
    //num.erase(3,6); num.erase(3); //erases elements at given index or range of indexes (accepts iterators only)     

    int num2[] = {3,4,55,22,11, 8, 4};
    sort(num2,num2+(sizeof(num2)/sizeof(num2[0])));
    for(int i=0;i<sizeof(num2)/sizeof(num2[1]);i++)
        cout<<num2[i]<<" ";

    bool isP = binary_search(num.begin(),num.end(),9);
    isP?cout<<endl<<"9 is present":cout<<endl<<"9 is not present";
    num.pop_back();
    num.push_back(23);
    num.push_back(23);
    num.push_back(23);
    num.push_back(25);
    cout<<endl;
    for(int i=0;i<num.size();i++)
        cout<<num[i]<<" ";
    cout<<endl;
    vector<int>::iterator n = lower_bound(num.begin(), num.end(), 23);  //>=
    auto n2 = upper_bound(num.begin(), num.end(), 23); //>
    cout<<*n<<" "<<*n2<<endl;
    cout<<n2-n<<endl;
    
    sort(num.begin(), num.end(), f);
    for(int &x: num)
    {
        x++;
    }
    cout<<endl;
    for(int x: num)
        cout<<x<<" ";    
    cout<<endl;
    
    cout<<num.at(2)<<" "<<num[2]<<endl;

    vector <int> seta(5,1);      //vector of size 5 with all elements as 1
    for(auto i : seta) cout<<i<<" "; cout<<endl;
}

void setDemo()
{   
    cout<<"\t___Set Demo___\n";
    set<int> S;
    S.insert(1);    //inserts given element in O(logn) time
    S.insert(3);
    S.insert(-2);
    S.insert(-10);
    S.insert(3);    //duplicate not inserted
    S.insert(3);
    // S.erase(1);     //deletes given element in O(logn) time
    for(int x: S)
        cout<<x<<" ";
    cout<<endl;

    auto it = S.find(-2);
    if(it == S.end())
        cout<<"Not found\n";
    else
        cout<<"present "<< *it <<endl;
    
    auto it2 = S.upper_bound(1);
    auto it3 = S.lower_bound(1);
    cout<<*it2<<" "<<*it3<<endl;
    int y = S.count(3); cout<<y<<endl;
}

void mapDemo()
{
    cout<<"\t___Map Demo___\n";
    map<int,int> M;
    M[0] = 1;
    M[1] = 3;
    M[21] = -1;
    M[34322] = 100;
    M[23] = 5;

    // auto itr = M.begin();
    for(auto itr: M)
        cout<<itr.second<<" ";
    cout<<endl;

    for(auto it=M.begin(); it!=M.end(); it++)
        cout<<it->second<<" ";
    cout<<endl;
    
    map <char,int> cnt;
    string x = "Vishal Rex aa";
    for (char c: x)
        cnt[c]++;
    cout<<cnt['a']<<" "<<cnt['z']<<endl;
}

void listDemo()
{
    cout<<"\t___List Demo___\n";
    list <int> l;
    //list<int> l(5,4);   //initialize list of size 5 with all values set to 4
    l.push_back(1);
    l.push_front(0);
    // l.pop_back();
    // l.pop_front();
    l.push_back(8);
    l.push_back(4);
    l.push_back(9);
    l.reverse();
    int s = l.size(); cout<<"Size: "<<s<<endl;
    for(int i: l)
        cout<<i<<" ";
    cout<<endl<<"Sorted: ";
    l.sort();
    // sort(l.begin(), l.end());    --> syntax error
    for(int i: l)
        cout<<i<<" ";
    
    bool isP = binary_search(l.begin(), l.end(), 8);
    isP?cout<<endl<<"8 is present":cout<<endl<<"8 is not present";
    cout<<endl;
}

int gcd(int a, int b)
{
    if(b==0)
        return a;
    else 
        return gcd(b, a%b);
}

int main()
{
    setDemo();
    vectorDemo();
    mapDemo();
    listDemo();
    int a = 24, b = 38;
    int gcd1 = __gcd(a,b);
    int gcd2 = gcd(a,b);
    int lcm = a*b/gcd1;
    cout<<"gcd1: "<<gcd1<<"  gcd2: "<<gcd2<<"\tLCM: "<<lcm;
    return 0;
}
