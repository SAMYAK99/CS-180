#include<iostream>
#include<math.h>
#include<string.h>
using namespace std;
class Convert
{
private:
    int octo, octi, i, j, n, temp, orem, odeci, odeco;
    long int hdeci=0, hrem, val, len;
    char hexi[10], hexo[100];
public:
    void DecimalToOct()
    {
        i=1, octo=0;
        cout<<"\nEnter a Decimal Number: ";
        cin>>odeci;
        while(odeci!=0)
        {
            orem=odeci%8;
            odeci=odeci/8;
            octo=octo+(orem*i);
            i=i*10;
        }
        cout<<"\nOctal Equivalent is "<<octo;
    }
    void DecimalToHex()
    {
        i=0;
        cout<<"\nEnter a decimal number: ";
        cin>>n;
        while(n!=0)
        {
            temp=0;
            temp=n%16;
            if(temp<10)
            {
                hexo[i]=temp + 48;
                i++;
            }
            else
            {
                hexo[i]=temp + 55;
                i++;
            }
            n=n/16;
        }
        cout<<"\nHexadecimal Equivalent is: ";
        for(j=i-1; j>=0; j--)
        {
            cout<<hexo[j];
        }
    }
    void OctToDecimal()
    {
        odeco=0, i=0;
        cout<<"\nEnter a Octal Number: ";
        cin>>octi;
        while(octi!=0)
        {
            orem=octi%10;
            octi=octi/10;
            odeco = odeco+(orem*pow(8,i));
            ++i;
        }
        cout<<"\nDecimal Equivalent is "<<odeco;
    }
    void HexToDecimal()
    {
        cout<<"\nEnter a Hexadecimal String: ";
        cin>>hexi;
        strrev(hexi);
        len = strlen(hexi);
        for(i=0; i<len; i++)
        {
            switch(hexi[i])
            {
            case '0':
                val=0;
                break;
            case '1':
                val=1;
                break;
            case '2':
                val=2;
                break;
            case '3':
                val=3;
                break;
            case '4':
                val=4;
                break;
            case '5':
                val=5;
                break;
            case '6':
                val=6;
                break;
            case '7':
                val=7;
                break;
            case '8':
                val=8;
                break;
            case '9':
                val=9;
                break;
            case 'a':
            case 'A':
                val=10;
                break;
            case 'b':
            case 'B':
                val=11;
                break;
            case 'c':
            case 'C':
                val=12;
                break;
            case 'd':
            case 'D':
                val=13;
                break;
            case 'e':
            case 'E':
                val=14;
                break;
            case 'f':
            case 'F':
                val=15;
                break;
            }
            hrem=val;
            hdeci=hdeci+(hrem*pow(16,i));
        }
        cout<<"\nDecimal Equivalent is: "<<hdeci;
    }
    void execute()
    {
        int d;
        cout<<"\nWelcome to the Decimal-Hexadecimal-Octal Converter!";
        do
        {
            cout<<"\n\nPlease choose which conversion you would like to perform: ";
            cout<<"\n1 Decimal to Octal\n2 Octal to Decimal\n3 Decimal to Hexadecimal\n4 Hexadecimal to Decimal\n5 Exit\n";
            cin>>d;
            switch(d)
            {
            case 1:
                DecimalToOct();
                break;
            case 2:
                OctToDecimal();
                break;
            case 3:
                DecimalToHex();
                break;
            case 4:
                HexToDecimal();
                break;
            case 5:
                cout<<"\nIt was nice to have you! Have a nice time ahead!";
                break;
            default:
                cout<<"\nInvalid input! Try again!";
                break;
            }
        }while(d!=5);
    }
};
int main()
{
    Convert a;
    a.execute();
    return 0;
}