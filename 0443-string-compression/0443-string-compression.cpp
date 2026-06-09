class Solution {
public:
    int compress(vector<char>& chars) {
        int i = 0; // Iterator to traverse the whole array
        int ansIndex = 0; // Index to write the compressed characters in-place
        int n = chars.size();

        while (i < n) {
            int j = i + 1; // Start scanning for consecutive repeating characters

            // Move j forward until a different character is found or array ends
            while (j < n && chars[i] == chars[j]) {
                j++;
            }

            // Step 1: Store the current character at the writing index
            chars[ansIndex++] = chars[i];

            int count = j - i; // Calculate the total length of the current group

            // Step 2: If the character repeats, convert count to string and store its digits
            if (count > 1) {
                string cnt = to_string(count); // Convert number to string (e.g., 12 -> "12")
                for (char ch : cnt) {
                    chars[ansIndex++] = ch; // Store each digit of the count one by one
                }
            }

            // Step 3: Move the iterator 'i' to the next new character group
            i = j;
        }

        return ansIndex; // Return the new effective length of the compressed array
    }
};