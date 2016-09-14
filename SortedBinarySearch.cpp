#include <stdio.h>
#include <math.h>

#include<iostream>

using namespace std;

//inclusive of startIndex and endIndex
int* createNewArr(int* arr, int* newArray, int startIndex, int endIndex) {
  if(endIndex < startIndex)
    return NULL;

//  int* newArray = new int[endIndex - startIndex + 1];
  int newIndex = 0;

  for(int i = startIndex; i <= endIndex; i++) {
    newArray[newIndex++] = arr[i];
  }

  return newArray;
}

void printArray(int* arr, int size) {
  for(int i = 0; i < size; i++) {
    if(i == 0)
      printf("{");
    else
      printf(", ");
    printf("%d", arr[i]);
  }
  printf("}\n");
}

int returnIndex(int* arr, int n, int size) {
  int index;
  int newStartIndex = 0;
  int newEndIndex = 0;
  int middle = (int)ceil(size / 2);

  int* newArr;

  printArray(arr, size);

  if(size == 1) {
    if(arr[0] != n)
      return -1;
    else
      return 0;
  }

  if(arr[middle] == n) {
    index = middle;
  } else if(arr[middle] >  n) {//if halfway is bigger than n
    newStartIndex = 0;
    newEndIndex = middle - 1;

    newArr = new int[newEndIndex - newStartIndex + 1];

    index = returnIndex(createNewArr(arr, newArr, newStartIndex, newEndIndex), n, newEndIndex - newStartIndex + 1);
    
    delete[] newArr;
  } else if(arr[middle] < n) {//if halfway is smaller than n
    newStartIndex = middle + 1;
    newEndIndex = size - 1;

    newArr = new int[newEndIndex - newStartIndex + 1];

    index = middle + 1 + returnIndex(createNewArr(arr, newArr, newStartIndex, newEndIndex), n, newEndIndex - newStartIndex + 1);

    delete[] newArr;
  }

  return index;
}

int main(void) {

  int element;

  int size;
  printf("Number of elements in array: ");
  scanf("%d", &size);

  int arr[size];

  for(int i = 0; i < size; i++) {
    scanf("%d", &arr[i]);
  }

  printArray(arr, size);
  printf("Enter element to find: ");
  scanf("%d", &element);

  int index = returnIndex(arr, element, size);

  if(index == -1) {
    printf("Integer not found.");
  } else {
    printf("Integer found in index [%d]\n\n", index);
  }
}
