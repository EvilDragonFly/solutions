#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int marea(0);
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                int area(0);
                if(grid[i][j]==1)
                    clear(i,j,grid,area);
                marea = max(marea, area);
            }
        }
        return marea;
    }
    void clear(int i, int j, vector<vector<int>>& grid, int& area){
        if(i>=0&&i<grid.size() && j>=0&&j<grid[0].size() && grid[i][j]==1){
            grid[i][j]=0;       //clear
            area++;
            clear(i-1,j, grid, area);
            clear(i+1,j, grid, area);
            clear(i,j-1, grid, area);
            clear(i,j+1, grid, area);
        }else{
            return;
        }
    }
};