#include "newmouselayout.h"

#include <QVBoxLayout>
#include <QValidator>
#include <QLabel>

NewMouseLayout::NewMouseLayout(QWidget *p):
    QWidget (p),
    dpim(new QLineEdit(this)),
    dpiM(new QLineEdit(this)),
    pollingRate(new QLineEdit(this)),
    trackingSpeed(new QLineEdit(this)),
    angleSnapping(new QCheckBox("Angle Snapping", this)),
    sensore(new CBSensoreMouse(this)),
    pulsanti(new QLineEdit(this)),
    ergonomia(new CBErgonomiaMouse(this)),
    peso(new QDoubleSpinBox(this))
{
    QVBoxLayout *layoutMouse = new QVBoxLayout();

    QValidator* vDPImin = new QIntValidator(100, 3500, this);
    dpim->setValidator(vDPImin);
    dpim->setPlaceholderText("DPI min   (100-3500)");
    layoutMouse->addWidget(dpim);

    QValidator* vDPImax = new QIntValidator(1000, 16000, this);
    dpiM->setValidator(vDPImax);
    dpiM->setPlaceholderText("DPI max   (1000-16000)");
    layoutMouse->addWidget(dpiM);

    QValidator* vPR = new QIntValidator(50, 1000, this);
    pollingRate->setValidator(vPR);
    pollingRate->setPlaceholderText("Polling Rate   (50-1000 Hz)");
    layoutMouse->addWidget(pollingRate);

    QValidator* vTS = new QIntValidator(10, 150, this);
    trackingSpeed->setValidator(vTS);
    trackingSpeed->setPlaceholderText("Tracking Speed   (10-150 IPS)");
    layoutMouse->addWidget(trackingSpeed);

    layoutMouse->addWidget(angleSnapping);

    QGridLayout *grindSensore = new QGridLayout;
    QLabel* text1 = new QLabel("Sensore");
    grindSensore->addWidget(text1,0,0);
    grindSensore->addWidget(sensore,0,1);
    layoutMouse->addItem(grindSensore);

    QValidator* vPulsanti = new QIntValidator(3, 17, this);
    pulsanti->setValidator(vPulsanti);
    pulsanti->setPlaceholderText("Pulsanti  (3-17)");
    layoutMouse->addWidget(pulsanti);

    QGridLayout *grindErgonomia = new QGridLayout;
    QLabel* text2 = new QLabel("Ergonomia");
    grindErgonomia->addWidget(text2,0,0);
    grindErgonomia->addWidget(ergonomia,0,1);
    layoutMouse->addItem(grindErgonomia);

    peso->setSuffix("kg");
    peso->setPrefix("Peso:   ");
    layoutMouse->addWidget(peso);

    setLayout(layoutMouse);
}

unsigned int NewMouseLayout::getDpim() const
{
    return dpim->text().toUInt();
}

unsigned int NewMouseLayout::getDpiM() const
{
    return dpiM->text().toUInt();
}

unsigned int NewMouseLayout::getPollingRate() const
{
    return pollingRate->text().toUInt();
}

unsigned int NewMouseLayout::getTrackingSpeed() const
{
    return trackingSpeed->text().toUInt();
}

bool NewMouseLayout::getAngleSnapping() const
{
    return angleSnapping->isChecked();
}

CBSensoreMouse *NewMouseLayout::getSensore() const
{
    return sensore;
}

std::string NewMouseLayout::getSensoretxt() const
{
    std::string r;
    if(sensore->currentIndex()!=0)
        r=sensore->currentText().toStdString();
    return r;
}

unsigned int NewMouseLayout::getPulsanti() const
{
    return pulsanti->text().toUInt();
}

CBErgonomiaMouse *NewMouseLayout::getErgonomia() const
{
    return ergonomia;
}

std::string NewMouseLayout::getErgonomiatxt() const
{
    std::string r;
    if(ergonomia->currentIndex()!=0)
        r=ergonomia->currentText().toStdString();
    return r;
}

double NewMouseLayout::getPeso() const
{
    return peso->value();
}

void NewMouseLayout::slotResetMouse() const
{
    dpim->setText("");
    dpiM->setText("");
    pollingRate->setText("");
    trackingSpeed->setText("");
    angleSnapping->setChecked(false);
    sensore->setCurrentIndex(0);
    pulsanti->setText("");
    ergonomia->setCurrentIndex(0);
    peso->setValue(0.00);
}
