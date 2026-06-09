class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        int row = matrix.size();
        int col = matrix[0].size();
        
        int count = 0;
        int total = row * col; // Total number of elements to process
        
        // Index initialization for 4 boundaries
        int startingRow = 0;
        int startingCol = 0;
        int endingRow = row - 1;
        int endingCol = col - 1;
        
        while (count < total) {
            
            // 1. Traverse from Left to Right along the starting row
            for (int index = startingCol; count < total && index <= endingCol; index++) {
                ans.push_back(matrix[startingRow][index]);
                count++;
            }
            startingRow++; // Move the top boundary down
            
            // 2. Traverse from Top to Bottom along the ending column
            for (int index = startingRow; count < total && index <= endingRow; index++) {
                ans.push_back(matrix[index][endingCol]);
                count++;
            }
            endingCol--; // Move the right boundary left
            
            // 3. Traverse from Right to Left along the ending row
            for (int index = endingCol; count < total && index >= startingCol; index--) {
                ans.push_back(matrix[endingRow][index]);
                count++;
            }
            endingRow--; // Move the bottom boundary up
            
            // 4. Traverse from Bottom to Top along the starting column
            for (int index = endingRow; count < total && index >= startingRow; index--) {
                ans.push_back(matrix[index][startingCol]);
                count++;
            }
            startingCol++; // Move the left boundary right
        }
        
        return ans;
    }
};