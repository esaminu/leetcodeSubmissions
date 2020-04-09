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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root == NULL) {
            return {};
        } 
        deque<TreeNode*> qu;
        vector<vector<int>> arr = {{root->val}};
        
        qu.push_back(root);
        
        while(qu.size()) {
            vector<int> currLevel;
            int levelSize = qu.size();
            for(int i = 0; i < levelSize; i++) {
                if(qu.front()->left) {  
                    qu.push_back(qu.front()->left);
                    currLevel.push_back(qu.front()->left->val);
                }
                if(qu.front()->right) {
                    qu.push_back(qu.front()->right);
                    currLevel.push_back(qu.front()->right->val);
                }
                qu.pop_front();
            }
            if(currLevel.size()) {
                arr.push_back(currLevel); 
            }
        }
        return arr;
    }
};