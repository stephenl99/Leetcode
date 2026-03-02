class Solution {
public:
    bool canAliceWin(vector<string>& a, vector<string>& b) {
        int aIndex = a.size() - 1;
        int bIndex = b.size() - 1;
        vector<bool> dpA(a.size());
        vector<bool> dpB(b.size());
        while (aIndex + bIndex > -2) {
            if (aIndex == -1) {
                return dpA[0];
            }
            if (bIndex == -1 || a[aIndex] > b[bIndex]) {
                if (bIndex == b.size() - 1 || 
                !isValidNext(a[aIndex], b[bIndex + 1])) {
                    dpA[aIndex] = true;
                } else {
                    dpA[aIndex] = dpB[bIndex + 1];
                }
                aIndex--;
            } else {
                if (aIndex == a.size() - 1 || 
                !isValidNext(b[bIndex], a[aIndex + 1])) {
                    dpB[bIndex] = false;
                } else {
                    dpB[bIndex] = dpA[aIndex + 1];
                }
                bIndex--;
            }
        }
        return dpA[0];
    }
    bool isValidNext(string first, string second) {
        return first[0] == second[0] || first[0] + 1 == second[0];
    }
};