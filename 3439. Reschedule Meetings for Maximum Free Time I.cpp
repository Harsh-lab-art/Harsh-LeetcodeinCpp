class Solution 
{
    public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) 
    {
        int n=startTime.size();
        vector<int> sum(n+1,0);
        for(int i=0;i<n;++i)
        {
            sum[i+1]=sum[i]+(endTime[i]-startTime[i]);
        }
        int res=0;
        for(int i=k-1;i<n;++i)
        {
            int r=(i==n-1)?eventTime:startTime[i+1];
            int l=(i==k-1)?0:endTime[i-k];
            int dur=sum[i+1]-sum[i-k+1];
            int free=r-l-dur;
            res=max(res,free);
        }
        return res;
    }
};
