#include <iostream>

using namespace std;
 
class Node {
    public:
        int value;
        Node* next;
};

Node* head = NULL;

void insertAtHead(int value) {
    Node* newNode = new Node;
    newNode->value = value;
    newNode->next = head;
    head = newNode;
} 

void insertAtLocation(int value, int location = 3){

    if (location < 1) {
        cout << "Invalid location. Location should be >= 1." << endl;
        return;
    }

    Node* newNode = new Node;
    newNode -> value = value;

    if (location == 1) {
        newNode->next = head;
        head = newNode;
        return;
    }

    Node* current = head;
    int count = 1;

    while (current != NULL && count < location - 1) {
        current = current->next;
        count++;
    }

    if (count < location - 1 || current == NULL) {
        cout << "Invalid location. Location exceeds the size of the list." << endl<<endl;
        delete newNode;  
    } else {
        newNode->next = current->next;
        current->next = newNode;
    }
}
 
void displayList() {
    Node* current = head;
    while (current != NULL) {
        cout << current->value << " ";
        current = current->next;
    }
    cout << endl <<endl;
}
 
void deleteNode(int value) {
    if (head == nullptr) {
        cout << "List is empty. Deletion is not possible." << endl;
        return;
    }

    if (head->value == value) {
        Node* temp = head;
        head = head->next;
        delete temp;
        cout << "Deleted node with value: " << value << endl;
        return;
    }

    Node* current = head;
    while (current->next != NULL && current->next->value != value) {
        current = current->next;
    }

    if (current->next == NULL) {
        cout << "Node with value " << value << " not found in the list." << endl;
    } else {
        Node* temp = current->next;
        current->next = temp->next;
        delete temp;
        cout << "Deleted node with value: " << value << endl;
    }
}


int countList() {
    int count = 0;
    Node* current = head;
    while (current != NULL) {
        count++;
        current = current->next;
    }
    return count;
}

int main() { 
    int choice;

    do {
        cout << "Linked List Menu:" << endl;
        cout << "1. Insert at head" << endl;
        cout << "2. Insert at location" << endl;
        cout << "3. Display list" << endl;
        cout << "4. Delete node by value" << endl;
        cout << "5. Count nodes" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                int value;
                cout << "Enter value to insert at head: ";
                cin >> value;
                insertAtHead(value);
                break;
            case 2:
                cout << "Enter value to insert at location: ";
                cin >> value;
                insertAtLocation(value, 3);
                break;
            case 3:
                cout << "Linked List: ";
                displayList( );
                break;
            case 4:
                cout << "Enter value to delete: ";
                cin >> value;
                deleteNode(value);
                break;
            case 5:
                cout << "Number of nodes in the list: " << countList() << endl << endl;
                break;
            case 6:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
        }
    } while (choice != 6);
 
    Node* current = head;
    while (current != nullptr) {
        Node* temp = current;
        current = current->next;
        delete temp;
    }

    return 0;
}
