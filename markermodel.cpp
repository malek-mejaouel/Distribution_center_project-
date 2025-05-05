#include "markermodel.h"
#include <QFile>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>

MarkerModel::MarkerModel(QObject *parent)
    : QAbstractListModel(parent)
{
}

/* -----------------------  Roles  ------------------------------*/
QHash<int, QByteArray> MarkerModel::roleNames() const
{
    return {
        { NameRole, "name" },
        { LatRole,  "latitude" },
        { LonRole,  "longitude" }
    };
}

/* -------------------  Model interface  ------------------------*/
int MarkerModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent)
    return m_markers.count();
}

QVariant MarkerModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid() || index.row() >= m_markers.size())
        return {};

    const Marker &m = m_markers.at(index.row());
    switch (role) {
    case NameRole: return m.name;
    case LatRole:  return m.lat;
    case LonRole:  return m.lon;
    default:       return {};
    }
}

/* ------------------------  API  --------------------------------*/
void MarkerModel::clear()
{
    if (m_markers.isEmpty()) return;
    beginResetModel();
    m_markers.clear();
    endResetModel();
    emit countChanged();
}

void MarkerModel::addLocation(const QString &name,double lat,double lon)
{
    beginInsertRows(QModelIndex(), m_markers.count(), m_markers.count());
    m_markers.append({name,lat,lon});
    endInsertRows();
    emit countChanged();
}

bool MarkerModel::loadFromJson(const QString &file)
{
    QFile f(file.isEmpty() ? ":/markerdata.json" : file);
    if (!f.open(QIODevice::ReadOnly)) return false;

    QJsonDocument doc = QJsonDocument::fromJson(f.readAll());
    if (!doc.isArray()) return false;

    clear();
    const QJsonArray arr = doc.array();
    for (const QJsonValue &v : arr) {
        const QJsonObject o = v.toObject();
        addLocation(o["name"].toString(),
                    o["lat"] .toDouble(),
                    o["lon"] .toDouble());
    }
    return true;
}
