#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "notedialog.h"
#include "note.h"
#include <QVector>
#include "notes_repository.h"
#include <QListWidgetItem>
#include <QLocale>
#include <QMessageBox>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    void show_notes(QVector <Note*> vector_note);
    ~MainWindow();

private slots:
    void on_actionAdd_Note_triggered();

    void on_listWidget_currentItemChanged(QListWidgetItem *current, QListWidgetItem *previous);

    void on_actionEdit_Note_triggered();

    void on_actionRemove_Note_triggered();

    void on_actionExit_triggered();

    void on_comboBox_currentIndexChanged(int index);

private:
    Ui::MainWindow *ui;
    notes_repository note_rep;
    void fill_categories();
};
#endif // MAINWINDOW_H
