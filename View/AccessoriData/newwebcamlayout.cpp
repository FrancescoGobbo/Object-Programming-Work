#include "newwebcamlayout.h"

#include <QVBoxLayout>
#include <QValidator>
#include <QLabel>

NewWebcamLayout::NewWebcamLayout(QWidget *p):
    QWidget (p),
    angoloDiVisione(new QLineEdit(this)),
    zoom(new QCheckBox("Zoom",this)),
    rotazione(new QCheckBox("Rotazione",this)),
    frameRate(new QLineEdit(this)),
    autofocus(new QCheckBox("Autofocus",this)),
    microfono(new CBMicWebcam(this)),
    luceIntegrata(new QCheckBox("Luce Integrata",this)),
    ripreseNotturne(new QCheckBox("Riprese Notturne",this))
{
    QVBoxLayout *layoutWebcam = new QVBoxLayout();

    QValidator* vAV = new QIntValidator(45, 100, this);
    angoloDiVisione->setValidator(vAV);
    angoloDiVisione->setPlaceholderText("Angolo di visione   (45-100°)");
    layoutWebcam->addWidget(angoloDiVisione);

    QGridLayout *grindZR = new QGridLayout;
    grindZR->addWidget(zoom,0,0);
    grindZR->addWidget(rotazione,0,1);
    layoutWebcam->addItem(grindZR);

    QValidator* vFR = new QIntValidator(10, 144, this);
    frameRate->setValidator(vFR);
    frameRate->setPlaceholderText("Frame Rate   (10-144 Hz)");
    layoutWebcam->addWidget(frameRate);

    layoutWebcam->addWidget(autofocus);

    QGridLayout *grindMIC = new QGridLayout;
    QLabel* text1 = new QLabel("Microfono");
    grindMIC->addWidget(text1,0,0);
    grindMIC->addWidget(microfono,0,1);
    layoutWebcam->addItem(grindMIC);

    QGridLayout *grind_LI_RN = new QGridLayout;
    grind_LI_RN->addWidget(luceIntegrata,0,0);
    grind_LI_RN->addWidget(ripreseNotturne,0,1);
    layoutWebcam->addItem(grind_LI_RN);

    setLayout(layoutWebcam);
}

unsigned int NewWebcamLayout::getAngoloDiVisione() const
{
    return angoloDiVisione->text().toUInt();
}

bool NewWebcamLayout::getZoom() const
{
    return zoom->isChecked();
}

bool NewWebcamLayout::getRotazione() const
{
    return rotazione->isChecked();
}

unsigned int NewWebcamLayout::getFrameRate() const
{
    return frameRate->text().toUInt();
}

bool NewWebcamLayout::getAutofocus() const
{
    return autofocus->isChecked();
}

CBMicWebcam *NewWebcamLayout::getMicrofono() const
{
    return microfono;
}

std::string NewWebcamLayout::getMicrofonotxt() const
{
    std::string r;
    if(microfono->currentIndex()!=0)
        r=microfono->currentText().toStdString();
    return r;
}

bool NewWebcamLayout::getLuceIntegrata() const
{
    return luceIntegrata->isChecked();
}

bool NewWebcamLayout::getRipreseNotturne() const
{
    return ripreseNotturne->isChecked();
}

void NewWebcamLayout::slotResetWebcam() const
{
    angoloDiVisione->setText("");
    zoom->setChecked(false);
    rotazione->setChecked(false);
    frameRate->setText("");
    autofocus->setChecked(false);
    microfono->setCurrentIndex(0);
    luceIntegrata->setChecked(false);
    ripreseNotturne->setChecked(false);
}
