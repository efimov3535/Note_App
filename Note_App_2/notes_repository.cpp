#include "notes_repository.h"

notes_repository::notes_repository()
{
    load_in_file();
}

QVector<Note *> notes_repository::get_vector_notes()
{
    return m_vector_notes;
}


void notes_repository::add_note(Note* note)
{
    m_vector_notes.push_back(note);
}

void notes_repository::save()
{
    QFile file("notes.txt");
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
        return;
    QTextStream in(&file);
    for(auto d : m_vector_notes)
    {
        in << d->get_name() << ";" << d->get_category()->get_name() << ";" <<
            d->get_date_create().toString() << ";" << d->get_date_modified().toString() << ";" << d->get_description() << "\n";
    }
    file.close();
}

void notes_repository::load_in_file()
{
    QFile file("notes.txt");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        return;
    QTextStream in(&file);
    category_repository cat_rep;
    while (!in.atEnd())
    {
        QString line = in.readLine();
        QStringList str_list = line.split(";");
        QString name = str_list[0];
        QString cat = str_list[1];
        QDateTime date_create = QDateTime::fromString(str_list[2]);
        QDateTime data_modified = QDateTime::fromString(str_list[3]);
        QString description = str_list[4];
        category* new_cat =  cat_rep.find_category(cat);
        Note* new_note = new Note(name, description, new_cat, date_create, data_modified);
        m_vector_notes.push_back(new_note);
    }
    file.close();
}

Note *notes_repository::find_current_note(QString name)
{
    for(auto d : m_vector_notes)
    {
        if(d->get_name() == name)
        {
            return d;
        }
    }
}

void notes_repository::delete_note(QString name)
{
    auto isEven = [name](Note* p) { return p->get_name() == name; };
    m_vector_notes.removeIf(isEven);
}

QVector<Note *> notes_repository::note_category(QString category)
{
    QVector <Note*> new_vector_notes;
    if(category == "Все")
        return m_vector_notes;


    for(auto d : m_vector_notes)
    {
        if(d->get_category()->get_name() == category)
            new_vector_notes.push_back(d);
    }
    return new_vector_notes;
}
