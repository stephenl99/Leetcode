using namespace std;
#include <string>
#include <vector>
#include <unordered_map>
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
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        Node* root = new Node();
        for (string word : wordDict) {
            Node* curr = root;
            for (int i = 0; i < word.size(); i++) {
                if (curr->children[word[i] - 'a'] == nullptr) {
                    curr->children[word[i] - 'a'] = new Node();
                }
                if (i == word.size() - 1) {
                    curr->isEnd = true;
                }
                curr = curr->children[word[i] - 'a'];
            }
        }
        unordered_map<int, vector<string>> map;
        vector<string> temp(1, "");
        map[-1] = temp;
        for (int i = 0; i < s.size(); i++) {
            if (map.count(i - 1) == 0) {
                continue;
            }
            Node* curr = root;
            vector<string> words = map[i - 1];
            string suffix = "";
            for (int j = i; j < s.size(); j++) {
                if (curr->children[s[j] - 'a'] == nullptr) {
                    break;
                }
                suffix += s[j];
                if (curr->isEnd) {
                    vector<string> tempWords = words;
                    for (int k = 0; k < words.size(); k++) {
                        if (j == s.size() - 1) {
                            tempWords[k] += suffix;
                        } else {
                            tempWords[k] += suffix + " ";
                        }
                    }
                    map[j].insert(map[j].end(), tempWords.begin(), tempWords.end());
                }
                curr = curr->children[s[j] - 'a'];
            }
        }
        return map[s.size() - 1];
    }
};