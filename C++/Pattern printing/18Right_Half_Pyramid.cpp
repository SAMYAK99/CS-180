// //        *
// //      * *
// //    * * *
// //  * * * *
// #include<iostream>
// using namespace std;
// int main()
// {
//     int r;
//     cout << "\nHow many row you want to print: ";
//     cin >> r;
//     for(int i = (r-1); i>=0; i--)
//     {
//         for(int spc=i; spc>0; spc--)
//         {
//             cout << "  ";
//         }
//         for(int j=r; j>i; j--)
//         {
//             cout << " *";
//         }
//         cout << "\n";
//     }
// }
//        *
//      * *
//    * * *
//  * * * *
#include <iostream>
using namespace std;

int main(int argc, char **argv){
    int n;
    cin >> n;
    
    //write your code here
    for(int r=1; r<=n; r++)
    {
        for(int spc=1; spc<=n-r; spc++)
            cout << "     ";

        for(int c=n; c>n-r; c--)
            cout << "    *";
        
        cout << "\n";
    }
}