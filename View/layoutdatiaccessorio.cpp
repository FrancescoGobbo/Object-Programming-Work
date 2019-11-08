#include "layoutdatiaccessorio.h"
#include <QGroupBox>
#include <QMessageBox>

#include <string>

#include<Contenitore/AccessoriPc/accessori.h>
#include<Contenitore/AccessoriPc/cuffie.h>
#include<Contenitore/AccessoriPc/monitor.h>
#include<Contenitore/AccessoriPc/mouse.h>
#include<Contenitore/AccessoriPc/tastiera.h>
#include<Contenitore/AccessoriPc/webcam.h>

#include "notvalidexception.h"

LayoutDatiAccessorio::LayoutDatiAccessorio(QWidget *parent):
    QWidget (parent),
    operationModify(new QLabel("MODIFICA: ",this)),
    nomeA(new QLabel("Nome: ",this)),
    datoNomeA(new QLabel(this)),
    marcaA(new QLabel("Marca: ",this)),
    datoMarcaA(new QLabel(this)),
    tipoA(new QLabel("Tipologia: ",this)),
    datoTipoA(new QLabel(this)),
    prezzoA(new QLabel("Prezzo(€): ",this)),
    datoPrezzoA(new QLabel(this)),
    meseA(new QLabel("Mese uscita: ",this)),
    datoMeseA(new QLabel(this)),
    annoA(new QLabel("Anno uscita: ",this)),
    datoAnnoA(new QLabel(this)),
    tipoInputA(new QLabel("Tipo input: ",this)),
    datoTipoInputA(new QLabel(this)),

    modifica_nomeA(new QLineEdit(this)),
    modifica_marcaA(new QLineEdit(this)),
    datoTipologiaMA(new QLabel(this)),
    modifica_prezzoA(new QDoubleSpinBox(this)),
    modifica_meseA(new CBMonth(this)),
    modifica_annoA(new QLineEdit(this)),
    modifica_tipoInputA(new QLineEdit(this)),

    dataCuffie(new Cuffie_StampaModificaDati(this)),
    dataMonitor(new Monitor_StampaModificaDati(this)),
    dataMouse(new Mouse_StampaModificaDati(this)),
    dataTastiera(new Tastiera_StampaModificaDati(this)),
    dataWebcam(new Webcam_StampaModificaDati(this)),

    qualitaA(new QLabel("Qualità: ",this)),
    datoQualitaA(new QLabel(this)),
    rappQualitaPrezzoA(new QLabel("Rapporto qualità-prezzo: ",this)),
    datoRappQualitaPrezzoA(new QLabel(this)),
    valUsatoA(new QLabel("Valore Attuale Usato: ",this)),
    datoValoreUsatoA(new QLabel(this)),
    specificheAmmortamento(new QPushButton("Specifiche",this)),

    modifica(new QPushButton("Modifica",this)),
    annulla(new QPushButton("Annulla",this)),
    conferma(new QPushButton("Conferma",this))
{
    QVBoxLayout *layoutDati = new QVBoxLayout(this);

    layoutDati->addWidget(operationModify);
    operationModify->hide();

    layoutDati->addWidget(datoNomeA);
    datoNomeA->setStyleSheet("Color: green; font: bold 10px;  min-width: 20em;");
    datoNomeA->setAlignment(Qt::AlignCenter);

    modifica_nomeA->setAlignment(Qt::AlignCenter);
    layoutDati->addWidget(modifica_nomeA);

    QGridLayout *generalDataGL = new QGridLayout;

    generalDataGL->addWidget(nomeA,0,0);
    generalDataGL->addWidget(modifica_nomeA,0,2);

    generalDataGL->addWidget(marcaA,1,0);
    generalDataGL->addWidget(datoMarcaA,1,1);
    generalDataGL->addWidget(modifica_marcaA,1,2);

    generalDataGL->addWidget(tipoA,2,0);
    generalDataGL->addWidget(datoTipoA,2,1);
    generalDataGL->addWidget(datoTipologiaMA,2,2);

    generalDataGL->addWidget(prezzoA,3,0);
    generalDataGL->addWidget(datoPrezzoA,3,1);
    generalDataGL->addWidget(modifica_prezzoA,3,2);
    modifica_prezzoA->setSuffix("€");
    modifica_prezzoA->setMinimum(0.00);
    modifica_prezzoA->setMaximum(50000.00);

    generalDataGL->addWidget(meseA,4,0);
    generalDataGL->addWidget(datoMeseA,4,1);
    generalDataGL->addWidget(modifica_meseA,4,2);

    generalDataGL->addWidget(annoA,5,0);
    generalDataGL->addWidget(datoAnnoA,5,1);
    generalDataGL->addWidget(modifica_annoA,5,2);
    modifica_annoA->setPlaceholderText("Anno d'uscita (+2000)");


    generalDataGL->addWidget(tipoInputA,6,0);
    generalDataGL->addWidget(datoTipoInputA,6,1);
    generalDataGL->addWidget(modifica_tipoInputA,6,2);

    nomeA->hide();
    modifica_nomeA->hide();
    modifica_marcaA->hide();
    datoTipologiaMA->hide();
    modifica_prezzoA->hide();
    modifica_meseA->hide();
    modifica_annoA->hide();
    modifica_tipoInputA->hide();

    generalDataGL->setSpacing(10);

    layoutDati->addItem(generalDataGL);

    layoutDati->addWidget(dataCuffie);
    dataCuffie->hide();
    layoutDati->addWidget(dataMonitor);
    dataMonitor->hide();
    layoutDati->addWidget(dataMouse);
    dataMouse->hide();
    layoutDati->addWidget(dataTastiera);
    dataTastiera->hide();
    layoutDati->addWidget(dataWebcam);
    dataWebcam->hide();

    QGridLayout *qualita_e_usato_GL = new QGridLayout;
    qualita_e_usato_GL->addWidget(qualitaA,0,0);
    qualita_e_usato_GL->addWidget(datoQualitaA,0,1);
    qualita_e_usato_GL->addWidget(rappQualitaPrezzoA,1,0);
    qualita_e_usato_GL->addWidget(datoRappQualitaPrezzoA,1,1);
    qualita_e_usato_GL->addWidget(valUsatoA,2,0);
    qualita_e_usato_GL->addWidget(datoValoreUsatoA,2,1);
    qualita_e_usato_GL->addWidget(specificheAmmortamento,2,2);
    qualita_e_usato_GL->setVerticalSpacing(10);
    qualita_e_usato_GL->setHorizontalSpacing(55);

    layoutDati->addItem(qualita_e_usato_GL);

    layoutDati->addWidget(modifica);

    QGridLayout *buttonsModifica = new QGridLayout;
    buttonsModifica->addWidget(annulla,0,0);
    buttonsModifica->addWidget(conferma,0,1);

    layoutDati->addItem(buttonsModifica);
    annulla->hide();
    conferma->hide();

    setMinimumWidth(450);

    setLayout(layoutDati);
    setWindowTitle("Dati Accessorio");

    connect(specificheAmmortamento, SIGNAL(clicked()),this,SLOT(showSpecificheAmmortamento()));
    connect(modifica,SIGNAL(clicked()),this,SLOT(showModificatori()));
    connect(annulla,SIGNAL(clicked()),this,SLOT(showDati()));
}

void LayoutDatiAccessorio::resetVistaDati()
{
    dataCuffie->hide();
    dataMonitor->hide();
    dataMouse->hide();
    dataTastiera->hide();
    dataWebcam->hide();
}

void LayoutDatiAccessorio::showDatiSpecifici()
{
    QString t= getDatoTipo()->text();
    std::string tipo= t.toStdString();
    if(tipo=="cuffie"){
        dataCuffie->show();
    }
    if(tipo=="monitor"){
        dataMonitor->show();
    }
    if(tipo=="mouse"){
        dataMouse->show();
    }
    if(tipo=="tastiera"){
        dataTastiera->show();
    }
    if(tipo=="webcam"){
        dataWebcam->show();
    }
}

QLabel *LayoutDatiAccessorio::getDatoNome() const
{
    return datoNomeA;
}

QLabel *LayoutDatiAccessorio::getDatoMarca() const
{
    return datoMarcaA;
}

QLabel *LayoutDatiAccessorio::getDatoTipo() const
{
    return datoTipoA;
}

QLabel *LayoutDatiAccessorio::getDatoPrezzo() const
{
    return datoPrezzoA;
}

QLabel *LayoutDatiAccessorio::getDatoMeseU() const
{
    return datoMeseA;
}

QLabel *LayoutDatiAccessorio::getDatoAnnoU() const
{
    return datoAnnoA;
}

QLabel *LayoutDatiAccessorio::getDatoTipInp() const
{
    return datoTipoInputA;
}

QLabel *LayoutDatiAccessorio::getDatoQualita() const
{
    return datoQualitaA;
}

QLabel *LayoutDatiAccessorio::getDatoRappQualitaPrezzo() const
{
    return datoRappQualitaPrezzoA;
}

QLabel *LayoutDatiAccessorio::getDatoAmmortamento() const
{
    return datoValoreUsatoA;
}

Cuffie_StampaModificaDati *LayoutDatiAccessorio::getDatiCuffie() const
{
    return dataCuffie;
}

Monitor_StampaModificaDati *LayoutDatiAccessorio::getDatiMonitor() const
{
    return dataMonitor;
}

QLabel *LayoutDatiAccessorio::getDatoTipologiaM() const
{
    return datoTipologiaMA;
}

Mouse_StampaModificaDati *LayoutDatiAccessorio::getDatiMouse() const
{
    return dataMouse;
}

Tastiera_StampaModificaDati *LayoutDatiAccessorio::getDatiTastiera() const
{
    return dataTastiera;
}

Webcam_StampaModificaDati *LayoutDatiAccessorio::getDatiWebcam() const
{
    return dataWebcam;
}
std::string LayoutDatiAccessorio::getModifNome() const
{
    return modifica_nomeA->text().toStdString();
}

std::string LayoutDatiAccessorio::getModifMarca() const
{
    return modifica_marcaA->text().toStdString();
}

double LayoutDatiAccessorio::getModifPrezzo() const
{
    return modifica_prezzoA->value();
}

unsigned int LayoutDatiAccessorio::getModifMese() const
{
    return modifica_meseA->currentIndex();
}

unsigned int LayoutDatiAccessorio::getModifAnno() const
{
    return modifica_annoA->text().toUInt();;
}

std::string LayoutDatiAccessorio::getModifTipoInput() const
{
    return modifica_tipoInputA->text().toStdString();
}

QPushButton *LayoutDatiAccessorio::getBtnConferma() const
{
    return conferma;
}

bool LayoutDatiAccessorio::modifySomething()
{
    bool modificatoQualcosa=1;
    if(getModifNome().size()==0 && getModifMarca().size()==0 && getModifPrezzo()==0.00 &&
       getModifMese()==0 && getModifAnno()==0 && getModifTipoInput().size()==0){
        modificatoQualcosa=0;
    }
    return modificatoQualcosa;
}

void LayoutDatiAccessorio::showWarning(QWidget *p, QString e) const
{
    QMessageBox::warning(p,"Attenzione",e);
}

void LayoutDatiAccessorio::showSpecificheAmmortamento()
{
    QString str= "L'ammortamento dei valore dell'accessorio usato non supera mai il 70% del valore iniziale.";
    QMessageBox::about(this,"Specifiche",str);
}

void LayoutDatiAccessorio::showModificatori()
{
    slotReset();
    operationModify->show();

    datoMarcaA->hide();
    datoTipoA->hide();
    datoPrezzoA->hide();
    datoMeseA->hide();
    datoAnnoA->hide();
    datoTipoInputA->hide();

    nomeA->show();
    modifica_nomeA->show();
    modifica_marcaA->show();
    datoTipologiaMA->show();
    modifica_prezzoA->show();
    modifica_meseA->show();
    modifica_annoA->show();
    modifica_tipoInputA->show();

    qualitaA->hide();
    datoQualitaA->hide();
    rappQualitaPrezzoA->hide();
    datoRappQualitaPrezzoA->hide();
    valUsatoA->hide();
    datoValoreUsatoA->hide();
    specificheAmmortamento->hide();

    modifica->hide();
    annulla->show();
    conferma->show();

    QString t= getDatoTipo()->text();
    std::string tipo= t.toStdString();
    if(tipo=="cuffie"){
        dataCuffie->showModificatori();
    }
    if(tipo=="monitor"){
        dataMonitor->showModificatori();
    }
    if(tipo=="mouse"){
        dataMouse->showModificatori();
    }
    if(tipo=="tastiera"){
        dataTastiera->showModificatori();
    }
    if(tipo=="webcam"){
        dataWebcam->showModificatori();
    }
}

void LayoutDatiAccessorio::showDati()
{
    operationModify->hide();

    datoMarcaA->show();
    datoTipoA->show();
    datoPrezzoA->show();
    datoMeseA->show();
    datoAnnoA->show();
    datoTipoInputA->show();

    nomeA->hide();
    modifica_nomeA->hide();
    modifica_marcaA->hide();
    datoTipologiaMA->hide();
    modifica_prezzoA->hide();
    modifica_meseA->hide();
    modifica_annoA->hide();
    modifica_tipoInputA->hide();

    qualitaA->show();
    datoQualitaA->show();
    rappQualitaPrezzoA->show();
    datoRappQualitaPrezzoA->show();
    valUsatoA->show();
    datoValoreUsatoA->show();
    specificheAmmortamento->show();

    modifica->show();
    annulla->hide();
    conferma->hide();

    QString t= getDatoTipo()->text();
    std::string tipo= t.toStdString();
    if(tipo=="cuffie"){
        dataCuffie->showDati();
    }
    if(tipo=="monitor"){
        dataMonitor->showDati();
    }
    if(tipo=="mouse"){
        dataMouse->showDati();
    }
    if(tipo=="tastiera"){
        dataTastiera->showDati();
    }
    if(tipo=="webcam"){
        dataWebcam->showDati();
    }
}

void LayoutDatiAccessorio::slotReset()
{
    modifica_nomeA->setText("");
    modifica_marcaA->setText("");
    modifica_prezzoA->setValue(0.00);
    modifica_meseA->setCurrentIndex(0);
    modifica_annoA->setText("");
    modifica_tipoInputA->setText("");

    //metodi per azzerare
    dataCuffie->slotReset();
    dataMonitor->slotReset();
    dataMouse->slotReset();
    dataTastiera->slotReset();
    dataWebcam->slotReset();
}

QPushButton *LayoutDatiAccessorio::getBtnAnnulla() const
{
    return annulla;
}

QPushButton *LayoutDatiAccessorio::getBtnModifica() const
{
    return modifica;
}
