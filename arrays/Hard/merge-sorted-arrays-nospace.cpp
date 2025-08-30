// Merge two sorted arrays without using an extra space

// Method-1
class Solution {
public:
    void merge(vector<int>& arr1, int n, vector<int>& arr2, int m) {
        int left=n-1;
        int right= 0;
        while(left>=0 && right<m){
            if(arr1[left]>arr2[right]){
                swap(arr1[left],arr2[right]);
                left--, right++;
            }
            else break;
        }
        sort(arr1.begin(), arr1.end());
        sort(arr2.begin(), arr2.end());
    }
};

// Method-2
class Solution {
private:
    void swapIfGreater(vector<int>& arr1, int ind1, vector<int>& arr2, int ind2){
        if(arr1[ind1]>arr2[ind2]){
            swap(arr1[ind1], arr2[ind2]);
        }
    }


public:
    void merge(vector<int>& arr1, int n, vector<int>& arr2, int m) {
        int len=n+m;
        int gap=(len/2) + (len%2);

        while(gap>0){
            int left=0;
            int right=left+gap;
            while(right<len){
                // arr1 and arr2
                if(left<n && right>=n){
                    swapIfGreater(arr1,arr2, left, right-n);
                }
                else if(left>=n){
                    swapIfGreater(arr1,arr2, left-n, right-n);
                }
                else{
                    swapIfGreater(arr1, arr2, left, right);
                }
                left++;
                right++;
            }
            if(gap==1) break;
            gap=(len/2) + (len%2);
        }
    }
};