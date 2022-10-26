#include<bits/stdc++.h>
using namespace std;

 struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

vector<vector<int>> verticalOrder(TreeNode* root)
{
    map<int,map<int,multiset<int>>> nodes;
    queue<pair<TreeNode* ,pair<int,int>>>q;
    q.push({root,{0,0}});
    while(!q.empty())
    {
       
        auto it=q.front();
        q.pop();
        TreeNode *p=it.first;
        int x=it.second.first;
        int y=it.second.second;
        nodes[x][y].insert(p->val);
        if(p->left) q.push({p->left,{x-1,y+1}});
        if(p->right)q.push({p->right,{x+1,y+1}});

    }
    vector<vector<int>>ans;
    for(auto it:nodes)
    {
        vector<int>col;
        for(auto q1:it.second)
        {
            col.insert(col.end(),q1.second.begin(),q1.second.end());

        }
        ans.push_back(col);
    }
    return ans;
}