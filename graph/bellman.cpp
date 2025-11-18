struct edge{
    int u,v;
    ll w;
};
int n,m;
const ll inf=1e17;
vector<edge>edges;
vector<ll>dist(N);
void bellman(int source){
    for (int i=0;i<=n;i++) dist[i]=inf;
    dist[source]=0;
    for (int i=1;i<n;i++){
        bool f=0;
        for (auto e:edges){
            if (dist[e.u]==inf) continue;
            if (dist[e.v]>dist[e.u]+e.w){
                dist[e.v]=dist[e.u]+e.w;
                f=1;
            }
        }
        if (!f) break;
    }

    // negative edge check
    bool neg=0;
    for (auto e:edges){
        if (dist[e.u]!=inf && dist[e.v]>dist[e.u]+d){
            neg=1;
            break;
        }
    }
}
