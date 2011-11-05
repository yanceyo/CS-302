#include "imageui.h"
#include <cstdlib>
#define MAX_QUE 10000

using namespace std;

imageUI::imageUI(QWidget *parent) //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    : QMainWindow(parent)
{
	ui.setupUi(this);
	image = NULL;
	N = 0;
	M = 0;
	Q = 0;
	tempFileName = "tempImage.pgm";
	ui.picture->setSizePolicy(QSizePolicy::Ignored,QSizePolicy::Ignored);
}

imageUI::~imageUI() //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
{
	delete image;
	image = NULL;
}

void imageUI::on_readInImage_clicked() //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
{
	fileName = ui.imageName->text();

	if (!fileName.isEmpty())
	{
		readImageHeader(fileName,N,M,Q);
		image = new Image(N,M,Q);
		readImage(fileName,image);

		// displays image
		writeImage(tempFileName, image);
		QPixmap tmpPixMap(tempFileName);
		ui.picture->setPixmap(tmpPixMap);
		ui.picture->resize(ui.picture->pixmap()->size());
	}
	else
	{
		QMessageBox msgBox;
		msgBox.setText("Read Image is Empty, please put in an Image name");
		msgBox.exec();
	}
}

void imageUI::on_enlargeImage_clicked() //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
{
	// if image is loaded
	if(image)
	{
		// grabbed data from the LineEdit text box
		QString size = ui.enlarge_LineEdit->text();

		if(size.toInt())
		{
			// create int for data inside text box
			int multiplier = size.toInt();

			// pass in variables to enlarge function
			image->enlargeImage(multiplier, *image);

			// display image
			writeImage(tempFileName, image);
			QPixmap tmpPixMap(tempFileName);
			ui.picture->setPixmap(tmpPixMap);
			ui.picture->resize(ui.picture->pixmap()->size());
		}
		else
		{
			QMessageBox msgBox;
			msgBox.setText("Data entered is not an integer");
			msgBox.exec();
		}
	}
	else
	{
		QMessageBox msgBox;
		msgBox.setText("Please read in an image");
		msgBox.exec();
	}
}

void imageUI::on_shrinkImage_clicked() //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
{
	// if image is loaded
	if(image)
	{
		// grabbed data from the LineEdit text box
		QString size = ui.shrink_LineEdit->text();

		if(size.toInt())
		{
			// create int for data inside text box
			int multiplier = size.toInt();

			// pass in variables to shrink function
			image->shrinkImage(multiplier, *image);

			// display image
			writeImage(tempFileName, image);
			QPixmap tmpPixMap(tempFileName);
			ui.picture->setPixmap(tmpPixMap);
			ui.picture->resize(ui.picture->pixmap()->size());
		}
		else
		{
			QMessageBox msgBox;
			msgBox.setText("Shrink Image is not an integer");
			msgBox.exec();
		}
	}
	else
	{
		QMessageBox msgBox;
		msgBox.setText("Please read in an image");
		msgBox.exec();
	}
}

void imageUI::on_translateImage_clicked() //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
{
	// if image is loaded
	if(image)
	{
		// grabbed data from the LineEdit text box
		QString size = ui.translate_LineEdit->text();

		if(size.toInt())
		{
			// create int for data inside text box
			int translate = size.toInt();

			// pass in variables to translate function
			image->translateImage(translate, *image);

			// display image
			writeImage(tempFileName, image);
			QPixmap tmpPixMap(tempFileName);
			ui.picture->setPixmap(tmpPixMap);
			ui.picture->resize(ui.picture->pixmap()->size());
		}
		else
		{
			QMessageBox msgBox;
			msgBox.setText("No integer entered to translate image");
			msgBox.exec();
		}
	}
	else
	{
		QMessageBox msgBox;
		msgBox.setText("Please read in an image");
		msgBox.exec();
	}
}

void imageUI::on_rotateImage_clicked() //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
{
	// if image is loaded
	if(image)
	{
		// grabbed data from the text box
		QString row = ui.row_LineEdit->text();
		QString col = ui.col_LineEdit->text();
		QString rotate = ui.rotation_LineEdit->text();

		// if data is entered
		if((row.toInt()>-1) && (col.toInt()>-1) && (rotate.toInt()>-1))
		{
			// create int for data inside text box
			int rotateRow = row.toInt();
			int rotateCol = col.toInt();
			int rotation = rotate.toInt();

			// pass in variables to function
			image->rotateImage(rotation,rotateRow, rotateCol, *image);
			writeImage(tempFileName, image);
			QPixmap tmpPixMap(tempFileName);
			ui.picture->setPixmap(tmpPixMap);
			ui.picture->resize(ui.picture->pixmap()->size());
		}
		else
		{
			QMessageBox msgBox;
			msgBox.setText("Enter integers into the fields");
			msgBox.exec();
		}
	}
	else
	{
		QMessageBox msgBox;
		msgBox.setText("Please read in an image");
		msgBox.exec();
	}
}

void imageUI::on_reflectImage_clicked() //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
{
	if(image)
	{
		// grabbed data from the LineEdit text box
		QString reflect = ui.reflectEdit->text();

		// if boxes not empty
		if(!reflect.isEmpty()
				&& (( reflect == "H" || reflect =="h"
						|| reflect == "V" || reflect == "v")))
		{
			bool axis;

			// check flags
			if( reflect == "H" || reflect =="h" )
			{
				axis= false;
			}
			else
			{
				axis = true;
			}

			// create a temp image
			Image tempImage(*image);

			// pass in variables to enlarge function
			image->reflectImage(axis,*image);

			// display image
			writeImage(tempFileName, image);
			QPixmap tmpPixMap(tempFileName);
			ui.picture->setPixmap(tmpPixMap);
			ui.picture->resize(ui.picture->pixmap()->size());

		}
		else
		{
			QMessageBox msgBox;
			msgBox.setText("Check Horizontal or Vertical reflection data");
			msgBox.exec();
		}
	}
	else
	{
		QMessageBox msgBox;
		msgBox.setText("Please read in an image");
		msgBox.exec();
	}
}

void imageUI::on_meanGray_clicked() //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
{
	// if image is loaded
	if(image)
	{
		// set int to meanGray() output
		int meanGray = image->meanGray();

		// convert output to QString
		QString tempString = QString::number(meanGray);

		// pass in string
		ui.meanGray_label->setText(tempString);
	}
	else
	{
		QMessageBox msgBox;
		msgBox.setText("Please read in an image");
		msgBox.exec();
	}
}

void imageUI::on_negateImage_clicked() //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
{
	if(image)
	{
		// set negate to tempImage
		Image tempImage = image->negateImage();

		// display Image
		writeImage(tempFileName, &tempImage);
		QPixmap tmpPixMap(tempFileName);
		ui.picture->setPixmap(tmpPixMap);
		ui.picture->resize(ui.picture->pixmap()->size());
	}
	else
	{
		QMessageBox msgBox;
		msgBox.setText("Please read in an image");
		msgBox.exec();
	}
}

void imageUI::on_subImage_clicked() //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
{
	// if image is loaded
	if(image)
	{
		// grabbed data from the text box
		QString UL = ui.UL_LineEdit->text();
		QString UR = ui.UR_LineEdit->text();
		QString LL = ui.LL_LineEdit->text();
		QString LR = ui.LR_LineEdit->text();

		// if data is entered
		if((UL.toInt()>-1) && (UR.toInt()>-1) && (LL.toInt()>-1) && (LR.toInt()>-1))
		{
			// create int for data inside text box
			int UCbox = UL.toInt();
			int URbox = UR.toInt();
			int LCbox = LL.toInt();
			int LRbox = LR.toInt();

			// pass in variables to enlarge function
			image->getSubImage( URbox, UCbox, LRbox, LCbox, *image );

		    // display image
			writeImage(tempFileName, image);
			QPixmap tmpPixMap(tempFileName);
			ui.picture->setPixmap(tmpPixMap);
			ui.picture->resize(ui.picture->pixmap()->size());
		}
		else
		{
			QMessageBox msgBox;
			msgBox.setText("Enter integers into the fields");
			msgBox.exec();
		}
	}
	else
	{
		QMessageBox msgBox;
		msgBox.setText("Please read in an image");
		msgBox.exec();
	}
}

void imageUI::on_DFS_clicked()
{
	// if image is loaded
	if(image)
	{
		QString value = ui.thresholdValue_LineEdit->text();

		if(!value.isEmpty())
		{
			if((value.toInt()>-1) && (value.toInt()<=255))
			{
				int N,M,Q;
				Image tempImage;
                               RegionType<key> slistLbl;
				// create int for data inside text box
				int valueInt = value.toInt();
				// pass in variable to threshold function
				image->threshold( valueInt );

				// erode and dilate threshold image
				tempImage = image->dilate();
				tempImage = tempImage.erode();
				tempImage = tempImage.erode();
				tempImage = tempImage.dilate();

				// retrieve image info
				tempImage.getImageInfo(N,M,Q);
				Image outImage(N,M,255);

				// start timer
				QTime timer;
				int time;
				timer.start();

				// set computeComponents() output
                                int labelNumber = computeComponents(&tempImage, &outImage, 1, slistLbl);

				// get time
				time = timer.elapsed();

				// convert output to QString
				QString tempString = QString::number(labelNumber);

				//pass in string
				ui.threshold_label->setText(tempString);

				// output time
				QString timerString = QString::number(time);
				ui.time_label->setText(timerString);

				// display image
				writeImage(tempFileName, &outImage);
				QPixmap tmpPixMap(tempFileName);
				ui.picture->setPixmap(tmpPixMap);
				ui.picture->resize(ui.picture->pixmap()->size());
			}
			else
			{
				QMessageBox msgBox;
				msgBox.setText("Integer must be from 0 and 255");
				msgBox.exec();
			}
		}
		else
		{
			QMessageBox msgBox;
			msgBox.setText("Enter integer into the field");
			msgBox.exec();
		}
	}
	else
	{
		QMessageBox msgBox;
		msgBox.setText("Please read in an image");
		msgBox.exec();
	}
}

void imageUI::on_BFS_clicked()
{
	// if image is loaded
	if(image)
	{
		QString value = ui.thresholdValue_LineEdit->text();

		if(!value.isEmpty())
		{
			if((value.toInt()>-1) && (value.toInt()<=255))
			{
				int N,M,Q;
				Image tempImage;
                               RegionType<key> slistLbl;
				// create int for data inside text box
				int valueInt = value.toInt();
				// pass in variable to threshold function
				image->threshold( valueInt );

				// erode and dilate threshold image
				tempImage = image->dilate();
				tempImage = tempImage.erode();
				tempImage =tempImage.erode();
				tempImage = tempImage.dilate();

				// retrieve image info
				tempImage.getImageInfo(N,M,Q);
				Image outImage(N,M,255);

				// start timer
				QTime timer;
				int time;
				timer.start();

				// set computeComponents() output
                                int labelNumber = computeComponents(&tempImage, &outImage, 2, slistLbl);

				// get time
				time = timer.elapsed();

				// convert output to QString
				QString tempString = QString::number(labelNumber);

				//pass in string
				ui.threshold_label->setText(tempString);

				// output time
				QString timerString = QString::number(time);
				ui.time_label->setText(timerString);

				// display image
				writeImage(tempFileName, &outImage);
				QPixmap tmpPixMap(tempFileName);
				ui.picture->setPixmap(tmpPixMap);
				ui.picture->resize(ui.picture->pixmap()->size());
			}
			else
			{
				QMessageBox msgBox;
				msgBox.setText("Integer must be from 0 and 255");
				msgBox.exec();
			}
		}
		else
		{
			QMessageBox msgBox;
			msgBox.setText("Enter integer into the field");
			msgBox.exec();
		}
	}
	else
	{
		QMessageBox msgBox;
		msgBox.setText("Please read in an image");
		msgBox.exec();
	}
}

void imageUI::on_Recursive_clicked()
{
	// if image is loaded
	if(image)
	{
		QString value = ui.thresholdValue_LineEdit->text();

		if(!value.isEmpty())
		{
			if((value.toInt()>-1) && (value.toInt()<=255))
			{
				int N,M,Q;
				Image tempImage;
                               RegionType<key> slistLbl;
				// create int for data inside text box
				int valueInt = value.toInt();
				// pass in variable to threshold function
				image->threshold( valueInt );

				// erode and dilate threshold image
				tempImage = image->dilate();
				tempImage = tempImage.erode();
				tempImage = tempImage.erode();
				tempImage = tempImage.dilate();

				// retrieve image info
				tempImage.getImageInfo(N,M,Q);
				Image outImage(N,M,255);

				// start timer
				QTime timer;
				int time;
				timer.start();

				// set computeComponents() output
                                int labelNumber = computeComponents(&tempImage, &outImage, 3, slistLbl);

				// get time
				time = timer.elapsed();

				// convert output to QString
				QString tempString = QString::number(labelNumber);

				//pass in string
				ui.threshold_label->setText(tempString);

				// output time
				QString timerString = QString::number(time);
				ui.time_label->setText(timerString);

				// display image
				writeImage(tempFileName, &outImage);
				QPixmap tmpPixMap(tempFileName);
				ui.picture->setPixmap(tmpPixMap);
				ui.picture->resize(ui.picture->pixmap()->size());
			}
			else
			{
				QMessageBox msgBox;
				msgBox.setText("Integer must be from 0 and 255");
				msgBox.exec();
			}
		}
		else
		{
			QMessageBox msgBox;
			msgBox.setText("Enter integer into the field");
			msgBox.exec();
		}
	}
	else
	{
		QMessageBox msgBox;
		msgBox.setText("Please read in an image");
		msgBox.exec();
	}
}

void imageUI::on_mergeImage_clicked() //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
{
	int errorFlag;

	if(image)
	{
		// set 2nd filename to data entered in text box
		QString difFilename = ui.imageName_2->text();

		if (!difFilename.isEmpty() )
		{
			// read in 2nd image
			int difN, difM, difQ;
			errorFlag = readImageHeader(difFilename, difN, difM, difQ);
			if (errorFlag > 0)
			{
				Image * difImage = new Image(difN,difM,difQ);
				readImage(difFilename, difImage );
				Image imageDiff(difN,difM,difQ);

				// get addition image
				imageDiff = *image + *difImage;

				// display image
				writeImage(tempFileName, &imageDiff);
				QPixmap tmpPixMap(tempFileName);
				ui.picture->setPixmap(tmpPixMap);
				ui.picture->resize(ui.picture->pixmap()->size());
			}
		}
		else
		{
			QMessageBox msgBox;
			msgBox.setText("Enter another filename to compare");
			msgBox.exec();
		}
	}
	else
	{
		QMessageBox msgBox;
		msgBox.setText("Please read in an image");
		msgBox.exec();
	}
}

void imageUI::on_differenceImage_clicked() //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
{
	int errorFlag;

	if(image)
	{
		QString difFilename = ui.imageName_3->text();
		if (!difFilename.isEmpty())
		{
			int difN, difM, difQ;

			// read in 2nd image
			errorFlag = readImageHeader(difFilename, difN, difM, difQ);
			if (errorFlag > 0)
			{
				Image * difImage = new Image(difN,difM,difQ);
				readImage(difFilename, difImage );
				Image imageDiff(difN,difM,difQ);

				// get difference image
				imageDiff = *image - *difImage;

				// display image
				writeImage(tempFileName, &imageDiff);
				QPixmap tmpPixMap(tempFileName);
				ui.picture->setPixmap(tmpPixMap);
				ui.picture->resize(ui.picture->pixmap()->size());
			}
		}
		else
		{
			QMessageBox msgBox;
			msgBox.setText("Enter another filename to compare");
			msgBox.exec();
		}
	}
	else
	{
		QMessageBox msgBox;
		msgBox.setText("Please read in an image");
		msgBox.exec();
	}
}

void imageUI::on_saveAsImage_clicked() //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
{
	if(image)
	{
		QString saveFilename = ui.imageName_4->text();

		if (!saveFilename.isEmpty())
		{
			writeImage(saveFilename, image);
		}
		else
		{
			QMessageBox msgBox;
			msgBox.setText("Enter image name to save image as");
			msgBox.exec();
		}
	}
	else
	{
		QMessageBox msgBox;
		msgBox.setText("Please read in an image");
		msgBox.exec();
	}
}

void imageUI::on_quitImage_clicked() //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
{
	exit(0);
}

int imageUI::readImage(QString fileName, Image * rImage) //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
{
	 int i, j;
	 int N, M, Q;
	 unsigned char *charImage;
	 char header [100], *ptr;
	 ifstream ifp;

	 //Convert from QString to a standard char *
	 QByteArray byteArray = fileName.toUtf8();
	 const char * fname = byteArray.constData();

	 ifp.open(fname, ios::in | ios::binary);

	 if (!ifp) {
		 QMessageBox msgBox;
		 QString tmpMsg = "Can't Read Image: " + fileName;
		 msgBox.setText(tmpMsg);
		 msgBox.exec();
		 return 0;
	 }

	 // read header
	 ifp.getline(header,100,'\n');
	 if ( (header[0]!=80) ||    /* 'P' */
		  (header[1]!=53) ) {   /* '5' */
		 QMessageBox msgBox;
		 QString tmpMsg = "Wrong filename: " + fileName;
		 msgBox.setText(tmpMsg);
		 msgBox.exec();
		 return 0;
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

	 if (ifp.fail())
	 {
		 QMessageBox msgBox;
		 QString tmpMsg = "Wrong Size: " + fileName;
		 msgBox.setText(tmpMsg);
		 msgBox.exec();
		 return 0;
	 }

	 ifp.close();

	 //
	 // Convert the unsigned characters to integers
	 //

	 int val;

	 for(i=0; i<N; i++)
	   for(j=0; j<M; j++)
	   {
		 val = (int)charImage[i*M+j];
		 rImage->setPixelVal(i, j, val);
	   }

	 delete [] charImage;
	 return 1;
}

int imageUI::writeImage(QString fileName, Image * wImage) //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
{
	 int i, j;
	 int iN, iM, iQ;
	 unsigned char *charImage;
	 ofstream ofp;
	 //Convert from QString to a standard char *
	 QByteArray byteArray = fileName.toUtf8();
	 const char * fname = byteArray.constData();
	 wImage->getImageInfo(iN, iM, iQ);

	 charImage = (unsigned char *) new unsigned char [iM*iN];

	 // convert the integer values to unsigned char

	 int val;

	 for(i=0; i<iN; i++)
	   for(j=0; j<iM; j++)
	   {
		 val = wImage->getPixelVal(i, j);
		 charImage[i*iM+j]=(unsigned char)val;
	   }

	 ofp.open(fname, ios::out | ios::binary);

	 if (!ofp)
	 {
		 QMessageBox msgBox;
		 QString tmpMsg = "Can't open file: " + fileName;
		 msgBox.setText(tmpMsg);
		 msgBox.exec();
		 return 0;
	 }

	 ofp << "P5" << endl;
	 ofp << iM << " " << iN << endl;
	 ofp << Q << endl;

	 ofp.write( reinterpret_cast<char *>(charImage), (iM*iN)*sizeof(unsigned char));

	 if (ofp.fail())
	 {
		 QMessageBox msgBox;
		 QString tmpMsg = "Can't open file: " + fileName;
		 msgBox.setText(tmpMsg);
		 msgBox.exec();
		 return 0;
	 }

	 ofp.close();

	 delete [] charImage;
	 return 1;
}

int imageUI::readImageHeader(QString fileName,int& iN, int& iM, int& iQ) //~~~~~~~~~~~~~~~
{
	 char header [100], *ptr;
	 ifstream ifp;
	 bool type;
	 //Convert from QString to a standard char *
	  QByteArray byteArray = fileName.toUtf8();
	  const char * fname = byteArray.constData();
	 ifp.open(fname, ios::in | ios::binary);

	 if (!ifp)
	 {
	   QMessageBox msgBox;
	   QString tmpMsg = "Wrong filename: " + fileName;
	   msgBox.setText(tmpMsg);
	   msgBox.exec();
	   return 0;
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
	 else
	 {
		QMessageBox msgBox;
		QString tmpMsg = fileName + "Does not end in .pgm";
		msgBox.setText(tmpMsg);
		msgBox.exec();
		return 0;
	 }

	ifp.getline(header,100,'\n');
	 while(header[0]=='#')
	   ifp.getline(header,100,'\n');

	 iM=strtol(header,&ptr,0);
	 iN=atoi(ptr);

	 ifp.getline(header,100,'\n');

	 iQ=strtol(header,&ptr,0);

	 ifp.close();
	return 1;
}

int imageUI::computeComponents(Image * inputImage, Image * outputImage, int flag, RegionType<key> &listReg) //
{

	//set outputImage to white (255) // unlabeled
	int connComp = 0;
	int N,M,Q, i, j, label;
        PixelType<imageNode> pixRegion;
        imageNode pixLbl;
        key itmReg;
	inputImage->getImageInfo(N,M,Q);

	// looping through image
	for( i = 0; i < N; i++ )
	{
		for( j = 0; j < M; j++ )
		{
			if(inputImage->getPixelVal(i,j) == 255 && outputImage->getPixelVal(i,j) == 255)
			{
				++connComp;
				label = connComp; // new label
                                
                                // Beginning of new pixel list
                                pixLbl.row = i;
                                pixLbl.col = j;
                                pixRegion.InsertItem(pixLbl);

				if( flag == 1 )
				{
					// iteratively with stacks
					findComponentDFS(inputImage, outputImage, i, j, label, pixRegion);
				}
				else if ( flag == 2)
				{
					// iteratively with queues
					findComponentBFS(inputImage, outputImage, i, j, label);
				}
				else
				{
					// recursive with stacks
					findComponentRecursive(inputImage, outputImage, i, j, label);
				}
                                
                                // Adds the pixel list - region to region list
                                itmReg.listPix = pixRegion;
                                listReg.InsertItem(itmReg);
			}
		}
	}

	return connComp;
}

void imageUI::findComponentBFS(Image * inputImage, Image * outputImage, int i, int j, int label) // Oliver
{
	// Init vars
	int pi,pj,ni,nj;
	int iRowMax,iColMax,iGrayLvl;

	// get Image Info to determine boundaries
	inputImage->getImageInfo(iRowMax,iColMax,iGrayLvl);

	QueueType<int> queList(MAX_QUE);

	queList.MakeEmpty();

	queList.Enqueue(i, j); // initialize Queue

	while(!queList.isEmpty())
	{
		queList.Dequeue(pi, pj);
		outputImage->setPixelVal(pi, pj, label*10);

		ni = pi;
		nj = pj;

		// Loop till row iterative counter < iGrid
		for( i = -1; i < 2; i++)
		{
			// Loop till col iterative counter < iGrid
			for( j = -1; j < 2; j++)
			{
				ni = pi + i;
				nj = pj + j;


				// if within bounds of image and not original row/col
				if ( (ni > -1 && ni < iRowMax) && (nj > -1 && nj < iColMax))
				{
					//if pixel value is black
					if( inputImage->getPixelVal(ni,nj) == 255 && outputImage->getPixelVal(ni,nj) == 255)
					{
						// set pixel in new image to -1
						outputImage->setPixelVal(ni,nj,-1);

						// push onto queue
						queList.Enqueue(ni,nj);
					}
				}
			}
		}
	}
}

void imageUI::findComponentDFS(Image * inputImage, Image * outputImage, int i, int j, int label, PixelType<imageNode> &pixList) // Caitlin
{
	int N,M,Q;
	inputImage->getImageInfo(N,M,Q);
	int nRow,nCol,newRow,newCol;
	StackType<imageNode> imageStack;
	imageStack.MakeEmpty();

    imageNode node;
    node.row = i;
    node.col = j;

    // initialize Stack
    imageStack.Push(node);
    imageNode newNode;

	while( !imageStack.IsEmpty())
	{
		imageStack.Pop(node);
		outputImage->setPixelVal(node.row,node.col,label * 10); // label this pixel

		// check neighbors for white
		for ( nRow = -1; nRow < 2; nRow++)
		{
			for ( nCol = -1; nCol < 2; nCol++ )
			{
				newRow = node.row + nRow;
				newCol = node.col + nCol;

				// if within bounds of image and not original row/col
				if ( (newRow > -1 && newRow < N) && (newCol > -1 && newCol < M) )
				{
					//if pixel value is black
					if( inputImage->getPixelVal(newRow,newCol) == 255 && outputImage->getPixelVal(newRow,newCol) == 255)
					{
						// set pixel in new image to -1
						outputImage->setPixelVal(newRow,newCol,-1);
						// set node to new coordinates
						newNode.row = newRow;
						newNode.col = newCol;
						// push new node into stack
						imageStack.Push(newNode);
                                                
                                                // Insert into PixelType list
                                                pixList.InsertItem(newNode);
					}
				}
			}
		}
	}
}

void imageUI::findComponentRecursive(Image * inputImage, Image * outputImage, int &i, int &j, int label) // Oliver using Caitlin's DFS (above)
{
	int N,M,Q;
	inputImage->getImageInfo(N,M,Q);
	int nRow,nCol,newRow,newCol;

		// check neighbors for white
		for ( nRow = -1; nRow < 2; nRow++)
		{
			for ( nCol = -1; nCol < 2; nCol++ )
			{
				newRow = i + nRow;
				newCol = j + nCol;

				// if within bounds of image and not original row/col
				if ( (newRow > -1 && newRow < N) && (newCol > -1 && newCol < M))
				{
					//if pixel value is black
					if( inputImage->getPixelVal(newRow,newCol) == 255 && outputImage->getPixelVal(newRow,newCol) == 255)
					{
						// sets neighbor pixels to label
						outputImage->setPixelVal(newRow,newCol,label*10);
						// call itself
						findComponentRecursive(inputImage,outputImage,newRow,newCol,label);
					}
				}
			}
		}
}

void deleteSmallComponents(RegionType<key> &listOfRegions,int threshold) // Oliver
{
    // PURPOSE: Given a certain threshold, remove all items in RegionType
    //          list with length smaller than threshold.
    // RETURNS: none, but shrinks the number of items in RegionType list
    
    // Init vars
    key itmRegion;
    int lengthRegion;
    
    // Loop through RegionType list
    // Get length of item's list and
    // compare to threshold, if smaller remove from RegionType list.
    for (int i = 0; i < listOfRegions.LengthIs(); i++) 
    {
        // Obtain region key value and length for comparison
        listOfRegions.GetNextItem(itmRegion);
        lengthRegion = itmRegion.listPix.LengthIs();
        
        if(lengthRegion <= threshold)
            listOfRegions.DeleteItem(itmRegion);
    }

}
