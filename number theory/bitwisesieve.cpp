int prime[N/64];
bool isPrime(int n){
    return !((prime[n/64]>>(n%64))&1);
}
void makeComp(int n){
    prime[n/64]|=(1LL<<(n%64));
}
void sieve(){
	makeComp(0);
	makeComp(1);
	for (int i=4;i<N;i+=2){
		makeComp(i);
	}
    for (int i=3;i*i<N;i+=2){
        if (isPrime(i)){
            for (int j=i*i,k=(i<<1);j<N;j+=k){
                makeComp(j);
            }
        }
    }
}
vector<pair<int,int>>factorize(int n){
    vector<pair<int,int>>ans;
    for (int i=0;i<=n/64;i++){
        if (i*64*i*64>n) break;
        for (int j=0;j<64;j++){
            if ((prime[i]>>j)&1) continue;
            int p=i*64+j;
            if (n%p==0){
				int c=0;
				while (n%p==0){
					n/=p;
					c++;
				}
				ans.push_back({p,c});
			}
        }
    }
    return ans;
}