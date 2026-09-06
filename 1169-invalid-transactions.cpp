struct Order {
    string name;
    int time;
    int amount;
    string city;
    int index;
    Order(string& transaction, int index) {
        stringstream ss(transaction);
        vector<string> tokens;
        string item;
        while(getline(ss, item, ',')) {
            tokens.push_back(item);
        }
        name = tokens[0];
        time = stoi(tokens[1]);
        amount = stoi(tokens[2]);
        city = tokens[3];
        this->index = index;
    }
    bool operator<(Order& other) {
        return this->time < other.time;
    }
    bool operator==(const Order& other) const {
        return this->name == other.name && this->city == other.city && this->time == other.time && this->amount == other.amount && this->index == other.index;
    }
    string to_string() {
        return this->name + ',' + std::to_string(this->time) + ',' + std::to_string(this->amount) + ',' + this->city;
    }
};
namespace std {
    template <>
    struct hash<Order> {
        size_t operator()(const Order& p) const noexcept {
            size_t h1 = hash<int>{}(p.amount);
            size_t h2 = hash<string>{}(p.name);
            return h1 ^ (h2 << 1); 
        }
    };
}

class Solution {
public:
    vector<string> invalidTransactions(vector<string>& transactions) {
        vector<string> ans;
        unordered_set<Order> handled;
        vector<Order> orders;
        for (int i = 0; i < transactions.size(); i++) {
            string& transaction = transactions[i];
            Order order = Order(transaction, i);
            if (order.amount > 1000) {
                handled.insert(order);
            }
            orders.push_back(order);
        }
        sort(orders.begin(), orders.end());
        for (int i = 1; i < orders.size(); i++) {
            int index = i - 1;
            while (index >= 0 && orders[index].time >= orders[i].time - 60) {
                if (orders[index].city != orders[i].city && orders[index].name == orders[i].name) {
                    handled.insert(orders[i]);
                    handled.insert(orders[index]);
                }
                index--;
            }
        }
        for (Order order : handled) {
            ans.emplace_back(order.to_string());
        }
        return ans;
    }
};