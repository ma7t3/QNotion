#ifndef NOTIONRICHTEXTITEM_H
#define NOTIONRICHTEXTITEM_H

#include <QObject>

#include <QJsonObject>

class NotionRichTextItem : public QObject {
    Q_OBJECT
public:
    enum Type {
        TextType,
        EquationType,
        MentionType
    };

    enum Color {
        DefaultColor,
        BlueColor,
        BlueBackgroundColor,
        BrownColor,
        brownBackgroundColor,
        GrayColor,
        GrayBackgroundColor,
        GreenColor,
        GreenBackgroundColor,
        OrangeColor,
        OrangeBackgroundColor,
        PinkColor,
        PinkBackgroundColor,
        PurpleColor,
        PurbleBackgroundColor,
        RedColor,
        RedBackgroundColor,
        YellowColor,
        YellowBackgroundColor
    };

    explicit NotionRichTextItem(QObject *parent);
    explicit NotionRichTextItem(QObject *parent, const QJsonObject &);
    NotionRichTextItem(const NotionRichTextItem &other);
    NotionRichTextItem operator=(const NotionRichTextItem &other);

    Type type() const;

    QString textContent() const;
    void setTextContent(const QString &newTextContent);

    QString textLink() const;
    bool hasTextLink() const;
    void setTextLink(const QString &newTextLink);

    QString equationExpression() const;
    void setEquationExpression(const QString &newEquationExpression);

    bool bold() const;
    void setBold(bool newBold);

    bool italic() const;
    void setItalic(bool newItalic);

    bool strikethrough() const;
    void setStrikethrough(bool newStrikethrough);

    bool underline() const;
    void setUnderline(bool newUnderline);

    bool code() const;
    void setCode(bool newCode);

    Color color() const;
    void setColor(Color newColor);

    QString plainText() const;

    QString href() const;
    bool hasHref() const;

protected:
    void fromJson(const QJsonObject &);

private:
    Type _type;

    QString _textContent, _textLink;
    QString _equationExpression;

    bool _bold, _italic, _strikethrough, _underline, _code;
    Color _color;
    QString _plainText;
    QString _href;
    bool _hasHref;

signals:
};

#endif // NOTIONRICHTEXTITEM_H
