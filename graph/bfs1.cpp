int vis[N],dist[N];
vector<int>g[N];
void bfs(int s){
    queue<int>q;
    q.push(s);
    vis[s]=1;
    dist[s]=0;
    while (!q.empty()){
        int v=q.front();
        q.pop();
        for (auto c:g[v]){
            if (vis[c]) continue;
            q.push(c);
            vis[c]=1;
            dist[c]=dist[v]+1;
        }
    }
}
