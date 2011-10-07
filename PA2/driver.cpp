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
  bool type,bHorz;
  int row1 = 0;
  int col1 = 0;
  int row2 = 0;
  int col2 = 0;
  int iThresVal;
  char cpImgName[40];
  char sAns[40];
  char cpSaveFile[] = "new_image.pgm";

  cout << "Please enter filename: ";
  cin >> cpImgName;

  cout << endl << "Please put in threshold value: ";
  cin >> iThresVal;

  readImageHeader(cpImgName, iN, iM, iQ, type);

  Image imgTest(iN, iM, iQ);

  readImage(cpImgName, imgTest);

  Image imgSub(imgTest);

  // Menu option of meanGray()
  /*
    // Get Avg G lvl
    iAvgGrayLvl = imgTest.meanGray();

    cout << "Average gray level is: " << iAvgGrayLvl << endl << endl;
  */

  // Menu option for getSubImage()
    /*
      // Get ULr
      cout << "Please enter upper left row: ";
      cin >> row1;

      // Get ULc
      cout << endl << "Please enter upper left column: ";
      cin >> col1;

      // Get LRr
      cout << endl << endl << "**Note lower right values should be higher than upper left**"
         << endl << "Please enter lower right row: ";
      cin >> row2;

      // Get LRc
      cout << endl << "Please enter lower right column: ";
      cin >> col2;

      //imgTest.getSubImage(row1,col1,row2,col2,imgSub);
    */

  // Menu option for reflectImage()
  /*
     cout << "Do you want to reflect horizontally? (No will reflect vertically) ";

     cin >> sAns;

     // Need to use string library or due a quick string compare function to
     // have sAns be better compared since any answer will come out to
     // false at the moment, possible changes could be changing to single
     // quotes as a fix as well.
     if( strcmp(sAns, "Yes") == 0 || strcmp(sAns, "yes") == 0 ||
          strcmp(sAns, "Y") == 0 || strcmp(sAns, "y") == 0 )
     {
       bHorz = true;
     }
     else
     {
       bHorz = false;
     }

     imgTest.reflectImage(bHorz, imgSub);
  */

    imgSub.threshold(iThresVal);

  writeImage(cpSaveFile,imgSub);

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
