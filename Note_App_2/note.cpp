#include "note.h"

Note::Note(QString name, QString description, category* cat, QDateTime date_create, QDateTime date_modified)
{
    m_name = name;
    m_description = description;
    m_category = cat;
    m_date_create = date_create;
    m_date_modified = date_modified;
}

QString Note::get_name()
{
    return m_name;
}

category *Note::get_category()
{
    return m_category;
}

QDateTime Note::get_date_create()
{
    return m_date_create;
}

QDateTime Note::get_date_modified()
{
    return m_date_modified;
}

QString Note::get_description()
{
    return m_description;
}

void Note::set_descreption(QString text)
{
    m_description = text;
}

void Note::set_title(QString name)
{
    m_name = name;
}

void Note::set_m_category(category *categoryy)
{
    m_category = categoryy;
}

void Note::set_date_modified(QDateTime date_modified)
{
    m_date_modified = date_modified;
}
