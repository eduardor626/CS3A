/****************************************************************************
** Meta object code from reading C++ file 'musicengine.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "musicengine.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'musicengine.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_musicEngine_t {
    QByteArrayData data[32];
    char stringdata0[298];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_musicEngine_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_musicEngine_t qt_meta_stringdata_musicEngine = {
    {
QT_MOC_LITERAL(0, 0, 11), // "musicEngine"
QT_MOC_LITERAL(1, 12, 10), // "currVolume"
QT_MOC_LITERAL(2, 23, 0), // ""
QT_MOC_LITERAL(3, 24, 6), // "volume"
QT_MOC_LITERAL(4, 31, 8), // "songData"
QT_MOC_LITERAL(5, 40, 6), // "size_t"
QT_MOC_LITERAL(6, 47, 4), // "time"
QT_MOC_LITERAL(7, 52, 12), // "songFinished"
QT_MOC_LITERAL(8, 65, 18), // "currPositionInSong"
QT_MOC_LITERAL(9, 84, 4), // "play"
QT_MOC_LITERAL(10, 89, 6), // "playAt"
QT_MOC_LITERAL(11, 96, 3), // "pos"
QT_MOC_LITERAL(12, 100, 5), // "pause"
QT_MOC_LITERAL(13, 106, 4), // "stop"
QT_MOC_LITERAL(14, 111, 11), // "fastForward"
QT_MOC_LITERAL(15, 123, 6), // "rewind"
QT_MOC_LITERAL(16, 130, 7), // "restart"
QT_MOC_LITERAL(17, 138, 9), // "setDevice"
QT_MOC_LITERAL(18, 148, 12), // "deviceNumber"
QT_MOC_LITERAL(19, 161, 9), // "setVolume"
QT_MOC_LITERAL(20, 171, 3), // "vol"
QT_MOC_LITERAL(21, 175, 16), // "setPlayingOffset"
QT_MOC_LITERAL(22, 192, 10), // "timeOffset"
QT_MOC_LITERAL(23, 203, 13), // "setWhatToPlay"
QT_MOC_LITERAL(24, 217, 6), // "string"
QT_MOC_LITERAL(25, 224, 10), // "whatToPlay"
QT_MOC_LITERAL(26, 235, 10), // "setBalance"
QT_MOC_LITERAL(27, 246, 3), // "pan"
QT_MOC_LITERAL(28, 250, 9), // "onTimeOut"
QT_MOC_LITERAL(29, 260, 14), // "onSoundStopped"
QT_MOC_LITERAL(30, 275, 16), // "setPlayBackSpeed"
QT_MOC_LITERAL(31, 292, 5) // "speed"

    },
    "musicEngine\0currVolume\0\0volume\0songData\0"
    "size_t\0time\0songFinished\0currPositionInSong\0"
    "play\0playAt\0pos\0pause\0stop\0fastForward\0"
    "rewind\0restart\0setDevice\0deviceNumber\0"
    "setVolume\0vol\0setPlayingOffset\0"
    "timeOffset\0setWhatToPlay\0string\0"
    "whatToPlay\0setBalance\0pan\0onTimeOut\0"
    "onSoundStopped\0setPlayBackSpeed\0speed"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_musicEngine[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      19,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,  109,    2, 0x06 /* Public */,
       4,    2,  112,    2, 0x06 /* Public */,
       7,    0,  117,    2, 0x06 /* Public */,
       8,    1,  118,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       9,    0,  121,    2, 0x0a /* Public */,
      10,    1,  122,    2, 0x0a /* Public */,
      12,    0,  125,    2, 0x0a /* Public */,
      13,    0,  126,    2, 0x0a /* Public */,
      14,    0,  127,    2, 0x0a /* Public */,
      15,    0,  128,    2, 0x0a /* Public */,
      16,    0,  129,    2, 0x0a /* Public */,
      17,    1,  130,    2, 0x0a /* Public */,
      19,    1,  133,    2, 0x0a /* Public */,
      21,    1,  136,    2, 0x0a /* Public */,
      23,    1,  139,    2, 0x0a /* Public */,
      26,    1,  142,    2, 0x0a /* Public */,
      28,    0,  145,    2, 0x0a /* Public */,
      29,    0,  146,    2, 0x0a /* Public */,
      30,    1,  147,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Float,    3,
    QMetaType::Void, 0x80000000 | 5, 0x80000000 | 5,    3,    6,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Float,    6,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   11,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   18,
    QMetaType::Void, QMetaType::Int,   20,
    QMetaType::Void, QMetaType::Float,   22,
    QMetaType::Void, 0x80000000 | 24,   25,
    QMetaType::Void, QMetaType::Int,   27,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   31,

       0        // eod
};

void musicEngine::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        musicEngine *_t = static_cast<musicEngine *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->currVolume((*reinterpret_cast< float(*)>(_a[1]))); break;
        case 1: _t->songData((*reinterpret_cast< size_t(*)>(_a[1])),(*reinterpret_cast< size_t(*)>(_a[2]))); break;
        case 2: _t->songFinished(); break;
        case 3: _t->currPositionInSong((*reinterpret_cast< float(*)>(_a[1]))); break;
        case 4: _t->play(); break;
        case 5: _t->playAt((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->pause(); break;
        case 7: _t->stop(); break;
        case 8: _t->fastForward(); break;
        case 9: _t->rewind(); break;
        case 10: _t->restart(); break;
        case 11: _t->setDevice((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 12: _t->setVolume((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 13: _t->setPlayingOffset((*reinterpret_cast< float(*)>(_a[1]))); break;
        case 14: _t->setWhatToPlay((*reinterpret_cast< string(*)>(_a[1]))); break;
        case 15: _t->setBalance((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 16: _t->onTimeOut(); break;
        case 17: _t->onSoundStopped(); break;
        case 18: _t->setPlayBackSpeed((*reinterpret_cast< const int(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (musicEngine::*_t)(float );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&musicEngine::currVolume)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (musicEngine::*_t)(size_t , size_t );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&musicEngine::songData)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (musicEngine::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&musicEngine::songFinished)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (musicEngine::*_t)(float );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&musicEngine::currPositionInSong)) {
                *result = 3;
                return;
            }
        }
    }
}

const QMetaObject musicEngine::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_musicEngine.data,
      qt_meta_data_musicEngine,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *musicEngine::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *musicEngine::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_musicEngine.stringdata0))
        return static_cast<void*>(const_cast< musicEngine*>(this));
    return QWidget::qt_metacast(_clname);
}

int musicEngine::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 19)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 19;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 19)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 19;
    }
    return _id;
}

// SIGNAL 0
void musicEngine::currVolume(float _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void musicEngine::songData(size_t _t1, size_t _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void musicEngine::songFinished()
{
    QMetaObject::activate(this, &staticMetaObject, 2, Q_NULLPTR);
}

// SIGNAL 3
void musicEngine::currPositionInSong(float _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_END_MOC_NAMESPACE
