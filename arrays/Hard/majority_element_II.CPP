vector<int> majorityElement(vector<int>& nums) {
        
    int n=nums.size();
    vector<int> ans;
    map<int,int> mpp;
    int mini= (n/3)+1;
    for(int i=0; i<nums.size(); i++){
        mpp[nums[i]]++;

        if(mpp[nums[i]]==mini){
            ans.push_back(nums[i]);
        }
        if(ans.size()==2) break;
    }
    return ans;  
}

// TC: O(n)
// SC: O(n)


// Optimal

vector<int> majorityElement(vector<int>& a) {
    int el1=INT_MIN, el2=INT_MIN;
    int cnt1=0, cnt2=0;
    int n=a.size();

    for(int i=0; i<n; i++){
        if(cnt1==0 && a[i]!=el2){
            el1=a[i];
            cnt1=1;
        }
        else if(cnt2==0 && a[i]!=el1){
            el2=a[i];
            cnt2=1;
        }
        else if(a[i]==el1) cnt1++;
        else if(a[i]==el2) cnt2++;
        else{
            cnt1--;
            cnt2--;
        }
    }

    cnt1=0, cnt2=0;
    vector<int> ans;
    int mini=(n/3) +1;
    for(int i=0; i<n; i++){
        if(a[i]==el1) cnt1++;
        if(a[i]==el2) cnt2++;
    }
    if(cnt1>=mini) ans.push_back(el1);
    if(cnt2>=mini) ans.push_back(el2);

    return ans;
}

// TC: O(n)
// SC: O(1)