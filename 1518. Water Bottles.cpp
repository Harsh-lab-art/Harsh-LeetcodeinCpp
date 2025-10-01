class Solution 
{
    public:
    int numWaterBottles(int numBottles, int numExchange) 
    {
        
        int total_drunk = numBottles;
        int empty_bottles = numBottles;
        while (empty_bottles >= numExchange) 
        {
        int new_full = empty_bottles / numExchange;
        total_drunk += new_full;
        empty_bottles = empty_bottles % numExchange + new_full;
    }
    return total_drunk;
    }
};
