ll nod(int n){
    vector<pair<int,int>>v=factorize(n);
    ll ans=1;
    for (auto [p,c]:v)
        ans=(ans*(c+1))%M;
    return ans;
}
