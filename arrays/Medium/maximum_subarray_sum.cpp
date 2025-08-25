// Kadane's Algorithm

long long maxSubArraySum(int arr[], int n){
    long long sum=0;
    maxi= INT_MIN;

    for(int i=0; i<n; i++){
        sum+=arr[i];
        if(sum>maxi){
            maxi=sum;
        }

        if(sum<0){
            sum=0;
        }
        if(maxi<0){
            maxi=0;
        }
    }
    return maxi;
}

// TC: O(N)
// SC: O(1)