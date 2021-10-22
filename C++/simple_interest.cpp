#include<iostream>
using namespace std;
class account
{
    private: int principle,rate,No_years;
    float s_interest;
    public:
        void getdata()
        {
            cout<<"enter the principle , rate of interest , no of years";
            cin>>principle>>rate>>No_years;
        }
        void calculate()
        {
            s_interest=(principle*rate*No_years)/100;
        }
        void putdata()
        {
            cout<<"simple interest is "<<s_interest;
        }
};
int main()
{
    account s;
    s.getdata();
    s.calculate();
    s.putdata();
    return 0;
}
