#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QStandardItemModel>
#include <string>
#include <QMainWindow>
#include <QStandardItemModel>
#include "lesson.h"
#include "foo.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    void createMessageBox(std::string message);
    inline std::string getFileName();
    ~MainWindow();

private slots:
    void on_pushButton_clicked();
    void on_plainTextEdit_textChanged();
    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    void showTable(QStandardItemModel* model, vector<Lesson>& lessonlist);
    Ui::MainWindow *ui;
    std::string filename;
    vector<Lesson> lessonlist;
    QStandardItemModel *model;
};
#endif // MAINWINDOW_H
