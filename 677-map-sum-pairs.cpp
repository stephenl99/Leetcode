
struct TrieNode {
    int val;
    array<shared_ptr<TrieNode>, 26> nexts;
    TrieNode(int val) {
        this->val = val;
    }

};
class MapSum {
public:
    shared_ptr<TrieNode> root = make_shared<TrieNode>(0);
    map<string, int> seen;
    MapSum() {
        
    }
    
    void insert(string key, int val) {
        if (seen.contains(key)) {
            int prev = seen[key];
            seen[key] = val;
            val -= prev;
        } else {
            seen[key] = val;
        }
        auto curr = root;
        for (char c : key) {
            if (curr.get()->nexts[c - 'a'] == nullptr) {
                curr.get()->nexts[c - 'a'] = make_shared<TrieNode>(0);
            }
            curr = curr.get()->nexts[c - 'a'];
            curr.get()->val += val;
        }
    }
    
    int sum(string prefix) {
        auto curr = root;
        for (char c : prefix) {
            curr = curr.get()->nexts[c - 'a'];
            if (curr == nullptr) {
                return 0;
            }
        }
        return curr.get()->val;
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */