#include <iostream>
#include <string>
#include <stdio.h>
#include <algorithm>
#define SIZE 5
using namespace std;

class queue {
    private:
        int Q[SIZE];
        string name[SIZE];
        int front = -1, rear = -1, count = 0;
    public:
        bool isEmpty(){
            if (front == -1)
                return true;
            return false;
        }
        bool isFull(){
            return (rear == SIZE - 1);
        }
        void RegisterPatient(int element, string nam){
            if (isFull())
                cout << " Queue is full!!" << endl;
            else{
                rear++;
                Q[rear] = element;
                name[rear] = nam;
                if (front == -1) {
                    front = 0;
                }
                count++; 
            }
        }

        int ServePatient(){
            int element;

            if (isEmpty()) {
                printf("\n Queue is empty !! \n");   
                return -1;
            }
            else {
                element = Q[front];
                front++;
                if (front > rear) {
                    front = rear = -1;  // Reset the queue
                }

                count--;
                return element;
            }
        }

        void CancelAll(){
            front = rear = -1;  
            count = 0;
        }

        void ShowAllPatient(){
            
            if (isEmpty()){
                cout << "Queue is empty." << endl;
            }
            else {
                string sortedNames[SIZE];
                int sortedIDs[SIZE];
                 
                for (int i = front; i <= rear; i++) {
                    sortedNames[i] = name[i];
                    sortedIDs[i] = Q[i];
                }
 
                sort(sortedNames + front, sortedNames + rear + 1);
 
                cout << "Waiting List (Name/ID, sorted alphabetically):" << endl;
                for (int i = front; i <= rear; i++) {
                    for (int j = front; j <= rear; j++) {
                        if (name[j] == sortedNames[i]) {
                            cout << sortedNames[i] << "/" << sortedIDs[j] << endl;
                            break;
                        }
                    }
                }

            }
        }

        int CanDoctorGoHome(){
			if (isEmpty()){
				cout << "Yes please." << endl;
				return 6;
			}
			else{
				cout << "NO. Patients are waiting." << endl;
                return -2;
			}
        }
};

int main(void){
	queue waiting;
	int select = 0;
	int id = 0;
	string name;
	while (select != 6){
		cout << "Waiting Room Management System:\n\n1. Register Patient\n2. Serve Patient\n3. Cancel All\n4. Can Doctor go Home?\n5. Show all Patients\n6. Exit\n" << endl;
        cout<< "Enter Your Choice: ";
		cin >> select;
		
        //system("CLS");
		
        if (select > 6 && select < 1)
			cout << "Wrong Entry." << endl;
		switch (select){
		case 1:
			if (!waiting.isFull()){
				id++;
				cout << "Enter Patient's Name:";
				cin >> name;
				waiting.RegisterPatient(id, name);
			}
			else{
				cout << " Queue is full!!" << endl;
			}
			break;
		case 2:
			waiting.ServePatient();
			cout << "Examined." << endl;
			break;
		case 3:
			waiting.CancelAll();
			cout << "Cancelled." << endl;
			break;
		case 4:
            int choice;
            choice = waiting.CanDoctorGoHome();
            
            if (choice == 6){
                select = choice;
            }

			break;
		case 5:
			cout << "Waiting List.(Name/ID)" << endl;
			waiting.ShowAllPatient();
			break;
		case 6:
			break;
		}
	}

	return 0;
}
