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
    int mx=INT_MIN;
    int fn(TreeNode* root){
        if(root==NULL) return 0;
        int left=fn(root->left);
        int right=fn(root->right);
        left=max(0,left);
        right=max(0,right);
        mx=max(mx,left+right+root->val);
        return root->val+max(left,right);
    }
    int maxPathSum(TreeNode* root) {
        fn(root);
        return mx;
    }
};
