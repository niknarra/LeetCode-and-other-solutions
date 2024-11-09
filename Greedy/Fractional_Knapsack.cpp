// Greedy Approach
// TC: O(N logN) -> N for loops, log N for sorting
// SC: O(N)

class Solution {
  public:
    // Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(vector<int>& val, vector<int>& wt, int capacity) {
        // Early return case, if the total weight is less than or equal to capacity,
	double total_wt = 0;
        double total_val = 0;
        
	for(auto it:wt){
            total_wt += it;
        }
        
	if(total_wt <= capacity){
            for(auto it:val){
                total_val += it;
            }
            return total_val; // Sum the total values and return
        }
        
	// Main case where we need to fill the knapsack optimally
	int i = 0;
        vector<pair<double, int>> unit_wts; // Vector to store per unit values and the total weight
        
        while(i<val.size()){
            double unit_wt = static_cast<double>(val[i]) / wt[i]; // Cast the per unit wt into double
            unit_wts.push_back({unit_wt, wt[i]}); // Fill the vector
            i += 1;
        }
        
	sort(unit_wts.rbegin(), unit_wts.rend()); // Sort the vector in descending order -> Greedy Algo
        
	for(auto it:unit_wts){
            if(it.second <= capacity){ // Case 1: If the current wt is less than or equal to curr capacity
                total_val += it.first*it.second; // Get the total wt and add it to ans
                capacity = capacity - it.second; // Update the total capacity
            }
            else{
                total_val = total_val + (it.first * capacity); // If capacity is less, calculate the fractional value
                break; // As capacity will be at max, break out
            }
        }
        return total_val;
    }
};

