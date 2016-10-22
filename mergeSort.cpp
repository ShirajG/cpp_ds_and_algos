#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

long inversionCount = 0;

vector<int> merge(vector<int> left, vector<int> right) {
  vector<int> returnVal;
  int i = 0;
  int j = 0;

  while (returnVal.size() < left.size() + right.size()) {
    if (left[i] <= right[j]) {
      returnVal.push_back(left[i]);
      i++;
    } else {
      inversionCount += left.size() - i;
      returnVal.push_back(right[j]);
      j++;
    }

    if (i == left.size()) {
      while (j < right.size()) {
        returnVal.push_back(right[j]);
        j++;
      }
    }

    if (j == right.size()) {
      while (i < left.size()) {
        returnVal.push_back(left[i]);
        i++;
      }
    }
  }

  return returnVal;
}

vector<int> mergeSort(vector<int> arr) {
  if (arr.size() < 2) {
    return arr;
  }

  vector<int> left;
  vector<int> right;
  for (int i = 0; i < arr.size(); ++i) {
    if (i < arr.size() / 2) {
      left.push_back(arr[i]);
    } else {
      right.push_back(arr[i]);
    }
  }
  return merge(mergeSort(left), mergeSort(right));
}

void print_vector(vector<int> v) {
  for (int i = 0; i < v.size(); i++) {
    cout << v[i] << endl;
  }
}

vector<int> reverseArray(vector<int> array) {
  vector<int> output;
  for (int i = array.size() - 1; i >= 0; i--) {
    output.push_back(array[i]);
  }
  return output;
}

vector<int> readFile(string fileName) {
  ifstream inputFile(fileName);
  string line;
  vector<int> numbers;
  int number;

  while (getline(inputFile, line)) {
    number = stoi(line);
    numbers.push_back(number);
  }

  return numbers;
}

int main() {
  vector<int> fileInput = readFile("int_array.txt");
  mergeSort(fileInput);
  cout << "Inversions: " << inversionCount << endl;
  return 0;
}
