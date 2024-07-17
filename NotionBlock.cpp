#include "NotionBlock.h"

NotionBlock::NotionBlock(QObject *parent) :
    QObject(parent),
    _parent(this),
    _isValid(true) {
}

NotionBlock::NotionBlock(QObject *parent, const QJsonObject &obj) :
    QObject(parent),
    _parent(this, obj.value("parent").toObject()),
    _isValid(true)  {
    fromJson(obj);
}

QString                NotionBlock::id()             const {return _id;}
NotionParent           NotionBlock::blockParent()    const {return _parent;}
QDateTime              NotionBlock::createdTime()    const {return _createdTime;}
QDateTime              NotionBlock::lastEditedTime() const {return _lastEditedTime;}
QString                NotionBlock::creatdBy()       const {return _creatdBy;}
QString                NotionBlock::lastEditedBy()   const {return _lastEditedBy;}
bool                   NotionBlock::inTrash()        const {return _inTrash;}
NotionBlock::BlockType NotionBlock::type()           const {return _type;}

void NotionBlock::fromJson(const QJsonObject &obj) {
    if(obj.value("object") != "page") {
        _isValid = false;
        return;
    }

    _id = obj.value("id").toString();
    _createdTime = QDateTime::fromString(obj.value("created_time").toString(), "yyyy-MM-dd'T'HH:mm:ss.zzz'Z'");
    _lastEditedTime = QDateTime::fromString(obj.value("last_edited_time").toString(), "yyyy-MM-dd'T'HH:mm:ss.zzz'Z'");
    _creatdBy = obj.value("created_by").toObject().value("id").toString();
    _lastEditedBy = obj.value("last_edited_by").toObject().value("id").toString();
    _inTrash = obj.value("in_trash").toBool();
}
