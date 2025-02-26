#include <iostream>
#include <deque> 
using namespace std;

void printKMax(int arr[], int n, int k){
	//Write your code here.
     deque<int> dq;
    
    // Process first k elements separately
    for (int i = 0; i < k; i++) {
        while (!dq.empty() && arr[dq.back()] <= arr[i]) {
            dq.pop_back();  // Remove smaller elements from the back
        }
        dq.push_back(i);  // Add the current element's index to the deque
    }
    
    // Process the rest of the elements
    for (int i = k; i < n; i++) {
        // The element at the front of the deque is the maximum for the previous window
        cout << arr[dq.front()] << " ";
        
        // Remove elements that are out of the current window
        while (!dq.empty() && dq.front() <= i - k) {
            dq.pop_front();
        }
        
        // Remove all elements smaller than the current element arr[i]
        while (!dq.empty() && arr[dq.back()] <= arr[i]) {
            dq.pop_back();
        }
        
        // Add the current element to the deque
        dq.push_back(i);
    }
    
    // The maximum for the last window is at the front of the deque
    cout << arr[dq.front()] << endl;
}



int main(){
  
	int t;
	cin >> t;
	while(t>0) {
		int n,k;
    	cin >> n >> k;
    	int i;
    	int arr[n];
    	for(i=0;i<n;i++)
      		cin >> arr[i];
    	printKMax(arr, n, k);
    	t--;
  	}
  	return 0;
}