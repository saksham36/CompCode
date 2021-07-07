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
    int recursive(TreeNode *root, int depth){
        if(root == NULL)
            return depth;
        return max(recursive(root->left, depth+1), recursive(root->right, depth+1));
        
    }
    int maxDepth(TreeNode* root) {
        int res = 0;
        return recursive(root, 0);
    }
};