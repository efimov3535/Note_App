#ifndef NOTE_H
#define NOTE_H
#include "category.h"
#include <QDateTime>

class Note
{
private:
    QString m_name;
    QString m_description;
    category* m_category;
    QDateTime m_date_create;
    QDateTime m_date_modified;
public:
    Note(QString name, QString description, category* cat, QDateTime date_create, QDateTime date_modified);
    QString get_name();
    category* get_category();
    QDateTime get_date_create();
    QDateTime get_date_modified();
    QString get_description();
    void set_descreption(QString text);
    void set_title(QString name);
    void set_m_category(category* categoryy);
    void set_date_modified(QDateTime date_modified);
};

#endif // NOTE_H
