const ll b1=87257,b2=27407,m1=1000004207,m2=1034558389;
ll p1[N],p2[N];
void Pow(){
    p1[0]=p2[0]=1;
    for (ll i=1;i<N;i++){
        p1[i]=(p1[i-1]*b1)%m1;
        p2[i]=(p2[i-1]*b2)%m2;
    }
}
struct Hash{
	int n;
	string s; // 0-indexed
	vector<ll>hs1,hs2,r1,r2; // 1-indexed
	Hash(){}
	Hash(string _s){
		n=_s.size();
		s=_s;
		hs1.resize(n+1,0);
		hs2.resize(n+1,0);
		for (int i=1;i<=n;i++){
			hs1[i]=hs1[i-1]*b1+s[i-1];
			hs1[i]%=m1;
			hs2[i]=hs2[i-1]*b2+s[i-1];
			hs2[i]%=m2;
		}
	}
	void rHash(){
		reverse(all(s));
		r1.resize(n+1,0);
		r2.resize(n+1,0);
		for (int i=1;i<=n;i++){
			r1[i]=r1[i-1]*b1+s[i-1];
			r1[i]%=m1;
			r2[i]=r2[i-1]*b2+s[i-1];
			r2[i]%=m2;
		}
	}
	ll get_hash(int l,int r){ // 1-indexed
		if (l>r) return -1;
		ll h1=hs1[r]-(hs1[l-1]*p1[r-l+1])%m1;
		h1=(h1+m1)%m1;
		ll h2=hs2[r]-(hs2[l-1]*p2[r-l+1])%m2;
		h2=(h2+m2)%m2;
		return (h1<<32LL)|h2;
	}
	ll get_rhash(int l,int r){ // 1-indexed
		if (l>r) return -1;
		ll h1=r1[r]-(r1[l-1]*p1[r-l+1])%m1;
		h1=(h1+m1)%m1;
		ll h2=r2[r]-(r2[l-1]*p2[r-l+1])%m2;
		h2=(h2+m2)%m2;
		return (h1<<32LL)|h2;
	}
	bool check_pal(int l,int r){
		return (get_hash(l,r)==get_rhash(n-r+1,n-l+1));
	}
};
