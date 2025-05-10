/*
Soowlih Compaore
CISC 2200
File doublylinkedlist2
*/
#include <iostream>
#include <iomanip>

using namespace std;

struct DNode {
    string songTitle;
    string artist;
    DNode* next;
    DNode* prev;
    DNode(const string& title, const string& artist){
        songTitle = title;
        this->artist = artist;
        next = prev = nullptr;
    }
};

class Playlist{
    private: 
    DNode* head;
    DNode* tail;

    public:
    Playlist(){
    head = tail = nullptr;}
    ~Playlist(){
        DNode* temp = head;
        while(temp != nullptr){
            DNode* nextNode = temp->next;
            delete temp;
            temp = nextNode;
        }
    }
    void addSong(const string& title, const string& artist, DNode*& currentSong){
        DNode* newSong = new DNode(title, artist);
       if(head == nullptr){
        head = tail = newSong;
        currentSong = newSong;
       } else if(currentSong == nullptr){
        head->prev = newSong;
        newSong->next = head;
        head = newSong;
        currentSong = newSong;
       } else {
        newSong->prev = currentSong;
        newSong->next = currentSong->next;

        if(currentSong->next != nullptr){
            currentSong->next->prev = newSong;
        }
        currentSong->next = newSong;
        currentSong = newSong;
        if(currentSong->next == nullptr){
            tail = currentSong;
         }
       }
    }
    bool removeCurrentSong(DNode*& currentSong){
        if (currentSong == nullptr){
            return false;
        }
        DNode* temp = currentSong;
        if(currentSong == head && currentSong == tail ){
            head = tail = nullptr;
            currentSong = nullptr;
        }
        else if (currentSong == head){
        head = currentSong->next;
        head->prev = nullptr;
        currentSong = head;
        }
        else if(currentSong == tail){
            tail = currentSong->prev;
            tail->next = nullptr;
            currentSong = tail;
        } else{
        currentSong->prev->next = currentSong->next;
        currentSong->next->prev = currentSong->prev;
        currentSong = currentSong->prev;
    }
    delete temp;
    return true;
    }
    void moveNext(DNode*& currentSong){
        if(currentSong != nullptr && currentSong->next != nullptr){
            currentSong = currentSong->next;
        }
    }
    
    void movePrev(DNode*& currentSong){
        if(currentSong != nullptr && currentSong->prev != nullptr){
            currentSong = currentSong->prev;
        }
    }
    void displayCurrent(DNode*& currentSong){
        if(currentSong != nullptr){
           cout << "Playing " << currentSong->songTitle << " by " << currentSong->artist<< endl;
        }
        }
    }
};
int main() {
Playlist myPlaylist;
DNode* currentSong = nullptr;
// Add songs
myPlaylist.addSong("Imagine", "John Lennon", currentSong);
// current -> "Imagine"
myPlaylist.addSong("Bohemian Rhapsody", "Queen", currentSong);
// current -> "Bohemian Rhapsody"
myPlaylist.addSong("Hotel California", "Eagles", currentSong);
// current -> "Hotel California"
// Display current
std::cout << "Current song:\n";
myPlaylist.displayCurrent(currentSong);
// Move back once
std::cout << "\nMoving to previous song...\n";
myPlaylist.movePrev(currentSong);
myPlaylist.displayCurrent(currentSong);
// Remove current
std::cout << "\nRemoving current song...\n";
myPlaylist.removeCurrentSong(currentSong);
myPlaylist.displayCurrent(currentSong);
// Move next (if possible)
std::cout << "\nMoving to next song...\n";
myPlaylist.moveNext(currentSong);
myPlaylist.displayCurrent(currentSong);
// (You could add more rigorous tests here.)
return 0;
}
/*
soowlihhousmoulcompaore@Soowlihs-MacBook-Air-116 C++ % c++ -o doublylinkedlist2 doublylinkedlist2.cpp
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
