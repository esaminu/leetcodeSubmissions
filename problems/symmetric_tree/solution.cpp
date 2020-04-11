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
    bool isSymmetric(TreeNode* root) {
        if(!root) {
            return true;
        }
        queue<TreeNode*> qu;
        qu.push(root);
        
        while(qu.size()) {
            int size = qu.size();
            vector<int> vals;
            for(int i = 0; i < size ; i++) {
                TreeNode* curr = qu.front();
                qu.pop();
                if(curr->left) { 
                    qu.push(curr->left);
                }
                vals.push_back(curr->left ? curr->left->val : -1);
                if(curr->right) { 
                    qu.push(curr->right);
                }
                vals.push_back(curr->right ? curr->right->val : -1);
            }
            for(int i = 0, j = vals.size() - 1; i < j; i++, j--) {
                if(vals[i] != vals[j]) {
                    return false;
                }
            }
        }
        return true;
    }
};