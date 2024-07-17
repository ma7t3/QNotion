#include "NotionRichText.h"

NotionRichText::NotionRichText(QObject *parent) : QObject{parent} {}

NotionRichText::NotionRichText(QObject *parent, const QJsonArray &arr) :
    QObject(parent){
    fromJson(arr);
}

NotionRichTextItem &NotionRichText::operator[](std::size_t index) {
    return items[index];
}

void NotionRichText::fromJson(const QJsonArray &arr) {
    for(int i = 0; i < arr.count(); i++) {
        items << NotionRichTextItem(this, arr[i].toObject());
    }
}
