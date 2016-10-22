#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

vector<int> reversedNumbers = {1,2,3,4,5};
vector<int> numbers = {4,5,2,5,7,9,2,1,7,9,12,0};

void printArray(vector<int> arr) {
  cout << "[ ";
  for (int i = 0; i < arr.size(); i++) {
    cout << arr[i];
    if (i < arr.size() - 1) {
      cout << ", ";
    }
  }
  cout << " ]" << endl;
}

void partition(int start, int end) {
  if (start >= end) {return;}

  int pivotVal = numbers[start];
  int seen = 0;
  int border = start;
  int temp;
  cout << "Pivot is: " << pivotVal << endl;

  for (int i = start + 1; i <= end; i++) {
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
  cout << "Border is :" << border << endl;
  partition(start, border - 1);
  partition(border + 1, end);
}

void quickSort(int start, int end) {
  if (start >= end) return;
  partition(start, end);
}

int main() {
  quickSort(0, numbers.size() - 1);
  cout << "Sorted Array is: ";
  printArray(numbers);
  return 0;
}
