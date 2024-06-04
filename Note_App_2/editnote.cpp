#include "editnote.h"

editnote::editnote(QString name, notes_repository* note_rep, QObject *parent)
    : QAbstractItemModel(parent)
{
    QVector <Note* > vector_notes;
    vector_notes = note_rep->get_vector_notes();
    for(auto d : vector_notes)
    {
        if(name == d->get_name())
        {

        }
    }
}

editnote::~editnote()
{
    delete ui;
}

editnote *editnote::get_note()
{
    return m_note;
}

void editnote::fill_category()
{

}

void editnote::show()
{

}

