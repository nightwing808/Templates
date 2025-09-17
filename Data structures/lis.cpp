int Lis(vector<int>&a,int n)
{
    //for LDS reverse vector a,then calculate
    //then reverse the ans array
    int lis=0;
    vector<int>ans;
    for (int i=0;i<n;i++)
    {
        auto p=lower_bound(all(ans),a[i]);
        if (p==ans.end()) ans.push_back(a[i]);
    }
    return lis;
}
