#ifndef NOTIONBLOCK_H
#define NOTIONBLOCK_H

#include <QObject>

#include <QDateTime>
#include <QJsonObject>

#include "NotionParent.h"

class NotionBlock : public QObject {
    Q_OBJECT
public:
    enum BlockType {
        BookmarkType,
        BreadcrumbType,
        BulletedListItemType,
        CalloutType,
        ChildDatabaseType,
        ChildPageType,
        CodeType,
        ColumnListType,
        ColumnType,
        DividerType,
        EmbedType,
        EquationType,
        FileType,
        Heading1Type,
        Heading2Type,
        Heading3Type,
        ImageType,
        LinkPreviewType,
        MentionType,
        NumberedListItemType,
        ParagraphType,
        PdfType,
        QuoteType,
        SyncedBlockType,
        TableType,
        TableOfContentsType,
        ToDoType,
        ToogleBlockType,
        VideoType
    };

    explicit NotionBlock(QObject *parent);
    explicit NotionBlock(QObject *parent, const QJsonObject &);

    QString id() const;
    NotionParent blockParent() const;
    QDateTime createdTime() const;
    QDateTime lastEditedTime() const;
    QString creatdBy() const;
    QString lastEditedBy() const;;
    bool inTrash() const;
    BlockType type() const;

protected:
    void fromJson(const QJsonObject &);

private:
    QString _id;
    NotionParent _parent;
    QDateTime _createdTime, _lastEditedTime;
    QString _creatdBy, _lastEditedBy;
    bool _inTrash;
    BlockType _type;

    bool _isValid;

signals:
};

#endif // NOTIONBLOCK_H
