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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        if(root == NULL) return ans;
        deque<TreeNode*> q;
        q.push_back(root);
        ans.push_back(root->val);
        q.push_back(NULL);
        TreeNode* curr;
        
        while(!q.empty()){
            curr = q.front();
            q.pop_front();
            if(curr == NULL){
                if(q.back() == NULL)
                    break;
                ans.push_back(q.back()->val);
                if(q.empty()) break;
                q.push_back(NULL);
            }
            else{
                if(curr->left !=NULL) q.push_back(curr->left);
                if(curr->right !=NULL) q.push_back(curr->right);
            }
            
        }
        return ans;
    }
};