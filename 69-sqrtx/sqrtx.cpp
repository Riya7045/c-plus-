class Solution {
public:
    int mySqrt(int x) {
        if (x == 0 || x == 1) return x; 
        int low = 1, high = x / 2, ans = 0;

        while (low <= high) {
            long long mid = low + (high - low) / 2; 
            long long square = mid * mid;

            if (square == x) return mid;
            else if (square < x) {
                ans = mid;  
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return ans; 
    }
};