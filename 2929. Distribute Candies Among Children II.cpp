class Solution 
{
    public:
    long long distributeCandies(int n, int limit) 
    {
        long long ans=0;
        for(int i=0;i<=min(n,limit);i++)
        {
            int r=n-i;
            if(r>2*limit)
            continue;
            int l=max(r-limit,0);
            int u=min(limit,r);
            ans+=(u-l+1);
        }
        return ans;
    }
};
