int a[N][N],n,m;
ll dist[N][N];
bool is_valid(int x,int y){
    return x>=0 && y>=0 && x<n && y<m;
}
vector<pair<int,int>>moves={
    {0,-1},{0,1},{-1,0},{1,0}
};
void dijkstra(int i,int j){
    priority_queue<array<ll,3>,vector<array<ll,3>>,greater<>>pq;
    pq.push({a[i][j],i,j});
    dist[i][j]=a[i][j];
    while (!pq.empty()){
        array<ll,3>x=pq.top();
        ll d=x[0],x=x[1],y=x[2];
        pq.pop();
        if (dist[x][y]<d) continue;
        for (auto mov:moves){
            int cx=mov.ff+x,cy=mov.ss+y;
            if (!is_valid(cx,cy)) continue;
            ll w=a[cx][cy];
            if (dist[cx][cy]>dist[x][y]+w)
            {
                dist[cx][cy]=dist[x][y]+w;
                pq.push({dist[cx][cy],cx,cy});
            }
        }
    }
}
