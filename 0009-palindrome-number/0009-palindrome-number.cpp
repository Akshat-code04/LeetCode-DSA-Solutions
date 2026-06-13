class Solution {
public:
    bool isPalindrome(int x) {
        long long ans = 0;
        int original = x;
        if(x < 0){
            return false;
        }

        while(x!=0){
            int last_digit = x%10; // store the last digit 
            ans = (ans*10) + last_digit; 
            x = x/10;
        }
        if(ans == original){
            return true;
        }
        else{
            return false;
        }
    }
};