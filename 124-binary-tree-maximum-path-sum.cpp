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
int maxx =  INT_MIN;
    int maxPathSum(TreeNode* root) {
        handle(root);
        return maxx;
    }
    int handle(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        int l = handle(root->left);
        int r = handle(root->right);
        maxx = max(maxx, root->val + l + r);
        maxx = max(maxx, root->val + l);
        maxx = max(maxx, root->val + r);
        maxx = max(maxx, root->val);
        int next = max(l, r);
        next = max(next, 0);
        return next + root->val;
    }
};