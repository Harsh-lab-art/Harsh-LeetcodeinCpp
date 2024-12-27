#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution
{
  public:
   int maxScoreSightseeingPair(vector<int>values) 
    {
        int max=0;
        int atI=values[0]+0;
        for(int i=1;i<values.size();i++)
        {
            max=max(max,atI+values[i]-i);
            atI=max(atI,values[i]+i);
        }
        return max;
    }
};
    int main()
    {
        Solution obj;
        vector<int>arr={8,1,5,2,6};
        cout<<obj.maxScoreSightseeingPair(arr)<<endl;
        vector<int>arr2={1,2};
        cout<<obj.maxScoreSightseeingPair(arr2)<<endl;

    }
