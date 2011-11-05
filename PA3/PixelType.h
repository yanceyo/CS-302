/*
 * PixelType.h
 *
 *  Created on: Oct 29, 2011
 *      Author: yanceyo
 */

#ifndef PIXELTYPE_H_
#define PIXELTYPE_H_

// Global type - temp setup
const int MAX = 10000;

template<class ItemType>
class PixelType
{
	public:
		void MakeEmpty();
		bool isFull() const;
		int LengthIs() const;
		void RetrieveItem(ItemType&,bool&);
		void InsertItem(ItemType);
		void DeleteItem(ItemType);
		void ResetList();
		bool isLastItem();
		void GetNextItem(ItemType&);
                bool operator<(PixelType);
                bool operator!=(PixelType);
                PixelType& operator=(PixelType&);
	private:
		int length;
		ItemType info[MAX];
                int listCsr;
};

#include "PixelType.cpp"

#endif /* PIXELTYPE_H_ */
