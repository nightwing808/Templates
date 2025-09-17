const int LG=18;
vector<int>g[N];
int par[N][LG+1],dep[N];
void dfs(int v,int p=-1){
	for (int i=1;i<=LG;i++)
		if (dep[v]>=(1<<i)) par[v][i]=par[par[v][i-1]][i-1];
	for (int c:g[v]){
		if (c==p) continue;
		par[c][0]=v;
		dep[c]=dep[v]+1;
		dfs(c,v);
	}
}
int lca(int u,int v){
	if (dep[u]<dep[v]) swap(u,v);
	int d=dep[u]-dep[v];
	for (int k=LG;k>=0;k--){
		if ((d>>k)&1) u=par[u][k];
	}
	if (u==v) return u;
	for (int k=LG;k>=0;k--){
		if (dep[u]>=(1LL<<k) && par[u][k]!=par[v][k]){
			u=par[u][k];
			v=par[v][k];
		}
	}
	return par[u][0];
}
int kth(int u,int k){
	if (dep[u]<k) return -1;
	for (int i=0;i<=LG;i++)
		if (k&(1<<i)) u=par[u][i];
	return u;
}
//kth node from u to v,0th node is u
int go(int u,int v,int k){
	int l=lca(u,v);
	int d=dep[u]+dep[v]-(dep[l]<<1);
	if (k>d) return -1;
	if (dep[l]+k<=dep[u]) return kth(u,k);
	k-=dep[u]-dep[l];
	return kth(v,dep[v]-dep[l]-k);
}