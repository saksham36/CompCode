class Solution {
public:
    int mySqrt(int x) {
        if(x<=1) return x;
        int low = 1;
        int high = x;
        long long mid = low + (high-low)/2;
        int ans = 0;
        while(low<=high){
            // cout<<"low: "<<low<<" mid: "<<mid<<" high: "<<high<<endl;
            if(mid*mid == x) return mid;
            else if(mid*mid > x) high = mid-1;
            else{ 
                    ans = mid;
                    low = mid+1;
                }
            
            mid = low + (high-low)/2;
        }
        return ans;
    }
};