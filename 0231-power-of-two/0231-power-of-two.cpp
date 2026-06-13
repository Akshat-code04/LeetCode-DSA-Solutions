class Solution {
public:
    bool isPowerOfTwo(int n) { // O(logn)       
        if(n <= 0){
            return false;
        }
        while(n % 2 == 0){
            n = n/2;
        }
        if(n == 1){
            return true;
        }
        else{
            return false;
        }
    }
    // Approach 2
    bool approach2(int n) { // O(1)
        return (n > 0) && ((n & (n - 1)) == 0);
    }
};