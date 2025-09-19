class Spreadsheet {
public:
    vector<vector<int>> v;

    Spreadsheet(int rows) {
        v.assign(rows+1, vector<int>(26, 0));
    }
    
    void setCell(string cell, int value) {
        int col = cell[0] - 'A';
        int row = 0;
        int idx = 1;
        while (idx < cell.size()) {
            row *= 10;
            row += cell[idx] - '0';
            idx++;
        }
        v[row][col] = value;
    }
    
    void resetCell(string cell) {
        setCell(cell, 0);
    }
    
    int getValue(string formula) {
        // extract X
        int idx = 1;
        int X = 0;
        if (isdigit(formula[idx])) {
            while (formula[idx] != '+') {
                X *= 10;
                X += formula[idx] - '0';
                idx++;
            }
        }
        else {
            int col = formula[idx] - 'A';
            int row = 0;
            idx++;
            while (formula[idx] != '+') {
                row *= 10;
                row += formula[idx] - '0';
                idx++;
            }
            X = v[row][col];
        }

        // skip '+'
        idx++;

        // extract Y
        int Y = 0;
        if (isdigit(formula[idx])) {
            while (idx < formula.size()) {
                Y *= 10;
                Y += formula[idx] - '0';
                idx++;
            }
        }
        else {
            int col = formula[idx] - 'A';
            int row = 0;
            idx++;
            while (idx < formula.size()) {
                row *= 10;
                row += formula[idx] - '0';
                idx++;
            }
            Y = v[row][col];
        }

        return X + Y;
    }
};

/**
 * Your Spreadsheet object will be instantiated and called as such:
 * Spreadsheet* obj = new Spreadsheet(rows);
 * obj->setCell(cell,value);
 * obj->resetCell(cell);
 * int param_3 = obj->getValue(formula);
 */
