class Solution {
public:
    int getNumberOfBacklogOrders(vector<vector<int>>& orders) {
        priority_queue<pair<int, int>> buy;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> sell;
        for (vector<int> order : orders) {
            if (order[2] == 0) {
                buy.push(pair(order[0], order[1]));
            } else {
                sell.push(pair(order[0], order[1]));
            }
            while (!buy.empty() && !sell.empty() && buy.top().first >= sell.top().first) {
                int diff = buy.top().second - sell.top().second;
                if (diff == 0) {
                    buy.pop();
                    sell.pop();
                } else if (diff > 0) {
                    pair<int, int> temp = pair(buy.top().first, buy.top().second);
                    buy.pop();
                    buy.push(pair(temp.first, temp.second - sell.top().second));
                    sell.pop();
                } else {
                    pair<int, int> temp = sell.top();
                    sell.pop();
                    sell.push(pair(temp.first, temp.second - buy.top().second));
                    buy.pop();
                }
            }
        }
        int count = 0;
        long long mod = 1e9 + 7;
        while (!buy.empty()) {
            count += buy.top().second;
            count %= mod;
            buy.pop();
        }
        while (!sell.empty()) {
            count += sell.top().second;
            count %= mod;
            sell.pop();
        }
        return count;
    }
};