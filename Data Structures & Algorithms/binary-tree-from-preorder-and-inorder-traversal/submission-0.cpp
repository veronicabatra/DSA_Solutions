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
int idx=0;
    int search(vector<int> inorder,int val,int left,int right){
        for(int i=left;i<=right;i++){
            if(inorder[i]==val) return i;
        }
        return -1;
    }
    TreeNode* fn(vector<int> preorder,vector<int> inorder,int left,int right){
        if(left>right) return NULL;
        TreeNode* root=new TreeNode(preorder[idx]);
        idx++;
        int i=search(inorder,root->val,left,right);
        root->left=fn(preorder,inorder,left,i-1);
        root->right=fn(preorder,inorder,i+1,right);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return fn(preorder,inorder,0,inorder.size()-1);
    }
};
