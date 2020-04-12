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
    vector<int> inorderTraversal(TreeNode* root) {
        TreeNode* curr = root;
        vector<int> arr;
        
        while(curr) {
            if(!curr->left) {
              arr.push_back(curr->val); 
              curr = curr->right;
            } else {
                TreeNode* p = curr->left;
                while(p->right && p->right != curr) {
                    p = p->right;
                }
                if(!p->right) {
                    p->right=curr;
                    curr=curr->left;
                } else {
                    p->right=NULL;
                    arr.push_back(curr->val);
                    curr=curr->right;
                }
            }
        }
        return arr;
    }
};