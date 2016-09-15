#include <iostream>

using namespace std;

void printArray(int* arr, int size) {
  for(int i = 0; i < size; i++) {
    if(i == 0)
      cout << "{";
    else
      cout << ", ";
    cout << arr[i];
  }
  
  cout << "}" << endl << endl;
}

void swap(int* a, int* b) {
  int temp;
  temp = *a;
  *a = *b;
  *b = temp;
}

void insertionSort(int* arr, int size) {
  for(int i = 0; i < size - 1; i++) {
    for(int j = i + 1; j > 0; j--) {
      if(arr[j] < arr[j-1]) {
        swap(&arr[j], &arr[j-1]);
        printArray(arr, size);
      } else {
        break;
      }
    }
  }
}

int main(int argv, char* argc[]) {

  int size;
  printf("Number of elements in array: ");
  cin >> size;

  if(size <= 0) {
    cout << "Array is empty." << endl << endl;
    return 0;
  }

  int arr[size];

  for(int i = 0; i < size; i++)
    cin >> arr[i];

  printArray(arr, size);

  insertionSort(arr, size);

  printArray(arr, size);

  return 0;
}
