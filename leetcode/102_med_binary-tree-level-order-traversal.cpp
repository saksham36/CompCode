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
        vector<int> lvl;
        if(root == NULL) return ans;
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);
        TreeNode* curr;
        
        while(!q.empty()){
            curr = q.front();
            q.pop();
            if(curr == NULL){
                ans.push_back(lvl);
                lvl.clear();
                if(q.empty()) break;
                q.push(NULL);
            }
            else{
                lvl.push_back(curr->val);
                if(curr->left !=NULL) q.push(curr->left);
                if(curr->right !=NULL) q.push(curr->right);
            }
            
        }
        return ans;
    }
};