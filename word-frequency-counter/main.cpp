#include <iostream>
#include <unordered_map>
#include <string>
#include <fstream>
#include <cstring>

int main(int argc, char const *argv[]) {
  std::string fileName;
  std::unordered_map<std::string, int> wordCount;
  std::string highKey;
  int highValue = 0;

  if (argv[1] == NULL) {
    std::cout << "Input a file: ";
    std::cin >> fileName;
  } else {
    fileName = argv[1];
  }
  
  std::cout << "Reading file: " << fileName << std::endl;

  std::ifstream inputFile(fileName);

  if (inputFile.is_open()) {
    std::string word;

    while (inputFile >> word) {
      wordCount[word] += 1;
    }

    std::cout << "Frequencies: " << std::endl;
    for (auto& [key, value]: wordCount) {
      std::cout << "\"" << key << "\": " << value << std::endl;

      if (highValue < value) {
        highKey = key;
        highValue = value;
      }
    }

    std::cout << "Highest frequency is \"" << highKey << "\" with " << highValue << " words.\n";
  } else {
    std::cout << "File not found" << std::endl;
  }

  inputFile.close();
  return 0;
}
