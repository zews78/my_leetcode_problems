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
bool getPath_to_target(TreeNode* root, TreeNode* p, vector<TreeNode*>& store_path) {
    if (root == nullptr) return false;

    store_path.push_back(root);

    if (root == p) return true;

    if (getPath_to_target(root->left, p, store_path) || getPath_to_target(root->right, p, store_path))
        return true;

    // Backtrack if not found in either subtree
    store_path.pop_back();
    return false;
}

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> path_p, path_q;
        getPath_to_target(root, p, path_p);
        getPath_to_target(root, q, path_q);

        for(int i=0; i<path_p.size(); i++){
            cout<<path_p[i]->val<<" ";
        }cout<<endl;
        for(int i=0; i<path_q.size(); i++){
            cout<<path_q[i]->val<<" ";
        }
        int min_h = min(path_p.size(), path_q.size());
        TreeNode* prevPath;
        for(int i=0; i<min_h; i++){
            if(path_p[i]!=path_q[i]){
                break;
            }
            prevPath = path_p[i];
        }
        return prevPath;

    }
};