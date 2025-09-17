ll table[20][N],a[N];
void build(int n){
    for (int i=0;i<n;i++) table[0][i]=a[i];
    for (int i=1;i<20;i++){
        for (int j=0;j<n;j++){
            if (j+(1<<i)-1>=n) break;
            table[i][j]=min(table[i-1][j],table[i-1][j+(1<<(i-1))]);
        }
    }
}
ll query(int l,int r){
    if (l>r) return 0LL;
    int sz=r-l+1;
    int msb=31-__builtin_clz(sz);
    ll ans=min(table[msb][l],table[msb][r-(1<<msb)+1]);
    return ans;
}
