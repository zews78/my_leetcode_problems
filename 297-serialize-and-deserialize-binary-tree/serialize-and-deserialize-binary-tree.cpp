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
        string output ="";
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            TreeNode* front = q.front();
            q.pop();

            if(front){
                output+=to_string(front->val);
                q.push(front->left);
                q.push(front->right);
            }else{
                output+="N";
            }
            output+=",";
        }
        // cout<<output<<endl;
        return output;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.size()==0 || data[0]=='N') return nullptr;


        queue<TreeNode*> q;

        int i = 0;
        int j = 0;

        // Find the first comma
        while(data[j] != ',') j++;
        TreeNode* node = new TreeNode(stoi(data.substr(i, j - i)));
        q.push(node);
        i = j + 1;

        while(i<data.size() && !q.empty()){
            TreeNode* front = q.front();
            q.pop();
            
            // Left
            j = i;
            while(data[j] != ',') j++;
            string leftVal = data.substr(i, j - i);
            i = j + 1;

            if(leftVal == "N") {
                front->left = nullptr;
            } else {
                TreeNode* leftNode = new TreeNode(stoi(leftVal));
                front->left = leftNode;
                q.push(leftNode);
            }

            // Right
            j = i;
            while(j < data.size() && data[j] != ',') j++;
            string rightVal = data.substr(i, j - i);
            i = j + 1;

            if(rightVal == "N") {
                front->right = nullptr;
            } else {
                TreeNode* rightNode = new TreeNode(stoi(rightVal));
                front->right = rightNode;
                q.push(rightNode);
            }
        }
        return node;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));