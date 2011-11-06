#ifndef IMAGEUI_H
#define IMAGEUI_H

#include <QtGui/QMainWindow>
#include <QFileDialog>
#include <QDataStream>
#include <QFile>
#include <cmath>
#include <fstream>
#include <iostream>
#include "ui_imageui.h"
#include "image.h"
#include "StackType.h"
#include "queue.h"
#include "PixelType.h"
#include "RegionType.h"
#include "ImgGeo.h"
#include <string>
#include <cstdlib>
#include <QMessageBox>
#include <QTime>

class imageUI : public QMainWindow
{
    Q_OBJECT

public:
    imageUI(QWidget *parent = 0);
    ~imageUI();
    int readImage(QString, Image * rImage);
    int writeImage(QString, Image * wImage);
    int readImageHeader(QString,int&,int&,int& );
    int computeComponents(Image * inputImage, Image * outputImage, int flag, RegionType<key> &listReg);
    void findComponentBFS(Image * inputImage, Image * outputImage, int i, int j, int label);
    void findComponentDFS(Image * inputImage, Image * outputImage, int i, int j, int label, PixelType<imageNode> &pixList);
    void findComponentRecursive(Image * inputImage, Image * outputImage, int &i, int &j, int label);
    void deleteSmallComponents(RegionType<key>&,int);

private:
    Ui::imageUIClass ui;
    Image * image;
    int N, M, Q;
    QString fileName;
    QString tempFileName;

private slots:
	void on_readInImage_clicked();
	void on_enlargeImage_clicked();
	void on_shrinkImage_clicked();
	void on_translateImage_clicked();
	void on_rotateImage_clicked();
	void on_reflectImage_clicked();
	void on_meanGray_clicked();
	void on_negateImage_clicked();
	void on_subImage_clicked();
	void on_DFS_clicked();
	void on_BFS_clicked();
	void on_Recursive_clicked();
	void on_mergeImage_clicked();
	void on_differenceImage_clicked();
	void on_saveAsImage_clicked();
	void on_quitImage_clicked();
};

#endif // IMAGEUI_H
