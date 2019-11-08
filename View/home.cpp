#include "home.h"
#include "mwindow.h"
#include<QGroupBox>

Home::Home(QWidget *p):
    QWidget(p),
    btnTutti(new QPushButton("&Tutti",this)),
    btnCuffie(new QPushButton("&Cuffie",this)),
    btnMonitor(new QPushButton("&Monitor",this)),
    btnMouse(new QPushButton("&Mouse",this)),
    btnTastiera(new QPushButton("&Tastiera",this)),
    btnWebcam(new QPushButton("&Webcam",this))
{
    QLabel *intro = new QLabel(this);

    QVBoxLayout *layout = new QVBoxLayout();

    QIcon icon = QIcon (":/img/IMG/logo.png");
    QPixmap log = icon.pixmap(QSize(150, 150));
    intro->setPixmap(log);
    intro->setAlignment(Qt::AlignCenter);
    layout->addWidget(intro);

    QGroupBox *verticalGroupBox = new QGroupBox(tr("Scegli l'accessorio che cerchi"));

    QVBoxLayout *layoutmenu = new QVBoxLayout();

    btnTutti->setStyleSheet("background-color: white");
    btnTutti->resize(300, 100);
    layoutmenu->addWidget(btnTutti);

    QIcon c=QIcon(":/img/IMG/cuffie.png");
    btnCuffie->setIcon(c);
    btnCuffie->setStyleSheet("background-color: white");
    btnCuffie->resize(300, 100);
    btnCuffie->setIconSize(QSize(40,40));
    layoutmenu->addWidget(btnCuffie);

    QIcon mon=QIcon(":/img/IMG/monitor.png");
    btnMonitor->setIcon(mon);
    btnMonitor->setStyleSheet("background-color: white");
    btnMonitor->resize(300, 100);
    btnMonitor->setIconSize(QSize(40,40));
    layoutmenu->addWidget(btnMonitor);

    QIcon mou=QIcon(":/img/IMG/mouse.png");
    btnMouse->setIcon(mou);
    btnMouse->setStyleSheet("background-color: white");
    btnMouse->resize(300, 100);
    btnMouse->setIconSize(QSize(40,40));
    layoutmenu->addWidget(btnMouse);

    QIcon t=QIcon(":/img/IMG/tastiera.png");
    btnTastiera->setIcon(t);
    btnTastiera->setStyleSheet("background-color: white");
    btnTastiera->resize(300, 100);
    btnTastiera->setIconSize(QSize(40,40));
    layoutmenu->addWidget(btnTastiera);

    QIcon w=QIcon(":/img/IMG/webcam.png");
    btnWebcam->setIcon(w);
    btnWebcam->setStyleSheet("background-color: white");
    btnWebcam->resize(300, 100);
    btnWebcam->setIconSize(QSize(40,40));
    layoutmenu->addWidget(btnWebcam);

    verticalGroupBox->setLayout(layoutmenu);
    layout->addWidget(verticalGroupBox);

    setMinimumWidth(350);

    setLayout(layout);
}

QPushButton *Home::getBtnTutti() const
{
    return btnTutti;
}

QPushButton *Home::getBtnCuffie() const
{
    return btnCuffie;
}

QPushButton *Home::getBtnMonitor() const
{
    return btnMonitor;
}

QPushButton *Home::getBtnMouse() const
{
    return btnMouse;
}

QPushButton *Home::getBtnTastiera() const
{
    return btnTastiera;
}

QPushButton *Home::getBtnWebcam() const
{
    return btnWebcam;
}


