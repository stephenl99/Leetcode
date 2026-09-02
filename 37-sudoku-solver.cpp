class Solution {
public:
    vector<vector<char>> board;
    int n = 3;
    int N = n * n;
    bool solved;
    vector<vector<int>> rows;
    vector<vector<int>> cols;
    vector<vector<int>> boxes;

    bool can_insert(int i, int row, int col) {
        int idx = (row / n) * n + (col / n);
        return rows[row][i] + cols[col][i] + boxes[idx][i] == 0;
    }
    void insert(int i, int row, int col) {
        int idx = (row / n) * n + (col / n);
        rows[row][i]++;
        cols[col][i]++;
        boxes[idx][i]++;
        board[row][col] = i + '0';
    }
    void remove(int i, int row, int col) {
        int idx = (row / n) * n + (col / n);
        rows[row][i]--;
        cols[col][i]--;
        boxes[idx][i]--;
        board[row][col] = '.';
    }
    void next(int row, int col) {
        if (row == N - 1 && col == N - 1) {
            solved = true;
        } else {
            if (col == N - 1) {
                recurse(row + 1, 0);
            } else {
                recurse(row, col + 1);
            }
        }
    }
    void recurse(int row, int col) {
        if (board[row][col] == '.') {
            for (int i = 1; i < 10; i++) {
                if (can_insert(i, row, col)) {
                    insert(i, row, col);
                    next(row, col);
                    if (!solved) {
                        remove(i, row, col);
                    }
                }
            }
        } else {
            next(row, col);
        }
    }
    void solveSudoku(vector<vector<char>>& board) {
        this->board = board;
        rows = vector<vector<int>>(N, vector<int>(N + 1, 0));
        cols = vector<vector<int>>(N, vector<int>(N + 1, 0));
        boxes = vector<vector<int>>(N, vector<int>(N + 1, 0));
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (board[i][j] != '.') {
                    int idx = (i / n) * n + (j / n);
                    int d = board[i][j] - '0';
                    rows[i][d]++;
                    cols[j][d]++;
                    boxes[idx][d]++;
                }
            }
        }
        recurse(0, 0);
        board = this->board;
    }
};