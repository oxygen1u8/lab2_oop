#include "mainwindow.h"
#include <QApplication>


using namespace std;

bool isFileExist(const string& filename);
vector<string> splitString(string& str, char sym);

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}

