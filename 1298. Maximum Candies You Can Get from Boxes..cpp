class Solution 
{
    public:
    int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, vector<int>& initialBoxes) 
    {
        int n=status.size();
        vector<int> haskey(n);
        queue<int> q;
        for(int i=0;i<initialBoxes.size();i++)
        {
            q.push(initialBoxes[i]);
        }
        int cnt=0;
        int timer=0;
        while(!q.empty())
        {
            int bx=q.front();q.pop();
            if(status[bx]||haskey[bx])
            {
                cnt+=candies[bx];
                for(auto b:containedBoxes[bx])
                {
                    q.push(b);
                }
                for(auto k:keys[bx])
                {
                    haskey[k]=1;
                }
                timer=0;
            }
            else
            {
                q.push(bx);
                timer++;
            }
            if(timer>q.size())
            break;
        }
        return cnt;
    }
};
