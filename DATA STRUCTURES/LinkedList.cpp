#include <iostream>
 
struct Node
{
    int data;
    Node *next;
    Node(int value) : data(value), next(nullptr) {}
};
 
class LinkedList{
    private:
        Node *head;

    public: 
        LinkedList() : head(nullptr) {} 
        void insertAtBeginning(int value)
        {
            Node *newNode = new Node(value);
            newNode->next = head;
            head = newNode;
        }
    
        void insertAtEnd(int value)
        {
            Node *newNode = new Node(value);
            if (!head)
            {
                head = newNode;
            }
            else
            {
                Node *current = head;
                while (current->next)
                {
                    current = current->next;
                }
                current->next = newNode;
            }
        }
    
        void deleteNode(int value)
        {
            if (!head)
            {
                return;
            }

            if (head->data == value)
            {
                Node *temp = head;
                head = head->next;
                delete temp;
                return;
            }

            Node *current = head;
            while (current->next)
            {
                if (current->next->data == value)
                {
                    Node *temp = current->next;
                    current->next = current->next->next;
                    delete temp;
                    return;
                }
                current = current->next;
            }
        }
    
        void display()
        {
            Node *current = head;
            while (current)
            {
                std::cout << current->data << " --> ";
                current = current->next;
            }
            std::cout << "nullptr" << std::endl;
        }
    
        ~LinkedList()
        {
            while (head)
            {
                Node *temp = head;
                head = head->next;
                delete temp;
            }
        }
};

int main()
{
    LinkedList myList;

    myList.insertAtEnd(10);
    myList.insertAtEnd(20);
    myList.insertAtBeginning(5);
    myList.display();

    myList.deleteNode(20);
    myList.display();

    return 0;
}
