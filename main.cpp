#include <iostream>
#include "queue.h"

using namespace std;

void instructions();
void switchQueues(Queue **PQ1, Queue **PQ2);

int main() {
	Queue Q1, Q2, Q3;
    Queue *PAQ = &Q1, *PQ1 = &Q2, *PQ2 = &Q3;
    int choice;
    int value1, value2;
    instructions();
    cout << "? ";
    cin >> choice;
    while (choice != 15) {
        switch(choice) {
            case 0:
                cout << "Active Queue:" << endl << *PAQ;
                cout << "Queue 1:" << endl << *PQ1;
                cout << "Queue 2:" << endl << *PQ2;
                value1 = 0;
                while(value1 < 1 || value1 > 2) {
                    cout << "Enter:" << endl 
                    << "1. To switch to Queue 1" << endl 
                    << "2. To switch to Queue 2" << endl << "Your choice: "; 
                    cin >> value1;
                }
                if(value1 == 1)
                    switchQueues(&PAQ, &PQ1);
                else
                    switchQueues(&PAQ, &PQ2);
                cout << "Active Queue:" << endl << *PAQ;
                cout << "Queue 1:" << endl << *PQ1;
                cout << "Queue 2:" << endl << *PQ2;
                break;
            case 1:
                PAQ->condition();
                break;
            case 2:
                cout << "Active Queue:" << endl << *PAQ;
                cout << "Queue 1:" << endl << *PQ1;
                cout << "Queue 2:" << endl << *PQ2;
                value1 = 0;
                while(value1 < 1 || value1 > 2) {
                    cout << "Enter:" << endl 
                    << "1. to copy Active Queue into Queue 1" << endl 
                    << "2. to copy Active Queue into Queue 2" << endl << "Your choice: ";
                    cin >> value1;
                }
                if(value1 == 1)
                    *PQ1 = *PAQ;
                else
                    *PQ2 = *PAQ;
                cout << "Active Queue:" << endl << *PAQ;
                cout << "Queue 1:" << endl << *PQ1;
                cout << "Queue 2:" << endl << *PQ2;
                break;
            case 3:
                cout << "Enter integer to add at the beginning: ";
                cin >> value1;
                PAQ->phenqueue(value1);
                cout << *PAQ;
                break;
            case 4:
                cout << "Enter integer to add at the end: ";
                cin >> value1;
                PAQ->enqueue(value1);
                cout << *PAQ;
                break;
            case 5:
                cout << "Enter 2 integers (FROM WHAT|INTO WHAT): ";
                cin >> value1 >> value2;
                PAQ->edit(value1, value2);
                cout << *PAQ;
                break;
            case 6:
                cout << "Enter integer to delete: ";
                cin >> value1;
                PAQ->dequeueKey(value1);
                cout << *PAQ;
                break;
            case 7:
                value1 = PAQ->dequeue();
                cout << "Element with value " << value1 << " is deleted" << endl;
                cout << *PAQ;
                break;
            case 8:
                cout << "Deleting Active Queue" << endl;
                PAQ->deleteAll();
                cout << *PAQ;
                break;
            case 9:
                cout << "Length of Active Queue is: " << PAQ->length() << endl;
                break;
            case 10:
                cout << "Sorted Active Queue: " << endl;
                PAQ->sortQueue();
                cout << *PAQ;
                break;
            case 11:
                cout << "Reversed Active Queue: " << endl;
                PAQ->reverseQueue();
                cout << *PAQ;
                break;
            case 12:
                cout << "Active Queue:" << endl << *PAQ;
                cout << "Queue 1:" << endl << *PQ1;
                cout << "Queue 2:" << endl << *PQ2;
                value1 = 0;
                while(value1 < 1 || value1 > 2) {
                    cout << "Enter:" << endl 
                    << "1. To stack Active Queue with Queue 1 (result is saved in Queue 2)" << endl 
                    << "2. To stack Active Queue with Queue 2 (result is saved in Queue 1)" << endl << "Your choice: "; 
                    cin >> value1;
                }
                if(value1 == 1)
                    *PQ2 = *PAQ + *PQ1;
                else
                    *PQ1 = *PAQ + *PQ2;
                cout << "Active Queue:" << endl << *PAQ;
                cout << "Queue 1:" << endl << *PQ1;
                cout << "Queue 2:" << endl << *PQ2;
                break;
            case 13:
                cout << "Active Queue:" << endl << *PAQ;
                cout << "Queue 1:" << endl << *PQ1;
                cout << "Queue 2:" << endl << *PQ2;
                value1 = 0;
                while(value1 < 1 || value1 > 2) {
                    cout << "Enter:" << endl 
                    << "1. To merge Active Queue with Queue 1 (result is saved in Queue 2)" << endl 
                    << "2. To merge Active Queue with Queue 2 (result is saved in Queue 1)" << endl << "Your choice: "; 
                    cin >> value1;
                }
                if(value1 == 1)
                    *PQ2 = *PAQ * *PQ1;
                else
                    *PQ1 = *PAQ * *PQ2;
                cout << "Active Queue:" << endl << *PAQ;
                cout << "Queue 1:" << endl << *PQ1;
                cout << "Queue 2:" << endl << *PQ2;
                break;
            case 14:
                cout << "Queue without duplicates:" << endl;
                PAQ->deleteDups();
                cout << *PAQ;
                break;
            default:
                cout<<"invalid choice"<<endl<<endl;
                instructions();
                break;
        }
        cout<<"? ";
        cin >> choice;
    }
    cout << "End of run" << endl;
	return 0;
}

void instructions() {
	cout << "Enter your choice:" << endl
    << "0 to switch queues to work with" << endl
    << "1 to print the condition of your queue: head element, tail element, length of queue" << endl 
    << "2 to make a copy of your queue" << endl
    << "3 to add an element in the beginning of your queue" << endl
    << "4 to add an element in the end of your queue" << endl
    << "5 to change the chosen element" << endl
    << "6 to delete the chosen element" << endl
    << "7 to remove the element and print it" << endl
    << "8 to delete the whole queue" << endl
    << "9 to print the length of your queue" << endl
    << "10 to sort your queue in increasing order" << endl
    << "11 to invert your queue" << endl
    << "12 to add two queues together" << endl
    << "13 to combine two queues" << endl
    << "14 to delete the duplicates" << endl
    << "15 to end the run" << endl;
}

void switchQueues(Queue **PQ1, Queue **PQ2) {
    Queue *temp = *PQ1;
    *PQ1 = *PQ2;
    *PQ2 = temp;
}