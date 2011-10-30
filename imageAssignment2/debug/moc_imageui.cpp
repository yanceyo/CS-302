/****************************************************************************
** Meta object code from reading C++ file 'imageui.h'
**
** Created: Tue Oct 11 08:37:20 2011
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../imageui.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'imageui.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_imageUI[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
      16,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
       9,    8,    8,    8, 0x08,
      34,    8,    8,    8, 0x08,
      60,    8,    8,    8, 0x08,
      85,    8,    8,    8, 0x08,
     113,    8,    8,    8, 0x08,
     138,    8,    8,    8, 0x08,
     164,    8,    8,    8, 0x08,
     186,    8,    8,    8, 0x08,
     211,    8,    8,    8, 0x08,
     233,    8,    8,    8, 0x08,
     250,    8,    8,    8, 0x08,
     267,    8,    8,    8, 0x08,
     290,    8,    8,    8, 0x08,
     314,    8,    8,    8, 0x08,
     343,    8,    8,    8, 0x08,
     368,    8,    8,    8, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_imageUI[] = {
    "imageUI\0\0on_readInImage_clicked()\0"
    "on_enlargeImage_clicked()\0"
    "on_shrinkImage_clicked()\0"
    "on_translateImage_clicked()\0"
    "on_rotateImage_clicked()\0"
    "on_reflectImage_clicked()\0"
    "on_meanGray_clicked()\0on_negateImage_clicked()\0"
    "on_subImage_clicked()\0on_DFS_clicked()\0"
    "on_BFS_clicked()\0on_Recursive_clicked()\0"
    "on_mergeImage_clicked()\0"
    "on_differenceImage_clicked()\0"
    "on_saveAsImage_clicked()\0"
    "on_quitImage_clicked()\0"
};

const QMetaObject imageUI::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_imageUI,
      qt_meta_data_imageUI, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &imageUI::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *imageUI::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *imageUI::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_imageUI))
        return static_cast<void*>(const_cast< imageUI*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int imageUI::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: on_readInImage_clicked(); break;
        case 1: on_enlargeImage_clicked(); break;
        case 2: on_shrinkImage_clicked(); break;
        case 3: on_translateImage_clicked(); break;
        case 4: on_rotateImage_clicked(); break;
        case 5: on_reflectImage_clicked(); break;
        case 6: on_meanGray_clicked(); break;
        case 7: on_negateImage_clicked(); break;
        case 8: on_subImage_clicked(); break;
        case 9: on_DFS_clicked(); break;
        case 10: on_BFS_clicked(); break;
        case 11: on_Recursive_clicked(); break;
        case 12: on_mergeImage_clicked(); break;
        case 13: on_differenceImage_clicked(); break;
        case 14: on_saveAsImage_clicked(); break;
        case 15: on_quitImage_clicked(); break;
        default: ;
        }
        _id -= 16;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
