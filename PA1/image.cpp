/*
 * image.cpp
 *
 *  Created on: Sep 13, 2011
 *      Author: Oliver Yancey
 */

using namespace std;

#include"image.h"

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
 for(i=0; i<N; i++) {
   pixelValue[i] = new int[M];
   for(j=0; j<M; j++)
     pixelValue[i][j] = 0;
 }
}

Image::Image(const Image& cpyImg)
{
	int i,j;
	N = cpyImg.N;
	M = cpyImg.M;
	Q = cpyImg.Q;

	pixelValue = new int* [N];
	for(i=0; i<N; i++)
	{
		pixelValue[i] = new int[M];
		for(j=0; j<M; j++)
		{
			pixelValue[i][j] = cpyImg.pixelValue[i][j];
		}
	}
}

Image::~Image()
{
	// dealloc mem for pixelValue
	delete[]pixelValue;
}

void Image::getImageInfo(int& rows, int& cols, int& levels)
{
 rows = N;
 cols = M;
 levels = Q;
}

void Image::setPixelVal(int i, int j, int val)
{
 pixelValue[i][j] = val;
}

void Image::getPixelVal(int i, int j, int& val)
{
 val = pixelValue[i][j];
}


void Image::getSubImage(int ULr, int ULc, int LRr, int LRc, Image& oldImage)
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
	for( i=ULr; i<LRr; i++)
	{
		// Loop using ULc as the starting point for col
		// and loop until LRc is reached.
		for( j=ULc; j<LRc; j++)
		{
			// Set pixel value for new image
			imgSub.setPixelVal(k, l, pixelValue[i][j]);
			
			// Increment l to move to the next sub image column
			l++;
		}

		// Increment k to move to the next sub image row
		k++;
	}

	// Dealloc oldImage to
	// prepare for reuse
	// delete[] oldImage;
	
	// Set ref of oldImage to new Image
	// created in function
	oldImage = *csrHead;
}

int Image::meanGray()
{
	// Goal: Calculates the average gray level result
	// Returns: int of average gray value

	// Init var
	int i,j;
	int iNumItems = N*M;
	int sum = 0;

	// Loop through rows
	for(i=0; i<N; i++)
	{
		// Loop through columns
		for(j=0; j<M; j++)
		{
			// Grab gray value
			sum += pixelValue[i][j];
		}
	}

	// return average
	return sum/iNumItems;
}

void Image::enlargeImage(int s, Image& oldImage)
{

}

void Image::shrinkImage(int s, Image& oldImage)
{

}

void Image::reflectImage(bool flag, Image& oldImage)
{

}

void Image::translateImage(int t, Image& oldImage)
{

}

void Image::rotateImage(int theta, Image& oldImage)
{

}

Image Image::operator+(Image image1)
{
	Image imgSum;



	return imgSum;
}

Image Image::operator-(Image image1)
{
	Image imgDif;



	return imgDif;
}

Image negateImage()
{
	Image imgNeg;

	return imgNeg;

}

Image& Image::operator=(const Image& imgAssign)
{
	int i,j;
	N = imgAssign.N;
	M = imgAssign.M;
	Q = imgAssign.Q;

	pixelValue = new int* [N];
	for(i=0; i<N; i++)
	{
		pixelValue[i] = new int[M];
		for(j=0; j<M; j++)
		{
			pixelValue[i][j] = imgAssign.pixelValue[i][j];
		}
	}

	return *this;
}




