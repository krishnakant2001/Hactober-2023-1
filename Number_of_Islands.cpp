class Solution {
public:
    void solve(vector<vector<char>> &grid, int i, int j){
        if(i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size()){
            return;
        }
        if(grid[i][j] == '0'){
            return;
        }

        grid[i][j] = '0';
        
        //checking the neighbours
        
        //up
        solve(grid, i-1, j);
        
        //down
        solve(grid, i+1, j);

        //left
        solve(grid, i, j-1);

        //right
        solve(grid, i, j+1);
    }
    int numIslands(vector<vector<char>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();

        int cnt = 0;

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == '1'){
                    solve(grid, i, j);
                    cnt++;
                }
            }
        }

        return cnt;
    }
};
