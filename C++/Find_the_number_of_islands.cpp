/*
GFG - Problem name: Find the number of islands:

 Given a grid of size n*m (n is the number of rows and m is the number of columns in the grid)
 consisting of '0's (Water) and '1's(Land). Find the number of islands.
 Note: An island is surrounded by water and is formed by connecting adjacent lands horizontally or
 vertically or diagonally i.e., in all 8 directions.

time complexity -O(n*m)
space complexity-o(n*m)
*/

class Solution
{
public:
    int numIslands(vector<vector<char>> &grid)
    {
        // Code here
        int n = grid.size(); // calculate no. of rows
        int m = grid[0].size(); // calculate no. of columns
        vector<vector<char>> vis(n, vector<char>(m, '0')); // make a visited array that mark a position is visited or not
        queue<pair<int, int>> q; // form a queue that store the pair of indices those are islands(1)
        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (vis[i][j] == '0' && grid[i][j] == '1') // if a cell is unvisited and is a island
                {
                    q.push(make_pair(i, j)); //push inside the queue
                    vis[i][j] = 1;
                    while (!q.empty())
                    {
                        int nrow = q.front().first;  // take the new row
                        int ncol = q.front().second; // take the new column
                        q.pop();
                        for (int drow = -1; drow <= 1; drow++)
                        {
                            for (int dcol = -1; dcol <= 1; dcol++)
                            {
                                int x = nrow + drow; // traverse along all the possible directions
                                int y = ncol + dcol; 
                                if (x >= 0 && x < n && y >= 0 && y < m && vis[x][y] == '0' && grid[x][y] == '1') // check validity
                                {
                                    vis[x][y] = '1';
                                    q.push(make_pair(x, y));
                                }
                            }
                        }
                    }
                    cnt++; // increase the counter for the number of islands
                }
            }
        }
        return cnt;
    }
};