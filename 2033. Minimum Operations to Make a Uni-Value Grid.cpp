class Solution 
{
    public:
    int minOperations(vector<vector<int>>& grid, int x) 
    {
        vector<int>arr;
        int rem=grid[0][0]%x;
        for(int i=0;i<grid.size();++i)
        {
            for(int j=0;j<grid[0].size();++j)
            {
                if(grid[i][j]%x!=rem)
                return -1;
                arr.push_back(grid[i][j]);
            }
        }
        sort(arr.begin(),arr.end());
        int n=arr.size();
        int med=n/2;
        int step=0;
        for(int i=0;i<n;++i)
        step+=abs(arr[i]-arr[med])/x;
        return step;
    }
};
