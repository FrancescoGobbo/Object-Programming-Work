#include "mouse_stampamodificadati.h"

#include <QValidator>

Mouse_StampaModificaDati::Mouse_StampaModificaDati(QWidget *p):
    QWidget (p),
    datoDPIMinA(new QLabel(this)),
    dPIMinA(new QLabel("DPI minimi:",this)),
    datoDPIMaxA(new QLabel(this)),
    dPIMaxA(new QLabel("DPI massimi:",this)),
    datoPollingRateA(new QLabel(this)),
    pollingRateA(new QLabel("Polling Rate(Hz):",this)),
    datoTrackingSpeedA(new QLabel(this)),
    trackingSpeedA(new QLabel("Tracking Speed(IPS):",this)),
    datoAngleSnappingA(new QLabel(this)),
    angleSnappingA(new QLabel("Angle Snapping:",this)),
    datoSensoreA(new QLabel(this)),
    sensoreA(new QLabel("Sensore:",this)),
    datoPulsantiA(new QLabel(this)),
    pulsantiA(new QLabel("Pulsanti:",this)),
    datoErgonomiaA(new QLabel(this)),
    ergonomiaA(new QLabel("Ergonomia:",this)),
    datoPesoA(new QLabel(this)),
    PesoA(new QLabel("Peso(kg):",this)),

    modifica_dpim(new QLineEdit(this)),
    modifica_dpiM(new QLineEdit(this)),
    modifica_pollingRate(new QLineEdit(this)),
    modifica_trackingSpeed(new QLineEdit(this)),
    modifica_angleSnapping(new QCheckBox(this)),
    modifica_sensore(new CBSensoreMouse(this)),
    modifica_pulsanti(new QLineEdit(this)),
    modifica_ergonomia(new CBErgonomiaMouse(this)),
    modifica_peso(new QDoubleSpinBox(this))
{
    QVBoxLayout *layoutDati = new QVBoxLayout(this);

    QGridLayout *mouseDataGL = new QGridLayout;

    mouseDataGL->addWidget(dPIMinA,0,0);
    mouseDataGL->addWidget(datoDPIMinA,0,1);
    QValidator* vDPImin = new QIntValidator(100, 3500, this);
    modifica_dpim->setValidator(vDPImin);
    modifica_dpim->setPlaceholderText("(100-3500)");
    mouseDataGL->addWidget(modifica_dpim,0,2);

    mouseDataGL->addWidget(dPIMaxA,1,0);
    mouseDataGL->addWidget(datoDPIMaxA,1,1);
    QValidator* vDPImax = new QIntValidator(1000, 16000, this);
    modifica_dpiM->setValidator(vDPImax);
    modifica_dpiM->setPlaceholderText("(1000-16000)");
    mouseDataGL->addWidget(modifica_dpiM,1,2);

    mouseDataGL->addWidget(pollingRateA,2,0);
    mouseDataGL->addWidget(datoPollingRateA,2,1);
    QValidator* vPR = new QIntValidator(50, 1000, this);
    modifica_pollingRate->setValidator(vPR);
    modifica_pollingRate->setPlaceholderText("(50-1000 Hz)");
    mouseDataGL->addWidget(modifica_pollingRate,2,2);

    mouseDataGL->addWidget(trackingSpeedA,3,0);
    mouseDataGL->addWidget(datoTrackingSpeedA,3,1);
    QValidator* vTS = new QIntValidator(10, 150, this);
    modifica_trackingSpeed->setValidator(vTS);
    modifica_trackingSpeed->setPlaceholderText("(10-150 IPS)");
    mouseDataGL->addWidget(modifica_trackingSpeed,3,2);

    mouseDataGL->addWidget(angleSnappingA,4,0);
    mouseDataGL->addWidget(datoAngleSnappingA,4,1);
    mouseDataGL->addWidget(modifica_angleSnapping,4,2);

    mouseDataGL->addWidget(sensoreA,5,0);
    mouseDataGL->addWidget(datoSensoreA,5,1);
    mouseDataGL->addWidget(modifica_sensore,5,2);

    mouseDataGL->addWidget(pulsantiA,6,0);
    mouseDataGL->addWidget(datoPulsantiA,6,1);
    QValidator* vPulsanti = new QIntValidator(3, 17, this);
    modifica_pulsanti->setValidator(vPulsanti);
    modifica_pulsanti->setPlaceholderText("(3-17)");
    mouseDataGL->addWidget(modifica_pulsanti,6,2);

    mouseDataGL->addWidget(ergonomiaA,7,0);
    mouseDataGL->addWidget(datoErgonomiaA,7,1);
    mouseDataGL->addWidget(modifica_ergonomia,7,2);

    mouseDataGL->addWidget(PesoA,8,0);
    mouseDataGL->addWidget(datoPesoA,8,1);
    modifica_peso->setSuffix("kg");
    mouseDataGL->addWidget(modifica_peso,8,2);

    mouseDataGL->setSpacing(10);

    modifica_dpim->hide();
    modifica_dpiM->hide();
    modifica_pollingRate->hide();
    modifica_trackingSpeed->hide();
    modifica_angleSnapping->hide();
    modifica_sensore->hide();
    modifica_pulsanti->hide();
    modifica_ergonomia->hide();
    modifica_peso->hide();

    layoutDati->addItem(mouseDataGL);
    setLayout(layoutDati);
}

QLabel *Mouse_StampaModificaDati::getDatoDPIMin() const
{
    return datoDPIMinA;
}

QLabel *Mouse_StampaModificaDati::getDatoDPIMax() const
{
    return datoDPIMaxA;
}

QLabel *Mouse_StampaModificaDati::getDatoPR() const
{
    return datoPollingRateA;
}

QLabel *Mouse_StampaModificaDati::getDatoTS() const
{
    return datoTrackingSpeedA;
}

QLabel *Mouse_StampaModificaDati::getDatoAS() const
{
    return datoAngleSnappingA;
}

QLabel *Mouse_StampaModificaDati::getDatoSens() const
{
    return datoSensoreA;
}

QLabel *Mouse_StampaModificaDati::getDatoPul() const
{
    return datoPulsantiA;
}

QLabel *Mouse_StampaModificaDati::getDatoErg() const
{
    return datoErgonomiaA;
}

QLabel *Mouse_StampaModificaDati::getDatoP() const
{
    return datoPesoA;
}

unsigned int Mouse_StampaModificaDati::getModifDpim() const
{
    return modifica_dpim->text().toUInt();
}

unsigned int Mouse_StampaModificaDati::getModifDpiM() const
{
    return modifica_dpiM->text().toUInt();
}

unsigned int Mouse_StampaModificaDati::getModifPollingRate() const
{
    return modifica_pollingRate->text().toUInt();
}

unsigned int Mouse_StampaModificaDati::getModifTrackingSpeed() const
{
    return modifica_trackingSpeed->text().toUInt();
}

bool Mouse_StampaModificaDati::getModifAngleSnapping() const
{
    return modifica_angleSnapping->isChecked();
}

std::string Mouse_StampaModificaDati::getModifSensore() const
{
    std::string r;
    if(modifica_sensore->currentIndex()!=0)
        r=modifica_sensore->currentText().toStdString();
    /*switch(modifica_sensore->currentIndex()){
    case 1:
        r="ottico";
    case 2:
        r="laser";
    }*/
    return r;
}

unsigned int Mouse_StampaModificaDati::getModifPulsanti() const
{
    return modifica_pulsanti->text().toUInt();
}

std::string Mouse_StampaModificaDati::getModifErgonomia() const
{
    std::string r;
    if(modifica_ergonomia->currentIndex()!=0)
        r=modifica_ergonomia->currentText().toStdString();
    /*switch(modifica_ergonomia->currentIndex()){
    case 1:
        r="verticale";
    case 2:
        r="orizzontale";
    }*/
    return r;
}

double Mouse_StampaModificaDati::getModifPeso() const
{
    return modifica_peso->value();
}

bool Mouse_StampaModificaDati::modifySomething()
{
    bool modificatoQualcosa=1;
    if(getModifDpim()==0 && getModifDpiM()==0 && getModifPollingRate()==0 && getModifTrackingSpeed()==0 &&
       ((getModifAngleSnapping()==0 && datoAngleSnappingA->text()=="No") || (getModifAngleSnapping()==1 && datoAngleSnappingA->text()=="Si"))&&
       modifica_sensore->currentIndex()==0 && getModifPulsanti()==0 && modifica_ergonomia->currentIndex()==0 && getModifPeso()==0.00)
           modificatoQualcosa=0;
    return modificatoQualcosa;
}

void Mouse_StampaModificaDati::showModificatori()
{
    datoDPIMinA->hide();
    datoDPIMaxA->hide();
    datoPollingRateA->hide();
    datoTrackingSpeedA->hide();
    datoAngleSnappingA->hide();
    datoSensoreA->hide();
    datoPulsantiA->hide();
    datoErgonomiaA->hide();
    datoPesoA->hide();

    modifica_dpim->show();
    modifica_dpiM->show();
    modifica_pollingRate->show();
    modifica_trackingSpeed->show();
    modifica_angleSnapping->show();
    modifica_sensore->show();
    modifica_pulsanti->show();
    modifica_ergonomia->show();
    modifica_peso->show();
}

void Mouse_StampaModificaDati::showDati()
{
    datoDPIMinA->show();
    datoDPIMaxA->show();
    datoPollingRateA->show();
    datoTrackingSpeedA->show();
    datoAngleSnappingA->show();
    datoSensoreA->show();
    datoPulsantiA->show();
    datoErgonomiaA->show();
    datoPesoA->show();

    modifica_dpim->hide();
    modifica_dpiM->hide();
    modifica_pollingRate->hide();
    modifica_trackingSpeed->hide();
    modifica_angleSnapping->hide();
    modifica_sensore->hide();
    modifica_pulsanti->hide();
    modifica_ergonomia->hide();
    modifica_peso->hide();
}

void Mouse_StampaModificaDati::slotReset()
{
    modifica_dpim->setText("");
    modifica_dpiM->setText("");
    modifica_pollingRate->setText("");
    modifica_trackingSpeed->setText("");
    modifica_angleSnapping->setChecked(false);
    modifica_sensore->setCurrentIndex(0);
    modifica_pulsanti->setText("");
    modifica_ergonomia->setCurrentIndex(0);
    modifica_peso->setValue(0.00);
}
