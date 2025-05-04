#include<iostream>
#include<string>
using namespace std;
class Solution 
{
    public:
    string removeDigit(string number, char digit) 
    {
        int n=number.size();
        int idx=-1;
        for(int i=0;i<n;i++)
        {
            if(number[i]==digit)
            {
                idx=i;
                if(i+1<n && number[i+1]>digit)
                {
                    break;
                }
            }
        }
        return number.substr(0,idx)+number.substr(idx+1);
    }
};
