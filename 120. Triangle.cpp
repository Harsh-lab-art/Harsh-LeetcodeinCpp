class Solution 
{
    public:
    int minimumTotal(vector<vector<int>>& triangle) 
    {
        int n=triangle.size();
        vector<int> dp=triangle[n-1];
        for(int r=n-2;r>=0;r--)
        {
            for(int c=0;c<=r;c++)
            {
                dp[c]=triangle[r][c]+min(dp[c],dp[c+1]);
            }
        }
        return dp[0];
    }
};
