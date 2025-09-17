int vis[N];
vector<int>g[N];
void bfs(int s){
    queue<int>q;
    q.push(s);
    while (!q.empty()){
        int v=q.front();
        q.pop();
        vis[v]=1;
        for (auto c:g[v]){
            if (vis[c]) continue;
            q.push(c);
        }
    }
}
