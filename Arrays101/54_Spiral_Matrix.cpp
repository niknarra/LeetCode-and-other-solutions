// There is only one approach for this problem
// TC: O(n * m)
// SC: O(n * m)

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int columns = matrix[0].size();

	// Vector to store answer
        vector<int> ans;

        int top = 0, left = 0;
        int right = columns - 1;
        int bottom = rows - 1;

	// To loop through until there are enough rows and columns
        while (top <= bottom && left <= right) {
            // left->right
            for (int i = left; i <= right; i += 1) {
                ans.push_back(matrix[top][i]);
            }
	    // Move one row down
            top++;

            // top->bottom
            for (int i = top; i <= bottom; i += 1) {
                ans.push_back(matrix[i][right]);
            }
	    // Move one column to the left
            right--;

            if (top <= bottom) { // To avoid repetetive numbers
                // right->left
                for (int i = right; i >= left; i -= 1) {
                    ans.push_back(matrix[bottom][i]);
                }
		// Move one row up
                bottom--;
            }

            if (left <= right) { // To avoid reetetive numbers
                // bottom->top
                for (int i = bottom; i >= top; i -= 1) {
                    ans.push_back(matrix[i][left]);
                }
	        // Move one column to the right
                left++;
            }
        }

        return ans;
    }
};

