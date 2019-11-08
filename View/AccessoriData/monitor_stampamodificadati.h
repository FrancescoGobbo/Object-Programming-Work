#ifndef MONITOR_STAMPAMODIFICADATI_H
#define MONITOR_STAMPAMODIFICADATI_H

#include <QVBoxLayout>
#include <QLabel>

#include <QLineEdit>
#include <QDoubleSpinBox>
#include <QCheckBox>

#include "QComboBoxNewAccessori/cbrapportdaspettomonitor.h"
#include "QComboBoxNewAccessori/cbdr.h"
#include "QComboBoxNewAccessori/cbrisoluzionemonitor.h"

class Monitor_StampaModificaDati: public QWidget
{
    Q_OBJECT
private:
    QLabel* datoRisoluzioneA;
    QLabel* risoluzioneA;
    QLabel* datoRapportoDAspettoA;
    QLabel* rapportoDAspettoA;
    QLabel* datoPolliciA;
    QLabel* polliciA;
    QLabel* datoRefreshRateA;
    QLabel* refreshRateA;
    QLabel* datoFrameRateA;
    QLabel* frameRateA;
    QLabel* datoFreeSyncA;
    QLabel* freeSyncA;
    QLabel* datoGSyncA;
    QLabel* gSyncA;
    QLabel* datoDynamicRangeA;
    QLabel* dynamicRangeA;
    QLabel* datoCasseA;
    QLabel* casseA;

    CBRisoluzioneMonitor* modifica_risoluzione;
    CBRapportDAspettoMonitor* modifica_rappDAsp;
    QDoubleSpinBox* modifica_pollici;
    QLineEdit* modifica_refreshRate;
    QLineEdit* modifica_frameRate;
    QCheckBox* modifica_freeSync;
    QCheckBox* modifica_gSync;
    CBDR* modifica_dynamicRange;
    QCheckBox* modifica_casse;
public:
    Monitor_StampaModificaDati(QWidget * =nullptr);

    QLabel* getDatoRis()const;
    QLabel* getDatoRDA()const;
    QLabel* getDatoPol()const;
    QLabel* getDatoRR()const;
    QLabel* getDatoFR()const;
    QLabel* getDatoFS()const;
    QLabel* getDatoGS()const;
    QLabel* getDatoDR()const;
    QLabel* getDatoCas()const;

    std::string getModifRisoluzione()const;
    std::string getModifRappDAsp()const;
    double getModifPollici()const;
    unsigned int getModifRefreshRate()const;
    unsigned int getModifFrameRate()const;
    bool getModifFreeSync()const;
    bool getModifGSync()const;
    std::string getModifDynamicRange()const;
    bool getModifCasse()const;

    bool modifySomething();

public slots:
    void showModificatori();
    void showDati();
    void slotReset();
};

#endif // MONITOR_STAMPAMODIFICADATI_H
