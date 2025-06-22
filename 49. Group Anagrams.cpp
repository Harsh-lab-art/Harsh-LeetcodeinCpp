class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> map;
        for (string s : strs) {
            string sorted = s;
            sort(sorted.begin(), sorted.end());
            map[sorted].push_back(s);
        }
        vector<vector<string>> result;
        for (auto pair : map)
            result.push_back(pair.second);
        return result;
    }
};
