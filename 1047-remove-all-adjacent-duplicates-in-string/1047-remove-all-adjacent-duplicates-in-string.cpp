class Solution {
public:
    string removeDuplicates(string s) {
        string ans = ""; // This string will act as our stack
        
        // Traverse through each character of the input string
        for(int i = 0; i < s.length(); i++) {
            
            // If ans is not empty and current char matches the last char of ans
            if(ans.length() > 0 && s[i] == ans.back()) {
                ans.pop_back(); // Remove the duplicate adjacent pair (Pop operation)
            } 
            else {
                ans.push_back(s[i]); 
            }
        }
        
        return ans; 
    }
};