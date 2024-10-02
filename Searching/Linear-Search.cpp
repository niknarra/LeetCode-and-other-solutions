// Linear Search
// TC - O(n)

#include<bits/stdc++.h>
using namespace std;

bool targetInString(string s, char target){
	
	int l = s.size();

	for(int i = 0;i<l;i+=1){
		
		if(s[i] == target){
			
			return true;
			
		}
		
	}
	
	return false;
}


bool searchInRange(int arr[], int start, int end, int target){
	
	for(int i=start;i<=end;i+=1){
		
		if(arr[i] == target){
			
			return true;	
	
		}
		
	}
	
	return false;

}

int findMinMaxNumber(int arr[], int n){

	int ans = INT_MAX; // INT_MIN in case of max number
	
	for(int i=0;i<n;i+=1){

		if(arr[i] < ans){ // arr[i] > ans in case of max number
		
		ans = arr[i];
		
		}
	
	}

	return ans;
}

bool search2DArray(vector<vector<int>> arr, int target){
	
	for(int row=0;row<arr.size();row+=1){

		for(int col = 0; col<arr[row].size();col+=1){

			if(arr[row][col] == target){

				return true;
	
			}

		}

	}
	
	return false;
}



int main(){

	int arr[] = {1,2,3,4,5,65,911,230,918,69};
	int target = 69;

	for(int i=0;i<10;i+=1){
		if(arr[i] == target){
			cout<<i;
			break;
		}
	}

	string name = 'the boy';
	char target = 'y';

	cout<<targetInString(name, target);
	
	return 0;
}


