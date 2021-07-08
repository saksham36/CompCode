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
    void vTraverse(TreeNode *root, int col, int row,  map<int,vector<pair<int,int>>> &mp){
        if(root == NULL) return;
        mp[col].push_back({row, root->val});
        vTraverse(root->left, col-1, row+1, mp);
        vTraverse(root->right, col+1, row+1, mp);
        
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int,vector<pair<int,int>>> mp; // key: column, pair: row, value
        vTraverse(root, 0, 0, mp);
        vector<vector<int>> ans;
        for(auto it: mp){ //iterate over all column entries
            map<int,multiset<int>>row_map; //key: row, val
            for(auto x: it.second) // in each column entry, iterate over all elements
                row_map[x.first].insert(x.second); 
            vector<int>v;
            for(auto x: row_map)
                for(auto y: x.second)
                    v.push_back(y);
            ans.push_back(v);
        }
        return ans;
    }
};