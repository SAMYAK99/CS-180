#include<iostream>
using namespace std;
class sessional{
   char name[20];
   public:
   	int roll=50;
   	void get(){
   		cout<<"enter roll";
   		cin>>roll;
   		cout<<"enter name";
   		cin>>name;
   		cout<<"enter marks";
		   cin>>marks;
		   cout<<"roll="<<roll<<endl<<"name: "<<name<<endl<<"marks="<<marks<<endl;
	   }
	   void dis(){
	   }
	   protected:
	   	 float marks=435;
		};
		class sem:private sessional{
			public:
				void get1(){
					cout<<"final result is "<<marks;
				}
		};
int main(){
     sem s;
   cout<<s.roll;
 s.get1();
	return 0;
}
