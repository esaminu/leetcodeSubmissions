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
    int *lastVal = nullptr;
public:
    bool isValidBST(TreeNode* root) {
        return InorderCheck(root);
    }
    bool InorderCheck(TreeNode* node) {
        if(node == nullptr) return true;
        if(InorderCheck(node->left) && (lastVal == nullptr || node->val > *lastVal)) {
            lastVal = &node->val;
            return InorderCheck(node->right);
        }
        return false;
    }
};