vector<int>g[N];
int vis[N],in[N],low[N];
int cnt,bridge;
void dfs(int v,int p=-1){
	vis[v]=1;
	in[v]=low[v]=++cnt;
	bool skip=0;
	for (int c:g[v]){
		if (c==p && !skip){
			skip=1;
			continue;
		}
		if (vis[c])
			low[v]=min(low[v],in[c]);
		else{
			dfs(c,v);
			low[v]=min(low[v],low[c]);
			if (low[c]>in[v]) bridge++;
		}
	}
}