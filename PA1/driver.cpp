/*
 * driver.cpp
 *
 *  Created on: Sep 13, 2011
 *      Author: Oliver Yancey
 */

// Header files
#include"image.h"

using namespace std;

// Global constants

// Function prototypes
void readImage(char[], Image&);
void writeImage(char[], Image&);
void readImageHeader(char[],int&,int&,int&,bool&);

// Main
int main()
{
	// Question: How do I dynamically size image
	// without using readImageHeader
	int iN, iM, iQ;
	int iAvgGrayLvl;
	bool type;
	char* cpImgName;
	char cpSaveFile[] = "new_image.pgm";

	cout << "Please enter filename:";
	cin >> cpImgName;

	readImageHeader(cpImgName, iN, iM, iQ, type);

	Image imgTest(iN, iM, iQ);
	Image imgSub;

	readImage(cpImgName, imgTest);

	// Menu option of meanGray()
	/*
		// Get Avg G lvl
		iAvgGrayLvl = imgTest.meanGray();

		cout << "Average gray level is: " << iAvgGrayLvl << endl << endl;
	*/

	imgTest.getSubImage(0,0,1,1,imgSub);

	writeImage(cpSaveFile,imgTest);

	// Exit Main
	return 0;
}

// Supporting Functions
void readImage(char fname[], Image& image)
{
 int i, j;
 int N, M, Q;
 unsigned char *charImage;
 char header [100], *ptr;
 ifstream ifp;

 ifp.open(fname, ios::in | ios::binary);

 if (!ifp) {
   cout << "Can't read image: " << fname << endl;
   exit(1);
 }

 // read header

 ifp.getline(header,100,'\n');
 if ( (header[0]!=80) ||    /* 'P' */
      (header[1]!=53) ) {   /* '5' */
      cout << "Image " << fname << " is not PGM" << endl;
      exit(1);
 }

ifp.getline(header,100,'\n');
 while(header[0]=='#')
   ifp.getline(header,100,'\n');

 M=strtol(header,&ptr,0);
 N=atoi(ptr);

 ifp.getline(header,100,'\n');
 Q=strtol(header,&ptr,0);

 charImage = (unsigned char *) new unsigned char [M*N];

 ifp.read( reinterpret_cast<char *>(charImage), (M*N)*sizeof(unsigned char));

 if (ifp.fail()) {
   cout << "Image " << fname << " has wrong size" << endl;
   exit(1);
 }

 ifp.close();

 //
 // Convert the unsigned characters to integers
 //

 int val;

 for(i=0; i<N; i++)
   for(j=0; j<M; j++) {
     val = (int)charImage[i*M+j];
     image.setPixelVal(i, j, val);
   }

 delete [] charImage;

}

void writeImage(char fname[], Image& image)
{
 int i, j;
 int N, M, Q;
 unsigned char *charImage;
 ofstream ofp;

 image.getImageInfo(N, M, Q);

 charImage = (unsigned char *) new unsigned char [M*N];

 // convert the integer values to unsigned char

 int val;

 for(i=0; i<N; i++)
   for(j=0; j<M; j++) {
     image.getPixelVal(i, j, val);
     charImage[i*M+j]=(unsigned char)val;
   }

 ofp.open(fname, ios::out | ios::binary);

 if (!ofp) {
   cout << "Can't open file: " << fname << endl;
   exit(1);
 }

 ofp << "P5" << endl;
 ofp << M << " " << N << endl;
 ofp << Q << endl;

 ofp.write( reinterpret_cast<char *>(charImage), (M*N)*sizeof(unsigned char));

 if (ofp.fail()) {
   cout << "Can't write image " << fname << endl;
   exit(0);
 }

 ofp.close();

 delete [] charImage;

}

void readImageHeader(char fname[], int& N, int& M, int& Q, bool& type)
{
 char header [100], *ptr;
 ifstream ifp;

 ifp.open(fname, ios::in | ios::binary);

 if (!ifp) {
   cout << "Can't read image: " << fname << endl;
   exit(1);
 }

 // read header

 type = false; // PGM

 ifp.getline(header,100,'\n');
 if ( (header[0] == 80) &&  /* 'P' */
      (header[1]== 53) ) {  /* '5' */
      type = false;
 }
 else if ( (header[0] == 80) &&  /* 'P' */
      (header[1] == 54) ) {        /* '6' */
      type = true;
 }
 else {
   cout << "Image " << fname << " is not PGM or PPM" << endl;
   exit(1);
 }

ifp.getline(header,100,'\n');
 while(header[0]=='#')
   ifp.getline(header,100,'\n');

 M=strtol(header,&ptr,0);
 N=atoi(ptr);

 ifp.getline(header,100,'\n');

 Q=strtol(header,&ptr,0);

 ifp.close();

}


