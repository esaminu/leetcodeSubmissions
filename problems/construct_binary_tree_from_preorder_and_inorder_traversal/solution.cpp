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
    unordered_map<int, int> map;
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for(int i = 0; i<inorder.size(); i++) {
            map[inorder[i]] = i;
        }
        return helper(preorder, 0, 0, inorder.size() - 1);
    }
    TreeNode* helper(vector<int>& preorder, int preBegin, int inBegin, int inEnd) {
        if(preBegin > preorder.size() - 1 || inBegin > inEnd) {
            return NULL;
        }
        
        int itIndex=map[preorder[preBegin]];
        
        TreeNode* currRoot = new TreeNode(preorder[preBegin]);
        currRoot->left = helper(preorder, preBegin + 1, inBegin, itIndex - 1);
        currRoot->right = helper(preorder, preBegin + 1 + (itIndex - inBegin), itIndex + 1, inEnd);
        
        return currRoot;
        
    }
};