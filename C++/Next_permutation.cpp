//Author : Sundar


/*Problem : Find the next permutation of the given sequence.

        Sample Input : 1 3 2 4 4
        Next Permutation: 1 3 4 2 4
*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
void CreatePermutation(vector<int> &v)
{
    int n = v.size();
    for (int i = n - 2; i >= 0; i--)
    {
        //Finding the first number which is lesser than the next number 
        //So that we could change the number at that index to make the next permutation
        if (v[i] < v[i + 1])
        {
            //Finding the number that is just greater than the previously located number
            //So that it could replace the original number
            int j = n - 1;
            while (v[j] <= v[i])
            {
                j--;
            }
            swap(v[i], v[j]);
            i += 1;
            
            //Reversing the sequence so that it gets arranged in sorted manner
            for (int k = i; k < (n + i) / 2; k++)
            {
                swap(v[k],v[n-(k-i)-1]);
            }

            return;
        }
    }
    //If the current permutation is the last permutation like 3 2 1
    //Then it should be turned into 1 2 3
    reverse(v.begin(), v.end());
}

int main()
{
    int size;
    cin >> size;
    vector<int> perm(size); //input for permutation
    for (int i = 0; i < size; i++)
    {
        cin >> perm[i];
    }
    CreatePermutation(perm); //pass by reference

    cout << "The next Permutation is ";
    for (int it : perm)
    {
        cout << it << " ";
    }
    return 0;
}