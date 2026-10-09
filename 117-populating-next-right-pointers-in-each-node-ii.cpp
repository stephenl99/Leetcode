/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if (!root) {
            return nullptr;
        }
        Node* next = nullptr;
        Node* other = root->next;
        while (other != NULL && !other->left && !other->right) {
            other = other->next;
        }
        if (other) {
            if (other->left) {
                next = other->left;
            } else if (other->right) {
                next = other->right;
            }
        }
        if (root->right) {
            root->right->next = next;
        }
        if (root->left) {
            if (root->right) {
                root->left->next = root->right;
            } else {
                root->left->next = next;
            }
        }
        connect(root->right);
        connect(root->left);
        return root;
    }
};