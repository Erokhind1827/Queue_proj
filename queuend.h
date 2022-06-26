#ifndef QUEUEND_H
#define QUEUEND_H

class QueueNode {
	friend class Queue;

	public:
		QueueNode(int = 0);

	private:
		int data;
		QueueNode *nextPtr;
};

#endif