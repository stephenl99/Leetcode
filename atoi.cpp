class Solution {
public:
    int myAtoi(string s) {
        if (s.size() == 0) {
            return 0;
        }
        int index = 0;
        while (index < s.size() && s.at(index) == ' ') {
            index++;
        }
        if (index >= s.size()) {
            return 0;
        }
        bool first = true;
        bool neg = false;
        int num = 0;
        while (index < s.size()) {
            int val = INT_MIN / 10;
            int other = s.at(index) - '0';
            if (isNumber(s.at(index))) {
                if (!neg && (num > INT_MAX / 10 || (num == INT_MAX / 10 && s.at(index) - '0' >= INT_MAX % 10))) {
                    return INT_MAX;
                }
                if (neg && (-1 * num < INT_MIN / 10 || (-1 * num == INT_MIN / 10 && s.at(index) - '0' >= 8))) {
                    return INT_MIN;
                }
            }
            if (first) {
                if (s.at(index) == '-') {
                    neg = true;
                    first = false;
                    index++;
                    continue;
                } else if (s.at(index) == '+') {
                    first = false;
                    index++;
                    continue;
                }
                else if (s.at(index) != '+' && !isNumber(s.at(index))) {
                    return 0;
                }
            }
            if (!isNumber(s.at(index))) {
                break;
            }
            if (first) {
                first = false;
            } else {
                num *= 10;
            }
            num += s.at(index) - '0';
            index++;
        }
        int finalNum = neg ? -1 * num : num;
        if (finalNum > INT_MAX) {
            return INT_MAX;
        }
        if (finalNum < INT_MIN) {
            return INT_MIN;
        }
        return finalNum;
    }
    bool isNumber(char c) {
        if (c == '0' || c == '1' || c == '2' || c == '3'
        || c == '4' || c == '5' || c == '6'|| c == '7'||
        c == '8' || c == '9') {
            return true;
        }
        return false;
    }
};
