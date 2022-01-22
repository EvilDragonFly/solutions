#include <iostream>
#include <vector>
using namespace std;
vector<pair<int, int>> ans;
void dfs(vector<vector<int>> &maze, vector<pair<int, int>> &path, pair<int, int> p)
{
    path.emplace_back(p);
    int row = maze.size() - 1;
    int col = maze.back().size() - 1;
    if (p.first == row && p.second == col)
    {
        ans = path;                             //唯一一条路径
        return;
    }
    maze[p.first][p.second] = 1; // mark as visited
    if (p.first - 1 >= 0 && maze[p.first - 1][p.second] == 0)

        dfs(maze, path, make_pair(p.first - 1, p.second));

    if (p.second - 1 >= 0 && maze[p.first][p.second - 1] == 0)

        dfs(maze, path, make_pair(p.first, p.second - 1));

    if (p.first + 1 <= row && maze[p.first + 1][p.second] == 0)

        dfs(maze, path, make_pair(p.first + 1, p.second));

    if (p.second + 1 <= col && maze[p.first][p.second + 1] == 0)

        dfs(maze, path, make_pair(p.first, p.second + 1));

    path.pop_back(); //回溯
    maze[p.first][p.second] = 0;
}
int main()
{
    int row, col;
    while (cin >> row >> col)
    {
        vector<vector<int>> maze(row, vector<int>(col));
        for (auto &r : maze)

            for (auto &c : r)

                cin >> c;

        vector<pair<int, int>> path;
        dfs(maze, path, make_pair(0, 0));
        for (auto p : ans)
            cout << "(" << p.first << "," << p.second << ")" << endl;
    }
}