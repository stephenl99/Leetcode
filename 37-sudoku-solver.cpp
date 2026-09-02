class Solution {
public:
    int n = 3;
    int N = n * n;
    int **rows;
    int **cols;
    int **boxes;
    vector<vector<char>> board;
    bool solved = false;

    bool could_place(int d, int row, int col) {
        int idx = (row / n) * n + col / n;
        return rows[row][d] + cols[col][d] + boxes[idx][d] == 0;
    }

    void place_number(int d, int row, int col) {
        int idx = (row / n) * n + col / n;
        rows[row][d]++;
        cols[col][d]++;
        boxes[idx][d]++;
        board[row][col] = (char)(d + '0');
    }
    void remove_number(int d, int row, int col) {
        int idx = (row / n) * n + col / n;
        rows[row][d]--;
        cols[col][d]--;
        boxes[idx][d]--;
        board[row][col] = '.';
    }
    void place_next_numbers(int row, int col) {
        if (row == N - 1 && col == N - 1) {
            solved = true;
        } else {
            if (col == N - 1) {
                backtrack(row + 1, 0);
            } else {
                backtrack(row, col + 1);
            }
        }
    }
    void backtrack(int row, int col) {
        if (board[row][col] == '.') {
            for (int i = 1; i < 10; i++) {
                if (could_place(i, row, col)) {
                    place_number(i, row, col);
                    place_next_numbers(row, col);
                    if (!solved) {
                        remove_number(i, row, col);
                    }
                }
            }
        } else {
            place_next_numbers(row, col);
        }
    }
    void solveSudoku(vector<vector<char>>& board) {
        this->board = board;
        rows = new int *[N];
        cols = new int *[N];
        boxes = new int *[N];
        for (int i = 0; i < N; i++) {
            rows[i] = new int[N + 1]();
            cols[i] = new int[N + 1]();
            boxes[i] = new int[N + 1]();
        }
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                char num = board[i][j];
                if (num != '.') {
                    int d = num - '0';
                    place_number(d, i, j);
                }
            }
        }
        backtrack(0, 0);
        board = this->board;
    }
};