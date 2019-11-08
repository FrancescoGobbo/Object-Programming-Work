#ifndef NEWMONITORLAYOUT_H
#define NEWMONITORLAYOUT_H

#include <QLineEdit>
#include <QDoubleSpinBox>
#include <QCheckBox>

#include "QComboBoxNewAccessori/cbrisoluzionemonitor.h"
#include "QComboBoxNewAccessori/cbrapportdaspettomonitor.h"
#include "QComboBoxNewAccessori/cbdr.h"


class NewMonitorLayout: public QWidget
{
    Q_OBJECT
private:
    CBRisoluzioneMonitor* risoluzione;
    CBRapportDAspettoMonitor* rappDAsp;
    QDoubleSpinBox* pollici;
    QLineEdit* refreshRate;
    QLineEdit* frameRate;
    QCheckBox* freeSync;
    QCheckBox* gSync;
    CBDR* dynamicRange;
    QCheckBox* casse;

public:
    NewMonitorLayout(QWidget * =nullptr);

    CBRisoluzioneMonitor* getRisoluzione()const;
    std::string getRisoluzionetxt() const;
    CBRapportDAspettoMonitor* getRappDAsp()const;
    std::string getRappDAsptxt() const;
    double getPollici()const;
    unsigned int getRefreshRate()const;
    unsigned int getFrameRate()const;
    bool getFreeSync()const;
    bool getGSync()const;
    CBDR* getDynamicRange()const;
    std::string getDynamicRangetxt() const;
    bool getCasse()const;

public slots:
    void slotResetMonitor()const;
};

#endif // NEWMONITORLAYOUT_H
