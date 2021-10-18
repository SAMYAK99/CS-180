#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <queue>
#include <deque>
#include <bitset>
#include <iterator>
#include <list>
#include <stack>
#include <map>
#include <set>
#include <functional>
#include <numeric>
#include <utility>
#include <limits>
#include <time.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
using namespace std;
#define ll long long
#define mod 1000000007LL
#define pb push_back
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#define v(x,a,n) vector<x>a(n)
#define all(v) v.begin(),v.end()
#define dbg(x) cout<<#x<<"=="<<x<<"\n"
#define inf 1LL<<60
int main() {

	   int t;
	   cin>>t;
	   while(t--)
	   {

	  string s;
	  cin>>s;
	  int k;
	  cin>>k;
	  k%=26;
	  for(int i=0;i<s.length();i++)
	  {
	  	if((s[i]-k)<97)
	  	{
	  		int kk=(s[i]-('a'))?(s[i]-'a'+1):1;
	  		s[i]='z'-(k-kk);
	  	}
	  	else{
          s[i]-=k;
	  	}

	  }
	  cout<<s<<"\n";
	}
	return 0;
}
