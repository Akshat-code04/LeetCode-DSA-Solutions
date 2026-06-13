class Solution {
public:
    int reverse(int x) {
        
        long long ans = 0;
        while(x!=0){
            int last_digit = x%10; // find out last digit 
            ans = (ans*10) + last_digit; // store ans*10 + last_digit in ans 
            x = x/10; // remove the last digit of the number 
        }
        // in case if ans value is out "int" range then return 0
        if(ans > INT_MAX || ans < INT_MIN){
            return 0;
        }
        return ans;
    }
};