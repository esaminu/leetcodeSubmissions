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
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        TreeNode* ptr = root, *lastLeft = NULL;
        while(ptr) {
            if(ptr->val > p->val) {
                lastLeft = ptr;
                ptr = ptr->left;
            } else {
                ptr = ptr->right;
            }
        }
        return lastLeft;
    }
};