class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size();
        int col = matrix[0].size();
        
        int start = 0;
        int end = (row * col) - 1; // Treat the 2D matrix as a flat 1D array
        
        int mid = start + (end - start) / 2; // Prevent integer overflow
        
        while (start <= end) {
            // Formula to map 1D index 'mid' back to 2D matrix coordinates
            int element = matrix[mid / col][mid % col];
            
            if (element == target) {
                return true; // Target element found
            }
            
            if (element < target) {
                start = mid + 1; // Go to the right half
            } 
            else {
                end = mid - 1; // Go to the left half
            }
            
            mid = start + (end - start) / 2; // Recalculate mid for the next iteration
        }
        
        return false; // Target not found in the matrix
    }
};