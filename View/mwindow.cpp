#include "mwindow.h"

#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QMessageBox>
#include <QFileDialog>
#include <QMessageBox>
#include <QBuffer>

#include<Contenitore/AccessoriPc/accessori.h>
#include<Contenitore/AccessoriPc/cuffie.h>
#include<Contenitore/AccessoriPc/monitor.h>
#include<Contenitore/AccessoriPc/mouse.h>
#include<Contenitore/AccessoriPc/tastiera.h>
#include<Contenitore/AccessoriPc/webcam.h>

#include "notvalidexception.h"

#include <iostream>

using std::string;

void MWindow::slotSaveData() const
{
    if(!modello->getIsDataSaved()){
        modello->saveToFile();
        modello->setDataSaved(true);
        slotDataChanged(false);
    }
}

void MWindow::slotDataChanged(bool b) const
{
    menuBar->getSave()->setEnabled(b);
}

void MWindow::slotEliminaDaModello()
{
    if(modello->getPathSize()>0){
        if(!modello->isDataEmpty()){
            QMessageBox::StandardButton reply;
            reply=QMessageBox::question(this,"Elimina","Vuoi eliminare l'accessorio "+layoutVista->getLista()->currentItem()->text()+"?",QMessageBox::Yes|QMessageBox::No);
            if(reply==QMessageBox::Yes){
                modello->eliminazione(layoutVista->getLista()->currentRow());
                layoutVista->getLista()->takeItem(layoutVista->getLista()->currentIndex().row());
                layoutVista->resetLista();
                inputDatiLista();
                slotSaveData();
                QMessageBox::information(this,"Informazione","Eliminazione eseguita con successo","Ok");
            }
        }
        else
            QMessageBox::warning(this,"Attenzione!","Il file inserito nel programma è vuoto. \nNon è possibile eliminare dati che non esistono.");
    }else{
        QMessageBox::warning(this,"Attenzione!","Nessun file inserito nel programma. \nNon è possibile eliminare dati che non esistono.");
    }

}

void MWindow::slotVerificaDiModifica()
{
    if(!modello->getIsDataSaved()){
        modello->setDataSaved(false);
        slotDataChanged(true);
        layoutVista->resetLista();
        modello->resetRicerca();
        slotResetDataRicerca();
        //inputDatiLista();
    }
}

void MWindow::slotLoad()
{
    if(!modello->getIsDataSaved()){
        QMessageBox::StandardButton reply= QMessageBox::question(this,"Attenzione!","Ci sono modifiche che non sono state salvate, clicca YES per salvare i dati nel file corrente.",QMessageBox::Yes|QMessageBox::No);
        if(reply==QMessageBox::No)
            return;
        else
            slotSaveData();
    }
    QString file= QFileDialog::getOpenFileName(
                this,
                tr("Choose file"),
                "../QontainerAccessoriPc/FileXML",
                "File XML(*.xml)"
                );
    if(file!=""){
        modello->clear();
        modello->setNewPath(file.toStdString());
        modello->loadFromFile();

        if(modello->getDataUsed()==0){
            QMessageBox::warning(this,"Attenzione!","Il file del programma è vuoto.");
        }
        else{
            modello->setDataSaved(true);
            slotDataChanged(false);
        }
    }
    else{
        QMessageBox::warning(this,"Attenzione!","Nessun file inserito nel programma.");
    }
}

void MWindow::slotLoadNewData()
{
    slotVReturnHome();
    slotLoad();
}

MWindow::MWindow(Model* m,QWidget * parent) :
    QWidget (parent),
    menuBar(new MenuBar(this)),
    modello(m),
    mainLayout (new QHBoxLayout(this)),
    home(new Home(this)),
    layoutIns(new LayoutInserisciArticolo(this)),
    layoutVista(new LayoutListaRicercaAccessori(this)),
    layoutVistaDati (new LayoutDatiAccessorio())
{
    mainLayout->setMenuBar(menuBar);

    mainLayout->addWidget(home);
    mainLayout->addWidget(layoutIns);
    mainLayout->addWidget(layoutVista);

    layoutIns->hide();
    layoutVista->hide();

    setLayout(mainLayout);

    //MenuAction
    connect(menuBar->getSave(),SIGNAL(triggered()),this,SLOT(slotSaveData()));
    connect(menuBar->getExit(),SIGNAL(triggered()),this,SLOT(slotClose()));
    connect(menuBar->getLoad(),SIGNAL(triggered()),this, SLOT(slotLoadNewData()));

    //LayoutHome
    connect(home->getBtnTutti(),SIGNAL(clicked()),this,SLOT(slotShowListaRicercaViewTutti()));
    connect(home->getBtnCuffie(),SIGNAL(clicked()),this,SLOT(slotShowListaRicercaViewCuffie()));
    connect(home->getBtnMonitor(),SIGNAL(clicked()),this,SLOT(slotShowListaRicercaViewMonitor()));
    connect(home->getBtnMouse(),SIGNAL(clicked()),this,SLOT(slotShowListaRicercaViewMouse()));
    connect(home->getBtnTastiera(),SIGNAL(clicked()),this,SLOT(slotShowListaRicercaViewTastiera()));
    connect(home->getBtnWebcam(),SIGNAL(clicked()),this,SLOT(slotShowListaRicercaViewWebcam()));

    //LayoutInserisciArticolo
    connect(layoutIns->getBAggButton(),SIGNAL(clicked()),this,SLOT(slotAggiungiElemento()));
    connect(layoutIns->getBResButton(),SIGNAL(clicked()),this,SLOT(slotResetElemento()));
    connect(layoutIns->getBAnnButton(),SIGNAL(clicked()),this,SLOT(slotInReturnHome()));

    //LayoutListaRicercaEliminaArticolo
    connect(layoutVista->getReturnHome(),SIGNAL(clicked()),this,SLOT(slotVReturnHome()));
    connect(layoutVista->getBtnElimina(),SIGNAL(clicked()),this,SLOT(slotEliminaDaModello()));
    connect(layoutVista->getBtnInserisci(),SIGNAL(clicked()),this,SLOT(slotShowInserisci()));
    connect(layoutVista->getBtnRicerca(), SIGNAL(clicked()),this, SLOT(slotRicercaAcc()));
    connect(layoutVista->getBtnResetRicerca(),SIGNAL(clicked()),this, SLOT(slotResetDataRicerca()));

    //LayoutShowData
    connect(layoutVista->getLista(),SIGNAL(itemDoubleClicked(QListWidgetItem*)),this,SLOT(slotShowData(QListWidgetItem*)));

    //ModifyData
    connect(layoutVistaDati->getBtnConferma(),SIGNAL(clicked()),this,SLOT(modificaDati()));

    slotLoad();
}

MWindow::~MWindow()
{
    if(!modello->isDataEmpty()){
        QMessageBox::information(this, tr("Informazione"),tr("I dati sono stati salvati in automatico."));
        slotSaveData();
    }
}

void MWindow::slotAggiungiElemento()
{
    if(modello->getPathSize()>0){
        try{
            int indexTipo = layoutIns->getTipoAccessorio()->currentIndex();
            if(indexTipo==0)
                throw NotValidException("Tipo Accessorio");
            string nome= layoutIns->getInserisciNome()->text().toStdString();
            if(nome.size()==0)
                throw NotValidException("Nome");
            string marca= layoutIns->getInserisciMarca()->text().toStdString();
            if(marca.size()==0)
                throw NotValidException("Marca");
            double prezzo= layoutIns->getInserisciPrezzo()->value();
            if(prezzo<=0.00)
                throw NotValidException("Prezzo");
            unsigned int meseU= layoutIns->getInserisciMese()->currentIndex();
            if(meseU==0)
                throw NotValidException("Mese");
            unsigned int annoU= layoutIns->getInserisciAnno()->text().toUInt();
            if(annoU<2000 || annoU>2019)
                throw NotValidException("Anno");
            string tipologia;

            string tipoInp= layoutIns->getInserisciTipoInput()->text().toStdString();
            if(tipoInp.size()==0)
                throw NotValidException("Tipo input");

            //eccezioni da verificare
            Accessori* daInserire=nullptr;
            if(indexTipo==1){
                //eccezioni da verificare cuffie
                tipologia="cuffie";
                if(layoutIns->getCuffie()->getRifC()==0 || layoutIns->getCuffie()->getRifC()<100 || layoutIns->getCuffie()->getRifC()>50000)
                    throw NotValidException("Risposta in frequenza cuffie");
                if(layoutIns->getCuffie()->getImpedenza()==0 || layoutIns->getCuffie()->getImpedenza()>250)
                    throw NotValidException("Impedenza");
                if((layoutIns->getCuffie()->getRifM()<20 || layoutIns->getCuffie()->getRifM()>20000) && layoutIns->getCuffie()->getMicrofono())
                    throw NotValidException("Risposta in frequenza microfono");
                if((layoutIns->getCuffie()->getSensM()<40 || layoutIns->getCuffie()->getSensM()>124)&& layoutIns->getCuffie()->getMicrofono())
                    throw NotValidException("Sensibilità microfono");
                if(layoutIns->getCuffie()->getSensC()<10|| layoutIns->getCuffie()->getSensC()>110)
                    throw NotValidException("Sensibilità cuffie");
                if(layoutIns->getCuffie()->getPeso()==0.00)
                    throw NotValidException("Peso");
                //Creazione nuove accessorio
                daInserire= new Cuffie(nome,marca,prezzo,meseU,annoU,tipologia,tipoInp,
                                       layoutIns->getCuffie()->getMicrofono(), layoutIns->getCuffie()->getRifC(),
                                       layoutIns->getCuffie()->getImpedenza(), layoutIns->getCuffie()->getRifM(),
                                       layoutIns->getCuffie()->getSensM(), layoutIns->getCuffie()->getCancellazRum(),
                                       layoutIns->getCuffie()->getSensC(),layoutIns->getCuffie()->getPeso());
            }
            else if(indexTipo==2){
                //eccezioni da verificare monitor
                tipologia="monitor";
                int ris= layoutIns->getMonitor()->getRisoluzione()->currentIndex();
                //std::cerr<<Ris<<std::endl;
                if(ris==0)
                    throw NotValidException("Risoluzione");
                int rda= layoutIns->getMonitor()->getRappDAsp()->currentIndex();
                if(rda==0)
                    throw NotValidException("Rapporto d'Aspetto");
                if(layoutIns->getMonitor()->getPollici()<8.00 && layoutIns->getMonitor()->getPollici()<50.00)
                    throw NotValidException("Pollici");
                if(layoutIns->getMonitor()->getRefreshRate()<1|| layoutIns->getMonitor()->getRefreshRate()>5)
                    throw NotValidException("Refresh Rate");
                if(layoutIns->getMonitor()->getFrameRate()<30|| layoutIns->getMonitor()->getFrameRate()>240)
                    throw NotValidException("Frame Rate");
                if(layoutIns->getMonitor()->getFreeSync()==true && layoutIns->getMonitor()->getGSync()==true)
                    throw NotValidException("FreeSync o GSync");
                int dr= layoutIns->getMonitor()->getDynamicRange()->currentIndex();
                if(dr==0)
                    throw NotValidException("DynamicRange");

                //Creazione nuove accessorio
                daInserire= new Monitor(nome,marca,prezzo,meseU,annoU,tipologia,tipoInp,
                                        layoutIns->getMonitor()->getRisoluzionetxt(), layoutIns->getMonitor()->getRappDAsptxt(),
                                        layoutIns->getMonitor()->getPollici(), layoutIns->getMonitor()->getRefreshRate(),
                                        layoutIns->getMonitor()->getFrameRate(), layoutIns->getMonitor()->getFreeSync(),
                                        layoutIns->getMonitor()->getGSync(), layoutIns->getMonitor()->getDynamicRangetxt(),
                                        layoutIns->getMonitor()->getCasse());
            }
            else if(indexTipo==3){
                //eccezioni da verificare mouse
                tipologia="mouse";
                if(layoutIns->getMouse()->getDpim()<100|| layoutIns->getMouse()->getDpim()>3500)
                    throw NotValidException("DPI min");
                if(layoutIns->getMouse()->getDpiM()<1000|| layoutIns->getMouse()->getDpiM()>16000)
                    throw NotValidException("DPI Max");
                if(layoutIns->getMouse()->getPollingRate()<50|| layoutIns->getMouse()->getPollingRate()>1000)
                    throw NotValidException("Polling Rate");
                if(layoutIns->getMouse()->getTrackingSpeed()<10|| layoutIns->getMouse()->getTrackingSpeed()>150)
                    throw NotValidException("Tracking Speed");
                int sens= layoutIns->getMouse()->getSensore()->currentIndex();
                if(sens==0)
                    throw NotValidException("Sensore");
                if(layoutIns->getMouse()->getPulsanti()<3|| layoutIns->getMouse()->getPulsanti()>17)
                    throw NotValidException("Pulsanti");
                int erg= layoutIns->getMouse()->getErgonomia()->currentIndex();
                if(erg==0)
                    throw NotValidException("Ergonomia");
                if(layoutIns->getMouse()->getPeso()==0.00)
                    throw NotValidException("Peso");
                //Creazione nuove accessorio
                daInserire= new Mouse(nome,marca,prezzo,meseU,annoU,tipologia,tipoInp,
                                      layoutIns->getMouse()->getDpim(),layoutIns->getMouse()->getDpiM(),
                                      layoutIns->getMouse()->getPollingRate(), layoutIns->getMouse()->getTrackingSpeed(),
                                      layoutIns->getMouse()->getAngleSnapping(), layoutIns->getMouse()->getSensoretxt(),
                                      layoutIns->getMouse()->getPulsanti(), layoutIns->getMouse()->getErgonomiatxt(),
                                      layoutIns->getMouse()->getPeso());
            }
            else if(indexTipo==4){
                //eccezioni da verificare tastiera
                tipologia="tastiera";
                int lay= layoutIns->getTastiera()->getLayout()->currentIndex();
                if(lay==0)
                    throw NotValidException("Layout");
                int conf= layoutIns->getTastiera()->getConfort()->currentIndex();
                if(conf==0)
                    throw NotValidException("Confort");
                if(layoutIns->getTastiera()->getPollingRate()<100|| layoutIns->getTastiera()->getPollingRate()>1000)
                    throw NotValidException("Polling Rate");
                int cat= layoutIns->getTastiera()->getCategoria()->currentIndex();
                if(cat==0)
                    throw NotValidException("Categoria");
                //Creazione nuove accessorio
                daInserire= new Tastiera(nome,marca,prezzo,meseU,annoU,tipologia,tipoInp,
                                         layoutIns->getTastiera()->getRetroIlluminazione(), layoutIns->getTastiera()->getLayouttxt(),
                                         layoutIns->getTastiera()->getConforttxt(), layoutIns->getTastiera()->getPollingRate(),
                                         layoutIns->getTastiera()->getCategoriatxt(), layoutIns->getTastiera()->getTrackPad());
            }
            else if(indexTipo==5){
                tipologia="webcam";
                //eccezioni da verificare webcam
                if(layoutIns->getWebcam()->getAngoloDiVisione()<45|| layoutIns->getWebcam()->getAngoloDiVisione()>100)
                    throw NotValidException("Angolo di Visione");
                if(layoutIns->getWebcam()->getFrameRate()<10|| layoutIns->getWebcam()->getFrameRate()>144)
                    throw NotValidException("Frame Rate");
                int mic= layoutIns->getWebcam()->getMicrofono()->currentIndex();
                if(mic==0)
                    throw NotValidException("Microfono");
                //Creazione nuove accessorio
                daInserire= new Webcam(nome,marca,prezzo,meseU,annoU,tipologia,tipoInp,
                                       layoutIns->getWebcam()->getAngoloDiVisione(), layoutIns->getWebcam()->getZoom(),
                                       layoutIns->getWebcam()->getRotazione(), layoutIns->getWebcam()->getFrameRate(),
                                       layoutIns->getWebcam()->getAutofocus(), layoutIns->getWebcam()->getMicrofonotxt(),
                                       layoutIns->getWebcam()->getLuceIntegrata(), layoutIns->getWebcam()->getRipreseNotturne());
            }

            if(!(daInserire==nullptr)){
                Deepptr<Accessori>input(daInserire);
                unsigned int k= modello->getDataUsed();
                modello->inserimento(input);
                if(modello->getDataUsed()>k){
                    QMessageBox::information(this,"Conferma", "Nuovo accessorio inserito correttamente");
                    slotSaveData();
                    slotVReturnHome();
                    modello->loadFromFile();
                }
            }
        }catch (NotValidException ex ) {
                    layoutIns->showWarning(this, ex.getError());
        }
    }
    else
        QMessageBox::warning(this,"Attenzione!","Nessun file inserito nel programma.\nNon è possibile fare un inserimento.");
}

void MWindow::slotResetElemento()
{
    layoutIns->slotReset();
}

void MWindow::slotMSGBOXAboutDialog()
{
    QMessageBox::about(this, "Contatti","Questa applicazione è stata realizzata per il corso di Programmazione ad Oggetti (P2) da Francesco Gobbo, matricola: 1120713.\n\nLaurea triennale: Informatica, Dipartimento: Matematica. \nUniversità: UNIPD.");
}

void MWindow::slotMSGBOXReportBug()
{
    QMessageBox::about(this, "Report","Per segnalare un bug è pregato di contattare tramite l'email: francesco.gobbo.6@studenti.unipd.it. \nGrazie!");
}

void MWindow::slotShowInserisci() const
{
    home->hide();
    layoutIns->slotReset();
    layoutIns->show();
    layoutVista->hide();
}

void MWindow::inputDatiLista() const
{
    for(auto it=modello->cBegin(); it!=modello->cEnd(); ++it){
        QString s = QString::fromStdString((*it)->getNome());
        layoutVista->aggRiga(s);
     }
    slotShowQualita();
}

void MWindow::slotShowListaRicercaViewTutti() const
{
    layoutVista->getIntro()->setText("Tutti");
    home->hide();
    layoutIns->hide();
    layoutVista->show();

    layoutVista->resetLista();
    modello->resetRicerca();
    inputDatiLista();
}

void MWindow::slotShowListaRicercaViewCuffie() const
{
    layoutVista->getIntro()->setText("Cuffie");
    home->hide();
    layoutIns->hide();
    layoutVista->show();

    layoutVista->resetLista();
    modello->resetRicerca();
    modello->filtroTipologia("cuffie");
    inputDatiLista();
}

void MWindow::slotShowListaRicercaViewMonitor() const
{
    layoutVista->getIntro()->setText("Monitor");
    home->hide();
    layoutIns->hide();
    layoutVista->show();

    layoutVista->resetLista();
    modello->resetRicerca();
    modello->filtroTipologia("monitor");
    inputDatiLista();
}

void MWindow::slotShowListaRicercaViewMouse() const
{
    layoutVista->getIntro()->setText("Mouse");
    home->hide();
    layoutIns->hide();
    layoutVista->show();

    layoutVista->resetLista();
    modello->resetRicerca();
    modello->filtroTipologia("mouse");
    inputDatiLista();
}

void MWindow::slotShowListaRicercaViewTastiera() const
{
    layoutVista->getIntro()->setText("Tastiera");
    home->hide();
    layoutIns->hide();
    layoutVista->show();

    layoutVista->resetLista();
    modello->resetRicerca();
    modello->filtroTipologia("tastiera");
    inputDatiLista();
}

void MWindow::slotShowListaRicercaViewWebcam() const
{
    layoutVista->getIntro()->setText("Webcam");
    home->hide();
    layoutIns->hide();
    layoutVista->show();

    layoutVista->resetLista();
    modello->resetRicerca();
    modello->filtroTipologia("webcam");
    inputDatiLista();
}

void MWindow::slotShowQualita() const
{
    layoutVista->getNAccEcc()->setText(QString::number(modello->calcolaValori5()));
    layoutVista->getNAccOtt()->setText(QString::number(modello->calcolaValori4()));
    layoutVista->getNAccBuo()->setText(QString::number(modello->calcolaValori3()));
    layoutVista->getNAccSuf()->setText(QString::number(modello->calcolaValori2()));
    layoutVista->getNAccPes()->setText(QString::number(modello->calcolaValori1()));
}

void MWindow::slotRicercaAcc()
{
    if(modello->getPathSize()>0){
        if(!modello->isDataEmpty()){
            layoutVista->resetLista();
            modello->resetRicerca();
            string nome= layoutVista->getNome();
            if(nome!=""){
                modello->filtroNome(nome);
            }
            string marca= layoutVista->getMarca();
            if(marca!=""){
                modello->filtroMarca(marca);
            }

            double prezzo_m= layoutVista->getPrezzoMin();
            if(prezzo_m!=0.00){
                modello->filtroPrezzoMin(prezzo_m);
            }
            double prezzo_M= layoutVista->getPrezzoMax();
            if(prezzo_M!=0.00){
                if(prezzo_M<prezzo_m){
                    QMessageBox error (QMessageBox::Warning,"Attenzione","Devi correggere il campo di Ricerca: \nPrezzo maggiore non valido");
                    error.exec();
                }
                else
                    modello->filtroPrezzoMag(prezzo_M);
            }
            int indexTipo = layoutVista->getTipo();
            if(indexTipo==0){
                layoutVista->getIntro()->setText("Tutti");
                inputDatiLista();
            }
            if(indexTipo==1){
                modello->filtroTipologia("cuffie");
                layoutVista->getIntro()->setText("Cuffie");
                inputDatiLista();
            }
            if(indexTipo==2){
                modello->filtroTipologia("monitor");
                layoutVista->getIntro()->setText("Monitor");
                inputDatiLista();
            }
            if(indexTipo==3){
                modello->filtroTipologia("mouse");
                layoutVista->getIntro()->setText("Mouse");
                inputDatiLista();
            }
            if(indexTipo==4){
                modello->filtroTipologia("tastiera");
                layoutVista->getIntro()->setText("Tastiera");
                inputDatiLista();
            }
            if(indexTipo==5){
                modello->filtroTipologia("webcam");
                layoutVista->getIntro()->setText("Webcam");
                inputDatiLista();
            }
        }
        else
            QMessageBox::warning(this,"Attenzione!","Il file inserito nel programma è vuoto.\nNon è possibile fare una ricerca.");
    }
    else
        QMessageBox::warning(this,"Attenzione!","Nessun file inserito nel programma.\nNon è possibile fare una ricerca.");
}

void MWindow::slotResetDataRicerca() const
{
    string s = layoutVista->getIntro()->text().toStdString();
    if(s=="Tutti"){
        layoutVista->azzeraRicerca();
        slotShowListaRicercaViewTutti();
    }
    if(s=="Cuffie")
    {
        layoutVista->azzeraRicerca();
        slotShowListaRicercaViewCuffie();
    }
    if(s=="Monitor")
    {
        layoutVista->azzeraRicerca();
        slotShowListaRicercaViewMonitor();
    }
    if(s=="Mouse")
    {
        layoutVista->azzeraRicerca();
        slotShowListaRicercaViewMouse();
    }
    if(s=="Tastiera")
    {
        layoutVista->azzeraRicerca();
        slotShowListaRicercaViewTastiera();
    }
    if(s=="Webcam")
    {
        layoutVista->azzeraRicerca();
        slotShowListaRicercaViewWebcam();
    }

}

void MWindow::slotShowData(QListWidgetItem* it) const
{
    it->text();
    Container<Deepptr<Accessori>>::ConstIter i=modello->cBegin();
    while(!((*i)->getNome()==(it->text().toStdString())) && i!=modello->cEnd()){
        ++i;
    }
    layoutVistaDati->resetVistaDati();

    layoutVistaDati->getDatoNome()->setText(QString::fromStdString((*i)->getNome()));
    layoutVistaDati->getDatoMarca()->setText(QString::fromStdString((*i)->getMarca()));
    layoutVistaDati->getDatoTipo()->setText(QString::fromStdString((*i)->getTipologia()));
    layoutVistaDati->getDatoTipologiaM()->setText(QString::fromStdString((*i)->getTipologia()));
    layoutVistaDati->getDatoPrezzo()->setText(QString::number((*i)->getCosto()));
    layoutVistaDati->getDatoMeseU()->setText(QString::number((*i)->getMeseUscita()));
    layoutVistaDati->getDatoAnnoU()->setText(QString::number((*i)->getAnnoUscita()));
    layoutVistaDati->getDatoTipInp()->setText(QString::fromStdString((*i)->getTipoInput()));
    layoutVistaDati->getDatoQualita()->setText(QString::fromStdString((*i)->qualita()));
    layoutVistaDati->getDatoRappQualitaPrezzo()->setText(QString::fromStdString((*i)->rapportoQualitaPrezzo()));
    layoutVistaDati->getDatoAmmortamento()->setText(QString::number((*i)->valoreAttualeUsato()));

    if(layoutVistaDati->getDatoTipo()->text().toStdString()=="cuffie"){
        Deepptr<Accessori> k= const_cast<Deepptr<Accessori>&>(*i);
        Cuffie j= dynamic_cast<Cuffie&>(*k);
        layoutVistaDati->getDatiCuffie()->getDatoMic()->setText((j).getMicrofono()?"Si":"No");
        layoutVistaDati->getDatiCuffie()->getDatoRIFC()->setText(QString::number((j).getRispInFreqC()));
        layoutVistaDati->getDatiCuffie()->getDatoImp()->setText(QString::number((j).getImpedenza()));
        layoutVistaDati->getDatiCuffie()->getDatoRIFM()->setText(QString::number((j).getRispInFreqMic()));
        layoutVistaDati->getDatiCuffie()->getDatoSM()->setText(QString::number((j).getSensMic()));
        layoutVistaDati->getDatiCuffie()->getDatoSC()->setText(QString::number((j).getSensCuff()));
        layoutVistaDati->getDatiCuffie()->getDatoCR()->setText((j).getCancRum()?"Si":"No");
        layoutVistaDati->getDatiCuffie()->getDatoP()->setText(QString::number((j).getPeso()));
        layoutVistaDati->showDatiSpecifici();
    }
    if(layoutVistaDati->getDatoTipo()->text().toStdString()=="monitor"){
        Deepptr<Accessori> k= const_cast<Deepptr<Accessori>&>(*i);
        Monitor j= dynamic_cast<Monitor&>(*k);
        layoutVistaDati->getDatiMonitor()->getDatoRis()->setText(QString::fromStdString((j).getRisoluzione()));
        layoutVistaDati->getDatiMonitor()->getDatoRDA()->setText(QString::fromStdString((j).getRapportoDAspetto()));
        layoutVistaDati->getDatiMonitor()->getDatoPol()->setText(QString::number((j).getPollici()));
        layoutVistaDati->getDatiMonitor()->getDatoRR()->setText(QString::number((j).getRefreshRate()));
        layoutVistaDati->getDatiMonitor()->getDatoFR()->setText(QString::number((j).getFrameRate()));
        layoutVistaDati->getDatiMonitor()->getDatoFS()->setText((j).getFreeSync()?"Si":"No");
        layoutVistaDati->getDatiMonitor()->getDatoGS()->setText((j).getGSync()?"Si":"No");
        layoutVistaDati->getDatiMonitor()->getDatoDR()->setText(QString::fromStdString((j).getDynamicRange()));
        layoutVistaDati->getDatiMonitor()->getDatoCas()->setText((j).getCasse()?"Si":"No");
        layoutVistaDati->showDatiSpecifici();
    }
    if(layoutVistaDati->getDatoTipo()->text().toStdString()=="mouse"){
        Deepptr<Accessori> k= const_cast<Deepptr<Accessori>&>(*i);
        Mouse j= dynamic_cast<Mouse&>(*k);
        layoutVistaDati->getDatiMouse()->getDatoDPIMin()->setText(QString::number((j).getDPImin()));
        layoutVistaDati->getDatiMouse()->getDatoDPIMax()->setText(QString::number((j).getDPImax()));
        layoutVistaDati->getDatiMouse()->getDatoPR()->setText(QString::number((j).getPollingRate()));
        layoutVistaDati->getDatiMouse()->getDatoTS()->setText(QString::number((j).getTrackingSpeed()));
        layoutVistaDati->getDatiMouse()->getDatoAS()->setText((j).getAngleSnapping()?"Si":"No");
        layoutVistaDati->getDatiMouse()->getDatoSens()->setText(QString::fromStdString((j).getSensore()));
        layoutVistaDati->getDatiMouse()->getDatoPul()->setText(QString::number((j).getPulsanti()));
        layoutVistaDati->getDatiMouse()->getDatoErg()->setText(QString::fromStdString((j).getErgonomia()));
        layoutVistaDati->getDatiMouse()->getDatoP()->setText(QString::number((j).getPeso()));
        layoutVistaDati->showDatiSpecifici();
    }
    if(layoutVistaDati->getDatoTipo()->text().toStdString()=="tastiera"){
        Deepptr<Accessori> k= const_cast<Deepptr<Accessori>&>(*i);
        Tastiera j= dynamic_cast<Tastiera&>(*k);
        layoutVistaDati->getDatiTastiera()->getDatoRI()->setText((j).getRetroIlluminazione()?"Si":"No");
        layoutVistaDati->getDatiTastiera()->getDatoLay()->setText(QString::fromStdString((j).getLayout()));
        layoutVistaDati->getDatiTastiera()->getDatoConf()->setText(QString::fromStdString((j).getConfort()));
        layoutVistaDati->getDatiTastiera()->getDatoPR()->setText(QString::number((j).getPollingRate()));
        layoutVistaDati->getDatiTastiera()->getDatoCat()->setText(QString::fromStdString((j).getCategoria()));
        layoutVistaDati->getDatiTastiera()->getDatoTP()->setText((j).getTrackPad()?"Si":"No");
        layoutVistaDati->showDatiSpecifici();
    }
    if(layoutVistaDati->getDatoTipo()->text().toStdString()=="webcam"){
        Deepptr<Accessori> k= const_cast<Deepptr<Accessori>&>(*i);
        Webcam j= dynamic_cast<Webcam&>(*k);
        layoutVistaDati->getDatiWebcam()->getDatoADV()->setText(QString::number((j).getAngoloDiVisione()));
        layoutVistaDati->getDatiWebcam()->getDatoZ()->setText((j).getZoom()?"Si":"No");
        layoutVistaDati->getDatiWebcam()->getDatoR()->setText((j).getRotazione()?"Si":"No");
        layoutVistaDati->getDatiWebcam()->getDatoFR()->setText(QString::number((j).getFrameRate()));
        layoutVistaDati->getDatiWebcam()->getDatoAf()->setText((j).getAutofocus()?"Si":"No");
        layoutVistaDati->getDatiWebcam()->getDatoMic()->setText(QString::fromStdString((j).getMicrofono()));
        layoutVistaDati->getDatiWebcam()->getDatoLI()->setText((j).getLuceIntegrata()?"Si":"No");
        layoutVistaDati->getDatiWebcam()->getDatoRN()->setText((j).getRipreseNotturne()?"Si":"No");
        layoutVistaDati->showDatiSpecifici();
    }
    layoutVistaDati->setWindowModality(Qt::ApplicationModal);
    layoutVistaDati->show();
}

void MWindow::modificaDati()
{
    try{

        std::string nome= layoutVistaDati->getModifNome();

        std::string marca= layoutVistaDati->getModifMarca();

        int indexTipo;
        QString t= layoutVistaDati->getDatoTipo()->text();
        std::string tipo= t.toStdString();
        if(tipo=="cuffie"){
            indexTipo =1;
        }
        if(tipo=="monitor"){
            indexTipo =2;
        }
        if(tipo=="mouse"){
            indexTipo =3;
        }
        if(tipo=="tastiera"){
            indexTipo =4;
        }
        if(tipo=="webcam"){
            indexTipo =5;
        }

        double prezzo= layoutVistaDati->getModifPrezzo();
        if(prezzo<0.00)
            throw NotValidException("Devi correggere il campo: Prezzo");

        unsigned int meseU= layoutVistaDati->getModifMese();

        unsigned int annoU= layoutVistaDati->getModifAnno();
        if((annoU<2000 || annoU>2019)&&annoU!=0)
            throw NotValidException("Devi correggere il campo: Anno");

        std::string tipoInp= layoutVistaDati->getModifTipoInput();

        if(indexTipo==1){
            //eccezioni da verificare cuffie
            if(layoutVistaDati->getDatiCuffie()->getModifRifC()!=0 &&( layoutVistaDati->getDatiCuffie()->getModifRifC()<100 || layoutVistaDati->getDatiCuffie()->getModifRifC()>50000))
                throw NotValidException("Devi correggere il campo: Risposta in frequenza cuffie");
            if(layoutVistaDati->getDatiCuffie()->getModifImpedenza()!=0 && layoutVistaDati->getDatiCuffie()->getModifImpedenza()>250)
                throw NotValidException("Devi correggere il campo: Impedenza");
            if(!layoutVistaDati->getDatiCuffie()->getModifMicrofono()){
                if(layoutVistaDati->getDatiCuffie()->getModifRifM()!=0)
                    throw NotValidException("Devi correggere il campo: Risposta in frequenza microfono o Microfono");
                if(layoutVistaDati->getDatiCuffie()->getModifSensM()!=0)
                    throw NotValidException("Devi correggere il campo: Sensibilità microfono o Microfono");
                layoutVistaDati->getDatiCuffie()->modifyNoMic();
            }
            else if(layoutVistaDati->getDatiCuffie()->getModifMicrofono()){
                if(layoutVistaDati->getDatiCuffie()->getModifRifM()==0 &&(layoutVistaDati->getDatiCuffie()->getModifRifM()<20 || layoutVistaDati->getDatiCuffie()->getModifRifM()>20000))
                    throw NotValidException("Devi correggere il campo: Risposta in frequenza microfono");
                if(layoutVistaDati->getDatiCuffie()->getModifSensM()==0 &&(layoutVistaDati->getDatiCuffie()->getModifSensM()<40 || layoutVistaDati->getDatiCuffie()->getModifSensM()>124))
                    throw NotValidException("Devi correggere il campo: Sensibilità microfono");
            }

            if(layoutVistaDati->getDatiCuffie()->getModifSensC()!=0 &&(layoutVistaDati->getDatiCuffie()->getModifSensC()<10|| layoutVistaDati->getDatiCuffie()->getModifSensC()>110))
                throw NotValidException("Devi correggere il campo: Sensibilità cuffie");
            if(!(layoutVistaDati->modifySomething()) && !(layoutVistaDati->getDatiCuffie()->modifySomething())){
                throw NotValidException("Bisogna modificare almeno un dato");
            }
            //Modifica dati accessorio cuffie
            unsigned int index=0;
            Container<Deepptr<Accessori>>::ConstIter i=modello->cBegin();
            while(!((*i)->getNome()==(layoutVistaDati->getDatoNome()->text().toStdString())) && i!=modello->cEnd()){
                ++i;++index;
            }
            modello->modificaCuffie(index,nome,marca,prezzo,meseU,annoU,tipoInp,
                                    layoutVistaDati->getDatiCuffie()->getModifMicrofono(), layoutVistaDati->getDatiCuffie()->getModifRifC(),
                                    layoutVistaDati->getDatiCuffie()->getModifImpedenza(), layoutVistaDati->getDatiCuffie()->getModifRifM(),
                                    layoutVistaDati->getDatiCuffie()->getModifSensM(), layoutVistaDati->getDatiCuffie()->getModifCancellazRum(),
                                    layoutVistaDati->getDatiCuffie()->getModifSensC(), layoutVistaDati->getDatiCuffie()->getModifPeso());

        }
        else if(indexTipo==2){
            //eccezioni da verificare monitor
            if(layoutVistaDati->getDatiMonitor()->getModifPollici()!=0 &&(layoutVistaDati->getDatiMonitor()->getModifPollici()<8.00 && layoutVistaDati->getDatiMonitor()->getModifPollici()<50.00))
                throw NotValidException("Devi correggere il campo: Pollici");
            if(layoutVistaDati->getDatiMonitor()->getModifRefreshRate() &&(layoutVistaDati->getDatiMonitor()->getModifRefreshRate()<1|| layoutVistaDati->getDatiMonitor()->getModifRefreshRate()>5))
                throw NotValidException("Devi correggere il campo: Refresh Rate");
            if(layoutVistaDati->getDatiMonitor()->getModifFrameRate()!=0 &&(layoutVistaDati->getDatiMonitor()->getModifFrameRate()<30|| layoutVistaDati->getDatiMonitor()->getModifFrameRate()>240))
                throw NotValidException("Devi correggere il campo: Frame Rate");
            if(layoutVistaDati->getDatiMonitor()->getModifGSync()==true && layoutVistaDati->getDatiMonitor()->getModifFreeSync()==true)
                throw NotValidException("Devi correggere il campo: FreeSync o GSync");
            if(!(layoutVistaDati->modifySomething()) && !(layoutVistaDati->getDatiMonitor()->modifySomething()))
                throw NotValidException("Bisogna modificare almeno un dato");
            //Modifica dati accessorio monitor
            unsigned int index=0;
            Container<Deepptr<Accessori>>::ConstIter i=modello->cBegin();
            while(!((*i)->getNome()==(layoutVistaDati->getDatoNome()->text().toStdString())) && i!=modello->cEnd()){
                ++i;++index;
            }
            modello->modificaMonitor(index,nome,marca,prezzo,meseU,annoU,tipoInp,
                                    layoutVistaDati->getDatiMonitor()->getModifRisoluzione(), layoutVistaDati->getDatiMonitor()->getModifRappDAsp(),
                                    layoutVistaDati->getDatiMonitor()->getModifPollici(), layoutVistaDati->getDatiMonitor()->getModifRefreshRate(),
                                    layoutVistaDati->getDatiMonitor()->getModifFrameRate(), layoutVistaDati->getDatiMonitor()->getModifFreeSync(),
                                    layoutVistaDati->getDatiMonitor()->getModifGSync(), layoutVistaDati->getDatiMonitor()->getModifDynamicRange(),
                                    layoutVistaDati->getDatiMonitor()->getModifCasse());
        }
        else if(indexTipo==3){
            //eccezioni da verificare mouse
            if(layoutVistaDati->getDatiMouse()->getModifDpim()!=0 &&(layoutVistaDati->getDatiMouse()->getModifDpim()<100|| layoutVistaDati->getDatiMouse()->getModifDpim()>3500))
                throw NotValidException("Devi correggere il campo: DPI min");
            if(layoutVistaDati->getDatiMouse()->getModifDpiM()!=0 &&(layoutVistaDati->getDatiMouse()->getModifDpiM()!=0 &&(layoutVistaDati->getDatiMouse()->getModifDpiM()<1000|| layoutVistaDati->getDatiMouse()->getModifDpiM()>16000)))
                throw NotValidException("Devi correggere il campo: DPI Max");
            if(layoutVistaDati->getDatiMouse()->getModifPollingRate()!=0 &&(layoutVistaDati->getDatiMouse()->getModifPollingRate()<50|| layoutVistaDati->getDatiMouse()->getModifPollingRate()>1000))
                throw NotValidException("Devi correggere il campo: Polling Rate");
            if(layoutVistaDati->getDatiMouse()->getModifTrackingSpeed()!=0 && (layoutVistaDati->getDatiMouse()->getModifTrackingSpeed()<10|| layoutVistaDati->getDatiMouse()->getModifTrackingSpeed()>150))
                throw NotValidException("Devi correggere il campo: Tracking Speed");
            if(layoutVistaDati->getDatiMouse()->getModifPulsanti()!=0 &&(layoutVistaDati->getDatiMouse()->getModifPulsanti()<3|| layoutVistaDati->getDatiMouse()->getModifPulsanti()>17))
                throw NotValidException("Devi correggere il campo: Pulsanti");
            if(!(layoutVistaDati->modifySomething()) && !(layoutVistaDati->getDatiMouse()->modifySomething()))
                throw NotValidException("Bisogna modificare almeno un dato");
            //Modifica dati accessorio mouse
            unsigned int index=0;
            Container<Deepptr<Accessori>>::ConstIter i=modello->cBegin();
            while(!((*i)->getNome()==(layoutVistaDati->getDatoNome()->text().toStdString())) && i!=modello->cEnd()){
                ++i;++index;
            }
            modello->modificaMouse(index,nome,marca,prezzo,meseU,annoU,tipoInp,
                                   layoutVistaDati->getDatiMouse()->getModifDpim(), layoutVistaDati->getDatiMouse()->getModifDpiM(),
                                   layoutVistaDati->getDatiMouse()->getModifPollingRate(), layoutVistaDati->getDatiMouse()->getModifTrackingSpeed(),
                                   layoutVistaDati->getDatiMouse()->getModifAngleSnapping(), layoutVistaDati->getDatiMouse()->getModifSensore(),
                                   layoutVistaDati->getDatiMouse()->getModifPulsanti(), layoutVistaDati->getDatiMouse()->getModifErgonomia(),
                                   layoutVistaDati->getDatiMouse()->getModifPeso());

        }
        else if(indexTipo==4){
            //eccezioni da verificare tastiera
            if(layoutVistaDati->getDatiTastiera()->getModifPollingRate()!=0 &&(layoutVistaDati->getDatiTastiera()->getModifPollingRate()<100|| layoutVistaDati->getDatiTastiera()->getModifPollingRate()>1000))
                throw NotValidException("Devi correggere il campo: Polling Rate");
            if(!(layoutVistaDati->modifySomething()) && !(layoutVistaDati->getDatiTastiera()->modifySomething()))
                throw NotValidException("Bisogna modificare almeno un dato");
            //Modifica dati accessorio tastiera
            unsigned int index=0;
            Container<Deepptr<Accessori>>::ConstIter i=modello->cBegin();
            while(!((*i)->getNome()==(layoutVistaDati->getDatoNome()->text().toStdString())) && i!=modello->cEnd()){
                ++i;++index;
            }
            modello->modificaTastiera(index,nome,marca,prezzo,meseU,annoU,tipoInp,
                                      layoutVistaDati->getDatiTastiera()->getModifRetroIlluminazione(), layoutVistaDati->getDatiTastiera()->getModifLayout(),
                                      layoutVistaDati->getDatiTastiera()->getModifConfort(), layoutVistaDati->getDatiTastiera()->getModifPollingRate(),
                                      layoutVistaDati->getDatiTastiera()->getModifCategoria(), layoutVistaDati->getDatiTastiera()->getModifTrackPad());
        }
        else if(indexTipo==5){
            //eccezioni da verificare webcam
            if(layoutVistaDati->getDatiWebcam()->getModifAngoloDiVisione() &&(layoutVistaDati->getDatiWebcam()->getModifAngoloDiVisione()<45|| layoutVistaDati->getDatiWebcam()->getModifAngoloDiVisione()>100))
                throw NotValidException("Devi correggere il campo: Angolo di Visione");
            if(layoutVistaDati->getDatiWebcam()->getModifFrameRate()!=0 && (layoutVistaDati->getDatiWebcam()->getModifFrameRate()<10|| layoutVistaDati->getDatiWebcam()->getModifFrameRate()>144))
                throw NotValidException("Devi correggere il campo: Frame Rate");
            if(!(layoutVistaDati->modifySomething()) && !(layoutVistaDati->getDatiWebcam()->modifySomething()))
                throw NotValidException("Bisogna modificare almeno un dato");
            //Modifica dati accessorio webcam
            unsigned int index=0;
            Container<Deepptr<Accessori>>::ConstIter i=modello->cBegin();
            while(!((*i)->getNome()==(layoutVistaDati->getDatoNome()->text().toStdString())) && i!=modello->cEnd()){
                ++i;++index;
            }
            modello->modificaWebcam(index,nome,marca,prezzo,meseU,annoU,tipoInp,
                                    layoutVistaDati->getDatiWebcam()->getModifAngoloDiVisione(), layoutVistaDati->getDatiWebcam()->getModifZoom(),
                                    layoutVistaDati->getDatiWebcam()->getModifRotazione(), layoutVistaDati->getDatiWebcam()->getModifFrameRate(),
                                    layoutVistaDati->getDatiWebcam()->getModifAutofocus(), layoutVistaDati->getDatiWebcam()->getModifMicrofono(),
                                    layoutVistaDati->getDatiWebcam()->getModifLuceIntegrata(), layoutVistaDati->getDatiWebcam()->getModifRipreseNotturne());
        }

        QMessageBox::information(this,"Conferma", "Modifiche effettuate correttamente");
        modello->setDataSaved(false);
        layoutVistaDati->showDati();
        layoutVistaDati->close();
        slotVerificaDiModifica();
    }catch (NotValidException ex ) {
                layoutVistaDati->showWarning(this, ex.getError());
    }
}

void MWindow::slotInReturnHome() const
{
    layoutIns->slotReset();
    layoutIns->hide();
    layoutVista->hide();
    home->show();
}

void MWindow::slotVReturnHome() const
{
    layoutIns->hide();
    layoutVista->hide();
    home->show();
}

void MWindow::slotClose()
{
    if(!modello->isDataEmpty()){
        if(modello->getIsDataSaved()){
            slotSaveData();
            close();
        }
        else{
            QMessageBox::StandardButton resBtn = QMessageBox::information(this, tr("Attenzione"),tr("Bisogna salvare i dati prima di uscire."),QMessageBox::Cancel | QMessageBox::Yes);
            if(resBtn==QMessageBox::Yes){
                    slotSaveData();
                close();
            }
        }

    }
}
