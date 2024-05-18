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
    void solve(TreeNode* child, TreeNode* parent, int target){
        if(child==NULL) return;
        //leaf nodee
        if(child->left==NULL && child->right==NULL && child->val==target){
            //val = target
            if(parent!=NULL){
                if(parent->left==child){
                    parent->left = NULL;
                }
                else if(parent->right==child){
                    parent->right = NULL;
                }
            }
        }

        parent = child;
        solve(child->left, parent, target);
        solve(child->right, parent, target);
        if(child->left==NULL && child->right==NULL && child->val==target){
            //val = target
            if(parent!=NULL){
                if(parent->left==child){
                    parent->left = NULL;
                }
                else if(parent->right==child){
                    parent->right = NULL;
                }
            }
        }
    }
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        // TreeNode* child = root, *parent= NULL;
        // solve(child, parent, target);
        // return root;
        if(root==NULL) return root;
        // if(root->left==NULL&&root->right==NULL){
        //     if(root->val==target) return NULL;
        //     return root;
        // }
        root->left=removeLeafNodes(root->left,target);
        root->right=removeLeafNodes(root->right,target);
        if(root->left==NULL&&root->right==NULL){
            if(root->val==target) return NULL;
            return root;
        }
        return root;
    }
};