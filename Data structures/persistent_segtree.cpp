const int tsz=6000007;
int avail,version[N];
struct node{
	ll val,left,right;
}Tree[tsz];
void build(int idx,int st,int ed){ // 0th-version
	if (st==ed){
		Tree[idx].val=0;
		return;
	}
	Tree[idx].left=avail++;
	Tree[idx].right=avail++;
	int mid=(st+ed)/2;
	build(Tree[idx].left,st,mid);
	build(Tree[idx].right,mid+1,ed);
	Tree[idx].val=Tree[Tree[idx].left].val+Tree[Tree[idx].right].val;
}
ll update(int idx,int st,int ed,int pos,ll v){
	int nidx=avail++;
	Tree[nidx]=Tree[idx];
	if (st==ed){
		Tree[nidx].val=v;
		return nidx;
	}
	int mid=(st+ed)/2;
	if (pos<=mid) Tree[nidx].left=update(Tree[idx].left,st,mid,pos,v);
	else Tree[nidx].right=update(Tree[idx].right,mid+1,ed,pos,v);
	Tree[nidx].val=Tree[Tree[nidx].left].val+Tree[Tree[nidx].right].val;
	return nidx;
}
ll query(int idx,int st,int ed,int l,int r){
	if (st==l && ed==r) return Tree[idx].val;
	int mid=(st+ed)/2;
	if (r<=mid) return query(Tree[idx].left,st,mid,l,r);
	else if (l>mid) return query(Tree[idx].right,mid+1,ed,l,r);
	else {
		ll ans1=query(Tree[idx].left,st,mid,l,mid);
		ll ans2=query(Tree[idx].right,mid+1,ed,mid+1,r);
		return (ans1+ans2);
	}
}