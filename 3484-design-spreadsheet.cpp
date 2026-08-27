class Spreadsheet {
private:
    pair<int, int> deparse(string cell) {
        int col = cell[0] - 'A';
        int row = stoi(cell.substr(1)) - 1;
        return pair(row, col);
    }
public:
    vector<vector<int>> sheet;
    Spreadsheet(int rows) {
        sheet.resize(rows, vector<int> (26, 0));
    }
    
    void setCell(string cell, int value) {
        pair<int, int> coord = deparse(cell);
        int row = coord.first;
        int col = coord.second;
        sheet[row][col] = value;
    }
    
    void resetCell(string cell) {
        setCell(cell, 0);
    }
    
    int getValue(string formula) {
        int a = getInteger(formula.substr(1, formula.find('+')));
        int b = getInteger(formula.substr(formula.find('+') + 1));
        return a + b;
    }
    int getInteger(string formula) {
        if (formula[0] - 'A' < 26 && formula[0] - 'A' >= 0) {
            pair<int, int> coord = deparse(formula);
            return sheet[coord.first][coord.second];
        } else {
            return stoi(formula);
        }
    }
};

/**
 * Your Spreadsheet object will be instantiated and called as such:
 * Spreadsheet* obj = new Spreadsheet(rows);
 * obj->setCell(cell,value);
 * obj->resetCell(cell);
 * int param_3 = obj->getValue(formula);
 */