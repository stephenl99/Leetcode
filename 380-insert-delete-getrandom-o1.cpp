class RandomizedSet {
public:
    unordered_map<int, int> mapping;
    vector<int> list;
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if (mapping.contains(val)) {
            return false;
        }
        list.push_back(val);
        mapping[val] = list.size() - 1;
        return true;
    }
    
    bool remove(int val) {
        if (mapping.contains(val)) {
            int index = mapping[val];
            list[index] = list[list.size() - 1];
            mapping[list[index]] = index;
            list.pop_back();
            mapping.erase(val);
            return true;
        }
        return false;
    }
    
    int getRandom() {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<int> distrib(0, list.size() - 1);
        return list[distrib(gen)];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */