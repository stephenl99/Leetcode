#include <vector>
#include <map>
using namespace std;
class Solution {
    public:
        int findBlackPixel(vector<vector<char>>& picture, int target) {
            int count = 0;
            vector<vector<int>> numCounted (picture[0].size());
            vector<vector<int>> refRows(picture.size());
            map<int, bool> counted;
            for (int i = 0; i < picture.size(); i++) {
                for (int j = 0; j < picture[0].size(); j++) {
                    if (picture[i][j] == 'B') {
                        numCounted[j].push_back(i);
                        refRows[i].push_back(j);
                    }
                }
            }
            for (int j = 0; j < picture[0].size(); j++) {
                if (numCounted[j].size() == target) {
                    if (areEqual(target, j, numCounted, refRows)) {
                        counted[numCounted[j][0]] = true;
                        count += target;
                    }
                }
            }
            return count;
        }
        bool areEqual(int target, int col, vector<vector<int>>& cols, vector<vector<int>>& rows) {
            int size = rows[cols[col][0]].size();
            if (size != target) {
                return false;
            }
            vector<int> row = rows[cols[col][0]];
            for (int c : cols[col]) {
                if (rows[c].size() != size) {
                    return false;
                }
                for (int i = 0; i < rows[c].size(); i++) {
                    if (row[i] != rows[c][i]) {
                        return false;
                    }
                }
            }
            return true;
        }
    };