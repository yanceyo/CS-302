/*
 * image.cpp
 *
 *  Created on: Sept 29, 2011
 *      Author: Oliver Yancey and Caitlin Picerno
 */

#include "image.h"
#include<ios>
#include<fstream>
#include"math.h"
#include"string.h"

using namespace std;

Image::Image()
{
	N = 0;
	M = 0;
	Q = 0;

	pixelValue = NULL;
}

Image::Image(int tmpN, int tmpM, int tmpQ)
{
	int i, j;

	N = tmpN;
	M = tmpM;
	Q = tmpQ;

	pixelValue = new int* [N];
	for (i=0; i<N; i++)
	{
		pixelValue[i] = new int[M];
		for (j=0; j<M; j++)
			pixelValue[i][j] = Q;
	}
}

Image::~Image()
{
	// dealloc mem for pixelValue
	for( int i = 0; i < N; i++)
		delete [] pixelValue[i];
	delete [] pixelValue;
}

Image::Image(const Image& cpyImg)
{
	int i,j;
	N = cpyImg.N;
	M = cpyImg.M;
	Q = cpyImg.Q;

	pixelValue = new int* [N];
	for (i=0; i<N; i++)
	{
		pixelValue[i] = new int[M];
		for (j=0; j<M; j++)
		{
			pixelValue[i][j] = cpyImg.pixelValue[i][j];
		}
	}
}

void Image::getImageInfo(int& noRows, int& noCols, int& maxVal)
{
	// height (# of rows)
	noRows = N;
	// width (# of columns)
	noCols = M;
	//max gray-level value allowed
	maxVal = Q;
}

void Image::setPixelVal(int r, int c, int value)
{
	if (( r >= 0 && r < N ) && ( c >= 0 && c <  M))
	{
		// set pixel value at (r, c) location to value
		pixelValue[r][c] = value;
	}
	// an out-of-bounds exception should be raised if (r,c) falls outside the image
	else
	{
		cout<<"R: "<<r<<" C: "<<c<<endl;
		cout<<"N: "<<N<<" M: "<<M<<endl;
		cout << endl << " Set Pixel Value is out-of-bounds!" << endl << endl;
	}
}

int Image::getPixelVal(int r,int c)
{
	// an out-of-bounds exception should be raised if (r,c) falls outside the image
	if (( r >= 0 && r < N ) && ( c >= 0 && c < M ))
	{
		// return pixel value at (r, c) location
		return pixelValue[r][c];
	}
	else
	{
		cout<<"R: "<<r<<" C: "<<c<<endl;
		cout<<"N: "<<N<<" M: "<<M<<endl;
		cout << endl << " Get Pixel Value is out-of-bounds!" << endl << endl;
	}

	return 0;
}


void Image::getSubImage(int ULr, int ULc, int LRr, int LRc, Image& oldImage) // Oliver
{
	// Goal: grab part of the picture (usually for analysis)
	// Returns: none

	// Init vars
	int i,j;
	int k = 0;
	int l = 0;
	Image *csrHead;
	int iNewRow = LRr - ULr;
	int iNewCol = LRc - ULc;

	// Create a new image with the same
	// gray levels, but size by taking
	// ULr - LRr for the rows and
	// ULc - LRc for the cols
	Image imgSub(iNewRow, iNewCol, Q);

	// Create a "head" cursor
	// by copying the ref of oldImage
	csrHead = &imgSub;

	// Loop using ULr as the starting point for rows
	// and loop until LRr is reached
	for ( i=ULr; i<LRr; i++)
	{
		// Loop using ULc as the starting point for col
		// and loop until LRc is reached.
		for ( j=ULc; j<LRc; j++)
		{
			// Set pixel value for new image
			imgSub.setPixelVal(k, l, oldImage.getPixelVal(i,j));

			// Increment l to move to the next sub image column
			l++;
		}

		// Increment k to move to the next sub image row and reset column
		k++;
		l = 0;
	}

	// Dealloc oldImage to
	// prepare for reuse
	// delete[] oldImage;

	// Set ref of oldImage to new Image
	// created in function
	oldImage = *csrHead;
}

int Image::meanGray()	// Oliver
{
	// Goal: Calculates the average gray level result
	// Returns: int of average gray value

	// Init var
	int i,j;
	int iNumItems = N*M;
	int sum = 0;

	// Loop through rows
	for (i=0; i<N; i++)
	{
		// Loop through columns
		for (j=0; j<M; j++)
		{
			// Grab gray value
			sum += pixelValue[i][j];
		}
	}

	// return average
	return sum/iNumItems;
}

void Image::enlargeImage(int s, Image& oldImage) //Caitlin
{
	int currentPixVal = 0;
	int rowOffset = 0;
	int colOffset = 0;
	int origR, origC, newR, newC;
	int oldN, oldM, oldQ;
	oldImage.getImageInfo(oldN,oldM,oldQ);

	// error
	if ( s < 1 )
	{
		cout << "Cannot enlarge image by " << s << "!" << endl << endl;
		return;
	}

	// multiply the rows by s, multiply the columns by s to get new array size
	int newRow = s * oldN;
	int newCol = s * oldM;
	Image largeImage(newRow, newCol, oldQ);


	// looping through original image and enlarging into new array
	for ( origR = 0; origR < oldN; origR++ )
	{
		for ( origC = 0; origC < oldM; origC++ )
		{
			// find current value and row/col
			currentPixVal = oldImage.getPixelVal( origR, origC );
			rowOffset = origR * s;
			colOffset = origC * s;

			// enlarging original pixel
			for ( newR = rowOffset; newR < rowOffset + s; newR++ )
			{
				for ( newC = colOffset; newC < colOffset + s; newC++ )
				{
					largeImage.setPixelVal( newR, newC, currentPixVal );
				}
			}
		}
	}

	// set image to enlarged image
	oldImage = largeImage;
}

void Image::shrinkImage(int s, Image& oldImage)	//Caitlin
{

	int currentPixVal = 0;
	int rowOffset = 0;
	int colOffset = 0;
	int origR, origC;
	//int newR, newC;
	int oldN, oldM, oldQ;
	oldImage.getImageInfo(oldN,oldM,oldQ);
	// error
	if ( s < 1 )
	{
	  	cout << "Cannot shrink image by " << s << "!" << endl << endl;
		return;
	}

	// multiply the rows by s, multiply the columns by s to get new array size
	int newRow = oldN/s;
	int newCol = oldM/s;
	Image smallImage(newRow, newCol, oldQ);

	// set pixel at every other column at every other row to smaller image
	for ( origR = 0; origR < newRow; origR++ )
	{
		for ( origC = 0; origC < newCol; origC++ )
		{
			// find current value and row/col
			rowOffset = origR * s;
			colOffset = origC * s;
			currentPixVal = oldImage.getPixelVal( rowOffset, colOffset );
			smallImage.setPixelVal( origR, origC, currentPixVal );
		}
	}

	// set image to shrunk image
	oldImage = smallImage;
}

void Image::reflectImage(bool flag, Image& oldImage) // Oliver
{
	// Goal: Reflect image horizontally if true,
	// vertical if false;
	// Returns: none
	// Returns: None
	int oldN, oldM, oldQ;

	// get image info of original image
	oldImage.getImageInfo(oldN,oldM,oldQ);
	Image tempImage(oldN,oldM,255);
	// Init vars
	int i,j;
	int k = 0;
	int l = 0;

	// Flag true reflect horizontal
	if ( flag )
	{
		// Loop starting at the number of
		// rows and decrementing to zero
		for ( i = 0; i < oldN; i++)
		{
			// Loop starting at the number of
			// columns and decrementing to zero
			for ( j = oldM-1; j >= 0; j--)
			{
				// Starting at the beginning row
				// and column set the pixelValue
				// effectively reflecting the image
				tempImage.setPixelVal(l, k, oldImage.getPixelVal(i,j));

				// increment start column counter
				k++;
			}

			// Increment start row counter and reset column
			l++;
			k = 0;
		}
	}
	else // false reflect vertically
	{
		// Loop starting at the number of
		// rows and decrementing to zero
		for ( i = oldN-1; i >= 0; i--)
		{
			// Loop starting at the number of
			// columns and decrementing to zero
			for ( j = 0; j < oldM; j++)
			{
				// Starting at the beginning row
				// and column set the pixelValue
				// effectively reflecting the image
				tempImage.setPixelVal(l, k, pixelValue[i][j]);

				// increment start column counter
				k++;
			}

			// Increment start row counter and reset column
			l++;
			k = 0;
		}
	}
	oldImage = tempImage;
}

// translates the pixel locations by some amount t
void Image::translateImage(int t, Image& oldImage) //Caitlin
{

	int row, col;
	int oldN, oldM, oldQ;

	// get image info of original image
	oldImage.getImageInfo(oldN,oldM,oldQ);

	// setting original perimeters to new image and setting to black
	Image transImage(oldN, oldM, 255);
	if ( t > 0 )
	{
		// filling new image with translated old image
		for ( row = 0; row < oldN; row++ )
		{
			for ( col = 0; col < oldM; col++ )
			{
				if ( ( (row+t) < oldN ) && ( col+t < oldM ) )
				{
					transImage.setPixelVal( row+t, col+t, oldImage.getPixelVal(row, col));
				}
			}
		}
	}
// t is negative
	else
	{
		// filling new image with translated old image
		for ( row = 0; row < oldN; row++ )
		{
			for ( col = 0; col < oldM; col++ )
			{
				if ( ( (row+t) >= 0 ) && ( col+t >= 0 ) )
				{
					transImage.setPixelVal( row+t, col+t, oldImage.getPixelVal(row, col));
				}
			}
		}

	}

	oldImage = transImage;

}

void Image::rotateImage(int theta, int iCenterRow, int iCenterCol, Image& oldImage)	// Oliver
{
	// Goal: rotate oldImage by theta around a point
	// Returns: None
	int oldN, oldM, oldQ;

	// get image info of original image
	oldImage.getImageInfo(oldN,oldM,oldQ);
	// Init vars
	int i,j;
	int iNewRow, iNewCol;
	const float PI = 3.14159265;
	Image tempImage(oldN,oldM,255);
	int currentPixelVal;

	// Convert theta to radians
	float newTheta = (theta * PI)/180.0;

	// Loop through rows and cols and set value
	for ( i = 0; i < oldN; i++ )
	{
		// Loop - cols
		for ( j = 0; j < oldM; j++ )
		{
			// Check new pixelValue and
			// if out of bounds continue on
			// otherwise set value
			iNewRow = iCenterRow + (i - iCenterRow) * cos(newTheta) - (j - iCenterCol) * sin(newTheta);
			iNewCol = iCenterCol + (i - iCenterRow) * sin(newTheta) + (j - iCenterCol) * cos(newTheta);

			if ( (iNewRow >= oldN) || (iNewRow < 0) || (iNewCol >= oldM) || (iNewCol < 0) )
			{
				continue;
			}
			currentPixelVal = oldImage.getPixelVal(i,j);
			tempImage.setPixelVal(iNewRow, iNewCol, currentPixelVal );
		}
	}
	oldImage = tempImage;
}

Image Image::negateImage()	// Caitlin
{
	Image imgNeg(N,M,Q);
	int row, col, origPixVal;

	// loop through array
	for ( row = 0; row < N; row++ )
	{
		for ( col = 0; col < M; col++ )
		{
			// find pixel value and set to negated value
			origPixVal = pixelValue[row][col];
			imgNeg.setPixelVal(row, col, 255-origPixVal);
		}
	}

	return imgNeg;
}

Image Image::operator+(Image image1) // Oliver
{
	// Goal: Adds parts of two images together
	// Return: Combined image from two pictures.
	Image imgSum;

	// Init vars
	int i,j;
	int iImg1Val = 0;
	int iImg2Val = 0;
	float a = 0.7;

	// Loop through rows and columns
	for ( i = 0; i < N; i++ )
	{
		for ( j = 0; j < M; j++ )
		{
			// Sum row and column part
			iImg1Val = getPixelVal(i, j);
			iImg2Val = image1.getPixelVal(i, j);

			iImg1Val *= a;
			iImg2Val *= (1 - a);

			pixelValue[i][j] = iImg1Val + iImg2Val;
		}
	}

	return *this;
}

// change detector
Image Image::operator-(Image image1) //Caitlin
{
	int row, col;
	int im1N, im1M, im1Q;
	int currentPixVal = 0;

	// get image info of original image
	image1.getImageInfo(im1N,im1M,im1Q);
	//Image imgDif(N, M, Q);

	//
	if ( ( im1N != N ) ||
			 ( im1M != M ))
	{
		return *this;
	}
	// O(r,c) = abs(1sub1(r,c) - 1sub2(r,c) )
	for ( row = 0; row < N; row++ )
	{
		for ( col = 0; col < M; col++ )
		{
			currentPixVal = fabs( image1.getPixelVal(row,col) - getPixelVal(row,col) );
			setPixelVal(row,col,currentPixVal);
		}
	}

	return *this;
}

Image& Image::operator=(const Image& imgAssign)	// Oliver
{
	int i,j;
	N = imgAssign.N;
	M = imgAssign.M;
	Q = imgAssign.Q;

	pixelValue = new int* [N];
	for (i=0; i<N; i++)
	{
		pixelValue[i] = new int[M];
		for (j=0; j<M; j++)
		{
			pixelValue[i][j] = imgAssign.pixelValue[i][j];
		}
	}

	return *this;
}

Image Image::threshold(int T) // Oliver
{
	// Init vars
	int i,j;
	int iTestVal = 0;

	// Loop through image
	for(i=0; i<N; i++)
	{
		for(j=0; j<M; j++)
		{
			// get pixelValue
			iTestVal = pixelValue[i][j];

			// check pixelValue against threshold
			// and set to 0 if <= and 255 if >
			if( iTestVal <= T )
				setPixelVal(i,j,0);
			else
				setPixelVal(i,j,255);
		}
	}

	return *this;
}

Image Image::dilate() // Oliver
{
	int row, col;
	int newRow, newCol;
	int nRow, nCol;
	Image tempImage = *this;

	// loop through image
	for( row = 0; row < N; row++ )
	{
		for( col = 0; col < M; col++ )
		{
			// if image value is white
			if( pixelValue[row][col] ==  255 )
			{
				// check neighbors
				for ( nRow = -1; nRow < 2; nRow++)
				{
					for ( nCol = -1; nCol < 2; nCol++ )
					{
						newRow = row + nRow;
						newCol = col + nCol;

						// if within bounds of image and not original row/col
						if ( (newRow > -1 && newRow < N) && (newCol > -1 && newCol < M) && (newRow != row && newCol != col))
						{
							//if pixel value is black
							if( pixelValue[newRow][newCol] == 0)
							{
								// set tempImage pixel to white
								tempImage.setPixelVal(row, col, 255);
							}
						}
					}
				}
			}
		}
	}
	return tempImage;
}

Image Image::erode() // Caitlin
{
	int row, col;
	int newRow, newCol;
	int nRow, nCol;
	Image tempImage = *this;

	// loop through image
	for( row = 0; row < N; row++ )
	{
		for( col = 0; col < M; col++ )
		{
			// if image value is white
			if( pixelValue[row][col] == 255 )
			{
				// check neighbors
				for ( nRow = -1; nRow < 2; nRow++)
				{
					for ( nCol = -1; nCol < 2; nCol++ )
					{
						newRow = row + nRow;
						newCol = col + nCol;

						// if within bounds of image and not original row/col
						if ( (newRow > -1 && newRow < N) && (newCol > -1 && newCol < M) && (newRow != row && newCol != col))
						{
							//if pixel value is black
							if( pixelValue[newRow][newCol] == 0)
							{
								// set tempImage pixel to black
								tempImage.setPixelVal(row, col, 0);
							}
						}
					}
				}
			}
		}
	}
	return tempImage;
}

Image Image::computeRegionsRecursive(Image &outImg, int iItem, int iMatch, int &imgRow, int &imgCol, int iSearchSec) // Oliver
{
	// Init vars
	int i,j;
	int iSubRow = 0;
	int iSubCol = 0;
	int iTestRow = imgRow;
	int iInitRow = imgRow;
	int iInitCol = imgCol;
	int iTestCol = imgCol;
	bool bNeighbor = false;
	bool bChkRowBelow = false;
	bool bChkColRight = false;

	// Loop till row iterative counter < iSearchSec
	for( i = 0; i < iSearchSec; i++)
	{
		// Check if row above or bottom will be checked
		bChkRowBelow = (i % 2) == 1;

		// Set test row
		if( bChkRowBelow )
			iTestRow += i - iSubRow;
		else
			iTestRow -= i + iSubRow;

		// If row doesn't exist, move to a row that exists
		if( iTestRow < 0 || iTestRow >= N)
		{
			if( bChkRowBelow )
			{
				iSubRow = iTestRow - i;
				iTestRow -= iSubRow;
			}
			else
			{
				iSubRow = i - iTestRow;
				iTestRow += iSubRow;
			}
		}

		// Loop till col iterative counter < iSearchSec
		for( j = 0; j < iSearchSec; j++)
		{
			// Check if col left or right will be checked
			bChkColRight = (j % 2) == 1;

			// Set test col
			if( bChkColRight )
				iTestCol += j - iSubCol;
			else
				iTestCol -= j + iSubCol;

			// If col doesn't exist, move to a col that exists
			if( iTestCol < 0 || iTestCol >= M)
			{
				if( bChkColRight )
				{
					iSubCol = iTestCol - j;
					iTestCol -= iSubCol;
				}
				else
				{
					iSubCol = j - iTestCol;
					iTestCol += iSubCol;
				}
			}

			// Get pixelValue and compare to iMatch
			//   True: write iItem to outImg
//			cout << "Row: " << iTestRow << "Column: " << iTestCol
//				 << " Value: " << pixelValue[iTestRow][iTestCol] << endl;
			if( pixelValue[iTestRow][iTestCol] == iMatch)
				bNeighbor = true;
		}

		// Reset iTestCol
		iTestCol = imgCol;
	}

	// Check if imgRow and imgCol isn't max True: increment imgRow and recursive call
	if( !(imgRow >= N && imgCol >= M) )
	{
		// Check if imgCol is max
		// True: reset imgCol and increment imgRow
		// False: increment imgCol
		if( imgCol >= M)
		{
			imgCol = 0;
			imgRow++;
		}
		else
			imgCol++;

		// Mark point if a neighbor was found
		if(bNeighbor)
			outImg.pixelValue[iInitRow][iInitCol] = iItem;

		// Recursive call
		computeRegionsRecursive(outImg, iItem, iMatch, imgRow, imgCol, iSearchSec);
	}

	return *this;
}

