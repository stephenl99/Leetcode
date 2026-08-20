class Solution {
public:
    int minn;
    int snakesAndLadders(vector<vector<int>>& board) {
        minn = pow(board.size(), 2);
        int maxx = pow(board.size(), 2);
        queue<pair<int, int>> q;
        q.push(pair(1, 0));
        unordered_set<int> visited;
        int count = 0;
        while (!q.empty()) {
            pair<int, int> top = q.front();
            q.pop();
            if (top.first == maxx) {
                return top.second;
            }
            if (visited.contains(top.first)) {
                continue;
            } 
            visited.insert(top.first);
            int row = getRow(top.first, board.size());
            int col = getCol(top.first, board.size());
            int index = top.first;
            if (board[row][col] != -1) {
                index = board[row][col];
            }
            if (index == maxx) {
                return top.second;
            }
            for (int i = index + 1; i <= min(index + 6, maxx); i++) {
                q.push(pair(i, top.second + 1));
            }
        }
        return -1;
    }
    int getRow(int index, int boardSize) {
        return (pow(boardSize, 2) - index) / boardSize;
    }
    int getCol(int index, int boardSize) {
        if ((boardSize - getRow(index, boardSize)) % 2 == 1) {
            return (index - 1) % boardSize;
        } else {
            return boardSize - 1 - ((index - 1) % boardSize);
        }
    }
};