class Solution {
    vector<vector<char>> board;
    int directions[8][2] = {{0, 1}, {1, 0}, {1, 1}, {0, -1}, {-1, 0}, {-1, 1}, {1, -1}, {-1, -1}};
public:
    int mines(vector<int>& click) {
        int xx = click[0];
       int yy = click[1];
       int count = 0;
       for (auto direction : directions) {
        int x = xx + direction[0];
        int y = yy + direction[1];
        if (x < 0 || y < 0 || x >= board.size() || y >= board[0].size() || !(board[x][y] == 'M')) {
        continue;
       } 
       count++;
       }
       return count;
    }
    void helper(vector<int> click) {
        int x = click[0];
       int y = click[1];
       if (x < 0 || y < 0 || x >= board.size() || y >= board[0].size() || !(board[x][y] == 'M' || board[x][y] == 'E')) {
        return;
       }
       if (board[x][y] == 'M') {
        board[x][y] = 'X';
        return; 
       } else if (board[x][y] == 'E') {
        int minees = mines(click);
        if (minees == 0) {
            board[x][y] = 'B';
            for (auto direction : directions) {
                auto vec = {click[0] + direction[0], click[1] + direction[1]};
                helper(vec);
            }
        } else {
            board[x][y] = '0' + minees;
        }
       }
    }
    vector<vector<char>> updateBoard(vector<vector<char>>& board_input, vector<int>& click) {
        board = board_input;
        helper(click);
        return board;
    }
};