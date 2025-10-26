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
    string firstPath;
    string secondPath;
    string getDirections(TreeNode* root, int startValue, int endValue) {
        getPathToRoot(root, startValue, firstPath);
        getPathToRoot(root, endValue, secondPath);
        string temp1 = firstPath;
        string temp2 = secondPath;
        while (firstPath.size() != 0 && secondPath.size() != 0 && firstPath[0] == secondPath[0]) {
            firstPath.erase(0, 1);
            secondPath.erase(0, 1);
        }
        if (firstPath.size() == 0) {
            return secondPath;
        } else if (secondPath.size() == 0) {
            return string(firstPath.size(), 'U');
        } else {
            return string(firstPath.size(), 'U') + secondPath;
        }
    }
    bool getPathToRoot(TreeNode* node, int val, string& path) {
        if (node == nullptr) {
            return false;
        }
        if (node->val == val) {
            return true;
        }
        path += "L";
        if (getPathToRoot(node->left, val, path)) {
            return true;
        }
        path.pop_back();
        path += "R";
        if (getPathToRoot(node->right, val, path)) {
            return true;
        }
        path.pop_back();

        return false;
    }
};