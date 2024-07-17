#ifndef NOTIONPARENT_H
#define NOTIONPARENT_H

#include <QObject>

#include <QJsonObject>

class NotionParent : public QObject {
    Q_OBJECT
public:
    enum ParentType {
        DatabaseParent,
        PageParent,
        WorkspaceParent,
        BlockParent
    };

    explicit NotionParent(QObject *parent);
    explicit NotionParent(QObject *parent, const QJsonObject &);

    NotionParent(const NotionParent &other);

    ParentType type() const;
    QString id() const;

protected:
    void fromJson(const QJsonObject &);

signals:

private:
    ParentType _type;
    QString _id;
};

#endif // NOTIONPARENT_H
