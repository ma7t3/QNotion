#ifndef NOTIONRICHTEXT_H
#define NOTIONRICHTEXT_H

#include "NotionRichTextItem.h"

#include <QObject>

#include <QJsonArray>
#include <QJsonObject>

class NotionRichText : public QObject {
    Q_OBJECT
public:
    explicit NotionRichText(QObject *parent);
    explicit NotionRichText(QObject *parent, const QJsonArray &);

    NotionRichTextItem &operator[](std::size_t index);

protected:
    void fromJson(const QJsonArray &);

private:
    QList<NotionRichTextItem> items;

signals:
};

#endif // NOTIONRICHTEXT_H
