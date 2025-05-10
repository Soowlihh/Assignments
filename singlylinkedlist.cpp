/*
Soowlih Compaore
CISC 2200
File doublylinkedlist2
*/
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

struct Node{
    string title;
    int priority;
    Node* next;
    Node(const string& t, int p) : title(t), priority(p), next(nullptr){}
    
};

class SinglyLinkedList{
    private : 
    Node* head;

    public:
    SinglyLinkedList(){
        head = nullptr;
    }
    ~SinglyLinkedList(){
        Node* current = head;
        while(current != nullptr){
            Node* temp = current;
            current = current->next;
            delete temp;
        }
    }
    void addTaskFront(const string& title, int priority){
        Node* newNode = new Node(title, priority);
        newNode->next = head;
        head = newNode;
    }
    void addTaskEnd(const string& title, int priority){
        Node* newNode = new Node(title , priority);
        if(head == nullptr){
            head = newNode;
        } else{
            Node* temp = head;
            while(temp->next != nullptr){
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }
    bool removeTask(const string& title){
        if (head == nullptr){
            return false;
        }
        if(head->title == title){
            Node* temp = head;
            head = head-> next;
            delete temp;
            return true;
        }
        Node* current = head;
        while(current->next != nullptr){
            if(current->next->title == title){
                Node* temp = current->next;
                current->next = current->next->next;
                delete temp;
                return true;
            }
            current = current->next;
        }
        return false;
    }
    int findTask(const string& title){
        Node* current = head;
        while(current != nullptr){
        if(current->title == title){
                return current->priority;
            }
             current = current->next;
    }
    return -1;
    }
    void printList() const{
        Node* temp = head;
        while(temp != nullptr){
            cout << "Title: " << temp->title << ", Priority : " << temp->priority <<endl;
            temp = temp->next;
        }
    }
};
int main(){
    SinglyLinkedList todoList;
// Add tasks
todoList.addTaskFront("Buy Groceries", 2);
todoList.addTaskFront("Finish Assignment", 1);
todoList.addTaskEnd("Call Mom", 1);
todoList.addTaskEnd("Plan Vacation", 3);
// Print current list
std::cout << "Initial To-Do List:\n";
todoList.printList();
// Remove a task
bool removed = todoList.removeTask("Buy Groceries");
std::cout << "\nRemoving 'Buy Groceries'... "
<< (removed ? "Success" : "Not Found") << "\n";
todoList.printList();
// Search for a task
std::string searchTitle = "Finish Assignment";
int priority = todoList.findTask(searchTitle);
if (priority != -1) {
std::cout << "\nFound '" << searchTitle
<< "' with priority " << priority << "\n";
} else {
std::cout << "\n" << searchTitle <<  "not found in the list" << endl;
}
// Try removing a non-existent task
removed = todoList.removeTask("Do Laundry");
std::cout << "\nRemoving 'Do Laundry'... "
<< (removed ? "Success" : "Not Found") << "\n";
todoList.printList();
return 0;

}

/*
soowlihhousmoulcompaore@Soowlihs-MacBook-Air-116 C++ % c++ -o singlylinkedlist singlylinkedlist.cpp
soowlihhousmoulcompaore@Soowlihs-MacBook-Air-116 C++ % ./singlylinkedlist
Initial To-Do List:
Title: Finish Assignment, Priority : 1
Title: Buy Groceries, Priority : 2
Title: Call Mom, Priority : 1
Title: Plan Vacation, Priority : 3

Removing 'Buy Groceries'... Success
Title: Finish Assignment, Priority : 1
Title: Call Mom, Priority : 1
Title: Plan Vacation, Priority : 3

Found 'Finish Assignment' with priority 1

Removing 'Do Laundry'... Not Found
Title: Finish Assignment, Priority : 1
Title: Call Mom, Priority : 1
Title: Plan Vacation, Priority : 3
soowlihhousmoulcompaore@Soowlihs-MacBook-Air-116 C++ % 
*/
