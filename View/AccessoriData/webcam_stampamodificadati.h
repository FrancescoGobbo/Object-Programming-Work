#ifndef WEBCAM_STAMPAMODIFICADATI_H
#define WEBCAM_STAMPAMODIFICADATI_H

#include <QVBoxLayout>
#include <QLabel>

#include <QLineEdit>
#include <QCheckBox>

#include "QComboBoxNewAccessori/cbmicwebcam.h"

class Webcam_StampaModificaDati: public QWidget
{
    Q_OBJECT
private:
    QLabel* datoAngoloDiVisioneA;
    QLabel* angoloDiVisioneA;
    QLabel* datoZoomA;
    QLabel* zoomA;
    QLabel* datoRotazioneA;
    QLabel* rotazioneA;
    QLabel* datoFrameRateA;
    QLabel* frameRateA;
    QLabel* datoAutofocusA;
    QLabel* autofocusA;
    QLabel* datoMicrofonoA;
    QLabel* microfonoA;
    QLabel* datoLuceIntegrataA;
    QLabel* luceIntegrataA;
    QLabel* datoRipreseNotturneA;
    QLabel* ripreseNotturneA;

    QLineEdit* modifica_angoloDiVisione;
    QCheckBox* modifica_zoom;
    QCheckBox* modifica_rotazione;
    QLineEdit* modifica_frameRate;
    QCheckBox* modifica_autofocus;
    CBMicWebcam* modifica_microfono;
    QCheckBox* modifica_luceIntegrata;
    QCheckBox* modifica_ripreseNotturne;
public:
    Webcam_StampaModificaDati(QWidget * =nullptr);

    QLabel* getDatoADV()const;
    QLabel* getDatoZ()const;
    QLabel* getDatoR()const;
    QLabel* getDatoFR()const;
    QLabel* getDatoAf()const;
    QLabel* getDatoMic()const;
    QLabel* getDatoLI()const;
    QLabel* getDatoRN()const;

    unsigned int getModifAngoloDiVisione() const;
    bool getModifZoom() const;
    bool getModifRotazione() const;
    unsigned int getModifFrameRate() const;
    bool getModifAutofocus() const;
    std::string getModifMicrofono() const;
    bool getModifLuceIntegrata() const;
    bool getModifRipreseNotturne() const;

    bool modifySomething();

public slots:
    void showModificatori();
    void showDati();
    void slotReset();
};

#endif // WEBCAM_STAMPAMODIFICADATI_H
