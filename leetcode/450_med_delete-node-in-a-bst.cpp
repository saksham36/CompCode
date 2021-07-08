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
    TreeNode* getSuccessor(TreeNode *root){ // leftmost leaf of right cbild
        root = root->right;
        while(root && root->left)
            root = root->left;
        return root;
    }
    
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == NULL) return root;
        // cout<<"Root Val: "<<root->val<<endl;
        if(root->val > key) root->left = deleteNode(root->left, key);
        else if(root->val < key) root->right = deleteNode(root->right, key);
        else{ // found key
            if(root->left == NULL){
                TreeNode *tmp = root->right;
                delete root;
                return tmp;
            }
            else if(root->right == NULL){
                TreeNode *tmp = root->left;
                delete root;
                return tmp;
            }
            else{
                TreeNode *succ = getSuccessor(root);
                root->val = succ->val;
                root->right = deleteNode(root->right, succ->val);
            }
        }
        return root;
    }
};

