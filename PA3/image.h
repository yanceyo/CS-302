/*
 * image.h
 *
 *  Created on: Sep 19, 2011
 *      Author: root
 */

#ifndef IMAGE_H_
#define IMAGE_H_

// Include files
#include<iostream>
#include<fstream>
#include"math.h"
#include"string.h"

class imageNode
{
public:
	imageNode() { row = 0; col = 0; }
	imageNode(int i, int j){row = i; col = j; }
	~imageNode() { row = 0; col = 0; }
	imageNode& operator=(imageNode& nNode)
	{
		row = nNode.row;
		col = nNode.col;
		return *this;
	}
        bool operator!=(imageNode nNode)
        {
            return( (row == nNode.row) && (col == nNode.col) );
        }

	int row;
	int col;
};

class Image
{
	public:
		Image();
		Image(int,int,int);
		~Image();
		Image(const Image&);
		void getImageInfo(int&,int&,int&);
		void setPixelVal(int,int,int);
		int getPixelVal(int,int);
		void getSubImage(int,int,int,int,Image&);
		int meanGray();
		void enlargeImage(int,Image&);
		void shrinkImage(int,Image&);
		void reflectImage(bool,Image&);
		void translateImage(int,Image&);
		void rotateImage(int,int,int,Image&);
		Image computeRegionsRecursive(Image &outImg, int iItem, int iMatch, int &imgRow, int &imgCol, int iSearchSec);
		Image operator+(Image);
		Image operator-(Image);
		Image& operator=(const Image&);
		Image negateImage();
		Image threshold(int t);
		Image dilate();
		Image erode();

	private:
		int N, M, Q; // # of rows,col, & gray-level val
		int **pixelValue;
};

#endif /* IMAGE_H_ */
