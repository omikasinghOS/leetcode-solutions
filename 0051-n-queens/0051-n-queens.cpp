class Solution {
public:
    vector<vector<string>> ans;

    void backtrack(int row, int n,
                   vector<string>& board,
                   unordered_set<int>& cols,
                   unordered_set<int>& diag1,
                   unordered_set<int>& diag2) {

        if (row == n) {
            ans.push_back(board);
            return;
        }

        for (int col = 0; col < n; col++) {

            if (cols.count(col) ||
                diag1.count(row - col) ||
                diag2.count(row + col))
                continue;

            board[row][col] = 'Q';

            cols.insert(col);
            diag1.insert(row - col);
            diag2.insert(row + col);

            backtrack(row + 1, n, board, cols, diag1, diag2);

            board[row][col] = '.';

            cols.erase(col);
            diag1.erase(row - col);
            diag2.erase(row + col);
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n, string(n, '.'));

        unordered_set<int> cols;
        unordered_set<int> diag1;
        unordered_set<int> diag2;

        backtrack(0, n, board, cols, diag1, diag2);

        return ans;
    }
};