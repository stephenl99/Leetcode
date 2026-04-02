class Solution {
struct CompareSecond {
    bool operator()(const tuple<int, int, int>& a, const tuple<int, int, int>& b) {
        return std::get<2>(a) <= std::get<2>(b); 
    }
};
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        int n = costs.size() / 2;
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, CompareSecond> pq;
        for (int i = 0; i < costs.size(); i++) {
            if (costs[i][1] > costs[i][0]) {
                pq.push(tuple(i, 0, costs[i][1] - costs[i][0]));
            } else {
                pq.push(tuple(i, 1, costs[i][0] - costs[i][1]));
            }
        }
        int cost = 0;
        int count0 = 0;
        int count1 = 0;
        while (!pq.empty()) {
            tuple<int, int, int> t = pq.top();
            pq.pop();
            if ((get<1>(t) == 0 || count1 >= n) && count0 < n) {
                cost += costs[get<0>(t)][0];
                count0++;
            } else {
                cost += costs[get<0>(t)][1];
                count1++;
            }
        }
        return cost;
    }
};