#include<iostream>
#include<vector>
using namespace std;
class Solution 
{
 public:
    vector<vector<int>> generateMatrix(int n) 
    {
        vector<vector<int>>matrix(n,vector<int>(n,0));
        int l=0,r=n-1,t=0,b=n-1,val=1;
        while(l<=r && t<=b)
        {
            for(int i=l;i<=r;i++)
            {
                matrix[t][i]=val++;
            }
            t++;
        
            for(int i=t;i<=b;i++)
            {
                matrix[i][r]=val++;
            }
            r--;
            if(t<=b)
            {
               for(int i=r;i>=l;i--)
                {
                 matrix[b][i]=val++;
                }
            b--;
            }
            if(l<=r)
            {
               for(int i=b;i>=t;i--)
                {
                 matrix[i][l]=val++;
                }
              l++;
            }
           
       }
      return matrix;
    }
};
