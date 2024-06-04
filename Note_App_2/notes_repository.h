#ifndef NOTES_REPOSITORY_H
#define NOTES_REPOSITORY_H

#include <QVector>
#include "Note.h"
#include <QFile>
#include <QIODevice>
#include <QTextStream>
#include "category_repository.h"

class notes_repository
{
public:
    notes_repository();
    QVector <Note*> get_vector_notes();
    void add_note(Note* note);
    void save();
    void load_in_file();
    Note* find_current_note(QString name);
    void delete_note(QString name);
    QVector <Note*> note_category(QString category);
private:
    QVector <Note*> m_vector_notes;
};

#endif // NOTES_REPOSITORY_H
