vector<int>g[N];
int vis[N],in[N],low[N];
int cnt;
vector<int>cutp;
void dfs(int v,int p=-1){
	vis[v]=1;
	in[v]=low[v]=++cnt;
	int child=0;
	for (int c:g[v]){
		if (c==p) continue;
		if (vis[c]) 
			low[v]=min(low[v],in[c]);
		else{
			dfs(c,v);
			low[v]=min(low[v],low[c]);
			if (low[c]>=in[v] && p!=-1)
				cutp.push_back(v);
			child++;
		}
	}
	if (p==-1 && child>1) cutp.push_back(v);
}