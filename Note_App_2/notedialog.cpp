#include "notedialog.h"
#include "ui_notedialog.h"
#include <QDateTime>

NoteDialog::NoteDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::NoteDialog)
{
    ui->setupUi(this);
    m_note = nullptr;
    fill_category();

}

NoteDialog::~NoteDialog()
{
    delete ui;
}

Note* NoteDialog::get_note()
{
    return m_note;
}

void NoteDialog::on_buttonBox_accepted()
{
    QString title = ui->line_title->text();
    QString categoryy = ui->combo_box_categories->currentText();
    QString text = ui->textEdit_description->toPlainText();
    QDateTime date_created = QDateTime::currentDateTime();
    category* cat = nullptr;
    for(auto d : m_categories)
    {
        if(d->get_name() == categoryy)
            cat = d;
    }
    if(m_note == nullptr)
    {
        m_note = new Note(title, text, cat, date_created, date_created);
    }
    else
    {
        m_note->set_descreption(text);
        m_note->set_title(title);
        m_note->set_m_category(cat);
        m_note->set_date_modified(date_created);
    }
}

void NoteDialog::fill_category()
{
    category_repository m_cat_rep;
    m_categories = m_cat_rep.get_categories();
    for(int i = 0; i < m_categories.size(); i++)
    {
        ui->combo_box_categories->addItem(m_categories[i]->get_name());
    }

}

void NoteDialog::set_note(Note *note)
{
    m_note = note;
    ui->line_title->setText(m_note->get_name());
    ui->combo_box_categories->setCurrentText(m_note->get_category()->get_name());
    ui->line_created->setText(m_note->get_date_create().toString());
    ui->line_modified->setText(m_note->get_date_modified().toString());
    ui->textEdit_description->setText(m_note->get_description());
}
