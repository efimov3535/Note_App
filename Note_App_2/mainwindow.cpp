#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    fill_categories();
    show_notes(note_rep.get_vector_notes());
}

void MainWindow::show_notes(QVector <Note*> vector_note)
{
    ui->listWidget->clear();
    for(auto d: vector_note)
    {
        ui->listWidget->addItem(d->get_name());
    }
}



MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionAdd_Note_triggered()
{
    NoteDialog note_dialog;
    if(note_dialog.exec() == 1)
    {
        Note* note = note_dialog.get_note();
        note_rep.add_note(note);
        note_rep.save();
        show_notes(note_rep.get_vector_notes());
    }

}

void MainWindow::fill_categories()
{
    category_repository* cat_rep = new category_repository();
    QVector <category*> vect_cat = cat_rep->get_categories();
    ui->comboBox->addItem("Все");
    for(int i = 0; i < vect_cat.size(); i++)
    {
        ui->comboBox->addItem(vect_cat[i]->get_name());
    }
}


void MainWindow::on_listWidget_currentItemChanged(QListWidgetItem *current, QListWidgetItem *previous)
{
    if(current == nullptr)
        return;
    QString name_note_app;
    name_note_app = current->text();
    for(auto d : note_rep.get_vector_notes())
    {
        if(d->get_name() == name_note_app)
        {
            ui->label_categ->setText(d->get_category()->get_name());
            ui->label_2->setText(name_note_app);
            QLocale locale(QLocale::English);
            QString new_date_create = locale.toString(d->get_date_create(), "dd MMM yyyy");
            ui->lineEdit->setText(new_date_create);
            QString new_date_modified = locale.toString(d->get_date_modified(), "dd MMM yyyy");
            ui->lineEdit_2->setText(new_date_modified);
            ui->textEdit->setText(d->get_description());
        }
    }
}


void MainWindow::on_actionEdit_Note_triggered()
{
    if(ui->listWidget->selectedItems().size() > 0)
    {
        QListWidgetItem* currentItem = ui->listWidget->currentItem();
        QString name_note_app;
        name_note_app = currentItem->text();
        Note* my_note = note_rep.find_current_note(name_note_app);

        NoteDialog note_dialog;
        note_dialog.set_note(my_note);
        if(note_dialog.exec() == 1)
        {
            note_rep.save();
            show_notes(note_rep.get_vector_notes());
        }
    }
}


void MainWindow::on_actionRemove_Note_triggered()
{
    if(ui->listWidget->selectedItems().size() > 0)
    {
        QMessageBox::StandardButton reply;
        reply = QMessageBox::question(this, "Удаление", "Точно хотите удалить?", QMessageBox::Yes|QMessageBox::No);
        if(reply == QMessageBox::Yes)
        {
            if(note_rep.get_vector_notes().size() >= 0)
            {
                QListWidgetItem* currentItem = ui->listWidget->currentItem();
                QString name_note_app;
                name_note_app = currentItem->text();
                note_rep.delete_note(name_note_app);
                note_rep.save();
                show_notes(note_rep.get_vector_notes());
            }
        }
    }
}


void MainWindow::on_actionExit_triggered()
{
    close();
}


void MainWindow::on_comboBox_currentIndexChanged(int index)
{
    QString current_cat = ui->comboBox->currentText();
    QVector <Note*> new_vector_notes = note_rep.note_category(current_cat);
    show_notes(new_vector_notes);
}

