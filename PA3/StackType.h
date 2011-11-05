/*
 * stacktype.h
 *
 *  Created on: Oct 8, 2011
 *      Author: Caitlin Picerno
 */

#ifndef _STACKTYPEH_
#define _STACKTYPEH_

#define MAX_ITEMS 10000

template<class ItemType>
class StackType {
 public:
    StackType();
    void MakeEmpty();
    bool IsEmpty() const;
    bool IsFull() const;
 	void Push(ItemType);
    void Pop(ItemType&);
 private:
    int top;
    ItemType items[MAX_ITEMS];
};

#endif

#include "StackType.cpp"
