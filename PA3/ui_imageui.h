/********************************************************************************
** Form generated from reading UI file 'imageui.ui'
**
** Created: Sat Nov 5 10:26:11 2011
**      by: Qt User Interface Compiler version 4.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_IMAGEUI_H
#define UI_IMAGEUI_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QFormLayout>
#include <QtGui/QFrame>
#include <QtGui/QGridLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QStatusBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_imageUIClass
{
public:
    QWidget *centralwidget;
    QWidget *layoutWidget;
    QGridLayout *gridLayout_2;
    QFrame *line;
    QLabel *picture;
    QWidget *widget;
    QGridLayout *gridLayout_4;
    QHBoxLayout *horizontalLayout;
    QPushButton *readInImage;
    QLineEdit *imageName;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *enlargeImage;
    QLineEdit *enlarge_LineEdit;
    QSpacerItem *horizontalSpacer_2;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *shrinkImage;
    QLineEdit *shrink_LineEdit;
    QSpacerItem *horizontalSpacer_3;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *translateImage;
    QLineEdit *translate_LineEdit;
    QSpacerItem *horizontalSpacer_4;
    QHBoxLayout *horizontalLayout_5;
    QPushButton *rotateImage;
    QLineEdit *row_LineEdit;
    QLineEdit *col_LineEdit;
    QLineEdit *rotation_LineEdit;
    QHBoxLayout *horizontalLayout_10;
    QHBoxLayout *horizontalLayout_6;
    QPushButton *reflectImage;
    QLineEdit *reflectEdit;
    QSpacerItem *horizontalSpacer_10;
    QHBoxLayout *horizontalLayout_7;
    QPushButton *meanGray;
    QLabel *meanGray_label;
    QLabel *label;
    QSpacerItem *horizontalSpacer_9;
    QHBoxLayout *horizontalLayout_8;
    QPushButton *negateImage;
    QSpacerItem *horizontalSpacer_7;
    QGridLayout *gridLayout;
    QPushButton *subImage;
    QSpacerItem *horizontalSpacer_5;
    QLabel *UL_Label;
    QLineEdit *UL_LineEdit;
    QLabel *UR;
    QLineEdit *UR_LineEdit;
    QLabel *LL_Label;
    QLineEdit *LL_LineEdit;
    QLabel *LR;
    QLineEdit *LR_LineEdit;
    QGridLayout *gridLayout_3;
    QLabel *Regions_label;
    QLineEdit *thresholdValue_LineEdit;
    QLabel *label_num;
    QLabel *threshold_label;
    QSpacerItem *horizontalSpacer_8;
    QPushButton *BFS;
    QPushButton *DFS;
    QPushButton *Recursive;
    QLabel *Elapsed_label;
    QLabel *time_label;
    QSpacerItem *horizontalSpacer_11;
    QFormLayout *formLayout;
    QPushButton *mergeImage;
    QLineEdit *imageName_2;
    QFormLayout *formLayout_2;
    QPushButton *differenceImage;
    QLineEdit *imageName_3;
    QFormLayout *formLayout_3;
    QPushButton *saveAsImage;
    QLineEdit *imageName_4;
    QHBoxLayout *horizontalLayout_9;
    QPushButton *quitImage;
    QSpacerItem *horizontalSpacer;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *imageUIClass)
    {
        if (imageUIClass->objectName().isEmpty())
            imageUIClass->setObjectName(QString::fromUtf8("imageUIClass"));
        imageUIClass->resize(1073, 642);
        centralwidget = new QWidget(imageUIClass);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        layoutWidget = new QWidget(centralwidget);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(500, 10, 561, 591));
        gridLayout_2 = new QGridLayout(layoutWidget);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        line = new QFrame(layoutWidget);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);

        gridLayout_2->addWidget(line, 0, 0, 1, 1);

        picture = new QLabel(layoutWidget);
        picture->setObjectName(QString::fromUtf8("picture"));

        gridLayout_2->addWidget(picture, 0, 1, 1, 1);

        widget = new QWidget(centralwidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(11, 17, 481, 581));
        gridLayout_4 = new QGridLayout(widget);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        gridLayout_4->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        readInImage = new QPushButton(widget);
        readInImage->setObjectName(QString::fromUtf8("readInImage"));

        horizontalLayout->addWidget(readInImage);

        imageName = new QLineEdit(widget);
        imageName->setObjectName(QString::fromUtf8("imageName"));

        horizontalLayout->addWidget(imageName);


        gridLayout_4->addLayout(horizontalLayout, 0, 0, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        enlargeImage = new QPushButton(widget);
        enlargeImage->setObjectName(QString::fromUtf8("enlargeImage"));

        horizontalLayout_2->addWidget(enlargeImage);

        enlarge_LineEdit = new QLineEdit(widget);
        enlarge_LineEdit->setObjectName(QString::fromUtf8("enlarge_LineEdit"));

        horizontalLayout_2->addWidget(enlarge_LineEdit);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);


        gridLayout_4->addLayout(horizontalLayout_2, 1, 0, 1, 2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        shrinkImage = new QPushButton(widget);
        shrinkImage->setObjectName(QString::fromUtf8("shrinkImage"));

        horizontalLayout_3->addWidget(shrinkImage);

        shrink_LineEdit = new QLineEdit(widget);
        shrink_LineEdit->setObjectName(QString::fromUtf8("shrink_LineEdit"));

        horizontalLayout_3->addWidget(shrink_LineEdit);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_3);


        gridLayout_4->addLayout(horizontalLayout_3, 2, 0, 1, 2);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        translateImage = new QPushButton(widget);
        translateImage->setObjectName(QString::fromUtf8("translateImage"));

        horizontalLayout_4->addWidget(translateImage);

        translate_LineEdit = new QLineEdit(widget);
        translate_LineEdit->setObjectName(QString::fromUtf8("translate_LineEdit"));

        horizontalLayout_4->addWidget(translate_LineEdit);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_4);


        gridLayout_4->addLayout(horizontalLayout_4, 3, 0, 1, 2);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        rotateImage = new QPushButton(widget);
        rotateImage->setObjectName(QString::fromUtf8("rotateImage"));

        horizontalLayout_5->addWidget(rotateImage);

        row_LineEdit = new QLineEdit(widget);
        row_LineEdit->setObjectName(QString::fromUtf8("row_LineEdit"));

        horizontalLayout_5->addWidget(row_LineEdit);

        col_LineEdit = new QLineEdit(widget);
        col_LineEdit->setObjectName(QString::fromUtf8("col_LineEdit"));

        horizontalLayout_5->addWidget(col_LineEdit);

        rotation_LineEdit = new QLineEdit(widget);
        rotation_LineEdit->setObjectName(QString::fromUtf8("rotation_LineEdit"));

        horizontalLayout_5->addWidget(rotation_LineEdit);


        gridLayout_4->addLayout(horizontalLayout_5, 4, 0, 1, 2);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));
        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        reflectImage = new QPushButton(widget);
        reflectImage->setObjectName(QString::fromUtf8("reflectImage"));

        horizontalLayout_6->addWidget(reflectImage);


        horizontalLayout_10->addLayout(horizontalLayout_6);

        reflectEdit = new QLineEdit(widget);
        reflectEdit->setObjectName(QString::fromUtf8("reflectEdit"));

        horizontalLayout_10->addWidget(reflectEdit);


        gridLayout_4->addLayout(horizontalLayout_10, 5, 0, 1, 1);

        horizontalSpacer_10 = new QSpacerItem(208, 24, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_4->addItem(horizontalSpacer_10, 5, 1, 1, 1);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        meanGray = new QPushButton(widget);
        meanGray->setObjectName(QString::fromUtf8("meanGray"));

        horizontalLayout_7->addWidget(meanGray);

        meanGray_label = new QLabel(widget);
        meanGray_label->setObjectName(QString::fromUtf8("meanGray_label"));

        horizontalLayout_7->addWidget(meanGray_label);

        label = new QLabel(widget);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout_7->addWidget(label);

        horizontalSpacer_9 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_9);


        gridLayout_4->addLayout(horizontalLayout_7, 6, 0, 1, 1);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        negateImage = new QPushButton(widget);
        negateImage->setObjectName(QString::fromUtf8("negateImage"));

        horizontalLayout_8->addWidget(negateImage);

        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_7);


        gridLayout_4->addLayout(horizontalLayout_8, 7, 0, 1, 1);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        subImage = new QPushButton(widget);
        subImage->setObjectName(QString::fromUtf8("subImage"));

        gridLayout->addWidget(subImage, 0, 0, 1, 2);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_5, 0, 2, 1, 1);

        UL_Label = new QLabel(widget);
        UL_Label->setObjectName(QString::fromUtf8("UL_Label"));

        gridLayout->addWidget(UL_Label, 1, 0, 1, 1);

        UL_LineEdit = new QLineEdit(widget);
        UL_LineEdit->setObjectName(QString::fromUtf8("UL_LineEdit"));

        gridLayout->addWidget(UL_LineEdit, 1, 1, 1, 2);

        UR = new QLabel(widget);
        UR->setObjectName(QString::fromUtf8("UR"));

        gridLayout->addWidget(UR, 1, 3, 1, 1);

        UR_LineEdit = new QLineEdit(widget);
        UR_LineEdit->setObjectName(QString::fromUtf8("UR_LineEdit"));

        gridLayout->addWidget(UR_LineEdit, 1, 4, 1, 1);

        LL_Label = new QLabel(widget);
        LL_Label->setObjectName(QString::fromUtf8("LL_Label"));

        gridLayout->addWidget(LL_Label, 2, 0, 1, 1);

        LL_LineEdit = new QLineEdit(widget);
        LL_LineEdit->setObjectName(QString::fromUtf8("LL_LineEdit"));

        gridLayout->addWidget(LL_LineEdit, 2, 1, 1, 2);

        LR = new QLabel(widget);
        LR->setObjectName(QString::fromUtf8("LR"));

        gridLayout->addWidget(LR, 2, 3, 1, 1);

        LR_LineEdit = new QLineEdit(widget);
        LR_LineEdit->setObjectName(QString::fromUtf8("LR_LineEdit"));

        gridLayout->addWidget(LR_LineEdit, 2, 4, 1, 1);


        gridLayout_4->addLayout(gridLayout, 8, 0, 1, 2);

        gridLayout_3 = new QGridLayout();
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        Regions_label = new QLabel(widget);
        Regions_label->setObjectName(QString::fromUtf8("Regions_label"));

        gridLayout_3->addWidget(Regions_label, 0, 0, 1, 3);

        thresholdValue_LineEdit = new QLineEdit(widget);
        thresholdValue_LineEdit->setObjectName(QString::fromUtf8("thresholdValue_LineEdit"));

        gridLayout_3->addWidget(thresholdValue_LineEdit, 0, 3, 1, 1);

        label_num = new QLabel(widget);
        label_num->setObjectName(QString::fromUtf8("label_num"));

        gridLayout_3->addWidget(label_num, 0, 4, 1, 1);

        threshold_label = new QLabel(widget);
        threshold_label->setObjectName(QString::fromUtf8("threshold_label"));

        gridLayout_3->addWidget(threshold_label, 0, 5, 1, 1);

        horizontalSpacer_8 = new QSpacerItem(13, 18, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_8, 0, 6, 1, 1);

        BFS = new QPushButton(widget);
        BFS->setObjectName(QString::fromUtf8("BFS"));

        gridLayout_3->addWidget(BFS, 1, 0, 1, 3);

        DFS = new QPushButton(widget);
        DFS->setObjectName(QString::fromUtf8("DFS"));

        gridLayout_3->addWidget(DFS, 1, 3, 1, 1);

        Recursive = new QPushButton(widget);
        Recursive->setObjectName(QString::fromUtf8("Recursive"));

        gridLayout_3->addWidget(Recursive, 1, 4, 1, 2);

        Elapsed_label = new QLabel(widget);
        Elapsed_label->setObjectName(QString::fromUtf8("Elapsed_label"));

        gridLayout_3->addWidget(Elapsed_label, 2, 0, 1, 1);

        time_label = new QLabel(widget);
        time_label->setObjectName(QString::fromUtf8("time_label"));

        gridLayout_3->addWidget(time_label, 2, 1, 1, 1);

        horizontalSpacer_11 = new QSpacerItem(308, 18, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_11, 2, 2, 1, 5);


        gridLayout_4->addLayout(gridLayout_3, 9, 0, 1, 2);

        formLayout = new QFormLayout();
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        mergeImage = new QPushButton(widget);
        mergeImage->setObjectName(QString::fromUtf8("mergeImage"));

        formLayout->setWidget(0, QFormLayout::LabelRole, mergeImage);

        imageName_2 = new QLineEdit(widget);
        imageName_2->setObjectName(QString::fromUtf8("imageName_2"));

        formLayout->setWidget(0, QFormLayout::FieldRole, imageName_2);


        gridLayout_4->addLayout(formLayout, 10, 0, 1, 1);

        formLayout_2 = new QFormLayout();
        formLayout_2->setObjectName(QString::fromUtf8("formLayout_2"));
        differenceImage = new QPushButton(widget);
        differenceImage->setObjectName(QString::fromUtf8("differenceImage"));

        formLayout_2->setWidget(0, QFormLayout::LabelRole, differenceImage);

        imageName_3 = new QLineEdit(widget);
        imageName_3->setObjectName(QString::fromUtf8("imageName_3"));

        formLayout_2->setWidget(0, QFormLayout::FieldRole, imageName_3);


        gridLayout_4->addLayout(formLayout_2, 11, 0, 1, 2);

        formLayout_3 = new QFormLayout();
        formLayout_3->setObjectName(QString::fromUtf8("formLayout_3"));
        formLayout_3->setFieldGrowthPolicy(QFormLayout::AllNonFixedFieldsGrow);
        saveAsImage = new QPushButton(widget);
        saveAsImage->setObjectName(QString::fromUtf8("saveAsImage"));

        formLayout_3->setWidget(0, QFormLayout::LabelRole, saveAsImage);

        imageName_4 = new QLineEdit(widget);
        imageName_4->setObjectName(QString::fromUtf8("imageName_4"));

        formLayout_3->setWidget(0, QFormLayout::FieldRole, imageName_4);


        gridLayout_4->addLayout(formLayout_3, 12, 0, 1, 1);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        quitImage = new QPushButton(widget);
        quitImage->setObjectName(QString::fromUtf8("quitImage"));

        horizontalLayout_9->addWidget(quitImage);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_9->addItem(horizontalSpacer);


        gridLayout_4->addLayout(horizontalLayout_9, 13, 0, 1, 1);

        imageUIClass->setCentralWidget(centralwidget);
        menubar = new QMenuBar(imageUIClass);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1073, 20));
        imageUIClass->setMenuBar(menubar);
        statusbar = new QStatusBar(imageUIClass);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        imageUIClass->setStatusBar(statusbar);

        retranslateUi(imageUIClass);

        QMetaObject::connectSlotsByName(imageUIClass);
    } // setupUi

    void retranslateUi(QMainWindow *imageUIClass)
    {
        imageUIClass->setWindowTitle(QApplication::translate("imageUIClass", "Image Manipulator", 0, QApplication::UnicodeUTF8));
        picture->setText(QString());
        readInImage->setText(QApplication::translate("imageUIClass", "Read In Image", 0, QApplication::UnicodeUTF8));
        imageName->setText(QApplication::translate("imageUIClass", "Enter .pgm file", 0, QApplication::UnicodeUTF8));
        enlargeImage->setText(QApplication::translate("imageUIClass", "Enlarge ", 0, QApplication::UnicodeUTF8));
        shrinkImage->setText(QApplication::translate("imageUIClass", "Shrink ", 0, QApplication::UnicodeUTF8));
        translateImage->setText(QApplication::translate("imageUIClass", "Translate", 0, QApplication::UnicodeUTF8));
        rotateImage->setText(QApplication::translate("imageUIClass", "Rotate", 0, QApplication::UnicodeUTF8));
        row_LineEdit->setText(QApplication::translate("imageUIClass", "Enter row", 0, QApplication::UnicodeUTF8));
        col_LineEdit->setText(QApplication::translate("imageUIClass", "Enter column", 0, QApplication::UnicodeUTF8));
        rotation_LineEdit->setText(QApplication::translate("imageUIClass", "Enter theta", 0, QApplication::UnicodeUTF8));
        reflectImage->setText(QApplication::translate("imageUIClass", "Reflect", 0, QApplication::UnicodeUTF8));
        reflectEdit->setText(QApplication::translate("imageUIClass", "Reflect H or V", 0, QApplication::UnicodeUTF8));
        meanGray->setText(QApplication::translate("imageUIClass", "Mean Gray", 0, QApplication::UnicodeUTF8));
        meanGray_label->setText(QApplication::translate("imageUIClass", "--------", 0, QApplication::UnicodeUTF8));
        label->setText(QString());
        negateImage->setText(QApplication::translate("imageUIClass", "Negate", 0, QApplication::UnicodeUTF8));
        subImage->setText(QApplication::translate("imageUIClass", "Sub Image", 0, QApplication::UnicodeUTF8));
        UL_Label->setText(QApplication::translate("imageUIClass", "Upper Col:", 0, QApplication::UnicodeUTF8));
        UR->setText(QApplication::translate("imageUIClass", "Upper Row:", 0, QApplication::UnicodeUTF8));
        LL_Label->setText(QApplication::translate("imageUIClass", "Lower Col:", 0, QApplication::UnicodeUTF8));
        LR->setText(QApplication::translate("imageUIClass", "Lower Row:", 0, QApplication::UnicodeUTF8));
        Regions_label->setText(QApplication::translate("imageUIClass", "Count/Label Regions: ", 0, QApplication::UnicodeUTF8));
        thresholdValue_LineEdit->setInputMask(QString());
        thresholdValue_LineEdit->setText(QString());
        label_num->setText(QApplication::translate("imageUIClass", "Number of objects:", 0, QApplication::UnicodeUTF8));
        threshold_label->setText(QApplication::translate("imageUIClass", "--------", 0, QApplication::UnicodeUTF8));
        BFS->setText(QApplication::translate("imageUIClass", "Iterative BFS", 0, QApplication::UnicodeUTF8));
        DFS->setText(QApplication::translate("imageUIClass", "Iterative DFS", 0, QApplication::UnicodeUTF8));
        Recursive->setText(QApplication::translate("imageUIClass", "Recursive", 0, QApplication::UnicodeUTF8));
        Elapsed_label->setText(QApplication::translate("imageUIClass", "Time Elapsed:", 0, QApplication::UnicodeUTF8));
        time_label->setText(QApplication::translate("imageUIClass", "--------", 0, QApplication::UnicodeUTF8));
        mergeImage->setText(QApplication::translate("imageUIClass", "Merge With...", 0, QApplication::UnicodeUTF8));
        imageName_2->setText(QApplication::translate("imageUIClass", "Enter .pgm file", 0, QApplication::UnicodeUTF8));
        differenceImage->setText(QApplication::translate("imageUIClass", "Difference With...", 0, QApplication::UnicodeUTF8));
        imageName_3->setText(QApplication::translate("imageUIClass", "Enter .pgm file", 0, QApplication::UnicodeUTF8));
        saveAsImage->setText(QApplication::translate("imageUIClass", "Save As...", 0, QApplication::UnicodeUTF8));
        imageName_4->setText(QApplication::translate("imageUIClass", "Enter .pgm file", 0, QApplication::UnicodeUTF8));
        quitImage->setText(QApplication::translate("imageUIClass", "Quit", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class imageUIClass: public Ui_imageUIClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_IMAGEUI_H
