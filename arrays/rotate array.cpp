// Brute Force

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n= nums.size();
        k=k % n;
        vector<int> temp(k);
        for(int i=0; i<k; i++){
            temp[i]= nums[i];
        }
        for(int i=k; i<n; i++){
            nums[i-k]=nums[i];
        }
        for(int i=n-k; i<n; i++){
            nums[i]= temp[i-(n-k)];
        }
    }
};

// TC: O(3N)
// SC: O(k)




// Better Solution

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n= nums.size();
        vector<int> temp(n);
        for(int i=0; i<n; i++){
            temp[(i+k) % n]=nums[i];
            
        }
        nums=temp;
    }
};

// TC: O(N)
// SC: O(N)


// Optimal - Right rotate by K places

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n;
        
        reverse(nums.begin(), nums.end());

        reverse(nums.begin(), nums.begin()+k);

        reverse(nums.begin()+k, nums.end());
    }
};

// TC: O(N)
// SC: O(1)