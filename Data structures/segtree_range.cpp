struct node{
	ll sum,lazy;
}Tree[4*N];
void fix(int idx,int l,int r,int x){
    Tree[idx].lazy+=x;
    Tree[idx].sum+=x*(r-l+1);
}
void push(int idx,int l,int r){
    int mid=(l+r)/2,lft=idx*2,rgt=idx*2+1;
    fix(lft,l,mid,Tree[idx].lazy);
    fix(rgt,mid+1,r,Tree[idx].lazy);
    Tree[idx].lazy=0;
}
void build(int idx,int st,int ed,ll a[]){
	Tree[idx].lazy=0;
    if (st==ed){
        Tree[idx].sum=a[st];
        return;
    }
    int lft=idx*2,rgt=(idx*2)+1,mid=(st+ed)/2;
    build(lft,st,mid,a);
    build(rgt,mid+1,ed,a);
    Tree[idx].sum=(Tree[lft].sum+Tree[rgt].sum);
}
void update(int idx,int l,int r,int s,int e,int x){
    int mid=(l+r)/2,lft=idx*2,rgt=idx*2+1;
    if (l==s && r==e){
        fix(idx,l,r,x);
        return;
    }
    if (Tree[idx].lazy) push(idx,l,r);
    if (e<=mid) update(lft,l,mid,s,e,x);
    else if (s>mid) update(rgt,mid+1,r,s,e,x);
    else{
        update(lft,l,mid,s,mid,x);
        update(rgt,mid+1,r,mid+1,e,x);
    }
    Tree[idx].sum=(Tree[lft].sum+Tree[rgt].sum);
}
ll query(int idx,int l,int r,int s,int e){
    int mid=(l+r)/2,lft=idx*2,rgt=idx*2+1;
    if (l==s && r==e) return Tree[idx].sum;
    if (Tree[idx].lazy) push(idx,l,r);
    if (e<=mid) return query(lft,l,mid,s,e);
    else if (s>mid) return query(rgt,mid+1,r,s,e);
    else{
        ll ans1=query(lft,l,mid,s,mid);
        ll ans2=query(rgt,mid+1,r,mid+1,e);
        return (ans1+ans2);
    }
}