#ifndef NOTIONUSER_H
#define NOTIONUSER_H

#include <QObject>

#include <QJsonObject>

class NotionUser : public QObject {
    Q_OBJECT
public:
    enum Type {
        PersonType,
        BotType
    };

    enum BotOwnerType {
        WorkspaceOwnerType,
        UserOwnerType
    };

    explicit NotionUser(QObject *parent);
    explicit NotionUser(QObject *parent, const QJsonObject &);
    NotionUser(const NotionUser &other);

    QString id() const;
    Type type() const;
    QString name() const;
    QString avatarUrl() const;
    QString personEmail() const;

protected:
    void fromJson(const QJsonObject &);

private:
    QString _id;
    Type _type;
    QString _name, _avatarUrl;
    QString _personEmail;

signals:
};

#endif // NOTIONUSER_H
