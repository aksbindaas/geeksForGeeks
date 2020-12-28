#include <iostream>
using namespace std;

// first approach O(n^2)
void findSubarrayIndexofSumWorstCase(const int *A, const int length, const int sum) {
    int i, j;
    for (i = 0; i<length ; i++) {
        int localSum = 0;
        for (j=i; (localSum <= sum) && j<length;j++) {
            localSum += A[j];
            if(localSum == sum ) {
                cout<<i+1<<" "<<j+1<<endl;
                return;
            }
        }
    }
    cout<<-1<<endl; 
}


// Second approach is with sliding window O(n)
void findSubarrayIndexofSumBestCase(const int *A, const int length, const int sum) {
    int current_sum = 0, start=0;
    
    for (int i = 0; i<length ; i++) {
        current_sum += A[i];
        while (current_sum > sum && start < i) {
            current_sum -= A[start];
            start++;
        }
        
        if(current_sum == sum) {
            cout<< start+1<< " "<<i+1<<endl;
            return;
        }
    }
    cout<<-1<<endl;
}

int main() {
	int T;
	cin >> T;
	while (T--) {
	    int length,sum;
	    cin >> length >> sum;
	    int A[length];
	    for (int i=0; i< length; i++) {
	         cin >> A[i];
	    }
	    findSubarrayIndexofSumWorstCase(A, length, sum);
        findSubarrayIndexofSumBestCase(A, length, sum);
	}
	return 0;
}