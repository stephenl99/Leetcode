class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
        map<int, int> events;

        for (auto& flower : flowers) {
            events[flower[0]]++;
            events[flower[1] + 1]--;
        }

        vector<int> ans(people.size());

        priority_queue<pair<int, int>> pq;

        for (int i = 0; i < people.size(); i++) {
            pq.push({-people[i], i});
        }

        int curr = 0;

        for (auto [time, change] : events) {
            while (!pq.empty() && -pq.top().first < time) {
                auto [negativeTime, index] = pq.top();
                pq.pop();

                ans[index] = curr;
            }

            curr += change;
        }

        while (!pq.empty()) {
            auto [negativeTime, index] = pq.top();
            pq.pop();

            ans[index] = curr;
        }

        return ans;
    }
};