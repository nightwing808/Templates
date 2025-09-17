int  vis[N];
vector<int>g[N];
void dfs(int vertex,int par=-1)
{
    vis[vertex]=1;
    for (auto child:g[vertex])
    {
        if (vis[child]) continue;
        dfs(child,vertex);
    }
}
