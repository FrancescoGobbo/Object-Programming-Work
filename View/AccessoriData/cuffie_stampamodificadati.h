#ifndef CUFFIE_STAMPAMODIFICADATI_H
#define CUFFIE_STAMPAMODIFICADATI_H

#include <QVBoxLayout>
#include <QLabel>

#include <QLineEdit>
#include <QDoubleSpinBox>
#include <QCheckBox>

class Cuffie_StampaModificaDati: public QWidget
{
    Q_OBJECT
private:
    QLabel* datoMicrofonoA;
    QLabel* microfonoA;
    QLabel* datoRispostaInFrequenzaCuffieA;
    QLabel* rispostaInFrequenzaCuffieA;
    QLabel* datoImpedenzaA;
    QLabel* impedenzaA;
    QLabel* datoRispostaInFrequenzaMicrofonoA;
    QLabel* rispostaInFrequenzaMicrofonoA;
    QLabel* datoSensibilitaMicrofonoA;
    QLabel* sensibilitaMicrofonoA;
    QLabel* datoCancellazioneRumoreA;
    QLabel* cancellazioneRumoreA;
    QLabel* datoSensibilitaCuffieA;
    QLabel* sensibilitaCuffieA;
    QLabel* datoPesoA;
    QLabel* PesoA;

    QCheckBox* modifica_microfono;
    QLineEdit* modifica_rifC;
    QLineEdit* modifica_impedenza;
    QLineEdit* modifica_rifM;
    QLineEdit* modifica_sensM;
    QCheckBox* modifica_cancellazRum;
    QLineEdit* modifica_sensC;
    QDoubleSpinBox* modifica_peso;
public:
    Cuffie_StampaModificaDati(QWidget * =nullptr);

    QLabel* getDatoMic()const;
    QLabel* getDatoRIFC()const;
    QLabel* getDatoImp()const;
    QLabel* getDatoRIFM()const;
    QLabel* getDatoSM()const;
    QLabel* getDatoSC()const;
    QLabel* getDatoCR()const;
    QLabel* getDatoP()const;

    bool getModifMicrofono() const;
    unsigned int getModifRifC() const;
    unsigned int getModifImpedenza() const;
    unsigned int getModifRifM() const;
    unsigned int getModifSensM() const;
    bool getModifCancellazRum() const;
    unsigned int getModifSensC() const;
    double getModifPeso() const;

    bool modifySomething();

    void modifyNoMic();

public slots:
    void showModificatori();
    void showDati();
    void slotReset();
};

#endif // CUFFIE_STAMPAMODIFICADATI_H
