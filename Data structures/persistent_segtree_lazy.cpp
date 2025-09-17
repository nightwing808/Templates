const int tsz=6000007;
int avail,version[N];
struct node{
	ll val,left,right,lazy;
}Tree[tsz];
ll fix(int idx,int l,int r,int x){
	int nidx=avail++;
	Tree[nidx]=Tree[idx];
	Tree[nidx].lazy+=x;
	Tree[nidx].val+=(r-l+1)*x;
	return nidx;
}
void push(int idx,int l,int r){
	int mid=(l+r)/2;
	Tree[idx].left=fix(Tree[idx].left,l,mid,Tree[idx].lazy);
	Tree[idx].right=fix(Tree[idx].right,mid+1,r,Tree[idx].lazy);
	Tree[idx].lazy=0;
}
void build(int idx,int st,int ed){ // 0th-version
	Tree[idx].lazy=0;
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
ll update(int idx,int l,int r,int s,int e,int x){
	if (l==s && r==e) return fix(idx,l,r,x);
	if (Tree[idx].lazy) push(idx,l,r);
	int nidx=avail++;
	Tree[nidx]=Tree[idx];
	int mid=(l+r)/2;
	if (e<=mid) Tree[nidx].left=update(Tree[idx].left,l,mid,s,e,x);
	else if (s>mid) Tree[nidx].right=update(Tree[idx].right,mid+1,r,s,e,x);
	else{
		Tree[nidx].left=update(Tree[idx].left,l,mid,s,mid,x);
		Tree[nidx].right=update(Tree[idx].right,mid+1,r,mid+1,e,x);
	}
	Tree[nidx].val=Tree[Tree[nidx].left].val+Tree[Tree[nidx].right].val;
	return nidx;
}
ll query(int idx,int l,int r,int s,int e){
	if (l==s && r==e) return Tree[idx].val;
	if (Tree[idx].lazy) push(idx,l,r);
	int mid=(l+r)/2;
	if (e<=mid) return query(Tree[idx].left,l,mid,s,e);
    else if (s>mid) return query(Tree[idx].right,mid+1,r,s,e);
    else{
        ll ans1=query(Tree[idx].left,l,mid,s,mid);
        ll ans2=query(Tree[idx].right,mid+1,r,mid+1,e);
        return (ans1+ans2);
    }
}