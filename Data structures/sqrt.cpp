ll a[N],b[N],u;
int n,m,sqsz;
void build(){
	for (int i=0;i<n;i+=sqsz){
		for (int j=i;j<min(n,i+sqsz);j++){
			b[j]=a[j];
		}
		sort(b+i,b+min(n,i+sqsz));
	}
}
void update(int pos,int k){
	a[pos]=k;
	int block=pos/sqsz;
	for (int j=block*sqsz;j<min(n,(block+1)*sqsz);j++){
		b[j]=a[j];
	}
	sort(b+(block*sqsz),b+min(n,(block+1)*sqsz));
}
int query(int l,int r,ll v){
	int st=min(r+1,((l+sqsz-1)/sqsz)*sqsz),ed=st;
	int ans=0;
	for (int j=st;j+sqsz-1<=r;j+=sqsz){
		ed=j+sqsz;
		ans+=lower_bound(b+j,b+ed,v)-(b+j);
	}
	for (int j=l;j<st;j++) ans+=(a[j]<v);
	for (int j=ed;j<=r;j++) ans+=(a[j]<v);
	return ans;
}
