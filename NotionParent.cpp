#include "NotionParent.h"

NotionParent::NotionParent(QObject *parent) : QObject(parent) {}

NotionParent::NotionParent(QObject *parent, const QJsonObject &obj) :
    QObject(parent) {
    fromJson(obj);
}

NotionParent::NotionParent(const NotionParent &other) : QObject(other.parent()) {
    _type = other.type();

    if(_type == WorkspaceParent)
        _id = other.id();
}

NotionParent::ParentType NotionParent::type() const {
    return _type;
}

QString NotionParent::id() const {
    if(_type == WorkspaceParent)
        return "";
    return _id;
}

void NotionParent::fromJson(const QJsonObject &obj) {
    QString type = obj.value("type").toString();

    if(type == "database_id") {
        _type = DatabaseParent;
        _id = obj.value("database_id").toString();
    }
    if(type == "page_id") {
        _type = PageParent;
        _id = obj.value("page_id").toString();
    }
    if(type == "workspace") {
        _type = WorkspaceParent;
    }
    if(type == "block_id") {
        _type = BlockParent;
        _id = obj.value("block_id").toString();
    }
}
