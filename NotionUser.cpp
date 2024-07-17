#include "NotionUser.h"

NotionUser::NotionUser(QObject *parent) : QObject{parent} {}

NotionUser::NotionUser(QObject *parent, const QJsonObject &obj) :
    QObject(parent) {
    fromJson(obj);
}

NotionUser::NotionUser(const NotionUser &other) : QObject(other.parent()) {
    _id = other.id();
    _type = other.type();
    _name = other.name();
    _avatarUrl = other.avatarUrl();
}

QString          NotionUser::id()        const {return _id;}
NotionUser::Type NotionUser::type()      const {return _type;}
QString          NotionUser::name()      const {return _name;}
QString          NotionUser::avatarUrl() const {return _avatarUrl;}

QString NotionUser::personEmail() const {
    if(_type == PersonType)
        return _personEmail;
    return "";
}

void NotionUser::fromJson(const QJsonObject &obj) {
    _id = obj.value("id").toString();
    _name = obj.value("name").toString();
    _avatarUrl = obj.value("avatar_url").toString();
    QString typeStr = obj.value("type").toString();

    if(typeStr == "person") {
        _type = PersonType;
        _personEmail = obj.value("person").toObject().value("email").toString();
    } else {
        _type = BotType;
    }
}
