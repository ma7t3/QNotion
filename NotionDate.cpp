#include "NotionDate.h"

NotionDate::NotionDate(QObject *parent) : QObject{parent} {}

NotionDate::NotionDate(QObject *parent, const QJsonObject &obj) :
    QObject(parent){
    fromJson(obj);
}

NotionDate::NotionDate(const NotionDate &other) : QObject(other.parent()) {
    _start = other.startDateTime();
    _end = other.endDateTime();
    _hasTime = other.hasTime();
    _hasEnd = other.hasEnd();
}

NotionDate NotionDate::operator=(const NotionDate &other) {
    _start = other.startDateTime();
    _end = other.endDateTime();
    _hasTime = other.hasTime();
    _hasEnd = other.hasEnd();
    return *this;
}

bool NotionDate::hasEnd() const {return _hasEnd;}
bool NotionDate::hasTime() const {return _hasTime;}

QDateTime NotionDate::startDateTime() const {
    return _start;
}

void NotionDate::setStartDateTime(const QDateTime &newStartDateTime) {
    _start = newStartDateTime;
    _hasTime = true;
}

QDate NotionDate::startDate() const {
    return _start.date();
}

void NotionDate::setStartDate(const QDate &newStartDate) {
    _start = QDateTime(newStartDate, QTime(0, 0, 0, 0));
    _hasTime = false;
}

QDateTime NotionDate::endDateTime() const {
    return _end;
}

void NotionDate::setEndDateTime(const QDateTime &newEndDateTime) {
    _end = newEndDateTime;
    _hasTime = true;
    _hasEnd = true;
}

QDate NotionDate::endDate() const {
    return _hasEnd ? _end.date() : QDate();
}

void NotionDate::setEndDate(const QDate &newEndDate) {
    _end = QDateTime(newEndDate, QTime(0, 0, 0, 0));
    _hasTime = false;
    _hasEnd = true;
}

void NotionDate::removeEnd() {
    _end = QDateTime();
    _hasEnd = false;
}

void NotionDate::removeTime() {
    _start = QDateTime(_start.date(), QTime(0, 0, 0, 0));
    if(_hasEnd)
        _end = QDateTime(_end.date(), QTime(0, 0, 0, 0));

    _hasTime = false;
}

void NotionDate::fromJson(const QJsonObject &obj) {
    QString startStr = obj.value("start").toString();
    QString endStr = obj.value("end").toString();
    _hasTime = startStr.length() > 10;

    if(_hasTime)
        _start = QDateTime::fromString(startStr, "yyyy-MM-dd'T'HH:mm:ss.zzzttt");
    else
        _start = QDateTime(QDate::fromString(startStr, "yyyy-MM-dd"), QTime(0, 0, 0, 0));

    if(obj.value("end").isNull()) {
        _hasEnd = false;
    } else {
        _hasEnd = true;
        if(_hasTime)
            _end = QDateTime::fromString(endStr, "yyyy-MM-dd'T'HH:mm:ss.zzzttt");
        else
            _end = QDateTime(QDate::fromString(endStr, "yyyy-MM-dd"), QTime(0, 0, 0, 0));
    }
}
