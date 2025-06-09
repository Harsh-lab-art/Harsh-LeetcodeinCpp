class Solution 
{
    public:
    int maxSubArray(vector<int>& nums) 
    {
        int maxsum=nums[0],currs=nums[0];
        for(int i=1;i<nums.size();i++)
        {
            currs=max(nums[i],currs+nums[i]);
            maxsum=max(maxsum,currs);
        }
        return maxsum;
    }
};
