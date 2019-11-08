#ifndef LAYOUTLISTARICERCAACCESSORI_H
#define LAYOUTLISTARICERCAACCESSORI_H

#include <QPushButton>
#include <QScrollBar>
#include <QVBoxLayout>
#include <QLabel>
#include <QListWidget>
#include <string>

#include "Contenitore/AccessoriPc/accessori.h"
#include "Contenitore/container.h"
#include "Contenitore/deepptr.h"
#include "LayoutView-QualityResearch/layoutquality.h"
#include "LayoutView-QualityResearch/layoutresearch.h"


class LayoutListaRicercaAccessori : public QWidget
{
    Q_OBJECT
private:
    QPushButton* btnTornaHome;
    QLabel* tipoAcc;
    QListWidget* lista;
    LayoutQuality* qualita;
    LayoutResearch* ricerca;
    QPushButton* btnElimina;
    QPushButton* btnInserisci;
public:
    LayoutListaRicercaAccessori(QWidget * =nullptr);
    ~LayoutListaRicercaAccessori();

    QPushButton* getReturnHome()const;
    QLabel* getIntro() const;

    void aggRiga(QString s);
    void resetLista() const;
    QListWidget* getLista()const;

    QLabel* getNAccEcc() const;
    QLabel* getNAccOtt() const;
    QLabel* getNAccBuo() const;
    QLabel* getNAccSuf() const;
    QLabel* getNAccPes() const;

    int getTipo() const;
    string getNome() const;
    string getMarca() const;
    double getPrezzoMin()const;
    double getPrezzoMax()const;
    QPushButton *getBtnRicerca() const;
    QPushButton *getBtnResetRicerca() const;
    void azzeraRicerca()const;

    QPushButton *getBtnInserisci() const;
    QPushButton *getBtnElimina() const;

    //void listwiew();

/*
public slots:

signals:
    //void signalElementoSelezionato(bool=true)const;
*/
};

#endif // LAYOUTLISTARICERCAACCESSORI_H
