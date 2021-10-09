// Problem Link: https://practice.geeksforgeeks.org/problems/top-view-of-binary-tree/1

// Time Complexity: O(N)
// Space Complexity: O(N)

//-----------------------------------Main Code Starts-------------------------------------------//

/*
struct Node
{
    int data;
    Node* left;
    Node* right;
};
*/
class Solution
{
    public:
    //Function to return a list of nodes visible from the top view 
    //from left to right in Binary Tree.
    vector<int> topView(Node *root)
    {
        //Your code here
        
        vector<int> ans;
        
        queue<pair<Node*, int>> q;
        q.push({root, 0});
        
        map<int, int> m;
        
        while(!q.empty())
        {
            int n = (int)q.size();
            for(int i = 0; i < n; i++)
            {
                Node* node = q.front().first;
                int x = q.front().second;
                
                if(m.find(x) == m.end())
                    m[x] = node -> data;
                
                q.pop();
                
                if(node -> left)
                    q.push({node -> left, x - 1});
                if(node -> right)
                    q.push({node -> right, x + 1});
                
            }
                
        }
        
        for(auto i : m)
        {
            ans.push_back(i.second);
        }
        
        return ans;
        
    }

};
