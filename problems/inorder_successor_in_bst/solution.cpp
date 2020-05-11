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
        stack<TreeNode*> inorder;
        TreeNode* ptr = root, *lastVisited;
        
        while(ptr != NULL || inorder.size()) {
            if(ptr != NULL) {
                inorder.push(ptr);
                ptr = ptr->left;
            } else {
                ptr = inorder.top();
                inorder.pop();
                if(lastVisited == p) return ptr;
                lastVisited = ptr;
                ptr = ptr->right;
            }
        }
        return NULL;
        
    }
};