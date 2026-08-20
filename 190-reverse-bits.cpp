class Solution {
public:
    int reverseBits(int n) {
        int res = 0;
        int tempN = n;
        int idx = 0;

        for(int i = 0; i < 32; i++){
            int bit = ((n & (1 << i)) > 0) ? 1 : 0;

            if(bit == 1){
                res = res | (1 << (32-i-1));
            }
        }
        return res;
    }
};