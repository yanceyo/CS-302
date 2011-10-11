/*
 * queue.cpp
 *
 *  Created on: Oct 9, 2011
 *      Author: yanceyo
 */

using namespace std;

#include"queue.h"

template<class ItemType>
QueueType<ItemType>::QueueType(int max)
{
	maxQue = max + 1;
	front = max -1;
	rear = max - 1;
	items = new ItemType[maxQue];
}

template<class ItemType>
QueueType<ItemType>::~QueueType()
{
	delete[] items;
}

template<class ItemType>
void QueueType<ItemType>::MakeEmpty()
{
	front = maxQue - 1;
	rear = maxQue - 1;
}

template<class ItemType>
bool QueueType<ItemType>::isEmpty() const
{
	return (rear == front);
}

template<class ItemType>
bool QueueType<ItemType>::isFull() const
{
	return ( (rear+1) % maxQue == front );
}

template<class ItemType>
void QueueType<ItemType>::Enqueue(ItemType newItem)
{
	rear = (rear+1) % maxQue;
	items[rear] = newItem;
}

template<class ItemType>
void QueueType<ItemType>::Enqueue(ItemType val1, ItemType val2)
{
	rear = (rear+1) % maxQue;
	items[rear] = val1;

	if(!isFull())
	{
		rear = (rear+1) % maxQue;
		items[rear] = val2;
	}
}

template<class ItemType>
void QueueType<ItemType>::Dequeue(ItemType &item)
{
	front = (front+1) % maxQue;
	item = items[front];
}

template<class ItemType>
void QueueType<ItemType>::Dequeue(ItemType &item1, ItemType &item2)
{
	front = (front+1) % maxQue;
	item1 = items[front];

	if(!isEmpty())
	{
		front = (front+1) % maxQue;
		item2 = items[front];
	}
}

