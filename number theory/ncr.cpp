// BIN_EXPO
// FACTORIAL
int ncr(int n,int r)
{
    if (r>n || r<0 || n<0) return 0;
    ll up=fact[n];
    ll down=(ifact[r]*ifact[n-r])%M;
    return (up*down)%M;
}
