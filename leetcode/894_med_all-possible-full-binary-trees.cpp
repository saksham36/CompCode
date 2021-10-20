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
private:
    map <int, vector <TreeNode*>> dp;
public:
    vector<TreeNode*> allPossibleFBT(int n) {
        vector<TreeNode*>results;
        if(n%2){
            if(n==1) results.push_back(new TreeNode(0));
            else if (dp.find(n) != dp.end()) return dp[n];
            else{
                for (int i = 1; i < n; i += 2) {
                    vector <TreeNode*> Left = allPossibleFBT(i);
                    vector <TreeNode*> Right = allPossibleFBT(n - i - 1);
                    for (int j = 0; j < Left.size(); j++) {
                        for (int k = 0; k < Right.size(); k++) {
                            results.push_back(new TreeNode(0, Left[j], Right[k]));
                        }
                    }
                }
            }
        }
        return results;
    }
};