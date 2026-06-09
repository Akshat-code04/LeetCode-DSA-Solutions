class Solution {
public:
    bool checkEqual(int a[26], int b[26]) {
        for(int i = 0; i < 26; i++) {
            if(a[i] != b[i]) return false; // Mismatch found
        }
        return true; 
    }
    bool checkInclusion(string s1, string s2) {
     
        if(s1.length() > s2.length()) return false;

        int count1[26] = {0};
        
  
        for(int i = 0; i < s1.length(); i++) {
            int index = s1[i] - 'a';
            count1[index]++;
        }

        int i = 0;
        int windowSize = s1.length();
        int count2[26] = {0}; // Frequency array for current window in s2

        while(i < windowSize) {
            int index = s2[i] - 'a';
            count2[index]++;
            i++;
        }

        // Check if the first window matches s1's frequency
        if(checkEqual(count1, count2)) return true;

        // Slide the window forward across the remaining part of string s2
        while(i < s2.length()) {
            // Add the new character entering the window
            int newIndex = s2[i] - 'a';
            count2[newIndex]++;

            // Remove the old character leaving the window
            int oldIndex = s2[i - windowSize] - 'a';
            count2[oldIndex]--;

            i++; // Move window pointer forward

            // Check again if the current window matches s1's frequency
            if(checkEqual(count1, count2)) return true;
        }

        return false; // No permutation found in any window
    }
};