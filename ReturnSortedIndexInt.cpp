#include <stdio.h>
#include <math.h>

int getLength(int[] arr) {
  int count = 0;

  while(arr[count++] != NULL);

  return count;
}

//inclusive of startIndex and endIndex
int[] createNewArr(int[] arr, int startIndex, int endIndex) {
  int newArray[endIndex - startIndex + 1];
  int newIndex = 0;

  for(int i = startIndex; i <= endIndex; i++)
    newArray[newIndex++] = arr[i];

  return newArray;
}

int returnIndex(int[] arr, int n) {
  int size = getLength(arr);
  int answer;

  if(arr[ceil(size / 2)] == n) {
    return size / 2;
  } else if(arr[ceil(size / 2)] >  n)  {//if halfway is bigger than n
    answer = returnIndex(createNewArr(arr, 0, ceil(size/2) - 1), n);
  } else if(arr[ceil(size / 2)] < n) {//if halfway is smaller than n
    answer = returnIndex(createNewArr(arr, ceil(size/2) + 1, size - 1);
  } else {
    return -1; //integer not found
  }

  return answer;
}

int main(void) {
  int arr[10] = {2, 4, 6, 8, 10, 12, 14, 16, 18, 20};
  
  int index = returnIndex(arr, 6);

  if(index == -1) {
    printf("Integer not found.");
  } else {
    printf("%d", index);
  }
}
