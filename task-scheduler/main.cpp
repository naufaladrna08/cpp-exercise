#include <iostream>
#include <queue>
#include <string>
#include <unordered_map>

int main(int argc, char const *argv[]) {
  std::priority_queue<int> mapKey;
  std::unordered_map<int, std::string> taskList;

  std::string command;
  while (std::cin >> command) {
    if (command == "p") {
      std::cout << "Task List: " << std::endl;

      while (!mapKey.empty()) {
        std::cout << taskList[mapKey.top()] << " [" << mapKey.top() << "]" << std::endl;
        mapKey.pop();
      }

    } else if (command == "i") {
      std::string name;
      int priority;

      std::cout << "Input task title: ";
      std::cin >> name;
      std::cout << "Input task priority: ";
      std::cin >> priority;

      mapKey.push(priority);
      taskList[priority] = name;
    }
  }

  std::cout << std::endl;
  return 0;
}
