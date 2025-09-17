vector<int>g[N];
int sub[N],isCentroid[N];
int pCentroid[N];
int dfs(int v,int p,int d,int r){
	sub[v]=1;
	for (auto c:g[v]){
		if (c==p || isCentroid[c]) continue;
		sub[v]+=dfs(c,v,d+1,r);
	}
	return sub[v];
}
int get(int v,int p,int n){
	for (auto c:g[v]){
		if (c==p || isCentroid[c] || sub[c]<=n/2) continue;
		return get(c,v,n);
	}
	return v;
}
void decompose(int v,int p,int parCentroid){
	int n=dfs(v,p,0,v);
	int centroid=get(v,p,n);
	isCentroid[centroid]=1;
	pCentroid[centroid]=parCentroid;
	for (auto c:g[centroid]){
		if (c==p || isCentroid[c]) continue;
		decompose(c,centroid,centroid);
	}
}