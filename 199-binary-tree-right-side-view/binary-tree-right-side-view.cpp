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
    void rightView(TreeNode *root, vector<int> &ans, int &level, int maxLevel) {
        if(!root) return;
        if(maxLevel > level) {
            ans.push_back(root->val);
            level = maxLevel;
        }
        rightView(root->right, ans, level, maxLevel+1);
        rightView(root->left, ans, level, maxLevel+1);
    }

    vector<int> rightSideView(TreeNode* root) {
        int level = 0, maxLevel = 1;
        vector<int> ans;
        rightView(root, ans, level, maxLevel);
        return ans;
    }
};