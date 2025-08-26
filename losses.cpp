class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        int maxx = 0;
        for (vector<int> match : matches) {
            maxx = max(maxx, match[0]);
            maxx = max(maxx, match[1]);
        }
        vector<int> freq(maxx, -1);
        for (vector<int> match : matches) {
            if (freq[match[0] - 1] == -1) {
                freq[match[0] - 1] = 0;
            }
            if (freq[match[1] - 1] == -1) {
                freq[match[1] - 1] = 0;
            }
            freq[match[1] - 1]++;
        }
        vector<vector<int>> answer(2, vector<int>());
        for (int i = 0; i < freq.size(); i++) {
            if (freq[i] == 0) {
                answer[0].push_back(i + 1);
            } else if (freq[i] == 1) {
                answer[1].push_back(i + 1);
            }
        }
        return answer;
    }
};