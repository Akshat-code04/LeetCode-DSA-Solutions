class Solution {
public:
    string removeDuplicates(string s) {

        string ans = ""; // creating empty string to store non-duplicate characters 

        for(int i=0; i<s.length(); i++){
            // their must be atleast one character in ans string & ans top[first] character is duplicate of original string character then remove that duplicate character 
            if(ans.length() > 0 && ans.back() == s[i]){ 
                ans.pop_back();
            }
            // if no duplicates then push orignal string charater in ans string
            else{
                ans.push_back(s[i]);
            }
        }
        return ans;
    }
};