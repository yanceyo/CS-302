/*
 * RegionType.h
 *
 *  Created on: Oct 29, 2011
 *      Author: yanceyo
 */

#ifndef REGIONTYPE_H_
#define REGIONTYPE_H_

// Global type - temp setup
const int MAX_ITEM = 10000;

class key
{
    public:
        bool operator<(key cmpReg)
        {
            // Compare length of PixelType and
            // returns result
            return (listPix < cmpReg.listPix);
        }
        
        bool operator!=(key cmpReg)
        {
            return (listPix != cmpReg.listPix);
        }
        
        // int x and y will be replaced by the
        // geometric and intensity properties
        // I didn't remove and put with imageNode
        // since I didn't want the PixelType and
        // properties to be tied to each x and y
        // listed
        int y;
        PixelType<imageNode> listPix;
        ImgGeo propGeo;
};

template<class ItemType>
class RegionType
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
	private:
		int length;
                ItemType info[MAX_ITEMS];
                int listCsr;
};

#include "RegionType.cpp"

#endif /* REGIONTYPE_H_ */
