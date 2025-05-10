#include <iostream>
#include <string>
using namespace std;
class Solution 
{
    public:
    int countAsterisks(string s) 
    {
        bool inbars = false;
        int co = 0;
        for (char c : s) 
        {
            if (c == '|') 
            {
                inbars = !inbars;
            } else if (c == '*' && !inbars) 
            {
                co++;
            }
        }
        return co;
    }
};
