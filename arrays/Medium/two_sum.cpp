// Brute force
// TC: O(n^2)

vector<int> twoSum(vector<int>& nums, int target) {
    for(int i=0; i<nums.size(); i++){
        for(int j=i+1; j<nums.size(); j++){
            if(nums[i]+nums[j]==target){
                return {i,j};
                
            }
        }
    } 
    return {0,0};
}


// Better
// TC: O(N * log n) with ordered map


vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> mp;  // number -> index
    for (int i = 0; i < nums.size(); i++) {
        int complement = target - nums[i];
        if (mp.find(complement) != mp.end()) {
            return {mp[complement], i};
        }
        mp[nums[i]] = i;
    }
    return {-1, -1};
}
