vector<int> twoSum(vector<int>& nums, int target) {
        int a;
        int b;
     for(int i=0; i<nums.size(); i++){
        for(int j=i+1; j<nums.size(); j++){
            if(nums[i]+nums[j]==target){
                a=i;
                b=j;
                return {a,b};
                
            }
        }
     } 
     return {0,0};