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
        if(root == NULL) return {};
        vector<int> trav = inorderTraversal(root->left);
        trav.push_back(root->val);
        vector<int> travR = inorderTraversal(root->right);
        trav.insert(trav.end(),travR.begin(), travR.end());
        return trav;
    }
};