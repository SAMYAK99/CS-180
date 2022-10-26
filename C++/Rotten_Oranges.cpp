/*
 GFG- Problem name:Rotten Oranges
Given a grid of dimension nxm where each cell in the grid can have values 0, 1 or 2 which has the following meaning:
0 : Empty cell
1 : Cells have fresh oranges
2 : Cells have rotten oranges

We have to determine what is the minimum time required to rot all oranges. A rotten orange at index [i,j] can
rot other fresh orange at indexes [i-1,j], [i+1,j], [i,j-1], [i,j+1] (up, down, left and right) in unit time.

time complexity -O(n*m)
space complexity-o(n*m)

this question is basically the implementation of BFS algo of graph

*/

class solution
{
public:
    int orangesRotting(vector<vector<int>> &grid)
    {
        // Code here
        int n = grid.size();                           // calculate number of rows
        int m = grid[0].size();                        // calculate number of colums
        queue<pair<pair<int, int>, int>> pq;           // declare a queue of pair of pair
        vector<vector<int>> vis(n, vector<int>(m, 0)); // declare a 2 d vector
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 2) // if grid already contains rotten ornages than push them into queue
                {
                    vis[i][j] = 2; // mark visited array as visited
                    pq.push({{i, j}, 0});
                }
            }
        }
        int drow[4] = {-1, 1, 0, 0}; // tricky way to triverse in all direction except diagonal -> <-
        int dcol[4] = {0, 0, -1, 1};
        int tm = 0, t;
        while (!pq.empty()) // run the loop till the queue not become empty
        {
            int nrow = pq.front().first.first; // push new row and column to queue
            int ncol = pq.front().first.second;
            t = pq.front().second; // store the time needed to rotten nrow and ncol
            pq.pop();
            vis[nrow][ncol] = 2;
            tm = max(tm, t); // maximum of the time
            for (int i = 0; i < 4; i++)
            {
                int x = nrow + drow[i]; // traversing up,down left , right
                int y = ncol + dcol[i];
                if (x >= 0 && x < n && y >= 0 && y < m && vis[x][y] != 2 && grid[x][y] == 1) // check for valid index
                {
                    pq.push({{x, y}, t + 1}); // increment time and push into the queue
                    grid[x][y] = 2;
                    vis[x][y] = 2;
                }
            }
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 1) // chechk if any fresh orange remain if remain return -1
                {
                    return -1;
                }
            }
        }
        return tm; // max time needed
    }