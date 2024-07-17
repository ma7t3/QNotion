#ifndef NOTIONRICHTEXTMENTION_H
#define NOTIONRICHTEXTMENTION_H

#include "NotionDate.h"
#include "NotionUser.h"

#include <QObject>

#include <QDate>

class NotionRichTextMention : public QObject {
    Q_OBJECT
public:
    enum Type {
        DatabaseMention,
        DateMention,
        LinkPreviewMention,
        PageMention,
        TemplateUserMention,
        TemplateDateMention,
        UserMention
    };

    enum TemplateDate {
        Today,
        Now
    };

    explicit NotionRichTextMention(QObject *parent);
    explicit NotionRichTextMention(QObject *parent, const QJsonObject &);

    Type type() const;
    QString databaseId() const;
    QString linkPreviewUrl() const;
    QString pageId() const;
    NotionDate date() const;
    TemplateDate templateDate() const;
    NotionUser user() const;

protected:
    void fromJson(const QJsonObject &);

private:
    Type _type;
    QString _databaseId, _linkPreviewUrl, _pageId;
    NotionDate _date;
    TemplateDate _templateDate;
    NotionUser _user;

signals:
};

#endif // NOTIONRICHTEXTMENTION_H
