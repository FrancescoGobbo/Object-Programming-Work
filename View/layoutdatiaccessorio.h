#ifndef LAYOUTDATIACCESSORIO_H
#define LAYOUTDATIACCESSORIO_H

#include <QVBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QLineEdit>
#include <QDoubleSpinBox>
#include "AccessoriData/cuffie_stampamodificadati.h"
#include "AccessoriData/monitor_stampamodificadati.h"
#include "AccessoriData/mouse_stampamodificadati.h"
#include "AccessoriData/tastiera_stampamodificadati.h"
#include "AccessoriData/webcam_stampamodificadati.h"

#include "AccessoriData/QComboBoxNewAccessori/cbtype.h"
#include "AccessoriData/QComboBoxNewAccessori/cbmonth.h"

class LayoutDatiAccessorio: public QWidget
{
    Q_OBJECT
private:
    QLabel* operationModify;
    QLabel* nomeA;
    QLabel* datoNomeA;
    QLabel* marcaA;
    QLabel* datoMarcaA;
    QLabel* tipoA;
    QLabel* datoTipoA;
    QLabel* prezzoA;
    QLabel* datoPrezzoA;
    QLabel* meseA;
    QLabel* datoMeseA;
    QLabel* annoA;
    QLabel* datoAnnoA;
    QLabel* tipoInputA;
    QLabel* datoTipoInputA;

    QLineEdit* modifica_nomeA;
    QLineEdit* modifica_marcaA;
    QLabel* datoTipologiaMA;
    QDoubleSpinBox* modifica_prezzoA;
    CBMonth* modifica_meseA;
    QLineEdit* modifica_annoA;
    QLineEdit* modifica_tipoInputA;

    Cuffie_StampaModificaDati* dataCuffie;
    Monitor_StampaModificaDati* dataMonitor;
    Mouse_StampaModificaDati* dataMouse;
    Tastiera_StampaModificaDati* dataTastiera;
    Webcam_StampaModificaDati* dataWebcam;

    QLabel* qualitaA;
    QLabel* datoQualitaA;
    QLabel* rappQualitaPrezzoA;
    QLabel* datoRappQualitaPrezzoA;
    QLabel* valUsatoA;
    QLabel* datoValoreUsatoA;
    QPushButton* specificheAmmortamento;


    QPushButton* modifica;
    QPushButton* annulla;
    QPushButton* conferma;
public:
    LayoutDatiAccessorio(QWidget * = nullptr);
    void resetVistaDati();
    //metodo stampa dati specifici per tipologia
    void showDatiSpecifici();

    //stampa dei dati
    QLabel* getDatoNome()const;
    QLabel* getDatoMarca()const;
    QLabel* getDatoTipo()const;
    QLabel* getDatoPrezzo()const;
    QLabel* getDatoMeseU()const;
    QLabel* getDatoAnnoU()const;
    QLabel* getDatoTipInp()const;
    QLabel* getDatoQualita()const;
    QLabel* getDatoRappQualitaPrezzo()const;
    QLabel* getDatoAmmortamento()const;

    Cuffie_StampaModificaDati* getDatiCuffie()const;
    Monitor_StampaModificaDati* getDatiMonitor()const;
    QLabel* getDatoTipologiaM()const;
    Mouse_StampaModificaDati* getDatiMouse()const;
    Tastiera_StampaModificaDati* getDatiTastiera()const;
    Webcam_StampaModificaDati* getDatiWebcam()const;

    //modifica dati generali
    std::string getModifNome()const;
    std::string getModifMarca()const;
    double getModifPrezzo()const;
    unsigned int getModifMese()const;
    unsigned int getModifAnno()const;
    std::string getModifTipoInput()const;

    //bottoni
    QPushButton *getBtnModifica()const;
    QPushButton *getBtnAnnulla()const;
    QPushButton *getBtnConferma()const;

    bool modifySomething();
    void showWarning(QWidget* = nullptr, QString ="") const;

    //SLOT
public slots:
    void showSpecificheAmmortamento();
    void showModificatori();
    void showDati();
    void slotReset();
};

#endif // LAYOUTDATIACCESSORIO_H
