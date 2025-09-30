            }
            if (match && isMatch(s.substr(1), p)) {
                return true;
            if (isMatch(s, p.substr(2))) {
        if (p.size() >= 2 && p.at(1) == '*') {
at(0) || p.at(0) == '.'));
        bool match = (s.size() > 0 && (p.at(0) == s.
        }
            return false;
        } else if (p.size() == 0) {
            return true;
        if (p.size() == 0 && s.size() == 0) {
    bool isMatch(string s, string p) {
public:
class Solution {
                return true;
            }
        } else {
            return match && isMatch(s.substr(1), p.
substr(1));
        }
        return false;
    }
};