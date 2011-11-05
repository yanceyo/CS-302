/*
 * queue.h
 *
 *  Created on: Oct 9, 2011
 *      Author: yanceyo
 */

#ifndef _QUEUETYPEH_
#define _QUEUETYPEH_

template<class ItemType>
class QueueType
{
	public:
		QueueType(int);
		~QueueType();
		void MakeEmpty();
		bool isFull() const;
		bool isEmpty() const;
		void Enqueue(ItemType);
		void Enqueue(ItemType, ItemType);
		void Dequeue(ItemType&);
		void Dequeue(ItemType&, ItemType&);
	private:
		int front;
		int rear;
		ItemType* items;
		int maxQue;
};

#endif /* QUEUE_H_ */

#include "queue.cpp"
