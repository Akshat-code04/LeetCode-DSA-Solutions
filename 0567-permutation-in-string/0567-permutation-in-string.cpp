class Solution {
private:
    // checking both the arrays are equal or not 
    bool checkequal(int a[26], int b[26]){

        for(int i=0; i<26; i++){
            if(a[i] != b[i]){
                return false;
            }
        }
        return true;
    }
public:
    bool checkInclusion(string s1, string s2) {

        // if s1 is larger than s2 then permutation is not possible 
        if( s1.length() > s2.length() ){
            return false;
        }

        int countofs1[26] = {0};
        for(int i=0; i<s1.length(); i++){
            int index;
            index = s1[i] - 'a';
            countofs1[index]++;
        }

        int i=0;
        int windowsize = s1.length();
        int countofs2[26] = {0};

        // reading the first window of s1 length
        while(i < windowsize){
            int index;
            index = s2[i] - 'a';
            countofs2[index]++;
            i++;
        }
        // check array after reading the first window of size s1
        if( checkequal(countofs1,countofs2)){
            return true;
        }
        // checking for next window character by character 
        while(i < s2.length()){
            int index;

            // entering new character in reading window
            char newchar = s2[i];
            index = newchar - 'a';
            countofs2[index]++;
            
            // removing the old character from reading window 
            char oldchar = s2[i - windowsize];
            index = oldchar - 'a';
            countofs2[index]--;
            i++;

            // check array after entering newcharacter and removing old character 
            if( checkequal(countofs1, countofs2)){
                return true;
            }
        }
        return false; // still if we don't get our prmutation that means permutaion doesn't exist 
    }
};