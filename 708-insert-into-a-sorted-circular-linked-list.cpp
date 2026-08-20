/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;

    Node() {}

    Node(int _val) {
        val = _val;
        next = NULL;
    }

    Node(int _val, Node* _next) {
        val = _val;
        next = _next;
    }
};
*/

class Solution {
public:
    Node* insert(Node* head, int insertVal) {
        if (head == nullptr) {
            Node* node = new Node(insertVal);
            node->next = node;
            return node;
        }
        Node* curr = head;
        while (true) {
            if ((curr->next->val < curr->val && (curr->val <= insertVal || curr->next->val >= insertVal)) || 
            curr->val <= insertVal && (curr->next->val >= insertVal) ) {
                Node* newNode = new Node(insertVal, curr->next);
                curr->next = newNode;
                return head;
            }
            curr = curr->next;
            if (curr == head) {
                Node* newNode = new Node(insertVal, curr->next);
                curr->next = newNode;
                return head;
            }
        }
        return head;
    }
};