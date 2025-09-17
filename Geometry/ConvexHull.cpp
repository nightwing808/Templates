int cross(pair<int,int>O,pair<int,int>A,pair<int,int>B){
	return (A.ff-O.ff)*(B.ss-O.ss)-(A.ss-O.ss)*(B.ff-O.ff);
}
vector<pair<int,int>>hull(vector<pair<int,int>>&v){
	int n=v.size();
	sort(all(v));
	vector<pair<int,int>>lo,up;
	for (auto p:v){
		while (lo.size()>=2 && cross(lo[lo.size()-2],lo.back(),p)<=0){
			lo.pop_back();
		}
		lo.push_back(p);
	}
	for (int i=n-1;i>=0;i--){
		auto &p=v[i];
		while (up.size()>=2 && cross(up[up.size()-2],up.back(),p)<=0){
			up.pop_back();
		}
		up.push_back(p);
	}
	lo.pop_back();
	up.pop_back();
	vector<pair<int,int>>h=lo;
	for (auto p:up) h.push_back(p);
	reverse(all(h));
	h.push_back(h[0]);
	return h;
}