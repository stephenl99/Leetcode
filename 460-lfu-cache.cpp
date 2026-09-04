class LFUCache {
public:
    unordered_map<int, list<pair<int, int>>> freqs;
    unordered_map<int, pair<int, list<pair<int, int>>::iterator>> mapping;
    int min_level = 1;
    int size = 0;
    int capacity;

    void insert(int key, int val, int level) {
        freqs[level].push_front(pair(key, val));
        mapping[key] = pair(level, freqs[level].begin());
    }
    void remove(int key) {
        auto it = mapping[key];
        freqs[it.first].erase(it.second);
        mapping.erase(key);
    }
    void increment(int key, int value) {
        int level = mapping[key].first + 1;
        remove(key);
        insert(key, value, level);
        if (min_level == level - 1 && freqs[level - 1].size() == 0) {
            min_level++;
        }
    }
    LFUCache(int capacity) {
        this->capacity = capacity;
    }
    
    int get(int key) {
        if (!mapping.contains(key)) {
            return -1;
        }
        increment(key, mapping[key].second->second);
        return mapping[key].second->second;
    }
    
    void put(int key, int value) {
        if (mapping.contains(key)) {
            increment(key, value);
            return;
        }
        if (size == capacity) {
            remove(freqs[min_level].back().first);
            size--;
        }
        insert(key, value, 1);
        size++;
        min_level = 1;
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */