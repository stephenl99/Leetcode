class TimeMap {
public:
    unordered_map<string, std::set<pair<int, string>>> mapping;
    TimeMap() {
        // unordered_map<string, std::set<pair<int, int>>> mapping;
    }
    
    void set(string key, string value, int timestamp) {
        mapping[key].insert(pair(timestamp, value));
    }
    
    string get(string key, int timestamp) {
        auto& s = mapping[key];
        if (s.empty()) {
            return "";
        }
        auto it = s.upper_bound({timestamp, string(1, CHAR_MAX)});
        if (it == s.begin()) {
            return "";
        }
        return prev(it)->second;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */