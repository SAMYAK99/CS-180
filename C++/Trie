#include<bits/stdc++.h>
using namespace std;
struct trie
{
	char data;
	int end;
	struct trie* child[26];
};
struct trie* root = nullptr;
struct trie* init()
{
    //struct trie* f = nullptr;
    root = new trie();
	root->data = '\0';
	root->end = 0;
	for(int i = 0; i < 26; i++)
	root->child[i] = nullptr;
	//return f;
}
void insert(trie* temp, string s)
{
	for(int i = 0; i < s.length(); i++)
	{
		int p = s[i] - 'a';
		if(temp->child[p] == NULL)
		{
			temp->child[p] = new trie();
			temp->child[p]->data = s[i];
			temp->child[p]->end = 0;
			for(int i = 0; i < 26; i++)
			temp->child[p]->child[i] = NULL; 
		}
		temp = temp->child[p];
	}
	temp->end = 1;
}
bool search(trie* temp, string s)
{
	for(int i = 0; i < s.length(); i++)
	{
		int p = s[i] - 'a';
		if(temp->child[p] == NULL)
		return false;
		temp = temp->child[p];
		
	}
	return(temp != NULL && temp->end == 1);
}
int main()
{
	init();
	int n;
	cin>>n;
	string arr[n];
	for(int i = 0; i < n; i++)
	cin>>arr[i];
	for(int i = 0; i < n; i++)
	insert(root, arr[i]);
	string m;
	cin>>m;
	if(search(root, m))
	cout<<"true";
	else
	cout<<"false";
}
