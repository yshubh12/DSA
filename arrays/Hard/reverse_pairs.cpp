class Solution {
private:
    int cntPairs(vector<int> &arr, int low, int mid, int high){
        int right=mid+1;
        int cnt=0;
        for(int i=low; i<=mid; i++){
            while(right<=high && (long long)arr[i]> 2LL*arr[right]) right++;
            cnt+= (right-(mid+1));
        }
        return cnt;
    }
    int merge_sort(vector<int> &arr, int low, int high){
        int cnt=0;
        if(low>= high) return cnt;
        int mid = (low + high)/2;
        cnt+=merge_sort(arr, low, mid);
        cnt+=merge_sort(arr, mid+1, high);
        cnt+=cntPairs(arr, low, mid, high);
        merge(arr, low, mid, high);
        return cnt;
    }

    void merge(vector<int> &arr, int low, int mid, int high){
        vector<int> temp;
        int left=low;
        int right=mid+1;

        while(left<=mid && right<=high){
            if(arr[left]<=arr[right]){
                temp.push_back(arr[left]);
                left++;
            }
            else{
                temp.push_back(arr[right]);
                right++;
            }

        }

        while(left<=mid){
            temp.push_back(arr[left]);
            left++;
        }
        while(right<=high){
            temp.push_back(arr[right]);
            right++;
        }
        for(int i=low; i<=high; i++){
            arr[i]= temp[i - low];
        }
    }
public:
    int reversePairs(vector<int>& arr) {
        int n=arr.size();
        return merge_sort(arr, 0, n-1);
    }
};