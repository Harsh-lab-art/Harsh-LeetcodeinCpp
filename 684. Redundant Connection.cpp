class Solution 
{
    int find(vector<int>& arr,int v)
    {
        if(arr[v]==-1)
        return v;
        return arr[v]=find(arr,arr[v]);
    }
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) 
    {
        int n=edges.size();
        vector<int>arr(n+1,-1);
        for(auto edge:edges)
        {
            int x=find(arr,edge[0]);
            int y=find(arr,edge[1]);
            if(x==y)
            return edge;
            else
            arr[x]=y;
        }
        return{0,0};
    }
};
