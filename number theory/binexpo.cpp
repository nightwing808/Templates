ll bin_expo(ll x,ll y,ll m){
    ll ans=1;
    while (y){
        if (y & 1LL) ans=(ans*x)%m;
        x=(x*x)%m;
        y>>=1LL;
    }
    return ans;
}
