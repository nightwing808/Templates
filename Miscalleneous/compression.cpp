vector<ll>v;
v.push_back(val);
sort(all(v));
Unique(v);
lower_bound(all(v),val)-v.begin(); // 0-based search
