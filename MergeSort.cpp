#include <iostream>

using namespace std;

void printArray(int arr[], int n) {
	for(int i = 0; i < n; i++)
		cout << arr[i] << " ";
	cout << endl;
}

void merge(int* a, int low, int mid, int high) {
	int i = low, j = mid+1, k = low;
	int b[high];

	while(i <= mid && j <= high)
		b[k++] = (a[i] < a[j]) ? a[i++] : a[j++];

	while(i <= mid)
		b[k++] = a[i++];

	while(j <= high)
		b[k++] = a[j++];

	for(i = low; i < k; i++)
		a[i] = b[i];
}

void mergesort(int arr[], int low, int high) {
  if(low < high) {
    int mid = (high+low)/2;
    mergesort(arr,low,mid);
    mergesort(arr,mid+1,high);
    merge(arr,low,mid,high);
  }
}

int main(int argv, char** argc) {
	int n;
	cout << "How many elements in array?" << endl;
	cin >> n;

	int arr[n];
	
	cout << "Enter " << n << " elements:" << endl;
	for(int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	printArray(arr,n);

	mergesort(arr,0,n-1);
	printArray(arr,n);
}
