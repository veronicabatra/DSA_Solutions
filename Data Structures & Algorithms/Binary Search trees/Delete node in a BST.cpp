// Intuition
// at first try to just search for that key which needs to be deleted
// and then make 3 case
// case1: when no child is there
// case2: when key has one child
// case3: when it has bth the children

// Approach
// To search for a key in a BST use the property of a BST i.e
// if key is greater than the root then it will be in the right part of the root and if key is less than the root then it will li on the left part of the root and is same as root then u have found the element to be deleted
// Now lets analyse the case
// if there is no child then simply delete it
// if one child is there then just return the child to the root (root ke baad directtly vo child attach hjega)
// most imp case (2 child):
// Here,you have 2 options
// option1: look for the smallest emelent in the right which could take place of the root(all the right elements when places in position of root then left subtree will everytime satisfy BST property but for the right subtree of the key to be deleted , the replacement sgould be of the element which is smallest,then only the right elements will be greater than the root )
// option2: pick the largest element in the left subtree and replace with the root (the element at root now will obviously be smaller than right elements but it should be the greatest of all the elements of left subtree)
// Now,lets say we have gone with option 1 then replace the root val with the replaced value , after that go and repeat the process and now u have to delete the replace root which is there at the leaf level

// Complexity
// Time complexity:Since in a bst searching takes O(logn) and deleting is taking o(1) complexity only so overall tc would be o(logn)
// (in case of skewed trees it would be o(n));
// Space complexity:O(h) (h is the height of the tree)
// Code
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
    TreeNode* fn(TreeNode* root){
        while(root->left!=NULL) root=root->left;
        return root;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root) return NULL;
        if(root->val>key) root->left=deleteNode(root->left,key);
        else if(root->val<key) root->right=deleteNode(root->right,key);
        else{
            if(root->left==NULL && root->right==NULL){
                delete root;
                return NULL;
            }
            else if(root->left==NULL || root->right==NULL){
                return root->left==NULL?root->right:root->left;
            }
            else {
                TreeNode* replace=fn(root->right);
                root->val=replace->val;
                root->right=deleteNode(root->right,replace->val);
            }
        }
        return root;
    }
};