class Solution {
private:
    void solve(string digits, string output, int index, vector<string> &ans, string mapping[]){

        // base case 
        if(index >= digits.length()){
            ans.push_back(output);
            return;
        }
        // recursive case 
        int number = digits[index] - '0';
        string value = mapping[number];
        for(int i=0; i<value.length(); i++){
            output.push_back(value[i]);
            solve(digits,output,index+1,ans,mapping);
            /// back tracking --> to make the output string empty again for next character 
            output.pop_back();
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        vector<string> ans;

        if(digits.length() == 0){
            return ans;
        }
                        //    0   1   2     3     4     5     6     7      8     9
        string mapping[10] = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};

        string output = "";
        int index = 0;

        solve(digits,output,index,ans,mapping);
        return ans;
        
    }
};