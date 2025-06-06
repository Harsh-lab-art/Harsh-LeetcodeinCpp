class Solution 
{
    public:
    int maxProfit(vector<int>& prices) 
    {
        int minprice=INT_MAX,maxProfit=0;
        for(int price:prices)
        {
            minprice=min(minprice,price);
            maxProfit=max(maxProfit,price-minprice);
        }
        return maxProfit;
    }
};
