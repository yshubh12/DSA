// Brute
// TC: O(n^3)
// SC: O(2 * no. of triplets)

vector<vector<int>> threeSum(vector<int>& nums) {
    int n=nums.size();
    set<vector<int>> st;
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            for(int k=j+1; j<n; k++){
                if(nums[i]+nums[j]+nums[k]==0){
                    vector<int> temp={nums[i], nums[j], nums[k]};
                    sort(temp.begin(), temp.end());
                    st.insert(temp);
                }
            }
        }
    }
    vector<vector<int>> ans(st.begin(), st.end());
    return ans;
}


// Better -- Hashing
// TC: O(n^2 * log m)
// SC: O(n)

vector<vector<int>> threeSum(vector<int>& nums) {
    set<vector<int>> st;
    int n=nums.size();
    for(int i=0; i<n; i++){
        set<int> hashset;
        for(int j=i+1; j<n; j++){
            int third= -(nums[i]+nums[j]);
            if(hashset.find(third)!=hashset.end()){
                vector<int> temp={nums[i],nums[j], third};
                sort(temp.begin(), temp.end());
                st.insert(temp);
            }
            hashset.insert(nums[j]);
        }
    }
    vector<vector<int>> ans(st.begin(), st.end());
    return ans;
}


// Optimal
// TC: O(N log n) + O(N^2)

vector<vector<int>> threeSum(vector<int>& nums) {
    vector<vector<int> ans;
    int n=nums.size();
    for(int i=0; i<n; i++){
        if(i>0 && nums[i]==nums[i+1]) continue;
        int j=i+1;
        int k=n-1;
        while(j<k){
            int sum=nums[i]+nums[j]+nums[k];
            if(sum<0){
                j++;
            }
            else if(sum>0){
                k--;
            }
            else{
                vector<int> temp={nums[i], nums[j], nums[k]};
                ans.push_back(temp);
                j++;
                k--;
                while(j<k && nums[j]==nums[j-1]) j++;
                while(j<k && nums[k]==nums[k+1]) k--;
            }
        }
    }
    return ans;
}