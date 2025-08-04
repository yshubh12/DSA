// Brute Force
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        vector<int> temp;
        int n = nums.size();

        for(int i = 0; i<n; i++){
            if(nums[i] != 0){
                temp.push_back(nums[i]);
            }
        }

        int nz = temp.size();

        for(int i = 0; i<nz; i++){
            nums[i] = temp[i];
        }
        for(int i = nz; i<n; i++){
            nums[i] = 0;
        }
        
    }
};

// Time Complexity:O(n)
// Space Complexity:O(n)


// Optimal
class Solution{
public:
    void moveZeroes(vector<int> &arr){
        int n=arr.size();
        int j=-1;
        for(int i=0; i<n; i++){
            if(arr[i]==0){
                j=i;
                break;
            }
        }
        if(j!=0){
            for(int i=j+1; i<n; i++){
                if(arr[i]!=0){
                    swap(arr[i],arr[j]);
                    j++;
                }
            }
        }
    }

};

// TC = O(N)
// SC = O(1)