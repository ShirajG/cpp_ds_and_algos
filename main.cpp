#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

vector<int> merge(vector<int> left, vector<int> right) {
  vector<int> returnVal;
  int inversionCount = 0;
  struct mergeResults {
    vector<int> merged;
    int inversionCount;
  };

  int i = 0;
  int j = 0;

  while(returnVal.size() < left.size() + right.size()) {
    if(left[i] <= right[j]){
      returnVal.push_back(left[i]);
      i++;
    } else {
      // inversion here
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

  while (getline(inputFile, line)) {
    int number = stoi(line);
    numbers.push_back(number);
  }

  return numbers;
}

int main() {
  vector<int> fileInput = readFile("text.txt");
  // for (int i = 0; i < 11; ++i) {
    // numArray.push_back(rand());
  // }
  // print_vector(fileInput);
  // cout << "=====================================" << endl;
  print_vector(mergeSort(fileInput));
  return 0;
}
