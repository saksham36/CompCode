/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string serial_string = "";
        if(root == NULL) return serial_string;
        queue<TreeNode*>q;
        TreeNode* curr;
        q.push(root);
        while(!q.empty()){
            curr = q.front();
            q.pop();
            if(curr){
                serial_string.append(to_string(curr->val));
                serial_string.append("|");

                q.push(curr->left);
                q.push(curr->right);
            }
            else{
                serial_string.append("null");
                serial_string.append("|");
            }
                
        }
        return serial_string;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.size()==0) return NULL;
        deque<string> ll;
        string val = "";        
        for(char x: data){
            if(x != '|')
                val.push_back(x);
            else{
                ll.push_back(val);
                val.clear();
            }
        }
        queue<TreeNode*> q;
        TreeNode* root = new TreeNode(stoi(ll[0]));
        ll.pop_front();
        q.push(root);
        TreeNode*curr;
        bool left = true;
        while(!q.empty()){
            curr = q.front();
            val = ll[0];
            ll.pop_front();
            if(val == "null"){
                if(left)
                    curr->left = NULL;
                else{
                    curr->right = NULL;
                    q.pop();
                }
            }
            else{
                TreeNode* node = new TreeNode(stoi(val));
                q.push(node);
                if(left)
                    curr->left = node;
                else{
                    curr->right = node;
                    q.pop();
                }
            }
            left = !left;
            
                
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));