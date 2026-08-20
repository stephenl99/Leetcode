class Solution {
public:
    int shortestDistance(vector<string>& wordsDict, string word1, string word2) {
        vector<int> ones;
        vector<int> twos;
        int minn = wordsDict.size();
        for (int i = 0; i < wordsDict.size(); i++) {
            string word = wordsDict[i];
            if (word == word1) {
                ones.push_back(i);
            }
            if (word == word2) {
                twos.push_back(i);
            }
        }
        int twosIndex = 0;
        for (int i = 0; i < ones.size(); i++) {
            while (twosIndex < twos.size() && twos[twosIndex] <= ones[i]) {
                minn = min(minn, abs(ones[i] - twos[twosIndex]));
                twosIndex++;
            }
            if (twosIndex < twos.size()) {
                minn = min(minn, abs(ones[i] - twos[twosIndex]));
            } else {
                return minn;
            }
        }
        return minn;
    }
};