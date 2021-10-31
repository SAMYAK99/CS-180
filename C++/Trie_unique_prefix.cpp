// SEARCHING AND MATCHING IN EFFICIENT WAY
#include<bits/stdc++.h>
using namespace std;
struct trie 
{
  struct trie *children[500];
  int frequancy =0;
};
// craete a null node
struct trie *create()
{
  struct trie * newnode =new trie;
     newnode->frequancy=1;
   for(int i=0;i<500;i++)
   {
     newnode->children[i]=NULL;
   }

   return newnode;
}
// now insert it into trie
void insert(struct trie *root, string key)
{
  struct trie *temp = root;
  for(int i=0;i<key.size();i++)
  {
    int index =key[i];
    // if the letter of the word is not present
    if(!temp->children[index])
    {
      // create a newnode 
       temp->children[index]=create();
    }
    // if it is already present than increase the frequnacy count of it
    else 
      (temp->children[index]->frequancy)++;
    temp =temp->children[index];
  }
}
// now perform query search operation
void prefix_helper(struct trie *root, char prefix[],int ind)
{
  // corner case
  if(root==NULL)
  {
     return;
  }
  // base case
  if(root->frequancy==1)
  {
    prefix[ind] ='\0';
    cout<<prefix<<" ";
    return;
  }
  for(int i=0;i<500;i++)
  {
    if(root->children[i]!=NULL)
    {
      prefix[ind]=i;
      prefix_helper(root->children[i],prefix,ind+1);
    }
  }
}
int main()
{
  int n;
  cin>>n;
  vector<string> s;
  for(int i=0;i<n;i++)
  {
    string c;
    cin>>c;
    s.push_back(c);
  }
  struct trie *root = create();
  root->frequancy=0;
  for(int i=0;i<n;i++)
  {
    insert(root,s[i]);
  }
  char prefix[500];
  prefix_helper(root,prefix,0);

 

  return 0;
}
/*OUTPUT
4
dog
duck
zebra
were
do du w z 
*/