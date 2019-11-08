#include <QApplication>
#include "View/mwindow.h"
#include "model.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MWindow w(new Model());
    w.show();
    w.setWindowTitle("PC Accessory");
    a.setWindowIcon(QIcon(":/img/IMG/logoparziale.png"));
    w.show();

    return a.exec();
}
