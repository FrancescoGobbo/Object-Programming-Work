#include "webcam_stampamodificadati.h"

Webcam_StampaModificaDati::Webcam_StampaModificaDati(QWidget *p):
    QWidget (p),
    datoAngoloDiVisioneA(new QLabel(this)),
    angoloDiVisioneA(new QLabel("Angolo di Visione(°):",this)),
    datoZoomA(new QLabel(this)),
    zoomA(new QLabel("Zoom:",this)),
    datoRotazioneA(new QLabel(this)),
    rotazioneA(new QLabel("Rotazione:",this)),
    datoFrameRateA(new QLabel(this)),
    frameRateA(new QLabel("Frame Rate(Hz):",this)),
    datoAutofocusA(new QLabel(this)),
    autofocusA(new QLabel("Autofocus:",this)),
    datoMicrofonoA(new QLabel(this)),
    microfonoA(new QLabel("Microfono:",this)),
    datoLuceIntegrataA(new QLabel(this)),
    luceIntegrataA(new QLabel("Luce integrata:",this)),
    datoRipreseNotturneA(new QLabel(this)),
    ripreseNotturneA(new QLabel("Riprese notturne:",this)),

    modifica_angoloDiVisione(new QLineEdit(this)),
    modifica_zoom(new QCheckBox(this)),
    modifica_rotazione(new QCheckBox(this)),
    modifica_frameRate(new QLineEdit(this)),
    modifica_autofocus(new QCheckBox(this)),
    modifica_microfono(new CBMicWebcam(this)),
    modifica_luceIntegrata(new QCheckBox(this)),
    modifica_ripreseNotturne(new QCheckBox(this))
{
    QVBoxLayout *layoutDati = new QVBoxLayout(this);

    QGridLayout *webcamDataGL = new QGridLayout;

    webcamDataGL->addWidget(angoloDiVisioneA,0,0);
    webcamDataGL->addWidget(datoAngoloDiVisioneA,0,1);
    QValidator* vAV = new QIntValidator(45, 100, this);
    modifica_angoloDiVisione->setValidator(vAV);
    modifica_angoloDiVisione->setPlaceholderText("(45-100°)");
    webcamDataGL->addWidget(modifica_angoloDiVisione,0,2);

    webcamDataGL->addWidget(zoomA,1,0);
    webcamDataGL->addWidget(datoZoomA,1,1);
    webcamDataGL->addWidget(modifica_zoom,1,2);

    webcamDataGL->addWidget(rotazioneA,2,0);
    webcamDataGL->addWidget(datoRotazioneA,2,1);
    webcamDataGL->addWidget(modifica_rotazione,2,2);


    webcamDataGL->addWidget(frameRateA,3,0);
    webcamDataGL->addWidget(datoFrameRateA,3,1);
    QValidator* vFR = new QIntValidator(10, 144, this);
    modifica_frameRate->setValidator(vFR);
    modifica_frameRate->setPlaceholderText("(10-144 Hz)");
    webcamDataGL->addWidget(modifica_frameRate,3,2);

    webcamDataGL->addWidget(autofocusA,4,0);
    webcamDataGL->addWidget(datoAutofocusA,4,1);
    webcamDataGL->addWidget(modifica_autofocus,4,2);


    webcamDataGL->addWidget(microfonoA,5,0);
    webcamDataGL->addWidget(datoMicrofonoA,5,1);
    webcamDataGL->addWidget(modifica_microfono,5,2);

    webcamDataGL->addWidget(luceIntegrataA,6,0);
    webcamDataGL->addWidget(datoLuceIntegrataA,6,1);
    webcamDataGL->addWidget(modifica_luceIntegrata,6,2);


    webcamDataGL->addWidget(ripreseNotturneA,7,0);
    webcamDataGL->addWidget(datoRipreseNotturneA,7,1);
    webcamDataGL->addWidget(modifica_ripreseNotturne,7,2);

    webcamDataGL->setSpacing(10);

    modifica_angoloDiVisione->hide();
    modifica_zoom->hide();
    modifica_rotazione->hide();
    modifica_frameRate->hide();
    modifica_autofocus->hide();
    modifica_microfono->hide();
    modifica_luceIntegrata->hide();
    modifica_ripreseNotturne->hide();

    layoutDati->addItem(webcamDataGL);
    setLayout(layoutDati);
}

QLabel *Webcam_StampaModificaDati::getDatoADV() const
{
    return datoAngoloDiVisioneA;
}

QLabel *Webcam_StampaModificaDati::getDatoZ() const
{
    return datoZoomA;
}

QLabel *Webcam_StampaModificaDati::getDatoR() const
{
    return datoRotazioneA;
}

QLabel *Webcam_StampaModificaDati::getDatoFR() const
{
    return datoFrameRateA;
}

QLabel *Webcam_StampaModificaDati::getDatoAf() const
{
    return datoAutofocusA;
}

QLabel *Webcam_StampaModificaDati::getDatoMic() const
{
    return datoMicrofonoA;
}

QLabel *Webcam_StampaModificaDati::getDatoLI() const
{
    return datoLuceIntegrataA;
}

QLabel *Webcam_StampaModificaDati::getDatoRN() const
{
    return datoRipreseNotturneA;
}

unsigned int Webcam_StampaModificaDati::getModifAngoloDiVisione() const
{
    return modifica_angoloDiVisione->text().toUInt();
}

bool Webcam_StampaModificaDati::getModifZoom() const
{
    return modifica_zoom->isChecked();
}

bool Webcam_StampaModificaDati::getModifRotazione() const
{
    return modifica_rotazione->isChecked();
}

unsigned int Webcam_StampaModificaDati::getModifFrameRate() const
{
    return modifica_frameRate->text().toUInt();
}

bool Webcam_StampaModificaDati::getModifAutofocus() const
{
    return modifica_autofocus->isChecked();
}

std::string Webcam_StampaModificaDati::getModifMicrofono() const
{
    std::string r;
    if(modifica_microfono->currentIndex()!=0)
        r=modifica_microfono->currentText().toStdString();
    /*switch(modifica_microfono->currentIndex()){
    case 1:
        r="omnidirezionale";
    case 2:
        r="monodirezionale";
    }*/
    return r;
}

bool Webcam_StampaModificaDati::getModifLuceIntegrata() const
{
    return modifica_luceIntegrata->isChecked();
}

bool Webcam_StampaModificaDati::getModifRipreseNotturne() const
{
    return modifica_ripreseNotturne->isChecked();
}

bool Webcam_StampaModificaDati::modifySomething()
{
    bool modificatoQualcosa=1;
    if(getModifAngoloDiVisione()==0 &&
       ((getModifZoom()==0 && datoZoomA->text()=="No") || (getModifZoom()==1 && datoZoomA->text()=="Si"))&&
       ((getModifRotazione()==0 && datoRotazioneA->text()=="No") || (getModifRotazione()==1 && datoRotazioneA->text()=="Si"))&&
       getModifFrameRate()==0 &&
       ((getModifAutofocus()==0 && datoAutofocusA->text()=="No") || (getModifAutofocus()==1 && datoAutofocusA->text()=="Si"))&&
       modifica_microfono->currentIndex()==0 &&
       ((getModifLuceIntegrata()==0 && datoLuceIntegrataA->text()=="No") || (getModifLuceIntegrata()==1 && datoLuceIntegrataA->text()=="Si"))&&
       ((getModifRipreseNotturne()==0 && datoRipreseNotturneA->text()=="No") || (getModifRipreseNotturne()==1 && datoRipreseNotturneA->text()=="Si")))
            modificatoQualcosa=0;
    return modificatoQualcosa;
}

void Webcam_StampaModificaDati::showModificatori()
{
    datoAngoloDiVisioneA->hide();
    datoZoomA->hide();
    datoRotazioneA->hide();
    datoFrameRateA->hide();
    datoAutofocusA->hide();
    datoMicrofonoA->hide();
    datoLuceIntegrataA->hide();
    datoRipreseNotturneA->hide();

    modifica_angoloDiVisione->show();
    modifica_zoom->show();
    modifica_rotazione->show();
    modifica_frameRate->show();
    modifica_autofocus->show();
    modifica_microfono->show();
    modifica_luceIntegrata->show();
    modifica_ripreseNotturne->show();
}

void Webcam_StampaModificaDati::showDati()
{
    datoAngoloDiVisioneA->show();
    datoZoomA->show();
    datoRotazioneA->show();
    datoFrameRateA->show();
    datoAutofocusA->show();
    datoMicrofonoA->show();
    datoLuceIntegrataA->show();
    datoRipreseNotturneA->show();

    modifica_angoloDiVisione->hide();
    modifica_zoom->hide();
    modifica_rotazione->hide();
    modifica_frameRate->hide();
    modifica_autofocus->hide();
    modifica_microfono->hide();
    modifica_luceIntegrata->hide();
    modifica_ripreseNotturne->hide();
}

void Webcam_StampaModificaDati::slotReset()
{
    modifica_angoloDiVisione->setText("");
    modifica_zoom->setChecked(false);
    modifica_rotazione->setChecked(false);
    modifica_frameRate->setText("");
    modifica_autofocus->setChecked(false);
    modifica_microfono->setCurrentIndex(0);
    modifica_luceIntegrata->setChecked(false);
    modifica_ripreseNotturne->setChecked(false);
}
