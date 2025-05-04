/****************************************************************************
** Meta object code from reading C++ file 'QZXing.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.7.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../QZXing/src/QZXing.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'QZXing.h' doesn't include <QObject>."
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
struct qt_meta_stringdata_CLASSQZXingENDCLASS_t {};
constexpr auto qt_meta_stringdata_CLASSQZXingENDCLASS = QtMocHelpers::stringData(
    "QZXing",
    "decodingStarted",
    "",
    "decodingFinished",
    "succeeded",
    "enabledFormatsChanged",
    "tagFound",
    "tag",
    "tagFoundAdvanced",
    "format",
    "charSet",
    "rect",
    "metadata",
    "error",
    "msg",
    "decodeImage",
    "image",
    "maxWidth",
    "maxHeight",
    "smoothTransformation",
    "decodeImageFromFile",
    "imageFilePath",
    "decodeImageQML",
    "item",
    "decodeSubImageQML",
    "offsetX",
    "offsetY",
    "width",
    "height",
    "imageUrl",
    "encodeData",
    "data",
    "QZXingEncoderConfig",
    "encoderConfig",
    "EncoderFormat",
    "encoderFormat",
    "encoderImageSize",
    "EncodeErrorCorrectionLevel",
    "errorCorrectionLevel",
    "border",
    "transparent",
    "getProcessTimeOfLastDecoding",
    "getEnabledFormats",
    "setDecoder",
    "hint",
    "foundedFormat",
    "processingTime",
    "enabledDecoders",
    "tryHarderType",
    "imageSourceFilter",
    "tryHarder",
    "allowedExtensions",
    "DecoderFormat",
    "DecoderFormat_None",
    "DecoderFormat_Aztec",
    "DecoderFormat_CODABAR",
    "DecoderFormat_CODE_39",
    "DecoderFormat_CODE_93",
    "DecoderFormat_CODE_128",
    "DecoderFormat_DATA_MATRIX",
    "DecoderFormat_EAN_8",
    "DecoderFormat_EAN_13",
    "DecoderFormat_ITF",
    "DecoderFormat_MAXICODE",
    "DecoderFormat_PDF_417",
    "DecoderFormat_QR_CODE",
    "DecoderFormat_RSS_14",
    "DecoderFormat_RSS_EXPANDED",
    "DecoderFormat_UPC_A",
    "DecoderFormat_UPC_E",
    "DecoderFormat_UPC_EAN_EXTENSION",
    "DecoderFormat_CODE_128_GS1",
    "TryHarderBehaviour",
    "TryHarderBehaviour_ThoroughScanning",
    "TryHarderBehaviour_Rotate",
    "SourceFilter",
    "SourceFilter_ImageNormal",
    "SourceFilter_ImageInverted"
);
#else  // !QT_MOC_HAS_STRINGDATA
#error "qtmochelpers.h not found or too old."
#endif // !QT_MOC_HAS_STRINGDATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSQZXingENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
      40,   14, // methods
       6,  474, // properties
       3,  504, // enums/sets
       0,    0, // constructors
       0,       // flags
       8,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,  254,    2, 0x06,   10 /* Public */,
       3,    1,  255,    2, 0x06,   11 /* Public */,
       5,    0,  258,    2, 0x06,   13 /* Public */,
       6,    1,  259,    2, 0x06,   14 /* Public */,
       8,    3,  262,    2, 0x106,   16 /* Public | MethodIsConst  */,
       8,    4,  269,    2, 0x106,   20 /* Public | MethodIsConst  */,
       8,    4,  278,    2, 0x106,   25 /* Public | MethodIsConst  */,
      13,    1,  287,    2, 0x06,   30 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
      15,    4,  290,    2, 0x0a,   32 /* Public */,
      15,    3,  299,    2, 0x2a,   37 /* Public | MethodCloned */,
      15,    2,  306,    2, 0x2a,   41 /* Public | MethodCloned */,
      15,    1,  311,    2, 0x2a,   44 /* Public | MethodCloned */,
      20,    4,  314,    2, 0x0a,   46 /* Public */,
      20,    3,  323,    2, 0x2a,   51 /* Public | MethodCloned */,
      20,    2,  330,    2, 0x2a,   55 /* Public | MethodCloned */,
      20,    1,  335,    2, 0x2a,   58 /* Public | MethodCloned */,
      22,    1,  338,    2, 0x0a,   60 /* Public */,
      24,    5,  341,    2, 0x0a,   62 /* Public */,
      24,    4,  352,    2, 0x2a,   68 /* Public | MethodCloned */,
      24,    3,  361,    2, 0x2a,   73 /* Public | MethodCloned */,
      24,    2,  368,    2, 0x2a,   77 /* Public | MethodCloned */,
      24,    1,  373,    2, 0x2a,   80 /* Public | MethodCloned */,
      22,    1,  376,    2, 0x0a,   82 /* Public */,
      24,    5,  379,    2, 0x0a,   84 /* Public */,
      24,    4,  390,    2, 0x2a,   90 /* Public | MethodCloned */,
      24,    3,  399,    2, 0x2a,   95 /* Public | MethodCloned */,
      24,    2,  406,    2, 0x2a,   99 /* Public | MethodCloned */,
      24,    1,  411,    2, 0x2a,  102 /* Public | MethodCloned */,
      30,    2,  414,    2, 0x0a,  104 /* Public */,
      30,    6,  419,    2, 0x0a,  107 /* Public */,
      30,    5,  432,    2, 0x2a,  114 /* Public | MethodCloned */,
      30,    4,  443,    2, 0x2a,  120 /* Public | MethodCloned */,
      30,    3,  452,    2, 0x2a,  125 /* Public | MethodCloned */,
      30,    2,  459,    2, 0x2a,  129 /* Public | MethodCloned */,
      30,    1,  464,    2, 0x2a,  132 /* Public | MethodCloned */,
      41,    0,  467,    2, 0x0a,  134 /* Public */,
      42,    0,  468,    2, 0x10a,  135 /* Public | MethodIsConst  */,
      43,    1,  469,    2, 0x0a,  136 /* Public */,

 // methods: name, argc, parameters, tag, flags, initial metatype offsets
      45,    0,  472,    2, 0x102,  138 /* Public | MethodIsConst  */,
      10,    0,  473,    2, 0x102,  139 /* Public | MethodIsConst  */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    4,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    7,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString,    7,    9,   10,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QRectF,    7,    9,   10,   11,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QVariantMap,    7,    9,   10,   12,
    QMetaType::Void, QMetaType::QString,   14,

 // slots: parameters
    QMetaType::QString, QMetaType::QImage, QMetaType::Int, QMetaType::Int, QMetaType::Bool,   16,   17,   18,   19,
    QMetaType::QString, QMetaType::QImage, QMetaType::Int, QMetaType::Int,   16,   17,   18,
    QMetaType::QString, QMetaType::QImage, QMetaType::Int,   16,   17,
    QMetaType::QString, QMetaType::QImage,   16,
    QMetaType::QString, QMetaType::QString, QMetaType::Int, QMetaType::Int, QMetaType::Bool,   21,   17,   18,   19,
    QMetaType::QString, QMetaType::QString, QMetaType::Int, QMetaType::Int,   21,   17,   18,
    QMetaType::QString, QMetaType::QString, QMetaType::Int,   21,   17,
    QMetaType::QString, QMetaType::QString,   21,
    QMetaType::QString, QMetaType::QObjectStar,   23,
    QMetaType::QString, QMetaType::QObjectStar, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int,   23,   25,   26,   27,   28,
    QMetaType::QString, QMetaType::QObjectStar, QMetaType::Int, QMetaType::Int, QMetaType::Int,   23,   25,   26,   27,
    QMetaType::QString, QMetaType::QObjectStar, QMetaType::Int, QMetaType::Int,   23,   25,   26,
    QMetaType::QString, QMetaType::QObjectStar, QMetaType::Int,   23,   25,
    QMetaType::QString, QMetaType::QObjectStar,   23,
    QMetaType::QString, QMetaType::QUrl,   29,
    QMetaType::QString, QMetaType::QUrl, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int,   29,   25,   26,   27,   28,
    QMetaType::QString, QMetaType::QUrl, QMetaType::Int, QMetaType::Int, QMetaType::Int,   29,   25,   26,   27,
    QMetaType::QString, QMetaType::QUrl, QMetaType::Int, QMetaType::Int,   29,   25,   26,
    QMetaType::QString, QMetaType::QUrl, QMetaType::Int,   29,   25,
    QMetaType::QString, QMetaType::QUrl,   29,
    QMetaType::QImage, QMetaType::QString, 0x80000000 | 32,   31,   33,
    QMetaType::QImage, QMetaType::QString, 0x80000000 | 34, QMetaType::QSize, 0x80000000 | 37, QMetaType::Bool, QMetaType::Bool,   31,   35,   36,   38,   39,   40,
    QMetaType::QImage, QMetaType::QString, 0x80000000 | 34, QMetaType::QSize, 0x80000000 | 37, QMetaType::Bool,   31,   35,   36,   38,   39,
    QMetaType::QImage, QMetaType::QString, 0x80000000 | 34, QMetaType::QSize, 0x80000000 | 37,   31,   35,   36,   38,
    QMetaType::QImage, QMetaType::QString, 0x80000000 | 34, QMetaType::QSize,   31,   35,   36,
    QMetaType::QImage, QMetaType::QString, 0x80000000 | 34,   31,   35,
    QMetaType::QImage, QMetaType::QString,   31,
    QMetaType::Int,
    QMetaType::UInt,
    QMetaType::Void, QMetaType::UInt,   44,

 // methods: parameters
    QMetaType::QString,
    QMetaType::QString,

 // properties: name, type, flags
      46, QMetaType::Int, 0x00015001, uint(-1), 0,
      47, QMetaType::UInt, 0x00015003, uint(2), 0,
      48, QMetaType::UInt, 0x00015003, uint(-1), 0,
      49, QMetaType::UInt, 0x00015003, uint(-1), 0,
      50, QMetaType::Bool, 0x00015103, uint(-1), 0,
      51, QMetaType::QVariantList, 0x00015103, uint(-1), 0,

 // enums: name, alias, flags, count, data
      52,   52, 0x0,   19,  519,
      72,   72, 0x0,    2,  557,
      75,   75, 0x0,    2,  561,

 // enum data: key, value
      53, uint(QZXing::DecoderFormat_None),
      54, uint(QZXing::DecoderFormat_Aztec),
      55, uint(QZXing::DecoderFormat_CODABAR),
      56, uint(QZXing::DecoderFormat_CODE_39),
      57, uint(QZXing::DecoderFormat_CODE_93),
      58, uint(QZXing::DecoderFormat_CODE_128),
      59, uint(QZXing::DecoderFormat_DATA_MATRIX),
      60, uint(QZXing::DecoderFormat_EAN_8),
      61, uint(QZXing::DecoderFormat_EAN_13),
      62, uint(QZXing::DecoderFormat_ITF),
      63, uint(QZXing::DecoderFormat_MAXICODE),
      64, uint(QZXing::DecoderFormat_PDF_417),
      65, uint(QZXing::DecoderFormat_QR_CODE),
      66, uint(QZXing::DecoderFormat_RSS_14),
      67, uint(QZXing::DecoderFormat_RSS_EXPANDED),
      68, uint(QZXing::DecoderFormat_UPC_A),
      69, uint(QZXing::DecoderFormat_UPC_E),
      70, uint(QZXing::DecoderFormat_UPC_EAN_EXTENSION),
      71, uint(QZXing::DecoderFormat_CODE_128_GS1),
      73, uint(QZXing::TryHarderBehaviour_ThoroughScanning),
      74, uint(QZXing::TryHarderBehaviour_Rotate),
      76, uint(QZXing::SourceFilter_ImageNormal),
      77, uint(QZXing::SourceFilter_ImageInverted),

       0        // eod
};

Q_CONSTINIT const QMetaObject QZXing::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_CLASSQZXingENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSQZXingENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSQZXingENDCLASS_t,
        // property 'processingTime'
        QtPrivate::TypeAndForceComplete<int, std::true_type>,
        // property 'enabledDecoders'
        QtPrivate::TypeAndForceComplete<uint, std::true_type>,
        // property 'tryHarderType'
        QtPrivate::TypeAndForceComplete<uint, std::true_type>,
        // property 'imageSourceFilter'
        QtPrivate::TypeAndForceComplete<uint, std::true_type>,
        // property 'tryHarder'
        QtPrivate::TypeAndForceComplete<bool, std::true_type>,
        // property 'allowedExtensions'
        QtPrivate::TypeAndForceComplete<QVariantList, std::true_type>,
        // enum 'DecoderFormat'
        QtPrivate::TypeAndForceComplete<QZXing::DecoderFormat, std::true_type>,
        // enum 'TryHarderBehaviour'
        QtPrivate::TypeAndForceComplete<QZXing::TryHarderBehaviour, std::true_type>,
        // enum 'SourceFilter'
        QtPrivate::TypeAndForceComplete<QZXing::SourceFilter, std::true_type>,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<QZXing, std::true_type>,
        // method 'decodingStarted'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'decodingFinished'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'enabledFormatsChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'tagFound'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'tagFoundAdvanced'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'tagFoundAdvanced'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QRectF &, std::false_type>,
        // method 'tagFoundAdvanced'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QVariantMap &, std::false_type>,
        // method 'error'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'decodeImage'
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QImage &, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'decodeImage'
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QImage &, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'decodeImage'
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QImage &, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'decodeImage'
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QImage &, std::false_type>,
        // method 'decodeImageFromFile'
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'decodeImageFromFile'
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'decodeImageFromFile'
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'decodeImageFromFile'
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'decodeImageQML'
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<QObject *, std::false_type>,
        // method 'decodeSubImageQML'
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<QObject *, std::false_type>,
        QtPrivate::TypeAndForceComplete<const int, std::false_type>,
        QtPrivate::TypeAndForceComplete<const int, std::false_type>,
        QtPrivate::TypeAndForceComplete<const int, std::false_type>,
        QtPrivate::TypeAndForceComplete<const int, std::false_type>,
        // method 'decodeSubImageQML'
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<QObject *, std::false_type>,
        QtPrivate::TypeAndForceComplete<const int, std::false_type>,
        QtPrivate::TypeAndForceComplete<const int, std::false_type>,
        QtPrivate::TypeAndForceComplete<const int, std::false_type>,
        // method 'decodeSubImageQML'
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<QObject *, std::false_type>,
        QtPrivate::TypeAndForceComplete<const int, std::false_type>,
        QtPrivate::TypeAndForceComplete<const int, std::false_type>,
        // method 'decodeSubImageQML'
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<QObject *, std::false_type>,
        QtPrivate::TypeAndForceComplete<const int, std::false_type>,
        // method 'decodeSubImageQML'
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<QObject *, std::false_type>,
        // method 'decodeImageQML'
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QUrl &, std::false_type>,
        // method 'decodeSubImageQML'
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QUrl &, std::false_type>,
        QtPrivate::TypeAndForceComplete<const int, std::false_type>,
        QtPrivate::TypeAndForceComplete<const int, std::false_type>,
        QtPrivate::TypeAndForceComplete<const int, std::false_type>,
        QtPrivate::TypeAndForceComplete<const int, std::false_type>,
        // method 'decodeSubImageQML'
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QUrl &, std::false_type>,
        QtPrivate::TypeAndForceComplete<const int, std::false_type>,
        QtPrivate::TypeAndForceComplete<const int, std::false_type>,
        QtPrivate::TypeAndForceComplete<const int, std::false_type>,
        // method 'decodeSubImageQML'
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QUrl &, std::false_type>,
        QtPrivate::TypeAndForceComplete<const int, std::false_type>,
        QtPrivate::TypeAndForceComplete<const int, std::false_type>,
        // method 'decodeSubImageQML'
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QUrl &, std::false_type>,
        QtPrivate::TypeAndForceComplete<const int, std::false_type>,
        // method 'decodeSubImageQML'
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QUrl &, std::false_type>,
        // method 'encodeData'
        QtPrivate::TypeAndForceComplete<QImage, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QZXingEncoderConfig &, std::false_type>,
        // method 'encodeData'
        QtPrivate::TypeAndForceComplete<QImage, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        QtPrivate::TypeAndForceComplete<const EncoderFormat, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QSize, std::false_type>,
        QtPrivate::TypeAndForceComplete<const EncodeErrorCorrectionLevel, std::false_type>,
        QtPrivate::TypeAndForceComplete<const bool, std::false_type>,
        QtPrivate::TypeAndForceComplete<const bool, std::false_type>,
        // method 'encodeData'
        QtPrivate::TypeAndForceComplete<QImage, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        QtPrivate::TypeAndForceComplete<const EncoderFormat, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QSize, std::false_type>,
        QtPrivate::TypeAndForceComplete<const EncodeErrorCorrectionLevel, std::false_type>,
        QtPrivate::TypeAndForceComplete<const bool, std::false_type>,
        // method 'encodeData'
        QtPrivate::TypeAndForceComplete<QImage, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        QtPrivate::TypeAndForceComplete<const EncoderFormat, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QSize, std::false_type>,
        QtPrivate::TypeAndForceComplete<const EncodeErrorCorrectionLevel, std::false_type>,
        // method 'encodeData'
        QtPrivate::TypeAndForceComplete<QImage, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        QtPrivate::TypeAndForceComplete<const EncoderFormat, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QSize, std::false_type>,
        // method 'encodeData'
        QtPrivate::TypeAndForceComplete<QImage, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        QtPrivate::TypeAndForceComplete<const EncoderFormat, std::false_type>,
        // method 'encodeData'
        QtPrivate::TypeAndForceComplete<QImage, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'getProcessTimeOfLastDecoding'
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'getEnabledFormats'
        QtPrivate::TypeAndForceComplete<uint, std::false_type>,
        // method 'setDecoder'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const uint &, std::false_type>,
        // method 'foundedFormat'
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'charSet'
        QtPrivate::TypeAndForceComplete<QString, std::false_type>
    >,
    nullptr
} };

void QZXing::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<QZXing *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->decodingStarted(); break;
        case 1: _t->decodingFinished((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 2: _t->enabledFormatsChanged(); break;
        case 3: _t->tagFound((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 4: _t->tagFoundAdvanced((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[3]))); break;
        case 5: _t->tagFoundAdvanced((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<QRectF>>(_a[4]))); break;
        case 6: _t->tagFoundAdvanced((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<QVariantMap>>(_a[4]))); break;
        case 7: _t->error((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 8: { QString _r = _t->decodeImage((*reinterpret_cast< std::add_pointer_t<QImage>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<bool>>(_a[4])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 9: { QString _r = _t->decodeImage((*reinterpret_cast< std::add_pointer_t<QImage>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[3])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 10: { QString _r = _t->decodeImage((*reinterpret_cast< std::add_pointer_t<QImage>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 11: { QString _r = _t->decodeImage((*reinterpret_cast< std::add_pointer_t<QImage>>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 12: { QString _r = _t->decodeImageFromFile((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<bool>>(_a[4])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 13: { QString _r = _t->decodeImageFromFile((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[3])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 14: { QString _r = _t->decodeImageFromFile((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 15: { QString _r = _t->decodeImageFromFile((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 16: { QString _r = _t->decodeImageQML((*reinterpret_cast< std::add_pointer_t<QObject*>>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 17: { QString _r = _t->decodeSubImageQML((*reinterpret_cast< std::add_pointer_t<QObject*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[4])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[5])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 18: { QString _r = _t->decodeSubImageQML((*reinterpret_cast< std::add_pointer_t<QObject*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[4])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 19: { QString _r = _t->decodeSubImageQML((*reinterpret_cast< std::add_pointer_t<QObject*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[3])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 20: { QString _r = _t->decodeSubImageQML((*reinterpret_cast< std::add_pointer_t<QObject*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 21: { QString _r = _t->decodeSubImageQML((*reinterpret_cast< std::add_pointer_t<QObject*>>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 22: { QString _r = _t->decodeImageQML((*reinterpret_cast< std::add_pointer_t<QUrl>>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 23: { QString _r = _t->decodeSubImageQML((*reinterpret_cast< std::add_pointer_t<QUrl>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[4])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[5])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 24: { QString _r = _t->decodeSubImageQML((*reinterpret_cast< std::add_pointer_t<QUrl>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[4])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 25: { QString _r = _t->decodeSubImageQML((*reinterpret_cast< std::add_pointer_t<QUrl>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[3])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 26: { QString _r = _t->decodeSubImageQML((*reinterpret_cast< std::add_pointer_t<QUrl>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 27: { QString _r = _t->decodeSubImageQML((*reinterpret_cast< std::add_pointer_t<QUrl>>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 28: { QImage _r = _t->encodeData((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QZXingEncoderConfig>>(_a[2])));
            if (_a[0]) *reinterpret_cast< QImage*>(_a[0]) = std::move(_r); }  break;
        case 29: { QImage _r = _t->encodeData((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<EncoderFormat>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QSize>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<EncodeErrorCorrectionLevel>>(_a[4])),(*reinterpret_cast< std::add_pointer_t<bool>>(_a[5])),(*reinterpret_cast< std::add_pointer_t<bool>>(_a[6])));
            if (_a[0]) *reinterpret_cast< QImage*>(_a[0]) = std::move(_r); }  break;
        case 30: { QImage _r = _t->encodeData((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<EncoderFormat>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QSize>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<EncodeErrorCorrectionLevel>>(_a[4])),(*reinterpret_cast< std::add_pointer_t<bool>>(_a[5])));
            if (_a[0]) *reinterpret_cast< QImage*>(_a[0]) = std::move(_r); }  break;
        case 31: { QImage _r = _t->encodeData((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<EncoderFormat>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QSize>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<EncodeErrorCorrectionLevel>>(_a[4])));
            if (_a[0]) *reinterpret_cast< QImage*>(_a[0]) = std::move(_r); }  break;
        case 32: { QImage _r = _t->encodeData((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<EncoderFormat>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QSize>>(_a[3])));
            if (_a[0]) *reinterpret_cast< QImage*>(_a[0]) = std::move(_r); }  break;
        case 33: { QImage _r = _t->encodeData((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<EncoderFormat>>(_a[2])));
            if (_a[0]) *reinterpret_cast< QImage*>(_a[0]) = std::move(_r); }  break;
        case 34: { QImage _r = _t->encodeData((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])));
            if (_a[0]) *reinterpret_cast< QImage*>(_a[0]) = std::move(_r); }  break;
        case 35: { int _r = _t->getProcessTimeOfLastDecoding();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 36: { uint _r = _t->getEnabledFormats();
            if (_a[0]) *reinterpret_cast< uint*>(_a[0]) = std::move(_r); }  break;
        case 37: _t->setDecoder((*reinterpret_cast< std::add_pointer_t<uint>>(_a[1]))); break;
        case 38: { QString _r = _t->foundedFormat();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 39: { QString _r = _t->charSet();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (QZXing::*)();
            if (_t _q_method = &QZXing::decodingStarted; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (QZXing::*)(bool );
            if (_t _q_method = &QZXing::decodingFinished; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (QZXing::*)();
            if (_t _q_method = &QZXing::enabledFormatsChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (QZXing::*)(QString );
            if (_t _q_method = &QZXing::tagFound; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (QZXing::*)(const QString & , const QString & , const QString & ) const;
            if (_t _q_method = &QZXing::tagFoundAdvanced; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (QZXing::*)(const QString & , const QString & , const QString & , const QRectF & ) const;
            if (_t _q_method = &QZXing::tagFoundAdvanced; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (QZXing::*)(const QString & , const QString & , const QString & , const QVariantMap & ) const;
            if (_t _q_method = &QZXing::tagFoundAdvanced; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 6;
                return;
            }
        }
        {
            using _t = void (QZXing::*)(QString );
            if (_t _q_method = &QZXing::error; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 7;
                return;
            }
        }
    } else if (_c == QMetaObject::ReadProperty) {
        auto *_t = static_cast<QZXing *>(_o);
        (void)_t;
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< int*>(_v) = _t->getProcessTimeOfLastDecoding(); break;
        case 1: *reinterpret_cast< uint*>(_v) = _t->getEnabledFormats(); break;
        case 2: *reinterpret_cast< uint*>(_v) = _t->getTryHarderBehaviour(); break;
        case 3: *reinterpret_cast< uint*>(_v) = _t->getSourceFilterType(); break;
        case 4: *reinterpret_cast< bool*>(_v) = _t->getTryHarder(); break;
        case 5: *reinterpret_cast< QVariantList*>(_v) = _t->getAllowedExtensions(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        auto *_t = static_cast<QZXing *>(_o);
        (void)_t;
        void *_v = _a[0];
        switch (_id) {
        case 1: _t->setDecoder(*reinterpret_cast< uint*>(_v)); break;
        case 2: _t->setTryHarderBehaviour(*reinterpret_cast< uint*>(_v)); break;
        case 3: _t->setSourceFilterType(*reinterpret_cast< uint*>(_v)); break;
        case 4: _t->setTryHarder(*reinterpret_cast< bool*>(_v)); break;
        case 5: _t->setAllowedExtensions(*reinterpret_cast< QVariantList*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    } else if (_c == QMetaObject::BindableProperty) {
    }
}

const QMetaObject *QZXing::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QZXing::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSQZXingENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int QZXing::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 40)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 40;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 40)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 40;
    }else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::BindableProperty
            || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void QZXing::decodingStarted()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void QZXing::decodingFinished(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void QZXing::enabledFormatsChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void QZXing::tagFound(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void QZXing::tagFoundAdvanced(const QString & _t1, const QString & _t2, const QString & _t3)const
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))) };
    QMetaObject::activate(const_cast< QZXing *>(this), &staticMetaObject, 4, _a);
}

// SIGNAL 5
void QZXing::tagFoundAdvanced(const QString & _t1, const QString & _t2, const QString & _t3, const QRectF & _t4)const
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t4))) };
    QMetaObject::activate(const_cast< QZXing *>(this), &staticMetaObject, 5, _a);
}

// SIGNAL 6
void QZXing::tagFoundAdvanced(const QString & _t1, const QString & _t2, const QString & _t3, const QVariantMap & _t4)const
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t4))) };
    QMetaObject::activate(const_cast< QZXing *>(this), &staticMetaObject, 6, _a);
}

// SIGNAL 7
void QZXing::error(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}
QT_WARNING_POP
