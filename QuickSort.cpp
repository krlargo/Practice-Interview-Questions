#include <iostream>

using namespace std;

void printArray(int arr[], int n) {
	for(int i = 0; i < n; i++)
		cout << arr[i] << " ";
	cout << endl;
}

void quicksort(int* a, int low, int high) {
	if(low >= high)
		return;

	int i = low, j = high;
	int pivot = a[(high+low)/2];

	while(i <= j) {
		while(a[i] < pivot) i++;
		while(pivot < a[j]) j--;

		if(i <= j) {
			swap(a[i],a[j]);
			i++; j--;
		}
	}

	quicksort(a,low,j);
	quicksort(a,i,high);
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

	quicksort(arr,0,n-1);
	printArray(arr,n);
}
