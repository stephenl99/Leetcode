using namespace std;
#include <string>
#include <vector>
class Node {
    public:
    Node* children[26];
    bool isEnd;
    Node() {
        for (int i = 0; i < 26; i++) {
            children[i] = nullptr;
        }
        isEnd = false;
    }
};
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<bool> dp(s.length() + 1, false);
        dp[0] = true;
        Node* root = new Node();
        Node* curr = root;
        for (int i = 0; i < wordDict.size(); i++) {
            for (int j = 0; j < wordDict[i].size(); j++) {
                char c = wordDict[i][j];
                if (curr->children[c - 'a'] == nullptr) {
                    Node* newNode = new Node();
                    curr->children[c - 'a'] = newNode;
                }
                curr = curr->children[c - 'a'];
                if (j == wordDict[i].size() - 1) {
                    curr->isEnd = true;
                }
            }
            curr = root;
        }
        Node* node = root;
        for (int i = 0; i < s.size(); i++) {
            node = root;
            if (!dp[i]) {
                continue;
            }
            for (int j = i; j < s.size(); j++) {
                if (node->children[s[j] - 'a'] == nullptr) {
                    break;
                }
                node = node->children[s[j] - 'a'];
                if (node->isEnd) {
                    dp[j + 1] = true;
                }
            }
        }
        return dp[s.size()];
    }
};