vector<pair<int,int>>factorize(int n){
    vector<pair<int,int>v;
    for (int p:primes){
    	if (p*p>n) break;
    	if (n%p==0){
    		int c=0;
    		while (n%p==0) n/=p,c++;
            v.push_back({p,c});
    	}
    }
    if (n>1) v.push_back({n,1});
    return v;
}
