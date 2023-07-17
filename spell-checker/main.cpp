#include <iostream>
#include <cstdio>
#include <string>
#include <unordered_set>
#include <algorithm>
#include <fstream>

std::string toLower(const std::string& word) {
  std::string lowercase;
  std::string letter;

  for (int i = 0; i < word.size(); i++) {
    lowercase.push_back(std::tolower(word[i]));
  }

  return lowercase;
}

int main(int argc, char const *argv[]) {
  std::unordered_set<std::string> words;

  if (argv[1] == nullptr) {
    printf("Please provide a file for words dictionary\n");
    return 0;
  }

  /* Karena mungkin 'words' akan banyak maka akan kita import
   * Lewat file. 
   */
  std::ifstream fileStream(argv[1]);

  if (fileStream.is_open()) {
    std::string word;
    
    while (fileStream >> word) {
      words.insert(word);
    }
  } else {
    printf("File not found: %s\n", argv[1]);
  }

  /* Sekarang harusnya words sudah ada isinya dan kita bisa
   * langsung check word input menggunakan words yg sudah ada
   * pada kamus (words). 
   */
  std::string input;

  while (std::cin >> input) {
    if (words.find(input) == words.end()) {
      std::cout << "Mispelled word: " << input << std::endl;
    }
  }
  
  return 0;
}
