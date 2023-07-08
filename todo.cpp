//********************************************************************
//
//                      https://ataim9999/todo-list
//
//
//                    ████████  ██████  ██████   ██████  
//                       ██    ██    ██ ██   ██ ██    ██ 
//                       ██    ██    ██ ██   ██ ██    ██ 
//                       ██    ██    ██ ██   ██ ██    ██ 
//                       ██     ██████  ██████   ██████  
//
//
//  This project is made to learn more about c++
//  I used youtube on this
//  Everyone is allowed to use and modify it
//
//
//********************************************************************





#include <iostream>
#include <string>
#include <list>
#include <cstdlib>
#include <ctime>

class TodoItem {
private:
    int id;
    std::string description;
    bool completed;

public:
    TodoItem() : id(0), description(""), completed(false) {}
    ~TodoItem() = default;

    void create(std::string new_description) {
        id = rand() % 100 + 1;
        description = new_description;
    }

    int getId() const { return id; }
    std::string getDescription() const { return description; }
    bool isCompleted() const { return completed; }

    void setCompleted(bool val) { completed = val; }
};

int main() {
    char input_option;
    int input_id;
    std::string input_description;
    std::list<TodoItem> todoItems;
    std::string version = "v1.0.0";
    std::list<TodoItem>::iterator it;

    srand(static_cast<unsigned int>(time(NULL)));

    while (true) {
        system("cls");
        std::cout << "Todo List Maker - " << version << std::endl << std::endl;

        for (const auto& item : todoItems) {
            std::string completed = item.isCompleted() ? "done\n" : "not done\n";
            std::cout << item.getId() << " | " << item.getDescription() << " | " << completed << std::endl;
        }

        if (todoItems.empty()) {
            std::cout << "Add your first todo!\n" << std::endl;
        }

        std::cout << "[a]dd a new Todo" << std::endl;
        std::cout << "[c]omplete a Todo" << std::endl;
        std::cout << "[q]uit\n" << std::endl;

        std::cout << "Choice: ";
        std::cin >> input_option;

        if (input_option == 'q') {
            std::cout << "See you soon :)" << std::endl;
            break;
        } else if (input_option == 'a') {
            std::cout << "Add a new description: ";
            std::cin.ignore();  // Ignore the newline character in the input buffer
            std::getline(std::cin, input_description);

            TodoItem newItem;
            newItem.create(input_description);
            todoItems.push_back(newItem);
        } else if (input_option == 'c') {
            std::cout << "Enter id to mark completed: ";
            std::cin >> input_id;

            for (it = todoItems.begin(); it != todoItems.end(); it++) {
                if (input_id == it->getId()) {
                    it->setCompleted(true);
                    break;
                }
            }
        }
    }

    return 0;
}
