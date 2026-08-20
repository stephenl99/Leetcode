struct TrieNode {
    TrieNode* trieNodes[26]{};
    priority_queue<string> pq;
    void add(string s) {
        pq.push(s);
        while (pq.size() > 3) {
            pq.pop();
        }
    }
};
class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        vector<vector<string>> ans(searchWord.size());
        TrieNode* head = new TrieNode();
        TrieNode* curr;
        for (string& product : products) {
            curr = head;
            for (int i = 0; i < product.size(); i++) {
                if (curr->trieNodes[product[i] - 'a'] == nullptr) {
                    curr->trieNodes[product[i] - 'a'] = new TrieNode();
                }
                curr = curr->trieNodes[product[i] - 'a'];
                curr->add(product);
            }
        }
        curr = head;
        for (int i = 0; i < searchWord.size(); i++) {
            if (curr == nullptr) {
                break;
            }
            curr = curr->trieNodes[searchWord[i] - 'a'];
            if (curr == nullptr) {
                break;
            }
            while (!curr->pq.empty()) {
                ans[i].push_back(curr->pq.top());
                curr->pq.pop();
            }
            sort(ans[i].begin(), ans[i].end());
            if (i > 0 && ans[i].size() == 0) {
                ans[i] = ans[i - 1];
            }
        }
        return ans;
    }
};