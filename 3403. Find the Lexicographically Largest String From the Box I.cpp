class Solution 
{
    public:
    string answerString(string word, int numFriends) 
    {
        if(numFriends==1)
        return word;
        int n=word.size();
        int k=n-numFriends+1;
        char c='a';
        for(auto x:word)
        {
            if(x>c)
            {
                c=x;
            }
        }
        string mx="";
        for(int i=0;i<n;i++)
        {
            string s="";
            if(word[i]==c)
            {
                for(int j=i;j<i+k && j<n;j++)
                {
                    s+=word[j];
                }
            }
            if(s>mx)
            {
                mx=s;
            }
        }
        return mx;
    }
};
