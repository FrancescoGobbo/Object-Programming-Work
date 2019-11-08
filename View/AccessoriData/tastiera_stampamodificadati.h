#ifndef TASTIERA_STAMPAMODIFICADATI_H
#define TASTIERA_STAMPAMODIFICADATI_H

#include <QVBoxLayout>
#include <QLabel>

#include <QLineEdit>
#include <QCheckBox>

#include "QComboBoxNewAccessori/cbcategoriatastiera.h"
#include "QComboBoxNewAccessori/cblayouttastiera.h"
#include "QComboBoxNewAccessori/cbconforttastiera.h"

class Tastiera_StampaModificaDati: public QWidget
{
    Q_OBJECT
private:
    QLabel* datoRetroIlluminazioneA;
    QLabel* retroIlluminazioneA;
    QLabel* datoLayoutA;
    QLabel* layoutA;
    QLabel* datoConfortA;
    QLabel* confortA;
    QLabel* datoPollingRateA;
    QLabel* pollingRateA;
    QLabel* datoCategoriaA;
    QLabel* categoriaA;
    QLabel* datoTrackPadA;
    QLabel* trackPadA;

    QCheckBox* modifica_retroIlluminazione;
    CBLayoutTastiera* modifica_layout;
    CBConfortTastiera* modifica_confort;
    QLineEdit* modifica_pollingRate;
    CBCategoriaTastiera* modifica_categoria;
    QCheckBox* modifica_trackPad;
public:
    Tastiera_StampaModificaDati(QWidget * =nullptr);

    QLabel* getDatoRI()const;
    QLabel* getDatoLay()const;
    QLabel* getDatoConf()const;
    QLabel* getDatoPR()const;
    QLabel* getDatoCat()const;
    QLabel* getDatoTP()const;

    bool getModifRetroIlluminazione() const;
    std::string getModifLayout() const;
    std::string getModifConfort() const;
    unsigned int getModifPollingRate() const;
    std::string getModifCategoria() const;
    bool getModifTrackPad() const;

    bool modifySomething();

public slots:
    void showModificatori();
    void showDati();
    void slotReset();
};

#endif // TASTIERA_STAMPAMODIFICADATI_H
