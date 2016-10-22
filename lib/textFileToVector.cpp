#include <iostream>
#include <fstream>
#include <vector>

vector<int> main(string fileName) {
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
