vector<pair<int,int>>factorize(int n){
    vector<pair<int,int>>v;
    while (n>1){
    	int c=0,p=spf[n];
    	while (n>1 && spf[n]==p){
    		n/=p,c++;
    	}
    	v.push_back({p,c});
    }
    return v;
}
