int dist[N][N];
void solve(int tc){
    int n,m;
    cin>>n>>m;
    for (int i=1;i<=n;i++)
        for (int j=1;j<=n;j++) dist[i][j]=1e17;
    for (int i=1;i<=n;i++) dist[i][i]=0;
    for (int i=0;i<m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        dist[u][v]=min(dist[u][v],w);
        dist[v][u]=min(dist[v][u],w);
    }
    for (int k=1;k<=n;k++){
        for (int i=1;i<=n;i++){
            for (int j=1;j<=n;j++){
                dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
            }
        }
    }
}
