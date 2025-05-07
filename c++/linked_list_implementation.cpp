#include <iostream>
#include <vector>
#include <limits>
#include <queue>
#include <stack>
#include "string"
#include "algorithm"
#include "cmath"
#include "unordered_map"
#include <string>
#define endl '\n'
#define space ' '
#define INF 2147483647
#define MAX 2501
using namespace std;
typedef long long ll;
//const long long INF = 1LL << 60;
//typedef __int128 ll;

// list restriction :
//    this list can only have integer as a element
//    all integers are lower than 1000, and natural number

struct Node {
    int data;
    Node* next;
    
    // a single node have its own data and the pointer that points next node
};

class LinkedList {
private:
    int size = 0;
    Node* head = NULL;
    // head and size is managed as private member

public:

    bool is_empty() {
        if (size == 0) return true;
        // size zero represent empty
        return false;
    }
    
    void add_front(int data) {
        head = new Node(data, head);
        size++;
        // new node have original head information and new data
        // then head points new node to add
        return;
    }
    
    void add_rear(int data) {
        if (head == NULL) {
            head = new Node(data, NULL);
            return;
        }
        
        Node* current = head;
        Node* insertion_node = new Node(data, NULL);
        Node* previous = new Node;
        
        while (current != NULL) {
            previous = current;
            current = current -> next;
        }
        
        previous -> next = insertion_node;
        size++;
        
        // first, find NULL. and its previous node is last node
        // and set the next of last node into pointer of insertion node
        return;
    }
    
    void remove(int data) {
        Node* current = head;
        Node* previous = nullptr;
        
        while (current) {
            if (current -> data == data) {
                if (previous) {
                    previous -> next = current -> next;
                }
                else head = current -> next;
                delete current;
                size--;
                return;
            }
            previous = current;
            current = current -> next;
        }
        
        cout << data << " is not in list" << endl;
        
        // while current is not null pointer, find data.
        // if not same, pass to next node. if same,
        
        return;
    }
    
    void display() {
        Node* current = head;
        
        cout << '[';
        while (current != NULL) {
            cout << current -> data;
            if (current -> next != NULL) {
                cout << ' ';
            }
            current = current -> next;
        }
        cout << "]" << endl;
        
        // untill null, represents all nodes
        return;
    }

    void remove_duplicates() {
        bool existence[10001] = {false};
        
        Node* current = head;
        Node* previous = NULL;
        
        while (current != NULL) {
            int current_value = current -> data;
            
            if (existence[current_value] == true) {
                previous -> next = current -> next;
//                previous -> data = current_value;
                size--;
                
                current = previous -> next;
                continue;
            }
            
            existence[current_value] = true;
            previous = current;
            current = current -> next;
        }
        
        // first, declare the array that contains information about alpha's existence
        // and if the number appears, its value turns true.
        // after that, if the existence is already true, remove that node
        // repeat this operation untill the end
        return;
    }
    
    void find_kth_from_end(int k) {
        Node* current = head;
        
        int goal = size - k + 1;
        int cnt = 0;
        while (current != NULL) {
            if (cnt == goal) {
                cout << current -> data << endl;
                return;
            }
            current = current -> next;
            cnt++;
        }
        
        // the k th element from end can described by size - k + 1
        // so, set the cnt and count the number of while loop
        // then, if cnt is same as goal, print that value and return
        return;
    }
    
    LinkedList merge_lists(const LinkedList& l1, const LinkedList& l2) {
        
        Node* current = head;
        Node* insertion_node = l2.head;
        Node* previous = new Node;
        
        while (current != NULL) {
            previous = current;
            current = current -> next;
        }
        
        previous -> next = insertion_node;
        size += l2.size;
        
        return l1;
    }
    
    // this list use dynamic allocation to use heap
    // so, absolutely, clear method is required
    void clear() {
        Node* currrent = head;
        
        while (currrent != NULL) {
            Node* next = currrent -> next;
            delete currrent;
            currrent = next;
        }
        
        head = NULL;
        size = 0;
        
        return;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cout << "[Linked list operation ....]\n";

    LinkedList ll;
    LinkedList ll2;

    ll.add_front(3);
    ll.add_front(2);
    ll.add_front(1);
    ll.add_front(1);
    ll.display();
    ll.remove_duplicates();
    ll.display();
    ll.remove(2);
    ll.display();
    ll.remove(3);
    ll.display();
    ll.add_front(2);
    ll.add_front(3);
    ll.find_kth_from_end(2);
    ll.add_front(3);
    ll.add_front(3);
    ll.display();
    ll.find_kth_from_end(3);
    ll2.add_front(1);
    ll2.add_rear(4);
    ll2.add_rear(5);
    ll2.display();
    ll = LinkedList().merge_lists(ll, ll2);
    ll.clear();
    ll2.clear();
    
    return 0;
}

