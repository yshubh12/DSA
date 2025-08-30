// Find repeating and missing number

// TC: O(n)
// SC: O(1)

vector<int> findMissingAndRepeating(vector<int> & a){
    long long n=a.size();

    long long SN= (n * (n+1))/2;
    long long S2N= (n * (n+1) * (2n+1))/6;
    long long S=0, S2=0;
    for(int i=0; i<n; i++){
        S+=a[i];
        S2+= (long long)a[i] * (long long)a[i];
    }
    long long val1= S-SN; //x+y
    long long val2= S2-S2N;
    val2= val2/val1;  //x-y
    long long x= (val1+val2)/2;
    long long y= x-val1;

    return {(int)x, (int)y};
}