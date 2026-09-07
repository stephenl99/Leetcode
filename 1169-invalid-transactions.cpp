struct Order {
    string name;
    int time;
    int amount;
    string city;
    int index;
    Order(string& transaction, int index) {
        std::stringstream ss(transaction);
        vector<string> tokens;
        string temp;
        while (getline(ss, temp, ',')) {
            tokens.push_back(temp);
        }
        name = tokens[0];
        time = stoi(tokens[1]);
        amount = stoi(tokens[2]);
        city = tokens[3];
        this->index = index;
    }
    string to_string() {
        return name + ',' + ::to_string(time) + ',' + ::to_string(amount) + ',' + city;
    }
};

class Solution {
public:
    vector<string> invalidTransactions(vector<string>& transactions) {
        unordered_map<int, Order> orders;
        multimap<int, int> mapping;
        set<int> handled;
        for (int i = 0; i < transactions.size(); i++) {
            string& transaction = transactions[i];
            Order order = Order(transaction, i);
            if (order.amount > 1000) {
                handled.insert(i);
            }
            orders.insert({i, order});
            mapping.insert({order.time, i});
        }
        auto it = next(mapping.begin());
        vector<string> ans;
        for (; it != mapping.end(); it++) {
            auto prev_it = prev(it);
            while (prev_it->first >= it->first - 60) {
                Order prev_order = orders.at(prev_it->second);
                Order curr = orders.at(it->second);
                if (prev_order.name == curr.name && prev_order.city != curr.city) {
                    handled.insert(it->second);
                    handled.insert(prev_it->second);
                }
                if (prev_it == mapping.begin()) {
                    break;
                }
                prev_it = prev(prev_it);
            }
        }
        for (int handle : handled) {
            ans.emplace_back(orders.at(handle).to_string());
        }
        return ans;
    }
};