#include<iostream>
using namespace std;

// Recursion Examples from 0 -> Mastery

// 1. Print n -> 1
void nReducer(int n){
    if(n == 0){
        return;
    }
    cout<<n<<" ";
    nReducer(n-1);
}

// 2. Print 1 -> n
void nIncrementer(int n){
    if(n == 5){
        cout<<n;
        return;
    }
    cout<<n<<" ";
    nIncrementer(n+1);
}

// or, we can use reducer to print 1->n like so
void nReducerMod(int n){
    if(n == 0){
        return;
    }
    nReducerMod(n-1);
    cout<<n<<" ";
}

// 3. Print Factorial
int factorial(int n){
    if(n <= 1){
        return 1;
    }
    return n*factorial(n-1);
}

// 4. Print Sum from n -> 1
int getSum(int n){
    if(n == 1){
        return 1;
    }
    return n+getSum(n-1);
}

// 5. Print Sum of digits
int sumOfDigits(int n){
    if(n < 10){
        return n;
    }
    return n%10 + sumOfDigits(n/10);
}

// 6. Print Product of digits
int prodOfDigits(int n){
    if(n < 10){
        return n;
    }
    return n%10 * prodOfDigits(n/10);
}

// 7. Reverse a number
int reverser(int n){
    if(n < 10){
        return n;
    }
    return (n%10)*10 + reverser(n/10);
}

// 8. Reverse a string
string stReverser(string s){
    if(s.size() == 1) return s;

    return s.back() + stReverser(s.substr(0, s.length() - 1));
}

// 9. Check if an array is sorted
bool checkArrHelper(vector<int> nums, int i){
    if(i >= nums.size()){
        return true;
    }
    if(nums[i] < nums[i-1]){
        return false;
    }
    return checkArrHelper(nums, i+1);
}

bool checkArr(vector<int> nums){
    return checkArrHelper(nums, 1);
}

// 10. Linear Search
// Approach 1
bool searcher(vector<int>& nums, int target, int i){
    if(i == nums.size()) return false;

    return nums[i] == target || searcher(nums, target, i+1);
}
// Approach 2
bool searcher(vector<int>& nums, int target, int i){
    if(i == nums.size()) return false;

    if(nums[i] == target) return true;

    return searcher(nums, target, i+1);
}

// 11. Searching for index of target(s)
// Optimal Approach -> Pass ans as a parameter
vector<int> multipleSearcher(vector<int>& nums, vector<int>& ans, int target, int i){
    if(i == nums.size()) return ans;

    if(nums[i] == target) ans.push_back(i);

    return multipleSearcher(nums, ans, target, i+1);
}
//Approach 2 -> Create new lists and merge while returning
vector<int> multipleSearcher2(vector<int>& nums, int target, int i) {
    vector<int> ans; // To store results for the current recursion level

    // Base Case: If we reach the end of the array, return an empty vector
    if (i == nums.size()) return ans;

    // Check if the current index matches the target
    if (nums[i] == target) ans.push_back(i);

    // Recursive Call: Get results from the rest of the array
    vector<int> next = multipleSearcher2(nums, target, i + 1);

    // Merge the results of this level (`ans`) with results from the rest (`next`)
    ans.insert(ans.end(), next.begin(), next.end());

    // Return the merged vector
    return ans;
}

// 12. Binary Search
bool binSearch(vector<int>& nums, int target, int start, int end){

    if(start > end) return false;

    int mid = (start + end)/2;

    if(nums[mid] == target) return true;

    if(nums[mid] > target) return binSearch(nums, target, start, mid-1);

    else return binSearch(nums, target, mid+1, end);
}

// 13. Pattern Printer
// Approach 1
void patternPrinter(int n){
    if(n == 0) return;

    for(int i=0;i<n;i+=1){
        cout<<"*"<<" ";
    }
    cout<<endl;
    patternPrinter(n-1);
}

// Approach 2
void patternPrinter2(int row, int col){
    if(row == col) return;

    for(int i=0;i<=col;i+=1){
        cout<<"*"<<" ";
    }
    cout<<endl;
    patternPrinter2(row,col+1);
}

int main() {
    cout<<"Recursion"<<endl;

    // nReducer(5);
    // cout<<endl;
    // nIncrementer(1);
    // cout<<endl;
    // cout<<factorial(5);
    cout<<reverser(123);

    return 0;
}
