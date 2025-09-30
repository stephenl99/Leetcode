class Solution {
public:
    int myAtoi(string s) {
        if (s.size() == 0) {
            return 0;
        }
        int index = 0;
        while (index < s.size() && s.at(index) == ' ') {
            index++;
