class Solution {
public:
    vector<int> beautifulIndices(string s, string a, string b, int k) {
        vector<int> aCheck = kmp(a, s);
        vector<int> bCheck = kmp(b, s);
        int i = 0;
        int j = 0;
        vector<int> count;
        while (i != aCheck.size()) {
            if (j >= bCheck.size()) {
                return count;
            }
            if (bCheck[j] < aCheck[i] - k) {
                j++;
                continue;
            }
            else if (abs(aCheck[i] - bCheck[j]) <= k) {
                count.push_back(aCheck[i]);
                i++;
                continue;
            }
            else {
                i++;
            }
        }
        return count;
    }
    vector<int> kmp(string& a, string&s) {
        vector<int> table(a.size());
        table[0] = 0;
        int index = 1;
        int len = 0;
        while (index < a.size()) {
            char c = a[index];
            if (c == a[len]) {
                len++;
                table[index] = len;
                index++;
            } else {
                if (len != 0) {
                    len = table[len - 1];
                } else {
                    table[index] = 0;
                    index++;
                }
            }
        }
        
        vector<int> result;
        int i = 0; 
        int j = 0;
        while (i < s.size()) {
            if (s[i] == a[j]) {
                i++;
                j++;
                if (j == a.size()) {
                    result.push_back(i - j);
                    j = table[j - 1];
                }
            } else {
                if (j != 0) {
                    j = table[j - 1];
                }
                else {
                    i++;
                }
            }
        }
        return result;
    }
};