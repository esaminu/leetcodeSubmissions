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
    bool isBalanced(TreeNode* root) {
        return height(root)[1];
    }
    
    vector<int> height(TreeNode* root) {
        if(root != NULL) {
            vector<int> x = height(root->left);
            vector<int> y = {0, false};
            if(x[1]) {
             y = height(root->right);   
            }
            return {x[0] > y[0] ? x[0] + 1 : y[0] + 1, abs(x[0] - y[0]) <= 1 && x[1] && y[1]} ;
        } else {
            return {0, true};
        }
    }
};