
#include <bits/stdc++.h>
using namespace std;

int main()
{
	
	double principle, rate;
	int time;
	cout<<"Input the values of principle, rate and time";
	cin>>principle;
	cin>>rate;
	cin>>time;
	/* Calculate compound interest */
	double A = principle * (pow((1 + rate / 100), time));
	double CI = A- principle;
	cout << "Compound interest is " << CI;
	return 0;
}
