#include "server.h"
#include <QApplication>
#include "client.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    server w;
    w.show();
    client clie;
    clie.show();

    return a.exec();
}
