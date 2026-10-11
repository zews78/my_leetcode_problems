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
    void mapParent(TreeNode* root, unordered_map<TreeNode*, TreeNode*> &parent){
        if(!root){
            return;
        }
        if(root->left){
            parent[root->left] = root;
            mapParent(root->left, parent);
        }
        if(root->right){
            parent[root->right] = root;
            mapParent(root->right, parent);
        }
        
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, TreeNode*> parent;

        mapParent(root, parent);

        unordered_map<TreeNode*, bool> visited;
        vector<int> res;

        queue<TreeNode*> q;

        q.push(target);
        int level =0;

        while(!q.empty()){
            if(level==k){
                break;
            }
            int size=q.size();

            for(int i=0; i<size; i++){
                auto front = q.front();
                q.pop();
                visited[front] =true;

                if( front->left && !visited[front->left]){
                    q.push(front->left);
                }
                if(front->right && !visited[front->right]){
                    q.push(front->right);
                }
                if(parent.count(front) && !visited[parent[front]]){
                    q.push(parent[front]);
                }
            }
            level++;
            
        }

        
        while(!q.empty()){
            res.push_back(q.front()->val);
            q.pop();
        }

        return res;

    }
};