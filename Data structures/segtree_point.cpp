struct node{
	ll sum;
}Tree[4*N];
void build(int idx,int st,int ed,int a[]){
    if (st==ed){
        Tree[idx].sum=a[st];
        return;
    }
    int lft=idx*2,rgt=(idx*2)+1,mid=(st+ed)/2;
    build(lft,st,mid,a);
    build(rgt,mid+1,ed,a);
    Tree[idx].sum=(Tree[lft].sum+Tree[rgt].sum);
}
void update(int idx,int st,int ed,int pos,int v){
    if (st==ed){
        Tree[idx].sum=v;
        return;
    }
    int lft=idx*2,rgt=(idx*2)+1,mid=(st+ed)/2;
    if (pos<=mid) update(lft,st,mid,pos,v);
    else update(rgt,mid+1,ed,pos,v);
    Tree[idx].sum=(Tree[lft].sum+Tree[rgt].sum);
}
ll query(int idx,int st,int ed,int l,int r){
    if (st==l && ed==r) return Tree[idx].sum;
    int lft=idx*2,rgt=(idx*2)+1,mid=(st+ed)/2;
    if (r<=mid) return query(lft,st,mid,l,r);
    else if (l>mid) return query(rgt,mid+1,ed,l,r);
    else{
        ll ans1=query(lft,st,mid,l,mid);
        ll ans2=query(rgt,mid+1,ed,mid+1,r);
        return (ans1+ans2);
    }
}
