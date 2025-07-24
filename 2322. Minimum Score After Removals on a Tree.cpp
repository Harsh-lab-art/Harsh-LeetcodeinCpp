class Solution 
{
    public:
    int calc(int a, int b, int c) 
    {
        return max({a, b, c}) - min({a, b, c});
    }
    int minimumScore(vector<int>& nums, vector<vector<int>>& edges) 
    {
        int n = nums.size();
        vector<vector<int>> tree(n);
        for (auto& e : edges) 
        {
            tree[e[0]].push_back(e[1]);
            tree[e[1]].push_back(e[0]);
        }
        vector<int> xorSubtree(n);
        vector<int> parent(n, -1);
        function<int(int, int)> dfs1 = [&](int node, int par) 
        {
            int xorVal = nums[node];
            parent[node] = par;
            for (int nei : tree[node]) 
            {
                if (nei == par) continue;
                xorVal ^= dfs1(nei, node);
            }
            xorSubtree[node] = xorVal;
            return xorVal;
        };
        int totalXOR = dfs1(0, -1);
        int result = INT_MAX;
        vector<pair<int, int>> edgesList;
        for (int i = 1; i < n; ++i) 
        {
            edgesList.push_back({parent[i], i});
        }
        for (int i = 0; i < edgesList.size(); ++i) 
        {
            for (int j = i + 1; j < edgesList.size(); ++j) 
            {
                int a = edgesList[i].second;
                int b = edgesList[j].second;

                if (isAncestor(a, b, parent)) 
                {
                    int x = xorSubtree[b];
                    int y = xorSubtree[a] ^ xorSubtree[b];
                    int z = totalXOR ^ xorSubtree[a];
                    result = min(result, calc(x, y, z));
                } 
                else if (isAncestor(b, a, parent)) 
                {
                    int x = xorSubtree[a];
                    int y = xorSubtree[b] ^ xorSubtree[a];
                    int z = totalXOR ^ xorSubtree[b];
                    result = min(result, calc(x, y, z));
                } 
                else 
                {
                    int x = xorSubtree[a];
                    int y = xorSubtree[b];
                    int z = totalXOR ^ x ^ y;
                    result = min(result, calc(x, y, z));
                }
            }
        }
        return result;
    }

    bool isAncestor(int u, int v, vector<int>& parent) 
    {
        while (v != -1) 
        {
            if (v == u) return true;
            v = parent[v];
        }
        return false;
    }
};
