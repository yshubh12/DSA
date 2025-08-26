// Brute Force

vector<int> leadersInArray(vector<int> &a){
    vector<int> ans;
    
    for(int i=0; i<a.size(); i++){
        bool flag=true;
        for(int j=i+1; j<a.size(); j++){
            if(a[i]<a[j]){
                flag=false;
                break;
            }
            if(flag==true){
                ans.push_back(a[i]);
            }
        }
        return ans;
    }
}
// TC: O(N^2)
// SC: O(N)


// Optimal

vector<int> leadersInArray(vector<int> &a){
    // SC: O(N)
    vector<int> ans;
    int maxi=INT_MIN;
    // TC: O(N)
    for(int i=a.size()-1; i>=0; i--){
        if(a[i]>maxi){
            ans.push_back(a[i]);
        }
        maxi= max(maxi, a[i]);
    }
    
    // TC: O(N log N)
    sort(ans.begin(), ans.end());
    return ans;
}