vector<int>g[N];
int sz[N],in[N],out[N],head[N],par[N],dep[N],Time,n;
// COPY THE EXACT POINT SEGTREE
void dfs(int v,int p=-1){
	sz[v]=1;
	for (auto &c:g[v]){
		if (c==p) continue;
		par[c]=v;
		dep[c]=dep[v]+1;
		dfs(c,v);
		sz[v]+=sz[c];
		if (sz[c]>sz[g[v][0]]) swap(c,g[v][0]);
	}
}
void dfs_hld(int v,int p=-1)
{
	if (p==-1) head[v]=v;
	in[v]=++Time;
	for (auto &c:g[v]){
		if (c==p) continue;
		head[c]=(c==g[v][0]?head[v]:c);
		dfs_hld(c,v);
	}
	out[v]=Time;
}
/*
// FOR EDGE
vector<pair<int,int>>g[N];
void dfs(int v,int p=-1){
	sz[v]=1;
	for (auto &pp:g[v]){
		int c=pp.ff,w=pp.ss;
		if (c==p) continue;
		par[c]=v;
		dep[c]=dep[v]+1;
		dfs(c,v);
		sz[v]+=sz[c];
		if (sz[c]>sz[g[v][0].ff]) swap(pp,g[v][0]);
	}
}
void dfs_hld(int v,int p=-1,int cost=0){
	if (p==-1) head[v]=v;
	in[v]=++Time;
	update(1,1,n,in[v],cost);
	for (auto &[c,w]:g[v]){
		if (c==p) continue;
		head[c]=(c==g[v][0].ff?head[v]:c);
		dfs_hld(c,v,w);
	}
	out[v]=Time;
}
*/
bool isAncestor(int p,int v){
	return (in[p]<=in[v] && out[p]>=out[v]);
}
void upd_val(int v,ll val){
	// FOR EDGE,
	// if (in[u]>in[v]) swap(u,v);
	update(1,1,Time,in[v],val);
}
ll query_path(int a,int b){
	ll ans=0;
	while (head[a]!=head[b]){
		int x=head[a];
		int y=head[b];
		if (dep[x]>dep[y]){
			ans+=query(1,1,Time,in[x],in[a]);
			a=par[x];
		}
		else{
			ans+=query(1,1,Time,in[y],in[b]);
			b=par[y];
		}
	}
	if (dep[b]<dep[a]) swap(a,b);
	ans+=query(1,1,Time,in[a],in[b]);
	// FOR EDGE,
	//if (a!=b) ans+=query(1,1,Time,in[a]+1,in[b]);
	return ans;
}
void init(int n){
	Time=0;
	dep[1]=0;
	for (int i=1;i<=n;i++) g[i].clear();
	for (int i=1;i<=4*n;i++) Tree[i].sum=0;
}