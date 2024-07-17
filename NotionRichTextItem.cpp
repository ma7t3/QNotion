#include "NotionRichTextItem.h"

NotionRichTextItem::NotionRichTextItem(QObject *parent) : QObject{parent} {}

NotionRichTextItem::NotionRichTextItem(QObject *parent, const QJsonObject &obj) :
    QObject(parent){
    fromJson(obj);
}

NotionRichTextItem::NotionRichTextItem(const NotionRichTextItem &other) : QObject(other.parent()) {
    _type = other.type();
    _textContent = other.textContent();
    _textLink = other.textLink();
    _bold = other.bold();
    _italic = other.italic();
    _strikethrough = other.strikethrough();
    _underline = other.underline();
    _code = other.code();
    _color = other.color();
    _plainText = other.plainText();
    _href = other.href();
    _hasHref = other.hasHref();
}

NotionRichTextItem NotionRichTextItem::operator=(const NotionRichTextItem &other) {
    _type = other.type();
    _textContent = other.textContent();
    _textLink = other.textLink();
    _bold = other.bold();
    _italic = other.italic();
    _strikethrough = other.strikethrough();
    _underline = other.underline();
    _code = other.code();
    _color = other.color();
    _plainText = other.plainText();
    _href = other.href();
    _hasHref = other.hasHref();
    return *this;
}

void NotionRichTextItem::fromJson(const QJsonObject &obj) {
    QString type = obj.value("type").toString();

    if(type == "text")     _type = TextType;
    if(type == "mention")  _type = MentionType;
    if(type == "equation") _type = EquationType;

    if(_type == TextType) {
        _textContent = obj.value("text").toObject().value("content").toString();
        _textLink = obj.value("text").toObject().value("link").toString();
    }

    if(_type == EquationType) {
        _equationExpression = obj.value("equation").toObject().value("expression").toString();
    }

    if(_type == MentionType) {
        // implement mentions
    }

    QJsonObject annotations = obj.value("annotations").toObject();
    _bold           = annotations.value("bold").toBool();
    _italic         = annotations.value("italic").toBool();
    _strikethrough  = annotations.value("strikethrough").toBool();
    _underline      = annotations.value("underline").toBool();
    _code           = annotations.value("code").toBool();

    QString colorName = annotations.value("color").toString();

    if(colorName == "default")           _color = DefaultColor;
    if(colorName == "blue")              _color = BlueColor;
    if(colorName == "blue_background")   _color = BlueBackgroundColor;
    if(colorName == "brown")             _color = BrownColor;
    if(colorName == "brown_background")  _color = brownBackgroundColor;
    if(colorName == "gray")              _color = GrayColor;
    if(colorName == "gray_background")   _color = GrayBackgroundColor;
    if(colorName == "green")             _color = GreenColor;
    if(colorName == "green_background")  _color = GreenBackgroundColor;
    if(colorName == "orange")            _color = OrangeColor;
    if(colorName == "orange_background") _color = OrangeBackgroundColor;
    if(colorName == "pink")              _color = PinkColor;
    if(colorName == "pink_background")   _color = PinkBackgroundColor;
    if(colorName == "purple")            _color = PurpleColor;
    if(colorName == "purple_background") _color = PurbleBackgroundColor;
    if(colorName == "red")               _color = RedColor;
    if(colorName == "red_background")    _color = RedBackgroundColor;
    if(colorName == "yellow")            _color = YellowColor;
    if(colorName == "yellow_background") _color = YellowBackgroundColor;

    _plainText = obj.value("plain_text").toString();

    if(obj.value("href").isString()) {
        _href = obj.value("href").toString();
        _hasHref = true;
    } else {
        _hasHref = false;
    }
}

QString NotionRichTextItem::equationExpression() const {return _equationExpression;}
void NotionRichTextItem::setEquationExpression(const QString &newEquationExpression) {_equationExpression = newEquationExpression;}

QString NotionRichTextItem::textLink() const {return _textLink;}
bool NotionRichTextItem::hasTextLink() const {return _textLink.isEmpty();}
void NotionRichTextItem::setTextLink(const QString &newTextLink) {_textLink = newTextLink;}

QString NotionRichTextItem::textContent() const {return _textContent;}
void NotionRichTextItem::setTextContent(const QString &newTextContent) {_textContent = newTextContent;}

NotionRichTextItem::Type NotionRichTextItem::type() const {return _type;}

bool NotionRichTextItem::bold() const {return _bold;}
void NotionRichTextItem::setBold(bool newBold) {_bold = newBold;}

bool NotionRichTextItem::italic() const {return _italic;}
void NotionRichTextItem::setItalic(bool newItalic) {_italic = newItalic;}

bool NotionRichTextItem::strikethrough() const {return _strikethrough;}
void NotionRichTextItem::setStrikethrough(bool newStrikethrough) {_strikethrough = newStrikethrough;}

bool NotionRichTextItem::underline() const {return _underline;}
void NotionRichTextItem::setUnderline(bool newUnderline) {_underline = newUnderline;}

bool NotionRichTextItem::code() const {return _code;}
void NotionRichTextItem::setCode(bool newCode) {_code = newCode;}

NotionRichTextItem::Color NotionRichTextItem::color() const {return _color;}
void NotionRichTextItem::setColor(Color newColor) {_color = newColor;}

QString NotionRichTextItem::plainText() const {return _plainText;}

QString NotionRichTextItem::href() const {return _href;}
bool NotionRichTextItem::hasHref() const {return _hasHref;}
