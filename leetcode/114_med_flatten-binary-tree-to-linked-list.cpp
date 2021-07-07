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
    void flatten(TreeNode* root) {
        if(root == NULL) return;
        if(root->left) flatten(root->left);
        if(root->right) flatten(root->right);
        TreeNode* ptr = root->left, *prev = root;
        while(ptr){
            prev = ptr;
            ptr = ptr->right;    
        }
        
        prev->right = root->right;
        if(root->left){
            root->right = root->left;
            root->left = NULL;
        }
    }
};