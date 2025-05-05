#ifndef MARKERMODEL_H
#define MARKERMODEL_H

#include <QAbstractListModel>

/* ----------------------------------------------------------------
 *  A *very* small struct that stores one marker.
 * ---------------------------------------------------------------*/
struct Marker {
    QString name;
    double  lat  = 0.0;
    double  lon  = 0.0;
};

class MarkerModel : public QAbstractListModel
{
    Q_OBJECT
    /*  <--  This Q_PROPERTY lets QML query model.count    */
    Q_PROPERTY(int count READ count NOTIFY countChanged)

public:
    explicit MarkerModel(QObject *parent = nullptr);

    /* -------  Roles exposed to QML  -----------------------------*/
    enum Roles { NameRole = Qt::UserRole + 1, LatRole, LonRole };
    QHash<int,QByteArray> roleNames() const override;

    /* -------  QAbstractItemModel interface  --------------------*/
    int rowCount(const QModelIndex &parent = QModelIndex() ) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

    /* -------  API used by C++ or QML  ---------------------------*/
    Q_INVOKABLE void clear();
    Q_INVOKABLE void addLocation(const QString &name,double lat,double lon);
    Q_INVOKABLE bool loadFromJson(const QString &file = QString());

    /*  NEW wrapper so you can call  m_markerModel.count()  */
    int  count() const { return rowCount(); }

signals:
    void countChanged();

private:
    QList<Marker> m_markers;
};

#endif // MARKERMODEL_H
