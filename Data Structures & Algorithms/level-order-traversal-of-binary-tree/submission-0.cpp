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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(!root) return ans;
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);
        int i=0;
        while(!q.empty()){
            TreeNode* curr=q.front();
            q.pop();
            if(curr!=NULL){
                if(ans.size()<=i) ans.resize(i+1);
                ans[i].push_back(curr->val);
                if(curr->left!=NULL) q.push(curr->left);
                if(curr->right!=NULL) q.push(curr->right);
            }
            else{
                if(!q.empty()) {
                    i++;
                    q.push(NULL);
                }
            }
        }
        return ans;
    }
};
