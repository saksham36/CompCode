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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root == NULL) return ans;
        deque<TreeNode*> q;
        q.push_back(root);
        int i = 0;
        int count;
        while(!q.empty()){
            count = q.size();
            // cout<<"Count: "<<count<<endl;
            // cout<<"i: "<<i<<endl;
            vector<int>lvl;
            for(int j = 0; j<count; j++){
                if(i%2){
                    root = q.front();
                    q.pop_front();
                }
                else{
                    root = q.back();
                    q.pop_back();
                }
                // cout<<"Adding: "<<root->val<<endl;
                lvl.push_back(root->val);
                if(i%2){
                    if(root->right !=NULL) q.push_back(root->right);
                    if(root->left !=NULL) q.push_back(root->left);
                }
                else{
                    if(root->left !=NULL) q.push_front(root->left);
                    if(root->right !=NULL) q.push_front(root->right);
                }
            }
            i++;
            ans.push_back(lvl);
        }
        return ans;
    }
};