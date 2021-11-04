/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is lower than the guess number
 *			      1 if num is higher than the guess number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        int low = 1, high=n, mid, res;
        while(low <= high){
            mid = low + (high-low)/2;
            res = guess(mid);
            if(res < 0)
                high = mid -1;
            else if(res > 0)
                low = mid+1;
            else
                return mid;
            
        }
        return -1;  
    }
};