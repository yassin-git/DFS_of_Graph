//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

const int N = 1e5;
vector<int> v;
bool vis[N];

class Solution
{
public:
    void dfs(int pos, vector<int> adj[])
    {
        vis[pos] = true;
        v.push_back(pos);
        for (int i = 0; i < adj[pos].size(); i++)
        {
            int x = adj[pos][i];
            if (!vis[x])
                dfs(x, adj);
        }
        return;
    }

    // Function to return a list containing the DFS traversal of the graph.
    vector<int> dfsOfGraph(int V, vector<int> adj[])
    {
        // Code here
        memset(vis, false, sizeof(vis));
        v.clear();
        dfs(0, adj);
        return v;
    }
};

//{ Driver Code Starts.
int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.dfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++)
        {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends