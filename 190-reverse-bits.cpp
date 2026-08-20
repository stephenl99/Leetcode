class Solution {
public:
    int reverseBits(int n) {
        string s = std::bitset<32>(n).to_string();
        for (int i = 0; i < 16; i++) {
            char temp = s[i];
            s[i] = s[31 - i];
            s[31 - i] = temp;
        }
        return std::stoi(s, nullptr, 2);
    }
};