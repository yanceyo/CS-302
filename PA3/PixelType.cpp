/*
 * PixelType.cpp
 *
 *  Created on: Oct 30, 2011
 *      Author: yanceyo
 */

template<class ItemType>
void PixelType<ItemType>::MakeEmpty()
{
    length = 0;
}

template<class ItemType>
bool PixelType<ItemType>::isFull() const
{
    return (length == MAX);
}

template<class ItemType>
int PixelType<ItemType>::LengthIs() const
{
    return length;
}

template<class ItemType>
void PixelType<ItemType>::RetrieveItem(ItemType &itmFind, bool &bFound)
{
    int iLoc = 0;
    bFound = false;

    while( (iLoc < length) && !bFound )
    {
        if(itmFind == info[iLoc])
        {
            bFound = true;
            itmFind = info[iLoc];
        }
        else
            iLoc++;
    }
}

template<class ItemType>
void PixelType<ItemType>::InsertItem(ItemType itmNew)
{
    info[length] = itmNew;
    length++;
}

template<class ItemType>
void PixelType<ItemType>::DeleteItem(ItemType itmDel)
{
    int iLoc = 0;

    while(itmDel != info[iLoc])
        iLoc++;

    info[iLoc] = info[length-1];

    length--;
}

template<class ItemType>
void PixelType<ItemType>::ResetList()
{
    listCsr = -1;
}

template<class ItemType>
bool PixelType<ItemType>::isLastItem()
{
    return (listCsr == length-1);
}

template<class ItemType>
void PixelType<ItemType>::GetNextItem(ItemType &item)
{
    listCsr++;
    item = info[listCsr];
}

template<class ItemType>
bool PixelType<ItemType>::operator<(PixelType pixCmp)
{
    // Purpose: Compares which PixelType is smaller by using length
    // Returns: true if assigned PixelType is smaller otherwise false

    // Compare length and return result
    return(length < pixCmp.length);
}

template<class ItemType>
bool PixelType<ItemType>::operator!=(PixelType pixCmp)
{
    // Purpose: Determines if the two PixelTypes are different
    // Returns: True if different, false if same

    // Compare if equal or different
    // Three outcomes have been listed
    //  First: length is different set to true
    //  Second: Difference found between values at
    //          index i, return true
    //  Third: All values match return false
    //
    // **NOTE** Since this is an unsorted list, it is possible
    // with how it's constructed at the moment for the list to
    // have the same list of items, just at different indexes in
    // info[i].
    if(length != pixCmp.length)
        return false;
    
    for (int i = 0; i < length; i++) 
    {
        // Difference found return true
        if(info[i] != pixCmp.info[i])
            return true;
    }
    
    // All the same return false
    return false;
}

template<class ItemType>
typename PixelType<ItemType>::PixelType& PixelType<ItemType>::operator=(PixelType &pixVal)
{
    // Purpose: if template imageNode to assign values to PixelType
    // Returns: Assigns pixVal to the assigned PixelType

    // Init vars
    
    
    // Copy imageNode data from pixVal to assigned PixelType
    for( int i = 0; i < pixVal.length; i++ )
    {
        info[i] = pixVal.info[i];
    }
    
    return *this;

}
