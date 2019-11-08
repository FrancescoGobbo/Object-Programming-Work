#ifndef HOME_H
#define HOME_H

#include <QPushButton>
#include <QVBoxLayout>
#include<QScrollBar>
#include<QLabel>

class Home: public QWidget
{
    Q_OBJECT
private:
    QPushButton *btnTutti;
    QPushButton *btnCuffie;
    QPushButton *btnMonitor;
    QPushButton *btnMouse;
    QPushButton *btnTastiera;
    QPushButton *btnWebcam;
    QWidget* parent;
public:
    Home(QWidget * =nullptr);

    QPushButton* getBtnTutti() const;
    QPushButton* getBtnCuffie() const;
    QPushButton* getBtnMonitor() const;
    QPushButton* getBtnMouse() const;
    QPushButton* getBtnTastiera() const;
    QPushButton* getBtnWebcam() const;
};

#endif // HOME_H
