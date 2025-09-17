int indeg[N];
vector<int>g[N];
vector<int>kahn(int n){
	queue<int>q;
	for (int i=1;i<=n;i++){
		if (indeg[i]==0) q.push(i);
	}
	vector<int>order;
	while (!q.empty()){
		int node=q.front();
		q.pop();
		order.push_back(node);
		for (auto child:g[node]){
			indeg[child]--;
			if (indeg[child]==0) q.push(child);
		}
	}
	return order;
}