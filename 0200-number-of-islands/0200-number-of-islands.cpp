class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int ans = 0;
        int m = grid.size();
        int n = grid[0].size();
        vector<int> xnbr = {-1, 0, 0, 1};
        vector<int> ynbr = {0, -1, 1, 0};
        int nnbr = xnbr.size();
        vector<vector<bool>> vis(m, vector<bool>(n, false));
        stack<pair<int, int>> stk;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j]=='1' && !vis[i][j]){
                    vis[i][j] = true;
                    ans++;
                    stk.push({i, j});
                    while(!stk.empty()){
                        auto tp = stk.top();
                        stk.pop();
                        int x = tp.first;
                        int y = tp.second;
                        for(int nbr = 0; nbr<nnbr; nbr++){
                            int xn = x + xnbr[nbr];
                            int yn = y + ynbr[nbr];
                            if(((xn>=0&&yn>=0)&&(xn<m&&yn<n))&&(!vis[xn][yn]&&grid[xn][yn]=='1')){
                                vis[xn][yn] = true;
                                stk.push({xn, yn});
                            }
                        }
                    }
                }
            }
        }
        return ans;
    }
};