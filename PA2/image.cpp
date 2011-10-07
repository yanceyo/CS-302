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
	// Goal: Reflect image horizontally if true,
	// vertical if false;
	// Returns: none

	// Init vars
	int i,j;
	int k = 0;
	int l = 0;

	// Flag true reflect horizontal
	if( flag )
	{
		// Loop starting at the number of
		// rows and decrementing to zero
		for( i = 0; i < N; i++)
		{
			// Loop starting at the number of
			// columns and decrementing to zero
			for( j = M-1; j >= 0; j--)
			{
				// Starting at the beginning row
				// and column set the pixelValue
				// effectively reflecting the image
				oldImage.setPixelVal(l, k, pixelValue[i][j]);

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
		for( i = N-1; i >= 0; i--)
		{
			// Loop starting at the number of
			// columns and decrementing to zero
			for( j = 0; j < M; j++)
			{
				// Starting at the beginning row
				// and column set the pixelValue
				// effectively reflecting the image
				oldImage.setPixelVal(l, k, pixelValue[i][j]);

				// increment start column counter
				k++;
			}

			// Increment start row counter and reset column
			l++;
			k = 0;
		}
	}
}

void Image::translateImage(int t, Image& oldImage)
{

}

void Image::rotateImage(int theta, Image& oldImage)
{
	// Goal: rotate oldImage by theta around a point
	// Returns: None

	// Init vars
	int i,j;
	int iCenterRow = 0;
	int iCenterCol = 0;
	int iNewRow = 0;
	int iNewCol = 0;
	const int PI = 3.14159265;

	// Convert theta to radians
	theta = ((float)theta * PI)/180.0;

	// Ask for initial point to center
	cout << "Please enter row to center around: ";
	cin >> iCenterRow;

	cout << "Please enter col to center around: ";
	cin >> iCenterCol;

	// Loop through rows and cols and set value
	for( i = 0; i < N; i++ )
	{
		// Loop - cols
		for( j = 0; j < M; j++ )
		{
			// Check new pixelValue and
			// if out of bounds continue on
			// otherwise set value
			iNewRow = iCenterRow + (i - iCenterRow) * cos(theta) - (j - iCenterCol) * sin(theta);
			iNewCol = iCenterCol + (i - iCenterRow) * sin(theta) + (j - iCenterCol) * cos(theta);

			if( iNewRow >= N || iNewRow < 0 ||
				iNewCol >= M || iNewCol < 0 )
			{
				continue;
			}

			oldImage.setPixelVal(iNewRow, iNewCol, pixelValue[i][j] );
		}
	}

}

Image Image::threshold(int T)
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
			// cout << i << " " << j << " pixelValue: " << iTestVal << endl;

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

Image Image::operator+(Image image1)
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
	for( i = 0; i < N; i++ )
	{
		for( j = 0; j < M; j++ )
		{
			// Sum row and column part
			getPixelVal(i, j, iImg1Val);
			image1.getPixelVal(i, j, iImg2Val);

			iImg1Val *= a;
			iImg2Val *= (1 - a);

			pixelValue[i][j] = iImg1Val + iImg2Val;
		}
	}

	return *this;
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




