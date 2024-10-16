#include <iostream>
#include <vector>
using namespace std;

int subArrayGenerator(vector<int> arr, int length){

    int ans = INT_MIN;

    for(int i=0;i<=(arr.size())-length;i+=1){
        int curr_sum = 0;
        for(int j=i;j<=(i+length)-1;j+=1){
            curr_sum += arr[j];
        }
        if(curr_sum>ans){
            ans = curr_sum;
        }
    }
    return ans;
}

int subArrayWSlidingWindow(vector<int> arr, int length){

    int left = 0;
    int right = 0;
    int curr_sum = 0;
    int ans = INT_MIN;

    while(right<arr.size()){
        curr_sum += arr[right];

        if(right - left + 1 == length){
            ans = max(ans, curr_sum);
            curr_sum -= arr[left];
            left += 1;
        }
        right += 1;
    }
    return ans;
}

int main(){

    vector<int> arr = {5,1,9,8,7};
    int subArrayLength = 3;

    cout<<subArrayWSlidingWindow(arr, subArrayLength);


    return 0;
}
