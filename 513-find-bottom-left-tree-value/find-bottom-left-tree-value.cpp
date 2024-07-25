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
    void preorder(TreeNode *root, int &ans, int lev, int &maxlev) {
        if(root) {
            if(maxlev<lev) {
                maxlev = lev;
                ans = root->val;
            }
            preorder(root->left, ans, lev+1, maxlev);
            preorder(root->right, ans, lev+1, maxlev);
        }
    }

    int findBottomLeftValue(TreeNode* root) {
        int ans = root->val;
        int lev = 1, maxlev = 0;
        preorder(root, ans, lev, maxlev);
        return ans;
    }
};