class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        vector<vector<int>> board2;
        for(int i = 0; i < board.size(); i++) {
            vector<int> v;
            board2.push_back(v);
            for (int j = 0; j < board[0].size(); j++) {
                int result = 0;
                int lives = 0;
                lives += val(board, i - 1, j);
                lives += val(board, i - 1, j - 1);
                lives += val(board, i - 1, j + 1);
                lives += val(board, i + 1, j);
                lives += val(board, i + 1, j - 1);
                lives += val(board, i + 1, j + 1);
                lives += val(board, i, j + 1);
                lives += val(board, i, j - 1);
                if (board[i][j] == 1 && (lives == 2 || lives == 3) || lives == 3){
                    result = 1;
                }
                board2[i].push_back(result);
            }
        }
        for(int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                board[i][j] = board2[i][j];
            }
        }
    }
    int val(vector<vector<int>>& board, int i, int j) {
        if (i >= 0 && i < board.size() && j >= 0 && j < board[0].size()) {
            return board[i][j];
        }
        return 0;
    }
};