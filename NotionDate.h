#ifndef NOTIONDATE_H
#define NOTIONDATE_H

#include <QObject>

#include <QDateTime>
#include <QJsonObject>

class NotionDate : public QObject {
    Q_OBJECT
public:
    explicit NotionDate(QObject *parent);

    explicit NotionDate(QObject *parent, const QJsonObject &);
    NotionDate(const NotionDate &other);
    NotionDate operator=(const NotionDate &other);

    bool hasEnd() const;

    bool hasTime() const;

    QDateTime startDateTime() const;
    void setStartDateTime(const QDateTime &newStartDateTime);

    QDate startDate() const;
    void setStartDate(const QDate &newStartDate);

    QDateTime endDateTime() const;
    void setEndDateTime(const QDateTime &newStartDateTime);

    QDate endDate() const;
    void setEndDate(const QDate &newStartDate);

    void removeEnd();
    void removeTime();

protected:
    void fromJson(const QJsonObject &);

private:
    bool _hasEnd, _hasTime;
    QDateTime _start, _end;

signals:
};

#endif // NOTIONDATE_H
