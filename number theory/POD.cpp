ll pod(int n){
    vector<pair<int,int>>v=factorize(n);
    ll product=1,d=1;
    for (auto [p,c]:v){
        ll val=bin_expo(p,c*(c+1)/2,M);
        product=(bin_expo(product,c+1,M)*bin_expo(val,d,M))%M;
        d=(d*(c+1))%(M-1);
    }
    return product;
}
