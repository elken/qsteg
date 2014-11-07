#include "qsteg.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QSteg w;
    w.show();

    return a.exec();
}
