// BINEXPO
// FACTORIAL
ll npr (int n,int r)
{
    if (r>n || r<0 || n<0) return 0;
    return (fact[n]*ifact[r])%M;
}
