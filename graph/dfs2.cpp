int n,m,a[N][N],vis[N][N];
void dfs1(int i,int j)
{
    if (i<0 || j<0 || i>=n || j>=m) return;
    if (vis[i][j]) return;

    dfs1(i-1,j,a);
    dfs1(i+1,j,a);
    dfs1(i,j-1,a);
    dfs1(i,j+1,a);
}
