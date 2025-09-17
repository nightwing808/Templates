ll bit[N];
void update(int i,ll v){
	if (i<=0) return;
	for (;i<=n;i+=(i&-i)) bit[i]+=v;
}
void updatelr(int l,int r,ll v){
	update(l,v);
	update(r+1,-v);
}
ll sum(int i){
	ll ans=0;
	for (;i>=1;i-=(i&-i)) ans+=bit[i];
	return ans;
}
ll query(int l,int r){
	return sum(r)-sum(l-1);
}
