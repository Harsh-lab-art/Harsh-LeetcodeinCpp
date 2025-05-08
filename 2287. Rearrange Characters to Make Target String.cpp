#include<iostream>
#include<unordered_map>
#include<string>
using namespace std;
class Solution 
{
    public:
    int rearrangeCharacters(string s, string target) 
    {
        unordered_map<char,int> sc,tc;
        for(char c:s)
        {
            sc[c]++;
        }
        for(char c:target)
        {
            tc[c]++;
        }
        int maxcopy=INT_MAX;
        for(auto& [c,co]:tc)
        {
            if(sc.find(c)==sc.end())
            {
                return 0;
            }
            maxcopy=min(maxcopy,sc[c]/co);
        }
        return maxcopy;
    }
};
