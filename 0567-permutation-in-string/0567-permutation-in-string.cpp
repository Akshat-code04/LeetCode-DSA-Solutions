class Solution {
private:

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

        if( s1.length() > s2.length()){
            return false;
        }

        int countofs1[26] = {0};

        for(int i=0; i<s1.length(); i++) {
            int index;
            index = s1[i] - 'a';
            countofs1[index]++;
        }

        int i = 0;
        int windowsize = s1.length();
        int countofs2[26] = {0};

        while(i < windowsize && i < s2.length()){
            int index;
            index = s2[i] - 'a';
            countofs2[index]++;
            i++;
        }

        if( checkequal(countofs1, countofs2)){
            return true;
        }

        while(i < s2.length()){
            char newchar = s2[i];
            int index = newchar - 'a';
            countofs2[index]++;

            char oldchar = s2[i - windowsize];
            index = oldchar - 'a';
            countofs2[index]--;
            i++;

            if( checkequal(countofs1, countofs2)){
            return true;
            }
        }
        return false;
    }
};