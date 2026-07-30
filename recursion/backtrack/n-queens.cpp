/*
Problem: N-Queens
Link: https://leetcode.com/problems/n-queens/

Input:
    n - Number of queens (size of the chessboard)

Output:
    Return all distinct solutions to the n-queens puzzle.
    Each solution contains an n x n board represented as a
    vector of strings, where:
        'Q' -> Queen
        '.' -> Empty cell

Approach:
    - Use backtracking to place one queen in each row.
    - Track occupied columns, main diagonals (row + col),
      and anti-diagonals (row - col + n - 1) using boolean arrays.
    - If a valid position is found, recurse to the next row.
    - Backtrack after exploring each possibility.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    void recSolveQueens(vector<vector<string>>& ans,
                        vector<string>& curr,
                        vector<bool>& cols,
                        vector<bool>& mainDiag,
                        vector<bool>& antiDiag,
                        int n,
                        int row) {

        if (row == n) {
            ans.push_back(curr);
            return;
        }

        for (int col = 0; col < n; col++) {

            if (!cols[col] &&
                !mainDiag[row + col] &&
                !antiDiag[row - col + (n - 1)]) {

                curr[row][col] = 'Q';
                cols[col] = true;
                mainDiag[row + col] = true;
                antiDiag[row - col + (n - 1)] = true;

                recSolveQueens(ans, curr, cols, mainDiag, antiDiag, n, row + 1);

                curr[row][col] = '.';
                cols[col] = false;
                mainDiag[row + col] = false;
                antiDiag[row - col + (n - 1)] = false;
            }
        }
    }

public:
    vector<vector<string>> solveNQueens(int n) {

        vector<vector<string>> ans;
        vector<string> curr(n, string(n, '.'));

        vector<bool> cols(n, false);
        vector<bool> mainDiag(2 * n - 1, false);
        vector<bool> antiDiag(2 * n - 1, false);

        recSolveQueens(ans, curr, cols, mainDiag, antiDiag, n, 0);

        return ans;
    }
/*
Time Complexity: O(n!)
Space Complexity: O(n)
    - O(n) recursion stack
    - O(n) for columns
    - O(2n-1) for each diagonal array
    (Excluding the space required for storing the output.)
*/
};

int main() {
    Solution obj;

    int n = 4;

    vector<vector<string>> ans = obj.solveNQueens(n);

    for (const auto& board : ans) {
        for (const auto& row : board) {
            cout << row << '\n';
        }
        cout << '\n';
    }

    return 0;
}
