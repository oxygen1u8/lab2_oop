#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tableView->setEnabled(0);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    QString text = ui->plainTextEdit->toPlainText();
    filename = text.toStdString();
    if(!isFileExist(filename)) createMessageBox("Error! This file doesn't exist!");
    else
    {
        lessonlist.clear();
        getInfoFromFile(filename, lessonlist);
        model = new QStandardItemModel(lessonlist.size(), 4, this);
        ui->tableView->setEnabled(1);
        ui->tableView->setModel(model);
        showTable(model, lessonlist);
    }
    ui->plainTextEdit->clear();
}

inline std::string MainWindow::getFileName()
{
    return this->filename;
}

void MainWindow::createMessageBox(std::string message)
{
    QString msg = QString(QLatin1String(message.c_str()));
    QMessageBox::information(this, "Message", msg);
}

void MainWindow::on_plainTextEdit_textChanged()
{
    std::string text = ui->plainTextEdit->toPlainText().toStdString();
    if(text[text.size() - 1] == '\n') on_pushButton_clicked();
}

void MainWindow::on_pushButton_2_clicked()
{
    std::sort(lessonlist.begin(), lessonlist.end(), [](Lesson& l1 , Lesson& l2){return l1.getClassroom()<l2.getClassroom();});
    showTable(model, lessonlist);
}

void MainWindow::showTable(QStandardItemModel* model, vector<Lesson>& lessonlist)
{
    QModelIndex index;
    for(int i = 0; i < model->rowCount(); i++)
    {
        for(int j = 0; j < model->columnCount(); j++)
        {
            index = model->index(i, j);
            switch(j)
            {
            case 0:
                model->setData(index, lessonlist[i].getId());
            break;
            case 1:
                model->setData(index, lessonlist[i].getTitle().c_str());
            break;
            case 2:
                switch(lessonlist[i].getType())
                {
                case EMPLOYMENT::TYPE_NOTHING:
                    model->setData(index, "Nothing");
                break;
                case EMPLOYMENT::TYPE_PRACTICE:
                    model->setData(index, "Practice");
                break;
                case EMPLOYMENT::TYPE_LAB:
                    model->setData(index, "Lab");
                break;
                case EMPLOYMENT::TYPE_EXAM:
                    model->setData(index, "Exam");
                break;
                case EMPLOYMENT::TYPE_LECTION:
                    model->setData(index, "Lection");
                break;
                }
            break;
            case 3:
                model->setData(index, lessonlist[i].getClassroom());
            break;
            }
        }
    }
}

void MainWindow::on_pushButton_3_clicked()
{
    writeFile(filename, lessonlist);
}
