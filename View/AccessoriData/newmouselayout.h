#ifndef NEWMOUSELAYOUT_H
#define NEWMOUSELAYOUT_H

#include <QLineEdit>
#include <QDoubleSpinBox>
#include <QCheckBox>

#include "QComboBoxNewAccessori/cbsensoremouse.h"
#include "QComboBoxNewAccessori/cbergonomiamouse.h"

class NewMouseLayout : public QWidget
{
    Q_OBJECT
private:
    QLineEdit* dpim;
    QLineEdit* dpiM;
    QLineEdit* pollingRate;
    QLineEdit* trackingSpeed;
    QCheckBox* angleSnapping;
    CBSensoreMouse* sensore;
    QLineEdit* pulsanti;
    CBErgonomiaMouse* ergonomia;
    QDoubleSpinBox* peso;
public:
    NewMouseLayout(QWidget * =nullptr);

    unsigned int getDpim() const;
    unsigned int getDpiM() const;
    unsigned int getPollingRate() const;
    unsigned int getTrackingSpeed() const;
    bool getAngleSnapping() const;
    CBSensoreMouse* getSensore() const;
    std::string getSensoretxt() const;
    unsigned int getPulsanti() const;
    CBErgonomiaMouse* getErgonomia() const;
    std::string getErgonomiatxt() const;
    double getPeso() const;

public slots:
    void slotResetMouse()const;
};

#endif // NEWMOUSELAYOUT_H
