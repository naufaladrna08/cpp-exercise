#include <iostream>
#include <queue>
#include <string>

struct task {
  std::string title;
  std::string description;
  int priority;
  bool isCompleted = false;
  
  // Overload the less-than operator for priority comparison
  bool operator<(const task& other) const {
    return priority < other.priority;
  }
};

typedef struct task task_t;

void inputTask(std::priority_queue<task_t>& taskList) {
  task_t t;

  std::cout << "Input task title: ";
  std::getline(std::cin, t.title);
  std::cout << "Input task description: ";
  std::getline(std::cin, t.description);
  std::cout << "Input task priority: ";
  std::cin >> t.priority;
  
  taskList.push(t);
}

void printTasks(std::priority_queue<task_t>& taskList) {
  while (!taskList.empty()) {
    task_t tk = taskList.top();

    std::cout << "Task: " << tk.title << std::endl;
    std::cout << "Description: " << tk.description << std::endl;
    std::cout << "Priority: " << tk.priority << std::endl;

    taskList.pop();
  }
}

int main(int argc, char const *argv[]) {
  std::priority_queue<task_t> taskList;
  
  std::string command;
  while (std::cin >> command) {
    if (command == "i") {
      inputTask(taskList);
    } else if (command == "p") {
      printTasks(taskList);
    }
  }

  return 0;
}
