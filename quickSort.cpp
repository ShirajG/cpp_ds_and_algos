#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

int choosePivot(int start, int end) {
  int pivot = start + (abs(end - start) / 2);
  cout << " Start: " << start << " End: " << end << " Pivot: " << pivot  << endl;
  return pivot;
}

void partition(vector<int>* numbers, int start, int end, int pivot) {
  cout << "Partitioning" << endl;
}

void quickSort(vector<int>* numbers, int start, int end) {
  if (start >= end) return;
  int pivot = choosePivot(start, end);
  partition(numbers, start, end, pivot);
  quickSort(numbers, start, pivot - 1);
  quickSort(numbers, pivot + 1, end);
}

int main() {
  vector<int> numbers = {1,2,3,4,5,6,7,8,9,10,11,12,13};
  quickSort(&numbers, 0, numbers.size());
  return 0;
}
