/*
 * RegionType.cpp
 *
 *  Created on: Oct 30, 2011
 *      Author: yanceyo
 */

template<class ItemType>
void RegionType<ItemType>::MakeEmpty()
{
    length = 0;
}

template<class ItemType>
bool RegionType<ItemType>::isFull() const
{
    return (length == MAX_ITEM);
}

template<class ItemType>
int RegionType<ItemType>::LengthIs() const
{
    return length;
}

template<class ItemType>
void RegionType<ItemType>::RetrieveItem(ItemType &itmFind, bool &bFound)
{
    int iMid;
    int iFirst = 0;
    int iLast = length - 1;

    bFound = false;
    while( (iFirst <= iLast) && !bFound)
    {
        iMid = (iFirst + iLast)/2;
        if( itmFind < info[iMid] )
            iLast = iMid - 1;
        else if( itmFind > info[iMid] )
            iFirst = iMid + 1;
        else
        {
            bFound = true;
            itmFind = info[iMid];
        }
    }
}

template<class ItemType>
void RegionType<ItemType>::InsertItem(ItemType itmNew)
{
    int iLoc = 0;
    bool bFound = false;

    while( (iLoc < length) && !bFound )
    {
        if(itmNew < info[iLoc])
            bFound = true;
        else
            iLoc++;
    }

    for(int i = length; i > iLoc; i--)
        info[i] = info[i-1];

    info[iLoc] = itmNew;
    length++;
}

template<class ItemType>
void RegionType<ItemType>::DeleteItem(ItemType itmDel)
{
    int iLoc = 0;

    while(itmDel != info[iLoc])
        iLoc++;

    for(int i = iLoc + 1; i < length; i++)
        info[i-1] = info[i];

    length--;
}

template<class ItemType>
void RegionType<ItemType>::ResetList()
{
    listCsr = -1;
}

template<class ItemType>
bool RegionType<ItemType>::isLastItem()
{
    return (listCsr == length-1);
}

template<class ItemType>
void RegionType<ItemType>::GetNextItem(ItemType &item)
{
    listCsr++;
    item = info[listCsr];
}
