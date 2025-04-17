#include "markermodel.h"
#include <QFile>
#include <QIODevice>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>
#include <QJsonValue>
#include <QDebug>

MarkerModel::MarkerModel(QObject *parent) : QAbstractListModel(parent) {}

int MarkerModel::rowCount(const QModelIndex &parent) const {
    Q_UNUSED(parent);
    return m_coordinates.size();
}

QVariant MarkerModel::data(const QModelIndex &index, int role) const {
    if (!index.isValid() || index.row() >= m_coordinates.size())
        return QVariant();

    if (role == CoordinateRole)
        return QVariant::fromValue(m_coordinates.at(index.row()));

    return QVariant();
}

QHash<int, QByteArray> MarkerModel::roleNames() const {
    QHash<int, QByteArray> roles;
    roles[CoordinateRole] = "coordinate";
    return roles;
}

void MarkerModel::addMarker(const QGeoCoordinate &coordinate) {
    beginInsertRows(QModelIndex(), m_coordinates.size(), m_coordinates.size());
    m_coordinates.append(coordinate);
    endInsertRows();
    saveToJson(); // Sauvegarder après ajout
}

void MarkerModel::addLocation(const QString &name, double lat, double lon) {
    QGeoCoordinate coord(lat, lon);
    m_locationNames[coord] = name; // Stockez le nom dans une QMap séparée
    addMarker(coord);
}
void MarkerModel::loadFromJson()
{
    QFile file(m_jsonFilePath);
    if (!file.open(QIODevice::ReadOnly)) {
        qWarning() << "Impossible d'ouvrir" << m_jsonFilePath;
        return;
    }

    QByteArray data = file.readAll();
    QJsonDocument doc = QJsonDocument::fromJson(data);
    if (doc.isNull()) {
        qWarning() << "JSON invalide dans" << m_jsonFilePath;
        return;
    }

    beginResetModel();
    m_coordinates.clear();
    QJsonArray array = doc.array();
    for (const QJsonValue &value : array) {
        QJsonObject obj = value.toObject();
        QGeoCoordinate coord(obj["lat"].toDouble(), obj["lon"].toDouble());
        m_coordinates.append(coord);
        m_locationNames[coord] = obj["name"].toString(); // Assurez-vous que le nom est stocké
    }
    endResetModel();
}


void MarkerModel::saveToJson() {
    QJsonArray array;
    for (const QGeoCoordinate &coord : m_coordinates) {
        QJsonObject obj;
        obj["lat"] = coord.latitude();
        obj["lon"] = coord.longitude();
        array.append(obj);
    }

    QFile file(m_jsonFilePath);
    if (!file.open(QIODevice::WriteOnly)) {
        qWarning() << "Échec de sauvegarde dans" << m_jsonFilePath;
        return;
    }

    file.write(QJsonDocument(array).toJson());
}
void MarkerModel::removeLocation(const QString &name) {
    beginResetModel();
    endResetModel();
}
void MarkerModel::clear()
{
    beginResetModel();
    m_coordinates.clear();
    m_locationNames.clear();
    endResetModel();
}
