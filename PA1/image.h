#ifndef IMAGE_H
#define IMAGE_H



// Include files
#include<iostream>
#include<fstream>
#include"math.h"

class Image
{
	public:
		Image();
		Image(int,int,int);
		~Image();
		Image(const Image&);
		Image& operator=(const Image&);
		void getImageInfo(int&,int&,int&);
		void setPixelVal(int,int,int);
		void getPixelVal(int,int,int&);
		void getSubImage(int,int,int,int,Image&);
		int meanGray();
		void enlargeImage(int,Image&);
		void shrinkImage(int,Image&);
		void reflectImage(bool,Image&);
		void translateImage(int,Image&);
		void rotateImage(int,Image&);
		Image operator+(Image);
		Image operator-(Image);
		Image negateImage(); // may need changing
	private:
		int N, M, Q; // # of rows,col, & gray-level val
		int **pixelValue;
};

#endif
