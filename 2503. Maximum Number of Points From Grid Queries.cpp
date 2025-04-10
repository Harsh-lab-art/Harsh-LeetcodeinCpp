class Solution 
{
    #define pii pair<int,int>
    #define pip pair<int,pii>

    bool isvalid(int x, int y, int m, int n)
    {
        return (x >= 0 && x < m && y >= 0 && y < n);
    }

public:
    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) 
    {
        set<int> sorted(queries.begin(), queries.end());
        unordered_map<int, int> query;
        priority_queue<pip, vector<pip>, greater<pip>> minheap;
        
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));

        minheap.push(make_pair(grid[0][0], make_pair(0, 0)));
        visited[0][0] = true;

        vector<int> dir = {-1, 0, 1, 0, -1};
        int co = 0;

        for (int q : sorted)
        {
            while (!minheap.empty())
            {
                pip curr = minheap.top();
                minheap.pop();
                int val = curr.first;
                int x = curr.second.second;
                int y = curr.second.first;

                if (val >= q)
                {
                    minheap.push(curr);
                    break;
                }
                co++;

                for (int i = 0; i < 4; i++)
                {
                    int nx = x + dir[i];
                    int ny = y + dir[i + 1];

                    if (isvalid(nx, ny, m, n) && !visited[nx][ny])
                    {
                        visited[nx][ny] = true;
                        minheap.push(make_pair(grid[nx][ny], make_pair(ny, nx)));
                    }
                }
            }
            query[q] = co;
        }

        vector<int> res;
        for (int q : queries)
            res.push_back(query[q]);

        return res;
    }
};
