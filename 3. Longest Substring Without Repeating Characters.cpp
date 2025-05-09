#include<iostream>
#include<unordered_map>
#include<string>
class Solution 
{
    public:
    int lengthOfLongestSubstring(string s) 
    {
          unordered_map<char, int> charIndex;
        int left = 0, maxLen = 0;

        for (int right = 0; right < s.length(); ++right) 
        {
            char current = s[right];
            if (charIndex.count(current) && charIndex[current] >= left) 
            {
                left = charIndex[current] + 1; 
            }

            charIndex[current] = right;
            maxLen = max(maxLen, right - left + 1); 
        }

        return maxLen;
    }
};
