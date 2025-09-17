int n,m,a[N][N],vis[N][N];
bool is_valid(int x,int y,int _n,int _m){
    return x>=0 && y>=0 && x<_n && y<_m;
}
vector<pair<int,int>>moves={
    {0,-1},{0,1},{-1,0},{1,0}
};
void bfs1(int i,int j){
    queue<pair<int,int>>q;
    q.push({i,j});
    while (!q.empty()){
        pair<int,int>v=q.front();
        int x=v.first,y=v.second;
        q.pop();
        vis[x][y]=1;
        for (auto mov:moves){
            int cx=mov.first+x;
            int cy=mov.second+y;
            if (!is_valid(cx,cy,n,m)) continue;
            if (vis[cx][cy]) continue;
            q.push({cx,cy});
        }
    }
}
