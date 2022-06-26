#include "queuend.h"
#include <cstdlib>

QueueNode::QueueNode(int value) {
	data = value;
	nextPtr = NULL;
}