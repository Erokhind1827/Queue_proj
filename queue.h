#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
#include "queuend.h"

class Queue {
    friend std::ostream& operator<<(std::ostream&, Queue&);
    
	public:
		Queue();
        Queue(const Queue&);
		~Queue();

        const Queue& operator=(const Queue&);
	    Queue operator+(const Queue&);
        Queue operator*(const Queue&);

		void enqueue(int);
		void phenqueue(int);
		int dequeue();
        void dequeueKey(int);
		void edit(int, int);
		
		void stackQueue(const Queue&);
		void mergeQueue(const Queue&);
		
		void sortQueue();
		void reverseQueue();
		
		void deleteDups();
		void deleteAll();
		
		int isEmpty() const;
		int length() const;
		void condition() const;
		std::ostream& printStream(std::ostream&) const;
	
	private:
		QueueNode *headPtr;
		QueueNode *tailPtr;
		
		QueueNode *getNewNode(int);
};

#endif