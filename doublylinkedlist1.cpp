/*
Soowlih Compaore
CISC 2200
File doublylinkedlist2
*/
#include <iostream>
#include <iomanip>

using namespace std;

struct DNode{
string url;
DNode* next;
DNode* prev;

DNode(const string& newUrl1){
         url = newUrl1;
         next = prev = nullptr; 
    }
};

class DoublyLinkedList {
    private: 
    DNode* head;
    DNode* tail;
    DNode* current;

    public:
    DoublyLinkedList(){
        head = nullptr;
        tail = nullptr;
        current = nullptr;
    }
    ~DoublyLinkedList(){
        DNode* temp = head;
        while( temp != nullptr){
        DNode* nextNode = temp->next;
            delete temp;
            temp = nextNode;
        }
    }
    void visit(const string& newUrl1, DNode*& current){
        if(current != nullptr){
        DNode* temp = current->next;
            while(temp != nullptr){
                DNode* toDelete = temp;
                temp = temp->next;
                delete toDelete;
            }
            current->next = nullptr;
        }
        DNode* newNode = new DNode(newUrl1);
        if(current == nullptr){
            head = tail = current = newNode;
        } else {
        current->next = newNode;
        newNode->prev = current;
        current = newNode;
        tail = current;
        }
    }
    void back(DNode*& current){
        if(current != nullptr && current->prev != nullptr){
            current = current->prev;
        }
    }

    void forward(DNode*& current){
        if(current != nullptr && current->next != nullptr){
            current = current->next;
        }
    }
    void printHistory()const{
        DNode* temp = head;
        while(temp != nullptr){
            cout << temp->url << " " << endl;
            temp = temp->next;
        }
        cout <<endl;
    }
};
int main() {
DoublyLinkedList browserHistory;
DNode* current = nullptr; // pointer to track current page
browserHistory.visit("google.com", current);
browserHistory.visit("stackoverflow.com", current);
browserHistory.visit("github.com", current);
std::cout << "History (after visiting 3 sites):\n";
browserHistory.printHistory();
std::cout << "Current Page: "
<< (current ? current->url : "None") << "\n\n";
// Go back one page
browserHistory.back(current);
std::cout << "After going back:\n";
std::cout << "Current Page: "
<< (current ? current->url : "None") << "\n\n";
// Go forward one page
browserHistory.forward(current);
std::cout << "After going forward:\n";
std::cout << "Current Page: "
<< (current ? current->url : "None") << "\n\n";
// Visit a new page (which should clear forward history if any)
browserHistory.visit("news.ycombinator.com", current);
std::cout << "History (after visiting a new page):\n";
browserHistory.printHistory();
std::cout << "Current Page: "
<< (current ? current->url : "None") << "\n\n";
// Try going back twice
browserHistory.back(current);
browserHistory.back(current);
std::cout << "After going back twice:\n";
std::cout << "Current Page: "
<< (current ? current->url : "None") << "\n\n";
return 0;
}
/*
soowlihhousmoulcompaore@Soowlihs-MacBook-Air-116 C++ % c++ -o doublylinkedlist1 doublylinkedlist1.cpp
soowlihhousmoulcompaore@Soowlihs-MacBook-Air-116 C++ % ./doublylinkedlist2
Current song:
Playing Hotel California by Eagles

Moving to previous song...
Playing Bohemian Rhapsody by Queen

Removing current song...
Playing Imagine by John Lennon

Moving to next song...
Playing Hotel California by Eagles
soowlihhousmoulcompaore@Soowlihs-MacBook-Air-116 C++ %  
*/
