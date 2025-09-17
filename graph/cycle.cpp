int vis[N];
vector<int>g[N];
bool cycle(int vertex){
    vis[vertex]=1;
    for (auto child:g[vertex]){
        if (!vis[child]) if (cycle(child)) return 1;
        else if (vis[child]==1) return 1;
    }
    vis[vertex]=2;
    return 0;
}
