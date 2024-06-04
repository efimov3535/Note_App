#ifndef NOTEDIALOG_H
#define NOTEDIALOG_H

#include <QDialog>
#include "note.h"
#include "category_repository.h"
#include <QDateTime>

namespace Ui {
class NoteDialog;
}

class NoteDialog : public QDialog
{
    Q_OBJECT

public:
    explicit NoteDialog(QWidget *parent = nullptr);
    ~NoteDialog();
    Note* get_note();
    void fill_category();
    void set_note(Note* note);


private slots:
    void on_buttonBox_accepted();

private:
    Ui::NoteDialog *ui;
    Note* m_note;
    QVector <category*> m_categories;
};

#endif // NOTEDIALOG_H
