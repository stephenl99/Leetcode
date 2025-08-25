class Solution {
public:
    string numberToWords(int num) {
        if (num == 0) {
            return "Zero";
        }
        string str = to_string(num);
        string answer = "";
        int index = 0;
        int remaining = str.size();
        while (index < str.size()) {
            int place = (str.size()) - index;
            string returned;
            if (place % 3 == 2) {
                string val = '0' + str.substr(index, 2);
                returned = convert(val);
                answer += returned;
                index += 2;
                remaining -= 2;
            } else if (place % 3 == 1) {
                string val = "00" + str.substr(index, 1);
                returned = convert(val);
                answer += returned;
                index += 1;
                remaining -= 1;
            } else {
                string val = str.substr(index, 3);
                returned = convert(val);
                answer += returned;
                index += 3;
                remaining -= 3;
            }
            int threesomes = remaining / 3;
            if (returned != "") {
                if (threesomes == 1) {
                    answer += " Thousand ";
                } else if (threesomes == 2) {
                    answer += " Million ";
                } else if (threesomes == 3) {
                    answer += " Billion ";
                }
            }
        }
        if (answer[answer.size() - 1] == ' ') {
            answer.pop_back();
        }
        return answer;
    }
    string convert(string val) {
        string answer = "";
        if (val[0] != '0') {
            answer += toWord(val[0]) + " Hundred";
        }
        if (val[1] == '1') {
            if (answer != "") {
                answer += " ";
            }
            answer += teen(val[2]);
            return answer;
        } else if (val[1] != '0') {
            if (answer != "") {
                answer += " ";
            }
            answer += ten(val[1]);
        }
        if (val[2] != '0' && val[1] != '1') {
            if (answer != "") {
                answer += " ";
            }
            answer += toWord(val[2]);
        }
        return answer;
    }
    string ten(char c) {

        if (c == '2') {
            return "Twenty";
        }
        if (c == '3') {
            return "Thirty";
        }
        if (c == '4') {
            return "Forty";
        }
        if (c == '5') {
            return "Fifty";
        }
        if (c == '6') {
            return "Sixty";
        }
        if (c == '7') {
            return "Seventy";
        }
        if (c == '8') {
            return "Eighty";
        }
        if (c == '9') {
            return "Ninety";
        }
        return "ERROR";
    }
    string teen(char c) {
        if (c == '0') {
            return "Ten";
        }
        if (c == '1') {
            return "Eleven";
        }
        if (c == '2') {
            return "Twelve";
        }
        if (c == '3') {
            return "Thirteen";
        }
        if (c == '4') {
            return "Fourteen";
        }
        if (c == '5') {
            return "Fifteen";
        }
        if (c == '6') {
            return "Sixteen";
        }
        if (c == '7') {
            return "Seventeen";
        }
        if (c == '8') {
            return "Eighteen";
        }
        if (c == '9') {
            return "Nineteen";
        }
        return "ERROR";
    }
    string toWord(char c) {
        if (c == '1') {
            return "One";
        }
        if (c == '2') {
            return "Two";
        }
        if (c == '3') {
            return "Three";
        }
        if (c == '4') {
            return "Four";
        }
        if (c == '5') {
            return "Five";
        }
        if (c == '6') {
            return "Six";
        }
        if (c == '7') {
            return "Seven";
        }
        if (c == '8') {
            return "Eight";
        }
        if (c == '9') {
            return "Nine";
        }
        return "ERROR";
    }
};