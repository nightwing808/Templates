ll sod(int n){
    vector<pair<int,int>>v=factorize(n);
    ll ans=1;
    for (auto [p,c]:v){
        ll x=bin_expo(p,c+1,M)-1+M;
        x%=M;
        ll y=bin_expo(p-1,M-2,M);
        x=(x*y)%M;
        ans=(ans*x)%M;
    }
    return ans;
}
