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
    int getHeight(TreeNode *root){
        if(root == NULL) return -1;
        return max(getHeight(root->left), getHeight(root->right))+1;
    }
    int isBalanced(TreeNode *root){
        return getHeight(root->left) - getHeight(root->right);
    }
    
    TreeNode* leftRotate(TreeNode* root){
        TreeNode* x = root->right;
        root->right = x->left;
        x->left = getRotation(root);
        return getRotation(x);
    }
    
    TreeNode* rightRotate(TreeNode* root){ // O(1)
       TreeNode* x = root->left;
        root->left = x->right;
        x->right = getRotation(root);
        return getRotation(x);
    }
    
    TreeNode* getRotation(TreeNode *root){
        int bal = isBalanced(root);
        // cout<<"Root: "<<root->val<<" Bal: "<<bal<<endl;
        if(bal >=2){ //Left height  > right height -> LL, LR
            if(isBalanced(root->left) >= 1){ // LL
                // cout<<"LL case: RightRotate("<<root->val<<")"<<endl;
                return rightRotate(root);
            }
            else{ //LR
                // auto tmp = (root->left==NULL)?INT_MAX:root->left->val;
                // cout<<"LR case: leftRotate("<<tmp<<")"<<endl;
                root->left = leftRotate(root->left);
                // cout<<"LR case: RightRotate("<<root->val<<")"<<endl;
                return rightRotate(root);
            }
        }
        else if(bal <= -2){ //RR , RL
            if(isBalanced(root->right) <= -1){ // RR
                // cout<<"RR case: LeftRotate("<<root->val<<")"<<endl;
                return leftRotate(root);
            }
            else{ //RL
                // auto tmp = (root->right==NULL)?INT_MAX:root->right->val; 
                // cout<<"RL case: RightRotate("<<tmp<<")"<<endl;
                root->right = rightRotate(root->right);
                // cout<<"RL case: LeftRotate("<<root->val<<")"<<endl;
                return leftRotate(root);
            }        
        }
        return root;
    }
    
    TreeNode* balanceBST(TreeNode* root) {
        if(root == NULL) return NULL;
        // cout<<"balanceBST("<<root->val<<")"<<endl;
        root->left = balanceBST(root->left);
        // int tmp = (root->left)?root->left->val: INT_MAX;
        // cout<<root->val<<"->left = "<<tmp<<endl;
        root->right = balanceBST(root->right);
        // tmp = (root->right)?root->right->val: INT_MAX;
        // cout<<root->val<<"->right = "<<tmp<<endl;
        return getRotation(root);
        
    }
};

