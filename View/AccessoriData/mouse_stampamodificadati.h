#ifndef MOUSE_STAMPAMODIFICADATI_H
#define MOUSE_STAMPAMODIFICADATI_H

#include <QVBoxLayout>
#include <QLabel>

#include <QLineEdit>
#include <QDoubleSpinBox>
#include <QCheckBox>

#include "QComboBoxNewAccessori/cbsensoremouse.h"
#include "QComboBoxNewAccessori/cbergonomiamouse.h"

class Mouse_StampaModificaDati: public QWidget
{
    Q_OBJECT
private:
    QLabel* datoDPIMinA;
    QLabel* dPIMinA;
    QLabel* datoDPIMaxA;
    QLabel* dPIMaxA;
    QLabel* datoPollingRateA;
    QLabel* pollingRateA;
    QLabel* datoTrackingSpeedA;
    QLabel* trackingSpeedA;
    QLabel* datoAngleSnappingA;
    QLabel* angleSnappingA;
    QLabel* datoSensoreA;
    QLabel* sensoreA;
    QLabel* datoPulsantiA;
    QLabel* pulsantiA;
    QLabel* datoErgonomiaA;
    QLabel* ergonomiaA;
    QLabel* datoPesoA;
    QLabel* PesoA;

    QLineEdit* modifica_dpim;
    QLineEdit* modifica_dpiM;
    QLineEdit* modifica_pollingRate;
    QLineEdit* modifica_trackingSpeed;
    QCheckBox* modifica_angleSnapping;
    CBSensoreMouse* modifica_sensore;
    QLineEdit* modifica_pulsanti;
    CBErgonomiaMouse* modifica_ergonomia;
    QDoubleSpinBox* modifica_peso;
public:
    Mouse_StampaModificaDati(QWidget * =nullptr);

    QLabel* getDatoDPIMin()const;
    QLabel* getDatoDPIMax()const;
    QLabel* getDatoPR()const;
    QLabel* getDatoTS()const;
    QLabel* getDatoAS()const;
    QLabel* getDatoSens()const;
    QLabel* getDatoPul()const;
    QLabel* getDatoErg()const;
    QLabel* getDatoP()const;

    unsigned int getModifDpim() const;
    unsigned int getModifDpiM() const;
    unsigned int getModifPollingRate() const;
    unsigned int getModifTrackingSpeed() const;
    bool getModifAngleSnapping() const;
    std::string getModifSensore() const;
    unsigned int getModifPulsanti() const;
    std::string getModifErgonomia() const;
    double getModifPeso() const;

    bool modifySomething();

public slots:
    void showModificatori();
    void showDati();
    void slotReset();
};

#endif // MOUSE_STAMPAMODIFICADATI_H
