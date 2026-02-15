class Solution 
{
    public:
    string addBinary(string a, string b) 
    {
        string res="";
        int i=a.size()-1;
        int j=b.size()-1;
        int carry=0;
        while (i>=0 || j>=0 || carry !=0)
        {
            int d=(i>=0)? a[i]-'0':0;
            int e=(j>=0)? b[j]-'0':0;
            int sum=d+e+carry;
            res+= char((sum%2)+'0');
            carry=sum/2;
            i--;
            j--;
        }
        reverse(res.begin(),res.end());
        return res;
    }
};
