class Solution 
{
    public:
    vector<int> productExceptSelf(vector<int>& nums) 
    {
        int n=nums.size();
        vector<int>res(n,1);
        int left=1,right=1;
        for(int i=0;i<n;i++)
        {
            res[i]*=left;
            left*=nums[i];
            res[n-1-i]*=right;
            right*=nums[n-1-i];
        }
        return res;
    }
};
