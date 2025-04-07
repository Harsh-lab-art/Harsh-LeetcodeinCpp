class Solution 
{
    #define pii pair<int,int>
    bool count(vector<pii>& coo)
    {
        int line=0;
        int over=0;
        for(int i=0;i<coo.size();++i)
        {
            if(coo[i].second==0)
            over--;
            else
            over++;
            if(over==0)
            line++;
        }
        return line>2;
    }
    public:
    bool checkValidCuts(int n, vector<vector<int>>& rectangles) 
    {
        vector<pii>yco,xco;
        for(auto rect:rectangles)
        {
            yco.push_back(make_pair(rect[1],1));
            yco.push_back(make_pair(rect[3],0));
            xco.push_back(make_pair(rect[0],1));
            xco.push_back(make_pair(rect[2],0));
        }
        sort(yco.begin(),yco.end());
        sort(xco.begin(),xco.end());
        return (count(yco)||count(xco)); 
    }
};
