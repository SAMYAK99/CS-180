#include<conio.h>
#include<iostream>
#include<string.h>


using namespace std;


struct book
{
   private:
    int bookid;
    char title[20];
    float price;

   public:
    void input()
    {
        cout<<"Enter bookid, title and price";
        cin>>bookid>>title>>price;
        if(bookid<0)
            bookid=-bookid;
    }
    void display()
    {
        cout<<"\n"<<bookid<<" "<<title<<" "<<price;
    }
};
void display(book);
int main()
{
    book b1;
    b1.input();
    b1.display();
    return 0;
}
