#include<bits/stdc++.h>
vector<vector<int>> fourSum(vector<int> & nums, int target){
    int n=nums.size();
    set<vector<int>> st;
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            for(int k=j+1; k<n; k++){
                set<int> hashset;
                long long sum= nums[i] + nums[j];
                sum+=nums[k];
                long long l= target - sum;
                if(hashset.find(l)!=hashset.end()){
                    vector<int> temp = {nums[i], nums[j], nums[k], (int(l))};
                    sort(temp.begin(),temp.end());
                    st.insert(temp);
                }
                
                hashset.insert(nums[k]);
            }
        }
    }
    vector<vector<int>> ans(st.begin(), st.end());
    return ans;
}

/* T.C= N^3 + log m */