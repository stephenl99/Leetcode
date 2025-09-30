class Solution {
public:
    bool isMatch(string s, string p) {
        if (p.size() == 0 && s.size() == 
0) {
            return true;
        } else if (p.size() == 0) {
            return false;
        }
        bool match = (s.size() > 0 && (p.at
(0) == s.at(0) || p.at(0) == '.'));
        if (p.size() >= 2 && p.at(1) == 
'*') {
            if (isMatch(s, p.substr(2))) {
                return true;