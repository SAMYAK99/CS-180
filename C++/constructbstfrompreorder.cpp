Given an array of integers preorder, which represents the preorder traversal of a BST (i.e., binary search tree), construct the tree and return its root.
Input: preorder = [8,5,1,7,10,12]
Output: [8,5,10,1,7,null,12]
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int i = 0;
      TreeNode* p = solve(preorder , i , INT_MAX);
        return(p);
        
    }
    TreeNode* solve(vector<int>&preorder, int &i , int u)
    {
        if(i == preorder.size()  || preorder[i] > u)
        {
            return(NULL);
        }
        TreeNode* m = new TreeNode(preorder[i++]);
        m->left = solve(preorder, i , m->val);
        m->right = solve(preorder, i , u);
        
        return(m);
    }
};
