class Solution {
public:
    int calculate(string s) {
        stack<int> sta;
        char curr_op = '+';
        int curr_num = 0;
        for (int i = 0; i <=  s.size(); i++) {
            if (isdigit(s[i])) {
                curr_num = curr_num * 10 + (s[i] - '0');
            }
            if ((!iswspace(s[i]) && !isdigit(s[i])) || i == s.size()) {
                if (curr_op == '+') {
                    sta.push(curr_num);
                } else if (curr_op == '-') {
                    sta.push(-curr_num);
                } else if (curr_op == '*') {
                    curr_num *= sta.top();
                    sta.pop();
                    sta.push(curr_num);
                } else if (curr_op == '/') {
                    curr_num = sta.top() / curr_num;
                    sta.pop();
                    sta.push(curr_num);
                }
                if (i != s.size()) {
                    curr_op = s[i];
                }
                curr_num = 0;
            }
        }
        int ans = 0;
        while (!sta.empty()) {
            ans += sta.top();
            sta.pop();
        }
        return ans;
    }
};