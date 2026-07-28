/*
This code is a solution of the problem Rotting Oranges from LeetCode at the link
https://leetcode.com/problems/rotting-oranges/description/
The solution progresses from brute force to optimal
Input:
    m n -> Number of rows and columns of the grid
    grid[0][0] grid[0][1] ... grid[m-1][n-1] -> grid values (0 = empty, 1 = fresh orange, 2 = rotten orange)
Output:
    Minimum number of minutes until no fresh orange remains, or -1 if impossible
*/

#include <bits/stdc++.h>

using namespace std;

class Solution {
//Multi - source BFS
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<int, int>> q;
        int fresh = 0;
        int t = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 1){
                    fresh++;
                }
                if(grid[i][j] == 2){
                    q.push({i, j});
                }
            }
        }
        vector<int> nbrx = {-1, 0, 0, 1};
        vector<int> nbry = {0, -1, 1, 0};
        int nbr = nbrx.size();
        while(fresh && !q.empty()){
            int numAtLvl = q.size();
            int x, y;
            for(int i = 0; i < numAtLvl; i++){
                x = q.front().first;
                y = q.front().second;
                q.pop();
                for(int nbrind = 0; nbrind < nbr; nbrind++){
                    int dx = nbrx[nbrind];
                    int dy = nbry[nbrind];
                    int nx = x+dx;
                    int ny = y+dy;
                    if(nx>=0&&ny>=0&&nx<m&&ny<n&&grid[nx][ny]==1){
                        grid[nx][ny] = 2;
                        q.push({nx, ny});
                        fresh--;
                    }
                }
            }
            t++;
        }
        if(fresh){
            return -1;
        }
        return t;
    }
//Time Complexity -> O(m*n)
//Space Complexity -> O(m*n)
};

int main(){
    Solution sol;
    int m, n;
    cin >> m >> n;
    vector<vector<int>> grid(m, vector<int>(n));
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            cin >> grid[i][j];
        }
    }
    int ans = sol.orangesRotting(grid);
    cout << ans << "\n";
    return 0;
}