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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode *node = new TreeNode(val);
        if(root == NULL){
            root = node;
            return root;
        }
        TreeNode* curr = root, *prev= root;
        while(curr){
            prev = curr;
            if(curr->val > val) curr = curr-> left;
            else curr = curr->right;
        }
        
        if(prev->val > val) prev->left = node;
        else prev->right = node;
        return root;
    }
};