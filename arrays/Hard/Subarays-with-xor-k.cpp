int subarraysWithXorK(vector<int> &arr, int k){
    int xr=0;
    int n=arr.size();
    map<int, int> mpp;
    mpp[xr]++; // {0,1}
    int cnt=0;
    for(int i=0; i<n; i++){
        xr=xr^arr[i];
        int x=xr-k;
        cnt+=mpp[x];
        mpp[xr]++;
    }
    return cnt;
}

// TC: O(n)