class Solution 
{
    #define pii pair<int,int>
    public:
    int countDays(int days, vector<vector<int>>& meetings) 
    {
        vector<pii> time;
        for(auto& meeting:meetings)
        {
            time.push_back(make_pair(meeting[0],1));
            time.push_back(make_pair(meeting[1]+1,0));
        }
        sort(time.begin(),time.end());
        int over=0;
        int co=time[0].first-1;
        for(int i=0;i<time.size()-1;++i)
        {
            if(time[i].second==0)
            over--;
            else
            over++;
            if(over==0)
            co+=time[i+1].first-time[i].first;
        }
        co+=days-time.back().first+1;
        return co;
    }
};
