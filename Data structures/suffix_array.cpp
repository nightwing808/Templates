const int LG=18;
void induced_sort(const vector<int>&v,int VR,vector<int>&SA,const vector<bool>&sl,const vector<int>&LI){
  	vector<int>l(VR,0),r(VR,0);
  	for (int c:v){
    	if (c+1<VR) ++l[c + 1];
    	++r[c];
  	}
  	partial_sum(all(l),l.begin());
  	partial_sum(all(r),r.begin());
  	fill(SA.begin(),SA.end(),-1);
  	for (int i=LI.size()-1;i>=0;--i)
    	SA[--r[v[LI[i]]]]=LI[i];
  	for (int i:SA){
    	if (i>=1 && sl[i-1]) SA[l[v[i-1]]++]=i-1;
    }
  	fill(all(r),0);
  	for (int c:v) ++r[c];
  	partial_sum(all(r),r.begin());
  	for (int k=SA.size()-1,i=SA[k];k>=1;--k,i=SA[k]){
    	if (i>=1 && !sl[i-1]) SA[--r[v[i-1]]]=i-1;
    }
}
vector<int>SA_IS(const vector<int>&v,int VR){
  	const int n=v.size();
  	vector<int>SA(n),LI;
  	vector<bool>sl(n);
  	sl[n-1]=false;
  	for (int i=n-2;i>=0;--i){
    	sl[i]=(v[i]>v[i+1] || (v[i]==v[i+1] && sl[i+1]));
    	if (sl[i] && !sl[i+1]) LI.push_back(i+1);
  	}
  	reverse(all(LI));
  	induced_sort(v,VR,SA,sl,LI);
  	vector<int>NLI(LI.size()),LMV(LI.size());
  	for (int i=0,k=0;i<n;++i){
    	if (!sl[SA[i]] && SA[i]>=1 && sl[SA[i]-1]) NLI[k++]=SA[i];
    }
  	int cur=0;
	SA[n-1]=cur;
  	for (size_t k=1;k<NLI.size();++k) {
    	int i=NLI[k-1],j=NLI[k];
    	if (v[i]!=v[j]){
      		SA[j]=++cur;
    		continue;
    	}
    	bool flag=false;
    	for (int a=i+1,b=j+1;;++a,++b){
      		if (v[a]!=v[b]){
        		flag=true;
        		break;
      		}
      		if ((!sl[a] && sl[a-1]) || (!sl[b] && sl[b-1])){
        		flag=!((!sl[a] && sl[a-1]) && (!sl[b] && sl[b-1]));
        		break;
      		}
    	}
    	SA[j]=(flag?++cur:cur);
  	}
  	for (size_t i=0;i<LI.size();++i)
    	LMV[i]=SA[LI[i]];
  	if (cur+1<(int)LI.size()) {
    	auto LSA=SA_IS(LMV,cur+1);
    	for (size_t i=0;i<LI.size();++i)
    		NLI[i]=LI[LSA[i]];
  	}
  	induced_sort(v,VR,SA,sl,NLI);
  	return SA;
}
vector<int>suffix_array(const string &s,const int LIM=128){
  	vector<int>v(s.size()+1);
  	copy(all(s),v.begin());
  	v.back()='$';
  	auto ret=SA_IS(v,LIM);
  	ret.erase(ret.begin());
  	return ret;
}
struct SuffixArray{
  	int n;
  	string s;
  	vector<int>sa,rank,lcp,lg;
  	vector<vector<int>>t,y;
  	SuffixArray() {}
  	SuffixArray(string _s){
    	n=_s.size();
    	s=_s;
    	sa=suffix_array(s);
    	rank.resize(n);
    	for (int i=0;i<n;i++) rank[sa[i]]=i;
    	costruct_lcp();
    	build();
  	}
  	void costruct_lcp(){
    	int k=0;
    	lcp.resize(n,0);
    	for (int i=0;i<n;i++){
      		if (rank[i]==n-1){
        		k=0;
        		continue;
      		}
      		int j=sa[rank[i]+1];
      		while (i+k<n && j+k<n && s[i+k]==s[j+k]) k++;
      		lcp[rank[i]]=k;
      		if (k) k--;
    	}
  	}
  	void build(){
    	int sz=n;
    	t.resize(sz);
    	y.resize(sz);
    	for (int i=0;i<sz;i++){
      		t[i].resize(LG);
      		t[i][0]=sa[i];
      		y[i].resize(LG);
      		y[i][0]=lcp[i];
    	}
    	for (int i=1;i<LG;i++){
	        for (int j=0;j<n;j++){
	            if (j+(1<<i)-1>=n) break;
	            t[j][i]=min(t[j][i-1],t[j+(1<<(i-1))][i-1]);
	            y[j][i]=min(y[j][i-1],y[j+(1<<(i-1))][i-1]);
	        }
	    }
  	}
  	int querysa(int l,int r){ // minimum of sa[l], ..., sa[r]
  		int sz=r-l+1;
    	int msb=31-__builtin_clz(sz);
    	int ans=min(t[l][msb],t[r-(1<<msb)+1][msb]);
    	return ans;
  	}
  	int querylcp(int l,int r){ // minimum of sa[l], ..., sa[r]
  		int sz=r-l+1;
    	int msb=31-__builtin_clz(sz);
    	int ans=min(y[l][msb],y[r-(1<<msb)+1][msb]);
    	return ans;
  	}
  	int get_lcp(int i,int j){ // lcp of suffix starting from i and j
    	if (i == j) return n - i;
    	int l = rank[i], r = rank[j];
    	if (l > r) swap(l, r);
    	return querylcp(l, r - 1);
  	}
  	int lower_bound(string &t){
    	int l=0,r=n-1,k=t.size(),ans=n;
    	while (l<=r){
      		int mid=(l+r)>>1;
      		if (s.substr(sa[mid],min(n-sa[mid],k))>=t) ans=mid,r=mid-1;
      		else l=mid+1;
    	}
    	return ans;
	}
  	int upper_bound(string &t){
    	int l=0,r=n-1,k=t.size(),ans=n;
    	while (l<=r){
    	  	int mid=(l+r)>>1;
      		if (s.substr(sa[mid],min(n-sa[mid],k))>t) ans=mid,r=mid-1;
      		else l=mid+1;
    	}
    	return ans;
  	}
	// occurrences of s[p, ..., p + len - 1]
  	pair<int,int>find_occurrence(int p,int len){
		p=rank[p];
    	pair<int,int>ans={p,p};
    	int l=0,r=p-1;
    	while (l<=r){
      		int mid=(l+r)>>1;
      		if (querylcp(mid,p-1)>=len) ans.first=mid,r=mid-1;
      		else l=mid+1;
    	}
    	l=p+1,r=n-1;
    	while (l<=r){
      		int mid=(l+r)>>1;
      		if (querylcp(p,mid-1)>=len) ans.second=mid,l=mid+1;
      		else r=mid-1;
    	}
    	return ans;
  	}
};