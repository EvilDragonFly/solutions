#include<vector>
using namespace std;
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int ret(0);
        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid[0].size(); j++){
                if(grid[i][j]=='1'){
                    ret++;
                    clear(i,j,grid);
                }
            }
        }
        return ret;

    }
    //清楚一座岛屿
    void clear(int i, int j, vector<vector<char>>& grid){
        if(grid[i][j] == '0'){      //推出递归
            return;
        }
        grid[i][j] = '0';
        if(i-1>=0)  clear(i-1,j,grid);
        if(i+1<grid.size()) clear(i+1,j,grid);
        if(j-1>=0) clear(i,j-1,grid);
        if(j+1<grid[0].size()) clear(i,j+1,grid);
    }
};