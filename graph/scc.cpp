int n,m,vis[N],root[N],sz[N];
vector<int>g[N],r[N],ng[N],nodes;
stack<int>order;
void dfs1(int v){
	vis[v]=1;
	for (int c:g[v]){
		if (vis[c]) continue;
		dfs1(c);
	}
	order.push(v);
}
void dfs2(int v,int id){
	root[v]=id;
	sz[id]++;
	vis[v]=1;
	for (int c:r[v]){
		if (vis[c]) continue;
		dfs2(c,id);
	}
}
void findSCC(){
	for (int i=1;i<=n;i++){
		if (vis[i]) continue;
		dfs1(i);
	}
	memset(vis,0,sizeof(vis));
	while (!order.empty()){
		int v=order.top();
		order.pop();
		if (vis[v]) continue;
		dfs2(v,v);
		nodes.push_back(v);
	}
	for (int i=1;i<=n;i++){
    	for (int c:g[i])
    		if (root[c]!=root[i]) ng[root[i]].push_back(root[c]);
    }
}
void init(int _n){
	while (!order.empty()) order.pop();
	for (int i=1;i<=_n;i++){
		g[i].clear();
		r[i].clear();
		ng[i].clear();
		root[i]=sz[i]=vis[i]=0;
	}
	nodes.clear();
}
