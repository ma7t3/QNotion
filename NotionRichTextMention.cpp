#include "NotionRichTextMention.h"

NotionRichTextMention::NotionRichTextMention(QObject *parent) :
    QObject(parent),
    _date(NotionDate(this)),
    _user(NotionUser(this)) {
}

NotionRichTextMention::NotionRichTextMention(QObject *parent, const QJsonObject &obj) :
    QObject(parent),
    _date(NotionDate(this)),
    _user(NotionUser(this)) {
    fromJson(obj);
}

void NotionRichTextMention::fromJson(const QJsonObject &obj) {
    QString typeStr = obj.value("type").toString();

    if(typeStr == "database") _type = DatabaseMention;
    if(typeStr == "date") _type = DateMention;
    if(typeStr == "link_preview") _type = LinkPreviewMention;
    if(typeStr == "page") _type = PageMention;
    if(typeStr == "template_mention") {
        QString subType = obj.value("template_mention").toObject().value("type").toString();
        if(subType == "template_mention_date") _type = TemplateDateMention;
        if(subType == "template_mention_user") _type = TemplateUserMention;
    }
    if(typeStr == "user") _type = UserMention;

    if(_type == DatabaseMention) _databaseId = obj.value("database").toObject().value("id").toString();
    if(_type == DateMention) _date = NotionDate(this, obj.value("date").toObject());
    if(_type == LinkPreviewMention) _linkPreviewUrl = obj.value("link_preview").toObject().value("url").toString();
    if(_type == PageMention) _pageId = obj.value("page").toObject().value("id").toString();

    // missing template mentions
}

NotionUser NotionRichTextMention::user() const {return _user;}
NotionRichTextMention::TemplateDate NotionRichTextMention::templateDate() const {return _templateDate;}
NotionDate NotionRichTextMention::date() const {return _date;}
QString NotionRichTextMention::pageId() const {return _pageId;}
QString NotionRichTextMention::linkPreviewUrl() const {return _linkPreviewUrl;}
QString NotionRichTextMention::databaseId() const {return _databaseId;}
NotionRichTextMention::Type NotionRichTextMention::type() const {return _type;}
