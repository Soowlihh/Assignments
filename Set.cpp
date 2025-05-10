/*
 Soowlih Compaore
 04/06/2025
 Assignment 02
 Set Implementation
 */
#include <iostream>
using namespace std;

class PhishingBlocklist{
private:
    string* emails;
    int tracker;
    int capacity;
public:
    //constructor
    PhishingBlocklist(int initialCapacity = 10){
        capacity = initialCapacity;
        tracker = 0;
        emails = new string[capacity];
    }
    //destructor
    ~PhishingBlocklist(){
        delete[] emails;
    }
    //Adds phishing email to the list
    bool addEmail(const string& email){
        if(contains(email)){
            return false;
        }
        emails[tracker] = email;
        ++tracker;
        return true;
    }
    //removes phishing email from the list
    bool removeEmail(const std::string& email){
        int index = -1;
        for(int i = 0; i < tracker; ++i){
            if(emails[i] == email){
                index = i;
                break;
            }
        }
        if(index == -1){
            return false;
        }
        for(int i = index; i < tracker - 1; ++i){
            emails[i] = emails[i + i];
        }
        --tracker;
        return true;
    }
    //checks to see whether or not the list contains a specific phishing email
    bool contains(const std::string& email) const{
        for(int i = 0; i < tracker; ++i){
            if(emails[i] == email){
                return true;
            }
        }
        return false;
    }
    //Prints out all phishing emails in the list
    void printBlocklist() const{
            for(int i = 0; i < tracker; ++i){
                cout << emails[i] << endl;
        }
    }
};
int main() {
    PhishingBlocklist blocklist;
    // Test adding phishing emails
    std::cout << "Adding Emails:\n";
    std::cout << (blocklist.addEmail("phish1@malicious.com") ?
                  "Added" : "Duplicate") << "\n";
    std::cout << (blocklist.addEmail("scam@fraud.net") ? "Added"
                  : "Duplicate") << "\n";
    std::cout << (blocklist.addEmail("attack@phishers.org") ?
                  "Added" : "Duplicate") << "\n";
    std::cout << (blocklist.addEmail("phish1@malicious.com") ?
                  "Added" : "Duplicate") << " (duplicate test)\n";
    // Print current blocklist
    std::cout << "\nCurrent Phishing Blocklist:\n";
    blocklist.printBlocklist();
    // Test membership
    std::string searchEmail = "scam@fraud.net";
    std::cout << "\nSearching for " << searchEmail << ": "
    << (blocklist.contains(searchEmail) ? "Found" :
        "Not Found") << "\n";
    // Test removal
    std::cout << "\nRemoving 'attack@phishers.org'... "
    << (blocklist.removeEmail("attack@phishers.org") ?
        "Success" : "Not Found") << "\n";
    std::cout << "Removing 'unknown@phishers.org'... "
    << (blocklist.removeEmail("unknown@phishers.org") ?
        "Success" : "Not Found") << "\n";
    // Print final blocklist
    std::cout << "\nBlocklist after removals:\n";
    blocklist.printBlocklist();
    return 0;
}
/*
 Adding Emails:
 Added
 Added
 Added
 Duplicate (duplicate test)

 Current Phishing Blocklist:
 phish1@malicious.com
 scam@fraud.net
 attack@phishers.org

 Searching for scam@fraud.net: Found

 Removing 'attack@phishers.org'... Success
 Removing 'unknown@phishers.org'... Not Found

 Blocklist after removals:
 phish1@malicious.com
 scam@fraud.net
 Program ended with exit code: 0
 */
