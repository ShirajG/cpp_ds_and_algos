#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

vector<int> merge(vector<int> left, vector<int> right) {
  vector<int> returnVal;
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
      right.push_back(arr[i]);
    } else {
      left.push_back(arr[i]);
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

// vector<int> readFile(string fileName) {
//  ifstream file;
//  file.open(filename);
//  while(!file.eof()) {
//      /* code */
//  }
// }

int main() {
  vector<int> numArray;
  for (int i = 0; i < 11; ++i) {
    numArray.push_back(rand());
  }
  print_vector(numArray);
  cout << "=====================================" << endl;
  print_vector(mergeSort(numArray));
  return 0;
}
