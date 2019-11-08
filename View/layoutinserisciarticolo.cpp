#include "layoutinserisciarticolo.h"
#include "mwindow.h"
#include <QGroupBox>
#include <QMessageBox>

LayoutInserisciArticolo::LayoutInserisciArticolo(QWidget* p):
    QWidget (p),
    tipoAccessorio(new CBType(this)),
    nomeAccessorio(new QLineEdit(this)),
    marcaAccessorio(new QLineEdit(this)),
    prezzoAccessorio(new QDoubleSpinBox(this)),
    meseAccessorio(new CBMonth(this)),
    annoAccessorio(new QLineEdit(this)),
    tipoInputAccessorio(new QLineEdit(this)),

    cuffie(new NewCuffieLayout(this)),
    monitor(new NewMonitorLayout(this)),
    mouse(new NewMouseLayout(this)),
    tastiera( new NewTastieraLayout(this)),
    webcam(new NewWebcamLayout(this)),

    aggiungi(new QPushButton("Conferma",this)),
    reset(new QPushButton("Reset",this)),
    annulla(new QPushButton("Annulla",this))

{
    QVBoxLayout *layoutInserisciArticolo = new QVBoxLayout();

    layoutInserisciArticolo->addWidget(tipoAccessorio);

    QGroupBox *generalDataGB = new QGroupBox(tr("Dati generali"));;

    QVBoxLayout *layoutGeneralData = new QVBoxLayout();

    nomeAccessorio->setPlaceholderText("Inserisci il nome");
    layoutGeneralData->addWidget(nomeAccessorio);

    marcaAccessorio->setPlaceholderText("Marca dell'accessorio");
    layoutGeneralData->addWidget(marcaAccessorio);

    prezzoAccessorio->setSuffix("€");
    prezzoAccessorio->setPrefix("Prezzo:    ");
    prezzoAccessorio->setMinimum(0.00);
    prezzoAccessorio->setMaximum(50000.00);
    layoutGeneralData->addWidget(prezzoAccessorio);

    QGridLayout *layoutdata = new QGridLayout;

    layoutdata->addWidget(meseAccessorio,0,0);
    layoutdata->setSpacing(60);
    QValidator* anno = new QIntValidator(2000, 2019, this);
    annoAccessorio->setValidator(anno);
    annoAccessorio->setPlaceholderText("Anno d'uscita (+2000)");
    layoutdata->addWidget(annoAccessorio,0,1);

    layoutGeneralData->addItem(layoutdata);

    tipoInputAccessorio->setPlaceholderText("Tipologia di Input dell'Accessorio");
    layoutGeneralData->addWidget(tipoInputAccessorio);

    generalDataGB->setLayout(layoutGeneralData);
    layoutInserisciArticolo->addWidget(generalDataGB);

    QGroupBox *DataArtGB = new QGroupBox(tr("Dati specifici"));;

    QVBoxLayout *layoutDataArt = new QVBoxLayout();

    layoutDataArt->addWidget(cuffie);
    layoutDataArt->addWidget(monitor);
    layoutDataArt->addWidget(mouse);
    layoutDataArt->addWidget(tastiera);
    layoutDataArt->addWidget(webcam);

    DataArtGB->setLayout(layoutDataArt);
    layoutInserisciArticolo->addWidget(DataArtGB);

    QGridLayout *layoutbutton = new QGridLayout;
    layoutbutton->setSpacing(10);
    layoutbutton->addWidget(annulla,0,0);
    layoutbutton->addWidget(reset,0,1);
    layoutbutton->addWidget(aggiungi,0,2);
    layoutInserisciArticolo->addItem(layoutbutton);

    setLayout(layoutInserisciArticolo);

    setMinimumWidth(350);

    slotAccessoriesLayout(0);

    connect(tipoAccessorio,SIGNAL(activated(int)),this,SLOT(slotAccessoriesLayout(int)));
}

//General Data
QComboBox *LayoutInserisciArticolo::getTipoAccessorio() const
{
    return tipoAccessorio;
}

QLineEdit *LayoutInserisciArticolo::getInserisciNome() const
{
    return nomeAccessorio;
}

QLineEdit *LayoutInserisciArticolo::getInserisciMarca() const
{
    return marcaAccessorio;
}

QDoubleSpinBox *LayoutInserisciArticolo::getInserisciPrezzo() const
{
    return prezzoAccessorio;
}

QComboBox *LayoutInserisciArticolo::getInserisciMese() const
{
    return meseAccessorio;
}

QLineEdit *LayoutInserisciArticolo::getInserisciAnno() const
{
    return annoAccessorio;
}

QLineEdit *LayoutInserisciArticolo::getInserisciTipoInput() const
{
    return tipoInputAccessorio;
}

//Cuffie data
NewCuffieLayout *LayoutInserisciArticolo::getCuffie() const
{
    return cuffie;
}

//Monitor data
NewMonitorLayout *LayoutInserisciArticolo::getMonitor() const
{
    return monitor;
}

//Mouse data
NewMouseLayout *LayoutInserisciArticolo::getMouse() const
{
    return mouse;
}

//Tastiera data
NewTastieraLayout *LayoutInserisciArticolo::getTastiera() const
{
    return tastiera;
}

//Webcam data
NewWebcamLayout *LayoutInserisciArticolo::getWebcam() const
{
    return webcam;
}

//Messaggio d'errore
void LayoutInserisciArticolo::showWarning(QWidget *p, QString e) const
{
    QString str= "Devi correggere il campo: ";
    str.append(e);
    QMessageBox::warning(p,"Attenzione",str);
}


//Show AccessorioTipo input
void LayoutInserisciArticolo::slotAccessoriesLayout(int index) const
{
    switch (index) {
    case 1:
        cuffie->show();
        monitor->hide();
        mouse->hide();
        tastiera->hide();
        webcam->hide();
        break;
    case 2:
        cuffie->hide();
        monitor->show();
        mouse->hide();
        tastiera->hide();
        webcam->hide();
        break;
    case 3:
        cuffie->hide();
        monitor->hide();
        mouse->show();
        tastiera->hide();
        webcam->hide();
        break;
    case 4:
        cuffie->hide();
        monitor->hide();
        mouse->hide();
        tastiera->show();
        webcam->hide();
        break;
    case 5:
        cuffie->hide();
        monitor->hide();
        mouse->hide();
        tastiera->hide();
        webcam->show();
        break;
    case 0:
        cuffie->hide();
        monitor->hide();
        mouse->hide();
        tastiera->hide();
        webcam->hide();
        break;
    }
}

//bottoni
QPushButton *LayoutInserisciArticolo::getBAnnButton() const
{
    return annulla;
}
QPushButton *LayoutInserisciArticolo::getBAggButton() const
{
    return aggiungi;
}

QPushButton *LayoutInserisciArticolo::getBResButton() const
{
    return reset;
}

//Slot Annulla
void LayoutInserisciArticolo::slotReset() const
{
    tipoAccessorio->setCurrentIndex(0);
    nomeAccessorio->setText("");
    marcaAccessorio->setText("");
    prezzoAccessorio->setValue(0.00);
    meseAccessorio->setCurrentIndex(0);
    annoAccessorio->setText("");
    tipoInputAccessorio->setText("");

    //metodi per azzerare
    cuffie->slotResetCuffie();
    monitor->slotResetMonitor();
    mouse->slotResetMouse();
    tastiera->slotResetTastiera();
    webcam->slotResetWebcam();

    slotAccessoriesLayout(0);
}




