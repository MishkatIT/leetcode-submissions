class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        bool ok = true;
        int n = 9;
        for (int i = 0; i < n; i++) {
            vector<int> f(10);
            for (int j = 0; j < n; j++) {
                if (board[i][j] == '.') continue;
                f[board[i][j] - '0']++;
            }
            for (int x = 1; x <= 9; x++) {
                ok &= (f[x] <= 1);
            }
        }
        for (int j = 0; j < n; j++) {
            vector<int> f(10);
            for (int i = 0; i < n; i++) {
                if (board[i][j] == '.') continue;
                f[board[i][j] - '0']++;
            }
            for (int x = 1; x <= 9; x++) {
                ok &= (f[x] <= 1);
            }
        }
        cout << "here" << ok << '\n';


        for (int i = 0; i < n; i += 3) {
            for (int j = 0; j < n; j += 3) {
                vector<int> f(10);
                for (int k = i; k < i + 3; k++) {
                    for (int l = j; l < j + 3; l++) {
                        if (board[k][l] == '.') continue;
                        f[board[k][l] - '0']++;
                    }
                }
                for (int x = 1; x <= 9; x++) {
                    ok &= (f[x] <= 1);
                }
            } 
        }
        return ok;
    }
};