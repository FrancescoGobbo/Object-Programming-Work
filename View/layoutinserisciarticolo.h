#ifndef LAYOUTINSERISCIARTICOLO_H
#define LAYOUTINSERISCIARTICOLO_H

#include <QComboBox>
#include <QLineEdit>
#include <QDoubleSpinBox>
#include <QPushButton>

#include "AccessoriData/QComboBoxNewAccessori/cbtype.h"
#include "AccessoriData/QComboBoxNewAccessori/cbmonth.h"

#include"AccessoriData/newcuffielayout.h"
#include"AccessoriData/newmonitorlayout.h"
#include"AccessoriData/newmouselayout.h"
#include"AccessoriData/newtastieralayout.h"
#include"AccessoriData/newwebcamlayout.h"

using std::string;

class LayoutInserisciArticolo : public QWidget
{
  Q_OBJECT
 private:
        CBType *tipoAccessorio;

        //general data
        QLineEdit* nomeAccessorio;
        QLineEdit* marcaAccessorio;
        QDoubleSpinBox* prezzoAccessorio;
        CBMonth* meseAccessorio;
        QLineEdit* annoAccessorio;
        QLineEdit* tipoInputAccessorio;

        //data Accessories
        NewCuffieLayout* cuffie;
        NewMonitorLayout* monitor;
        NewMouseLayout* mouse;
        NewTastieraLayout* tastiera;
        NewWebcamLayout* webcam;

        //buttons
        QPushButton* aggiungi;
        QPushButton* reset;
        QPushButton* annulla;

public:
    LayoutInserisciArticolo(QWidget * =nullptr);

    //General Data
    QComboBox* getTipoAccessorio()const;

    QLineEdit* getInserisciNome()const;
    QLineEdit* getInserisciMarca()const;
    QDoubleSpinBox* getInserisciPrezzo()const;
    QComboBox* getInserisciMese()const;
    QLineEdit* getInserisciAnno()const;
    QLineEdit* getInserisciTipoInput()const;

    //Cuffie data
    NewCuffieLayout* getCuffie() const;

    //Monitor data
    NewMonitorLayout* getMonitor() const;

    //Mouse data
    NewMouseLayout* getMouse() const;

    //Tastiera data
    NewTastieraLayout* getTastiera() const;

    //Webcam data
    NewWebcamLayout* getWebcam() const;

    void showWarning(QWidget* = nullptr, QString ="") const;

    QPushButton *getBAggButton()const;
    QPushButton *getBResButton()const;
    QPushButton *getBAnnButton()const;

public slots:
    void slotAccessoriesLayout(int) const;
    void slotReset()const;

};

#endif // LAYOUTINSERISCIARTICOLO_H
