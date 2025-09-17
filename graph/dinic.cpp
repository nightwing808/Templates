const ll inf=1e17;
ll nodes=N,src,dest;
ll dist[N],q[N],work[N];
struct edge{
    ll to,rev;
    ll f,cap;
};
vector<edge>g[N];
void addEdge(ll u,ll v,ll cap){
    edge a={v,g[v].size(),0,cap};
    edge b={u,g[u].size(),0,0};
    g[u].push_back(a);
    g[v].push_back(b);
}
bool dinic_bfs(){
    fill(dist,dist+nodes,-1);
    dist[src]=0;
    ll idx=0;
    q[idx++]=src;
    for (ll i=0;i<idx;i++){
        ll u=q[i];
        for (ll j=0;j<g[u].size();j++){
            edge &e=g[u][j];
            if (dist[e.to]<0 && e.f<e.cap){
                dist[e.to]=dist[u]+1;
                q[idx++]=e.to;
            }
        }
    }
    return dist[dest]>=0;
}
ll dinic_dfs(ll u,ll f){
    if (u==dest) return f;
    for (ll &i=work[u];i<g[u].size();i++){
        edge &e=g[u][i];
        if (e.cap<=e.f) continue;
        if (dist[e.to]==dist[u]+1){
            ll flow=dinic_dfs(e.to,min(f,e.cap-e.f));
            if (flow>0){
                e.f+=flow;
                g[e.to][e.rev].f-=flow;
                return flow;
            }
        }
    }
    return 0;
}
ll maxFlow(ll _src,ll _dest){
    src=_src;
    dest=_dest;
    int ans=0;
    while (dinic_bfs()){
        fill(work,work+nodes,0);
        while (ll delta=dinic_dfs(src,inf)){
            ans+=delta;
        }
    }
    return ans;
}
// addEdge(u, v, C);    edge from u to v. Capacity is C
// maxFlow(s, t);  max flow from s to t
