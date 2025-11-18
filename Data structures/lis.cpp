int lis(vector<int>&a,int n){
    vector<int>v;
    for (int i=0;i<n;i++){
        int p=lower_bound(all(v),a[i])-v.begin();
        if (p==v.size()) v.push_back(a[i]);
        else v[p]=a[i];
    }
    return v.size();
}
