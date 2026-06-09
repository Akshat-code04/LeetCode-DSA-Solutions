class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size();
        int col = matrix[0].size();
        
        // Start from the top-right corner of the matrix
        int rowIndex = 0;
        int colIndex = col - 1;
        
        // Loop runs until pointers stay inside the matrix boundaries
        while (rowIndex < row && colIndex >= 0) {
            int element = matrix[rowIndex][colIndex];
            
            // Check if current element is the target
            if (element == target) {
                return true; 
            }
            
            // If element is smaller than target, move down to the next row (larger numbers)
            if (element < target) {
                rowIndex++;
            } 
            // If element is greater than target, move left to the previous column (smaller numbers)
            else {
                colIndex--;
            }
        }
        
        return false; // Target not found after complete search
    }
};