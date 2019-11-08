#ifndef WIDGET_H
#define WIDGET_H

#include "model.h"
#include "View/home.h"
#include "View/menubar.h"
#include "layoutinserisciarticolo.h"
#include "layoutlistaricercaaccessori.h"
#include "layoutdatiaccessorio.h"

#include<QApplication>
#include <QWidget>
#include <QVBoxLayout>

class MWindow : public QWidget
{
    Q_OBJECT
private:
    MenuBar* menuBar;
    Model* modello;

    QHBoxLayout* mainLayout;

    Home* home;
    LayoutInserisciArticolo* layoutIns;
    LayoutListaRicercaAccessori* layoutVista;
    LayoutDatiAccessorio* layoutVistaDati;

public:
    MWindow(Model* , QWidget * = nullptr);
    ~MWindow();
    Model *getModello();

private slots:

    void slotMSGBOXAboutDialog();
    void slotMSGBOXReportBug();
    void slotLoad();
    void slotLoadNewData();
    void slotAggiungiElemento();
    void slotResetElemento();
    void slotSaveData()const;
    void slotDataChanged(bool)const;
    void slotEliminaDaModello();
    void slotVerificaDiModifica();
    //void slotShowVisualizza()const;

    void slotShowInserisci()const;

    void inputDatiLista()const;
    void slotShowListaRicercaViewTutti()const;
    void slotShowListaRicercaViewCuffie()const;
    void slotShowListaRicercaViewMonitor()const;
    void slotShowListaRicercaViewMouse()const;
    void slotShowListaRicercaViewTastiera()const;
    void slotShowListaRicercaViewWebcam()const;

    void slotShowQualita()const;

    void slotRicercaAcc();
    void slotResetDataRicerca() const;

    void slotShowData(QListWidgetItem*) const;
    void modificaDati();

    void slotInReturnHome()const;
    void slotVReturnHome()const;

    void slotClose();

};

#endif //  WIDGET_H
