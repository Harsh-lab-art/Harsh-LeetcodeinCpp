class Solution 
{
    public:
    int maxArea(vector<int>& height) 
    {
        int l = 0, r = height.size() - 1, mW = 0;
        while (l < r) 
        {
            mW = max(mW, min(height[l], height[r]) * (r- l));
            if (height[l] < height[r]) 
            l++;
            else 
            r--;
        }
        return mW;
    }
};
