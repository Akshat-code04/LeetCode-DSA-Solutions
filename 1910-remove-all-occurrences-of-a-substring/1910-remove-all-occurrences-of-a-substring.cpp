class Solution {
public:
    string removeOccurrences(string s, string part) {

        // runs loop untill our string is not empty OR 'part' exist in our string 
        while(s.length() != 0 && s.find(part) < s.length()){ // s.find(part) --> returns the index of first occurrence of part from left to right in a string 

            s.erase(s.find(part), part.length()); // erase part.length characters from index once it is found 
        }
        return s;
    }
};