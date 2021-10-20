/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        if(root == NULL) return {};
        unordered_map<TreeNode*, TreeNode*>parent_map;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            auto front = q.front();
            q.pop();
            if(front->left){
                q.push(front->left);
                
                //Map left child with parent
                parent_map[front->left] = front;
            }
            if(front->right){
                q.push(front->right);
                
                //Map right child with parent
                parent_map[front->right] = front;
            }
        }
        unordered_map<TreeNode*, bool> seen;
        q.push(target);
        seen[target] = true;
        int curLevel = 0;
        
        int n;
        while(!q.empty()){
            n= q.size();
            if(curLevel == k) break;
            curLevel++;
            for(int i=0; i<n; i++){
                auto node = q.front();
                q.pop();
                
                //Travel to the left if not already visited (by 1 distance)
                if(node -> left && !seen[node->left]){
                    q.push(node->left);
                    seen[node->left] = true;
                }
                //Travel to the right if not already visited (by 1 distance)
                if(node-> right && !seen[node->right]){
                    q.push(node->right);
                    seen[node->right] = true;
                }
                
                //Travel parent node if not already visited (by 1 distance)
                if(parent_map[node] && !seen[parent_map[node]]){
                    q.push(parent_map[node]);
                    seen[parent_map[node]] = true;
                }
            }
        }
        vector<int> res;
        while(!q.empty()){
            auto node = q.front();
            q.pop();
            res.push_back(node->val);
        }
        return res;
    }
};