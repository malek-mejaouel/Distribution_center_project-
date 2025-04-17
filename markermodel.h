#ifndef MARKERMODEL_H
#define MARKERMODEL_H

#include <QAbstractListModel>
#include <QGeoCoordinate>

class MarkerModel : public QAbstractListModel
{
    Q_OBJECT

public:
    explicit MarkerModel(QObject *parent = nullptr);

    enum MarkerRoles { CoordinateRole = Qt::UserRole + 1 };

    // QAbstractItemModel interface
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    QHash<int, QByteArray> roleNames() const override;

    // QML interface
    Q_INVOKABLE void addMarker(const QGeoCoordinate &coordinate);
    Q_INVOKABLE void addLocation(const QString &name, double lat, double lon);
    Q_INVOKABLE void removeLocation(const QString &name);
    Q_INVOKABLE void loadFromJson();
    Q_INVOKABLE void saveToJson();
    Q_INVOKABLE void clear(); // Méthode pour effacer les marqueurs

private:
    QList<QGeoCoordinate> m_coordinates;
    QHash<QGeoCoordinate, QString> m_locationNames;
    QString m_jsonFilePath = "markers.json";
};

#endif // MARKERMODEL_H
