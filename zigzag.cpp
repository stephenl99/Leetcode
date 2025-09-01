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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if (root == nullptr) {
            return {};
        }
        vector<vector<int>> answer;
        deque<TreeNode*> dq;
        int level = 0;
        dq.push_back(root);
        while (!dq.empty()) {
            int num = dq.size();
            vector<int> layer;
            if (level % 2 == 0) {
                for (int i = 0; i < num; i++) {
                    TreeNode* node = dq.back();
                    dq.pop_back();
                    layer.push_back(node->val);
                    if (node->left != nullptr) {
                        dq.push_front(node->left);
                    }
                    if (node->right != nullptr) {
                        dq.push_front(node->right);
                    }
                }
            } else {
                for (int i = 0; i < num; i++) {
                    TreeNode* node = dq.front();
                    dq.pop_front();
                    layer.push_back(node->val);
                    if (node->right != nullptr) {
                        dq.push_back(node->right);
                    }
                    if (node->left != nullptr) {
                        dq.push_back(node->left);
                    }
                }
            }
            level++;
            answer.push_back(layer);
        }
        return answer;
    }
};