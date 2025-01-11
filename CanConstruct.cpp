#include<iostream>
#include<string>
#include<vector>
class Solution 
{
    public:
    bool canConstruct(string s, int k) 
    {
        if(k>s.size())
        {
            return false;
        }
        vector<int>count(26,0);
        for(char c:s)
        {
            count[c-'a']++;
        }
        int oc=0;
        for(int i:count)
        {
            if(i%2!=0)
            {
                oc++;
            }
        }
        return oc<=k;
    }
};
