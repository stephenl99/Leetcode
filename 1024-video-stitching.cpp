class Solution {
public:
    int videoStitching(vector<vector<int>>& clips, int time) {
        sort(clips.begin(), clips.end());
        if (clips[0][0] != 0) {
            return -1;
        }
        int currMax = 0;
        int index = 0;
        int maxNext = 0;
        int count = 0;
        while (index < clips.size()) {
            if (currMax >= time) {
                return count;
            }
            while (index < clips.size() && clips[index][0] <= currMax) {
                maxNext = max(maxNext, clips[index][1]);
                index++;
            }
            if (maxNext <= currMax) {
                return -1;
            }
            currMax = maxNext;
            count++;
        }
        if (currMax >= time) {
            return count;
        }
        return -1;
    }
};