#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

vector<int> numbers = {9, 8, 11, 13, 3, 10, 4, 5, 12, 6, 7};

void printArray(vector<int> arr) {
  for (int i = 0; i < arr.size(); i++) {
    cout << arr[i] << ", ";
  }
  cout << endl;
}

void partition(int start, int end) {
  int pivotVal = numbers[start];
  int seen = 0;
  int border = 0;
  int temp;
  cout << "Pivot is: " << pivotVal << endl;

  for (int i = start + 1; i <= end; i++) {
    cout << numbers[i] << endl;
    if (numbers[i] < pivotVal) {
      temp = numbers[i];
      numbers[i] = numbers[border + 1];
      numbers[border + 1] = temp;
      border++;
    }
  }

  temp = numbers[border];
  numbers[border] = pivotVal;
  numbers[start] = temp;

  printArray(numbers);
}

void quickSort(int start, int end) {
  cout << numbers.size() << endl;
  if (start >= end) return;
  // int pivotPosition = end;
  // int pivotValue = (*numbers)[pivotPosition];
  partition(start, end);
  // quickSort(numbers, start, pivotPostion - 1);
  // quickSort(numbers, pivotPosition + 1, end);
}

int main() {
  quickSort(0, numbers.size() - 1);
  return 0;
}
