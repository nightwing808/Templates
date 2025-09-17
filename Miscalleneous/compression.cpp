int v[N]; // N=total number of elements
int C=0; // available index for new value
v[++C]=val // compression is 1 based
sort(v+1,v+1+C); // compression done
lower_bound(v+1,v+1+C,val)-v // find compressed value