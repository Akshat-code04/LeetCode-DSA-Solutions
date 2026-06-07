class Solution {
public:
    // checking valid character 
    bool isvalid(char ch){
        if((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9')){
            return 1;
        }
        return 0;
    }
    // lower case convesion function
    char tolower(char ch){
        if((ch >= 'a' && ch <= 'z') || (ch >= '0' && ch <= '9')){
            return ch;
        }
        else{
            char temp = ch - 'A' + 'a';
            return temp;
        }
    }
    bool checkpalindrome(string a){
        int start = 0;
        int end = a.length()-1;

        while(start <= end){
            if(a[start] != a[end]){
                return 0;
            } 
            else{
                start++;
                end--;
            }
        }
        return 1;
    }
    bool isPalindrome(string s) {
        string temp = "";
        // check valid character
        for(int i = 0; i < s.length(); i++){
            if(isvalid(s[i])){
                temp.push_back(tolower(s[i]));
            }
        }

        // lower case character
        for(int i = 0; i < temp.length(); i++){
            temp[i] = tolower(temp[i]);
        }
        return checkpalindrome(temp);
    }
};