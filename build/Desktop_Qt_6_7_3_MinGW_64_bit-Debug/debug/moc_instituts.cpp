/****************************************************************************
** Meta object code from reading C++ file 'instituts.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.7.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../instituts.h"
#include <QtNetwork/QSslError>
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'instituts.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.7.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {

#ifdef QT_MOC_HAS_STRINGDATA
struct qt_meta_stringdata_CLASSinstitutsENDCLASS_t {};
constexpr auto qt_meta_stringdata_CLASSinstitutsENDCLASS = QtMocHelpers::stringData(
    "instituts",
    "marqueurAjoute",
    "",
    "lat",
    "lon",
    "centerMap",
    "onemployee_in_TextChanged",
    "text",
    "employee_inExists",
    "id",
    "loadTableData",
    "updateTableData",
    "updateTableWithModel",
    "QSqlQueryModel*",
    "model",
    "performSearch",
    "performSorting",
    "order",
    "onTableRowClicked",
    "on_b1_in_clicked",
    "on_b2_in_clicked",
    "on_b3_in_clicked",
    "on_b4_in_clicked",
    "on_addButton_in_clicked",
    "onTri_inComboBoxChanged",
    "idx",
    "onCroissantButtonClicked",
    "onDecroissantButtonClicked",
    "onrecherche_inIdTextChanged",
    "on_pdf_in_clicked",
    "on_noti_in_clicked",
    "on_map_in_clicked",
    "on_pushButton_5_clicked",
    "on_pushButton_6_clicked",
    "on_pushButton_11_clicked",
    "on_pushButton_12_clicked",
    "update_label_in",
    "afficherStatistiquesCapacite",
    "onGeoCodeReply",
    "QNetworkReply*",
    "reply",
    "searchLocation",
    "address",
    "searchInstitut",
    "name",
    "notifyUser",
    "title",
    "message",
    "QSystemTrayIcon::MessageIcon",
    "icon",
    "on_pushButton_18_clicked"
);
#else  // !QT_MOC_HAS_STRINGDATA
#error "qtmochelpers.h not found or too old."
#endif // !QT_MOC_HAS_STRINGDATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSinstitutsENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
      34,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    2,  218,    2, 0x06,    1 /* Public */,
       5,    2,  223,    2, 0x06,    4 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       6,    1,  228,    2, 0x08,    7 /* Private */,
       8,    1,  231,    2, 0x08,    9 /* Private */,
      10,    0,  234,    2, 0x08,   11 /* Private */,
      11,    0,  235,    2, 0x08,   12 /* Private */,
      12,    1,  236,    2, 0x08,   13 /* Private */,
      15,    1,  239,    2, 0x08,   15 /* Private */,
      16,    1,  242,    2, 0x08,   17 /* Private */,
      18,    0,  245,    2, 0x08,   19 /* Private */,
      19,    0,  246,    2, 0x08,   20 /* Private */,
      20,    0,  247,    2, 0x08,   21 /* Private */,
      21,    0,  248,    2, 0x08,   22 /* Private */,
      22,    0,  249,    2, 0x08,   23 /* Private */,
      23,    0,  250,    2, 0x08,   24 /* Private */,
      24,    1,  251,    2, 0x08,   25 /* Private */,
      26,    0,  254,    2, 0x08,   27 /* Private */,
      27,    0,  255,    2, 0x08,   28 /* Private */,
      28,    1,  256,    2, 0x08,   29 /* Private */,
      29,    0,  259,    2, 0x08,   31 /* Private */,
      30,    0,  260,    2, 0x08,   32 /* Private */,
      31,    0,  261,    2, 0x08,   33 /* Private */,
      32,    0,  262,    2, 0x08,   34 /* Private */,
      33,    0,  263,    2, 0x08,   35 /* Private */,
      34,    0,  264,    2, 0x08,   36 /* Private */,
      35,    0,  265,    2, 0x08,   37 /* Private */,
      36,    0,  266,    2, 0x08,   38 /* Private */,
      37,    0,  267,    2, 0x08,   39 /* Private */,
      38,    1,  268,    2, 0x08,   40 /* Private */,
      41,    1,  271,    2, 0x08,   42 /* Private */,
      43,    1,  274,    2, 0x08,   44 /* Private */,
      45,    3,  277,    2, 0x08,   46 /* Private */,
      45,    2,  284,    2, 0x28,   50 /* Private | MethodCloned */,
      50,    0,  289,    2, 0x08,   53 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Double, QMetaType::Double,    3,    4,
    QMetaType::Void, QMetaType::Double, QMetaType::Double,    3,    4,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    7,
    QMetaType::Bool, QMetaType::QString,    9,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 13,   14,
    QMetaType::Void, QMetaType::QString,    7,
    QMetaType::Void, QMetaType::QString,   17,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   25,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    7,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 39,   40,
    QMetaType::Void, QMetaType::QString,   42,
    QMetaType::Void, QMetaType::QString,   44,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, 0x80000000 | 48,   46,   47,   49,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,   46,   47,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject instituts::staticMetaObject = { {
    QMetaObject::SuperData::link<QDialog::staticMetaObject>(),
    qt_meta_stringdata_CLASSinstitutsENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSinstitutsENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSinstitutsENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<instituts, std::true_type>,
        // method 'marqueurAjoute'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<double, std::false_type>,
        QtPrivate::TypeAndForceComplete<double, std::false_type>,
        // method 'centerMap'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<double, std::false_type>,
        QtPrivate::TypeAndForceComplete<double, std::false_type>,
        // method 'onemployee_in_TextChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'employee_inExists'
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'loadTableData'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'updateTableData'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'updateTableWithModel'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QSqlQueryModel *, std::false_type>,
        // method 'performSearch'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'performSorting'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'onTableRowClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_b1_in_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_b2_in_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_b3_in_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_b4_in_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_addButton_in_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onTri_inComboBoxChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'onCroissantButtonClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onDecroissantButtonClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onrecherche_inIdTextChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'on_pdf_in_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_noti_in_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_map_in_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pushButton_5_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pushButton_6_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pushButton_11_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pushButton_12_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'update_label_in'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'afficherStatistiquesCapacite'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onGeoCodeReply'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QNetworkReply *, std::false_type>,
        // method 'searchLocation'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'searchInstitut'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'notifyUser'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        QtPrivate::TypeAndForceComplete<QSystemTrayIcon::MessageIcon, std::false_type>,
        // method 'notifyUser'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'on_pushButton_18_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void instituts::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<instituts *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->marqueurAjoute((*reinterpret_cast< std::add_pointer_t<double>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<double>>(_a[2]))); break;
        case 1: _t->centerMap((*reinterpret_cast< std::add_pointer_t<double>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<double>>(_a[2]))); break;
        case 2: _t->onemployee_in_TextChanged((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 3: { bool _r = _t->employee_inExists((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 4: _t->loadTableData(); break;
        case 5: _t->updateTableData(); break;
        case 6: _t->updateTableWithModel((*reinterpret_cast< std::add_pointer_t<QSqlQueryModel*>>(_a[1]))); break;
        case 7: _t->performSearch((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 8: _t->performSorting((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 9: _t->onTableRowClicked(); break;
        case 10: _t->on_b1_in_clicked(); break;
        case 11: _t->on_b2_in_clicked(); break;
        case 12: _t->on_b3_in_clicked(); break;
        case 13: _t->on_b4_in_clicked(); break;
        case 14: _t->on_addButton_in_clicked(); break;
        case 15: _t->onTri_inComboBoxChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 16: _t->onCroissantButtonClicked(); break;
        case 17: _t->onDecroissantButtonClicked(); break;
        case 18: _t->onrecherche_inIdTextChanged((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 19: _t->on_pdf_in_clicked(); break;
        case 20: _t->on_noti_in_clicked(); break;
        case 21: _t->on_map_in_clicked(); break;
        case 22: _t->on_pushButton_5_clicked(); break;
        case 23: _t->on_pushButton_6_clicked(); break;
        case 24: _t->on_pushButton_11_clicked(); break;
        case 25: _t->on_pushButton_12_clicked(); break;
        case 26: _t->update_label_in(); break;
        case 27: _t->afficherStatistiquesCapacite(); break;
        case 28: _t->onGeoCodeReply((*reinterpret_cast< std::add_pointer_t<QNetworkReply*>>(_a[1]))); break;
        case 29: _t->searchLocation((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 30: _t->searchInstitut((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 31: _t->notifyUser((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QSystemTrayIcon::MessageIcon>>(_a[3]))); break;
        case 32: _t->notifyUser((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2]))); break;
        case 33: _t->on_pushButton_18_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
        case 6:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QSqlQueryModel* >(); break;
            }
            break;
        case 28:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QNetworkReply* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (instituts::*)(double , double );
            if (_t _q_method = &instituts::marqueurAjoute; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (instituts::*)(double , double );
            if (_t _q_method = &instituts::centerMap; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject *instituts::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *instituts::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSinstitutsENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int instituts::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 34)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 34;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 34)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 34;
    }
    return _id;
}

// SIGNAL 0
void instituts::marqueurAjoute(double _t1, double _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void instituts::centerMap(double _t1, double _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
