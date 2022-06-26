#include <cstdlib>
#include <iostream>
#include "queuend.h"
#include "queue.h"

#define EMPTY_DEQUEUE_VALUE 0

using namespace std;

ostream& operator<<(ostream& output, Queue& queue) {
	return queue.printStream(output);
}

Queue::Queue() {
	headPtr = tailPtr = NULL;
}

Queue::Queue(const Queue& queue) {
    *this = queue;
}

Queue::~Queue() {
	deleteAll();
}

const Queue& Queue::operator=(const Queue &queue) {
    if(&queue != this) {
        this->deleteAll();
        this->mergeQueue(queue);
    }
    return *this;
}

Queue Queue::operator+(const Queue& right) {
    Queue result;
    result.mergeQueue(*this);
    result.stackQueue(right);
    return result;
}

Queue Queue::operator*(const Queue& right) {
    Queue result;
    result.mergeQueue(*this);
    result.mergeQueue(right);
    return result;
}

void Queue::enqueue(int value) {
	QueueNode *newPtr = getNewNode(value);
	if(isEmpty())
		headPtr = newPtr;
	else
		tailPtr->nextPtr = newPtr;
	tailPtr = newPtr;
}

void Queue::phenqueue(int value) {
	QueueNode *newPtr = getNewNode(value);
	if(isEmpty())
		tailPtr = newPtr;
	else
		newPtr->nextPtr = headPtr;
	headPtr = newPtr;
}

int Queue::dequeue() {
	if(isEmpty()) {
		return EMPTY_DEQUEUE_VALUE;
	}
	QueueNode *tempPtr = headPtr;
	if(headPtr == tailPtr)
		headPtr = tailPtr = NULL;
	else
		headPtr = headPtr->nextPtr;
	int returnValue = tempPtr->data;
	delete tempPtr;
	return returnValue;
}

void Queue::dequeueKey(int value) {
    if(this->isEmpty()) {
        return;
    }
    Queue temp;
    QueueNode *currentPtr = this->headPtr;
    while(currentPtr != NULL) {
        if(currentPtr->data != value)
            temp.enqueue(currentPtr->data);
        currentPtr = currentPtr->nextPtr;
    }
    *this = temp;
}

void Queue::edit(int value, int change) {
	if(isEmpty()) {
		return;
	}
	int n = 0;
	QueueNode *currentPtr = headPtr;
	while(currentPtr != NULL) {
		if(currentPtr->data == value) {
			n++;
			currentPtr->data = change;
		}
		currentPtr = currentPtr->nextPtr;
	}
	if(n == 0)
		cout << "Element " << value << " not found" << endl;
	else
		cout << "Elements found: " << n << endl;
}

void Queue::stackQueue(const Queue &queue) {
	QueueNode *currentPtr1 = this->headPtr, *currentPtr2 = queue.headPtr;
	while(currentPtr1 != NULL && currentPtr2 != NULL) {
		currentPtr1->data = currentPtr1->data + currentPtr2->data;
		currentPtr1 = currentPtr1->nextPtr;
		currentPtr2 = currentPtr2->nextPtr;
	}
	while(currentPtr2 != NULL) {
		this->enqueue(currentPtr2->data);
		currentPtr2 = currentPtr2->nextPtr;
	}
}

void Queue::mergeQueue(const Queue &queue) {
	QueueNode *currentPtr = queue.headPtr;
	while(currentPtr != NULL) {
		this->enqueue(currentPtr->data);
		currentPtr = currentPtr->nextPtr;
	}
}

void Queue::sortQueue() {
    if(!isEmpty()) {
        QueueNode *currentPtr = headPtr, *tempPtr;
        while(currentPtr != NULL) {
            tempPtr = currentPtr->nextPtr;
            while(tempPtr != NULL) {
                if(currentPtr->data > tempPtr->data) {
                    int temp = currentPtr->data;
                    currentPtr->data = tempPtr->data;
                    tempPtr->data = temp;
                }
                tempPtr = tempPtr->nextPtr;
            }
            currentPtr = currentPtr->nextPtr;
        }
    }
}

void Queue::reverseQueue() {
	if(!isEmpty()) {
		Queue temp;
		int value;
		while(!isEmpty()) {
			value = this->dequeue();
			temp.phenqueue(value);
		}
        *this = temp;
	}
}

void Queue::deleteDups() {
	QueueNode *currentPtr1 = headPtr, *currentPtr2, *previousPtr;
	while(currentPtr1 != NULL) {
		currentPtr2 = currentPtr1->nextPtr;
		previousPtr = currentPtr1;
		while(currentPtr2 != NULL) {
			if(currentPtr1->data == currentPtr2->data) {
                QueueNode *tempPtr = currentPtr2;
				previousPtr->nextPtr = currentPtr2->nextPtr;
				currentPtr2 = currentPtr2->nextPtr;
                delete tempPtr;
            }
			else {
				previousPtr = currentPtr2;
				currentPtr2 = currentPtr2->nextPtr;
			}
		}
		tailPtr = currentPtr1;
		currentPtr1 = currentPtr1->nextPtr;
	}
}

void Queue::deleteAll() {
	while(!isEmpty())
		dequeue();
}

int Queue::isEmpty() const {
	return headPtr == NULL;
}

int Queue::length() const {
	QueueNode *currentPtr = headPtr;
	int l = 0;
	while(currentPtr != NULL) {
		l++;
		currentPtr = currentPtr->nextPtr;
	}
	return l;
}

void Queue::condition() const {
	if(isEmpty())
		cout << "Queue is empty" << endl;
	else {
		cout << "Condition of queue:" << endl <<
		"Head is " << headPtr->data << endl <<
		"Tail is " << tailPtr->data << endl << 
		"Length is " << length() << endl;
	}
}

ostream& Queue::printStream(ostream& output) const {
    if(!isEmpty()) {
        QueueNode *currentPtr = headPtr;
        while(currentPtr != NULL) {
            output << currentPtr->data << " <-- ";
            currentPtr = currentPtr->nextPtr;
        }
    }
    output << "NULL" << endl << endl;
    return output;
}

QueueNode* Queue::getNewNode(int value) {
	QueueNode *newPtr = new QueueNode(value);
	if(newPtr != NULL)
		return newPtr;
	cout << "Memory couldn't be allocated" << endl;	
	return NULL;
}

