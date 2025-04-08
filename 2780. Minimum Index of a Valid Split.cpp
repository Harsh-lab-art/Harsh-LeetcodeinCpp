class Solution 
{
    int moore(vector<int>& nums)
    {
        int maj=nums[0];
        int freq=1;
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i]!=maj)
            freq--;
            else
            freq++;
            if(freq==0)
            {
                maj=nums[i];
                freq=1;
            }
        }
        return maj;
    }
    public:
    int minimumIndex(vector<int>& nums) 
    {
        int n=nums.size();
        int maj=moore(nums);
        int mx=0;
        for(int i=0;i<n;i++)
        
            if(nums[i]==maj)
            mx++;
            int pre=0;
            for(int i=0;i<n-1;i++)
            {
                if(nums[i]==maj)
                {
                    pre++;
                    mx--;
                }
                if((pre>(i+1)/2) && (mx>(n-i-1)/2))
                return i;
            }
         return -1;   
        }
    
};
