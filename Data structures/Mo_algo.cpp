struct query{
	int l,r,ind;
};
query qs[N];
const int sqsz=max(int(sqrt(N)),1);
bool cmp(query a,query b){
	if (a.l/sqsz!=b.l/sqsz) return a.l<b.l;
	return (a.l/sqsz & 1)?(a.r>b.r):(a.r<b.r);
}
int a[N],ans[N],c;
int freq[N],mp[N];
void add(int ind){
	freq[mp[a[ind]]--;
	mp[a[ind]]++;
	freq[mp[a[ind]]++;
	if (mp[a[ind]]==1) c++;
}
void remove(int ind){
	freq[mp[a[ind]]--;
	mp[a[ind]]--;
	freq[mp[a[ind]]++;
	if (mp[a[ind]]==0) c--;
}
void Mo(int q){
	int l=1,r=1;
	c=0;
	freq[0]=n;
	for (int i=0;i<q;i++){
		while (r<=qs[i].r) add(r++);
		while (r-1>qs[i].r) remove(--r);
		while (l<qs[i].l) remove(l++);
		while (l>qs[i].l) add(--l);
		ans[qs[i].ind]=c;
	}
}
