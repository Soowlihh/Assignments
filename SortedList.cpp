/*
 Soowlih Compaore
 04/06/2025
 Assignment 02
 Sorted List Implementation
 */

#include <iostream>
#include <string>

using namespace std;

struct Node{
    string threatName;
    string severity;
    Node* next;
};

class AlertLog{
private:
    Node* head;
public:
    // constructor
    AlertLog(){
        head = nullptr;
    }
    // destructor
    ~AlertLog(){
        Node* current = head;
        while (current != nullptr){
            Node* temp = current;
            current = current->next;
            delete temp;
        }
    }
    //Adds alerts to the list
    void addAlert(const string& threatName, const string& severity){
        Node* newNode = new Node(threatName, severity);
        if (head == nullptr || head->threatName > threatName){
            newNode->next = head;
            head = newNode;
            return;
        }
        Node* current = head;
        while( current->next != nullptr && current->next->threatName < threatName){
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }
    // removes 'unwanted' alerts from the list
    bool removeAlert(const string& threatName){
        if(head == nullptr){
            return false;
        }
        if(head->threatName == threatName){
            Node* temp = head;
            head = head-> next;
            delete temp;
            return true;
        }
        Node* current = head;
        while( current->next != nullptr){
            if(current->next->threatName == threatName){
                Node* temp = current->next;
                current->next = current->next->next;
                delete temp;
                return true;
            }
            current = current->next;
        }
        return false;
    }
    //detects all alerts in the list and its severity
    string findAlert(const string& threatName) const{
        Node* current = head;
        while(current != nullptr){
            if(current->threatName == threatName){
                return current->severity;
            }
            current = current->next;
        }
        return 0;
    }
    //print all alerts in the list
    void printAlerts() const{
        Node* temp = head;
        while(temp != nullptr){
            cout<< temp->threatName << temp->severity << endl;
            temp = temp->next;
        }
    }
};
int main() {
    AlertLog securityAlerts;
    // Add alerts (automatically inserted in sorted order by threat name)
    securityAlerts.addAlert("ZeroDay Exploit", " - High");
    securityAlerts.addAlert("SQL Injection", " - Medium");
    securityAlerts.addAlert("Phishing Attempt", " - High");
    // Print current alert log
    std::cout << "Security Alert Log:\n";
    securityAlerts.printAlerts();
    // Search for an alert
    std::string searchThreat = "SQL Injection";
    std::string severity =
    securityAlerts.findAlert(searchThreat);
    if (!severity.empty()) {
        std::cout << "\nFound alert '" << searchThreat << "' with severity: " << severity << "\n";
    } else {
        std::cout << "\nAlert " << searchThreat << " not found in the log.\n";
    }
    // Remove an alert
    std::cout << "\nRemoving 'Phishing Attempt'... "
    << (securityAlerts.removeAlert("Phishing Attempt")
        ? "Success" : "Not Found") << "\n";
    // Final alert log
    std::cout << "\nUpdated Security Alert Log:\n";
    securityAlerts.printAlerts();
    return 0;
}
/*
 Security Alert Log:
 Phishing Attempt - High
 SQL Injection - Medium
 ZeroDay Exploit - High

 Found alert 'SQL Injection' with severity:  - Medium

 Removing 'Phishing Attempt'... Success

 Updated Security Alert Log:
 SQL Injection - Medium
 ZeroDay Exploit - High
 Program ended with exit code: 0
 */
