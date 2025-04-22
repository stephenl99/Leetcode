// #3365
using namespace std;
#include <string>
#include <unordered_map>
#include <map>
class Solution {
    public:
        bool isPossibleToRearrange(string s, string t, int k) {
            unordered_map<string, int> mapp;
            for (int i = 0; i < k; i++) {
                int index = i * (s.size() / k);
                string sub = s.substr(index, (s.size() / k));
                mapp[sub]++;
            }
            for (int i = 0; i < k; i++) {
                int index = i * (s.size() / k);
                string sub = t.substr(index, (s.size() / k));
                mapp[sub]--;
                if (mapp[sub] == -1) {
                    return false;
                    }
                }
            return true;
        }
    };