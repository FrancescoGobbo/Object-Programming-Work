#ifndef NEWWEBCAMLAYOUT_H
#define NEWWEBCAMLAYOUT_H

#include <QLineEdit>
#include <QCheckBox>

#include "QComboBoxNewAccessori/cbmicwebcam.h"

class NewWebcamLayout : public QWidget
{
    Q_OBJECT
private:
    QLineEdit* angoloDiVisione;
    QCheckBox* zoom;
    QCheckBox* rotazione;
    QLineEdit* frameRate;
    QCheckBox* autofocus;
    CBMicWebcam* microfono;
    QCheckBox* luceIntegrata;
    QCheckBox* ripreseNotturne;
public:
    NewWebcamLayout(QWidget * =nullptr);

    unsigned int getAngoloDiVisione() const;
    bool getZoom() const;
    bool getRotazione() const;
    unsigned int getFrameRate() const;
    bool getAutofocus() const;
    CBMicWebcam* getMicrofono() const;
    std::string getMicrofonotxt() const;
    bool getLuceIntegrata() const;
    bool getRipreseNotturne() const;

public slots:
    void slotResetWebcam()const;
};

#endif // NEWWEBCAMLAYOUT_H
