#include "model.h"

#include <QSaveFile>
#include <QXmlStreamReader>
#include <QFile>
#include <QMessageBox>

#include<Contenitore/AccessoriPc/cuffie.h>
#include<Contenitore/AccessoriPc/monitor.h>
#include<Contenitore/AccessoriPc/mouse.h>
#include<Contenitore/AccessoriPc/tastiera.h>
#include<Contenitore/AccessoriPc/webcam.h>
#include<SL/xmlio.h>
#include<QDebug>

#include<iostream>

void Model::saveToFile()
{
    XmlIO xmlio(QString::fromStdString(path));
    xmlio.write(*goods);
}

void Model::loadFromFile()
{
    XmlIO xmlio(QString::fromStdString(path));
    *goods= xmlio.read();
    resetRicerca();
    isDataSaved=true;
}

void Model::setNewPath(std::string s)
{
    path= s;
    delete goods;
    isDataSaved=false;
    goods = new Container<Deepptr<Accessori>>();
}

bool Model::getIsDataSaved() const
{
    return isDataSaved;
}

void Model::setDataSaved(bool nDS)
{
    isDataSaved=nDS;
}

void Model::filtroTipologia(string tipo) const
{
    for(auto it=cBegin(); it!=cEnd(); ++it){
        if(tipo != (*it)->getTipologia()){
            listSearch->pop(*it);
            --it;
        }
    }
}

void Model::filtroNome(string nome) const
{
    for(auto it=listSearch->cbegin(); it!=listSearch->cend(); ++it){
        if(nome != (*it)->getNome()){
            listSearch->pop(*it);
            --it;
        }
    }
}

void Model::filtroMarca(string marca) const
{
    for(auto it=cBegin(); it!=cEnd(); ++it){
        if(marca != (*it)->getMarca()){
            listSearch->pop(*it);
            --it;
        }
    }
}

void Model::filtroPrezzoMin(double prezzo) const
{
    for(auto it=cBegin(); it!=cEnd(); ++it){
        if(prezzo < (*it)->getCosto()){
            listSearch->pop(*it);
            --it;
        }
    }
}

void Model::filtroPrezzoMag(double prezzo) const
{
    for(auto it=cBegin(); it!=cEnd(); ++it){
        if(prezzo > (*it)->getCosto()){
            listSearch->pop(*it);
            --it;
        }
    }
}

void Model::resetRicerca() const
{
    if(!(listSearch == goods))
        *listSearch = *goods;
}

Model::Model(string p):
    goods(new Container<Deepptr<Accessori>>()),
    listSearch(new Container<Deepptr<Accessori>>()),
    path(p),
    isDataSaved(true)
{}

Model::~Model(){
    for(unsigned int i=0; i<goods->capacity(); i++){
        delete & goods[i];
    }
    delete &listSearch;
}

int Model::getPathSize() const
{
    return path.size();
}

void Model::inserimento(Deepptr<Accessori>newa)
{
    Container<Deepptr<Accessori>>::ConstIter it = goods->cbegin();
    bool found=false;
    for( ; it!=goods->cend() && !found; ++it){
         if((*it)->getNome()==newa->getNome())
             found=true;
    }
    if(!found){
        goods->push_back(newa);
        isDataSaved = false;
    }
    else{//da sistemare
        QMessageBox errorInput;
        errorInput.setWindowTitle("Inserimento fallito");
        errorInput.setText("Oggetto gia' presente nel database");
        errorInput.exec();
    }
}

unsigned int Model::getDataUsed() const
{
    return goods->containerUsed();
}

unsigned int Model::getDataSize() const
{
    return goods->capacity();
}

void Model::eliminazione(unsigned int index)
{
    isDataSaved=false;
    eliminazione(listSearch->at(index));
    listSearch->pop(index);
}

void Model::eliminazione(Deepptr<Accessori> it)
{
    isDataSaved=false;
    goods->pop(it);
}

bool Model::isDataEmpty() const
{
    return goods->empty();
}

void Model::clear()
{
    isDataSaved=false;
    goods->clear();
    listSearch->clear();
}

void Model::modificaCuffie(unsigned int index,
                           string nome, string marca , double costo, unsigned int meseUscita, unsigned int annoUscita, string tipoInput,
                           bool microfono, unsigned int rispostaInFreqC, unsigned int impedenza, unsigned int rispostaInFreqM, unsigned int sensM, bool cancRumore, unsigned int sensC, double peso)
{
    Deepptr<Accessori> newa= goods->at(index);
    std::string type=newa->getTipologia();
    if(type=="cuffie"){
        Accessori* datiaggiornati;
        Cuffie* p = static_cast<Cuffie*>(newa->clone());

        p->changeNome(nome);
        p->changeMarca(marca);
        p->changeCosto(costo);
        p->changeMeseUscita(meseUscita);
        p->changeAnnoUscita(annoUscita);
        p->changeTipoInput(tipoInput);
        p->changeMicrofono(microfono);
        p->changeRispInFreqC(rispostaInFreqC);
        p->changeImpedenza(impedenza);
        p->changeRispInFreqMic(rispostaInFreqM);
        p->changeSensMic(sensM);
        p->changeCancRum(cancRumore);
        p->changeSensCuff(sensC);
        p->changePeso(peso);
        datiaggiornati=p->clone();
        Deepptr<Accessori>input(datiaggiornati);
        eliminazione(newa);
        inserimento(input);
    }
    isDataSaved=false;
}

void Model::modificaMonitor(unsigned int index,
                           string nome, string marca , double costo, unsigned int meseUscita, unsigned int annoUscita, string tipoInput,
                           string risoluzione, string rapportoDAspetto, double pollici, unsigned int refreshRate, unsigned int frameRate, bool freeSync, bool gSync, string dynamicRange, bool casse)
{
    Deepptr<Accessori> newa= goods->at(index);
    std::string type=newa->getTipologia();
    if(type=="monitor"){
        Accessori* datiaggiornati;
        Monitor* p = static_cast<Monitor*>(newa->clone());
        p->changeNome(nome);
        p->changeMarca(marca);
        p->changeCosto(costo);
        p->changeMeseUscita(meseUscita);
        p->changeAnnoUscita(annoUscita);
        p->changeTipoInput(tipoInput);
        p->changeRisoluzione(risoluzione);
        p->changeRapportoDAspetto(rapportoDAspetto);
        p->changePollici(pollici);
        p->changeRefreshRate(refreshRate);
        p->changeFrameRate(frameRate);
        p->changeFreeSync(freeSync);
        p->changeGSync(gSync);
        p->changeDynamicRange(dynamicRange);
        p->changeCasse(casse);
        datiaggiornati=p->clone();
        Deepptr<Accessori>input(datiaggiornati);
        eliminazione(newa);
        inserimento(input);
    }
    isDataSaved=false;
}

void Model::modificaMouse(unsigned int index,
                           string nome, string marca , double costo, unsigned int meseUscita, unsigned int annoUscita, string tipoInput,
                           unsigned int dpimin, unsigned int dpimax, unsigned int pollingRate, unsigned int trackingSpeed, bool angleSnapping, string sens, unsigned int pulsanti, string ergonomia, double peso)
{
    Deepptr<Accessori> newa= goods->at(index);
    std::string type=newa->getTipologia();
    if(type=="mouse"){
        Accessori* datiaggiornati;
        Mouse* p = static_cast<Mouse*>(newa->clone());
        p->changeNome(nome);
        p->changeMarca(marca);
        p->changeCosto(costo);
        p->changeMeseUscita(meseUscita);
        p->changeAnnoUscita(annoUscita);
        p->changeTipoInput(tipoInput);
        p->changeDPImin(dpimin);
        p->changeDPImax(dpimax);
        p->changePollingRate(pollingRate);
        p->changeTrackingSpeed(trackingSpeed);
        p->changeAngleSnapping(angleSnapping);
        p->changeSensore(sens);
        p->changePulsanti(pulsanti);
        p->changeErgonomia(ergonomia);
        p->changePeso(peso);
        datiaggiornati=p->clone();
        Deepptr<Accessori>input(datiaggiornati);
        eliminazione(newa);
        inserimento(input);
    }
    isDataSaved=false;
}

void Model::modificaTastiera(unsigned int index,
                           string nome, string marca , double costo, unsigned int meseUscita, unsigned int annoUscita, string tipoInput,
                           bool retroIllum, string layout, string confort, unsigned int pollingRate, string categoria, bool trackPad)
{
    Deepptr<Accessori> newa= goods->at(index);
    std::string type=newa->getTipologia();
    if(type=="tastiera"){
        Accessori* datiaggiornati;
        Tastiera* p = static_cast<Tastiera*>(newa->clone());
        p->changeNome(nome);
        p->changeMarca(marca);
        p->changeCosto(costo);
        p->changeMeseUscita(meseUscita);
        p->changeAnnoUscita(annoUscita);
        p->changeTipoInput(tipoInput);
        p->changeRetroIlluminazione(retroIllum);
        p->changeLayout(layout);
        p->changeConfort(confort);
        p->changePollingRate(pollingRate);
        p->changeCategoria(categoria);
        p->changeTrackPad(trackPad);
        datiaggiornati=p->clone();
        Deepptr<Accessori>input(datiaggiornati);
        eliminazione(newa);
        inserimento(input);
    }
    isDataSaved=false;
}

void Model::modificaWebcam(unsigned int index,
                     string nome, string marca , double costo, unsigned int meseUscita, unsigned int annoUscita, string tipoInput,
                     unsigned int angoloDiVisione, bool zoom, bool rotazione, unsigned int frameRate, bool autofocus, string microfono, bool luceInt, bool ripreseN)
{
    Deepptr<Accessori> newa= goods->at(index);
    std::string type=newa->getTipologia();
    if(type=="webcam"){
        Accessori* datiaggiornati;
        Webcam* p = static_cast<Webcam*>(newa->clone());
        p->changeNome(nome);
        p->changeMarca(marca);
        p->changeCosto(costo);
        p->changeMeseUscita(meseUscita);
        p->changeAnnoUscita(annoUscita);
        p->changeTipoInput(tipoInput);
        p->changeAngoloDiVisione(angoloDiVisione);
        p->changeZoom(zoom);
        p->changeRotazione(rotazione);
        p->changeFrameRate(frameRate);
        p->changeAutofocus(autofocus);
        p->changeMicrofono(microfono);
        p->changeLuceIntegrata(luceInt);
        p->changeRipreseNotturne(ripreseN);
        datiaggiornati=p->clone();
        Deepptr<Accessori>input(datiaggiornati);
        eliminazione(newa);
        inserimento(input);
    }
    isDataSaved=false;
}

unsigned int Model::calcolaValori5() const{
    unsigned int k=0;
    for(auto it=cBegin(); it!=cEnd(); ++it){
        if((*it)->qualita()=="Eccezionale"){
            k++;
        }
    }
    return k;
}
unsigned int Model::calcolaValori4() const{
    unsigned int k=0;
    for(auto it=cBegin(); it!=cEnd(); ++it){
        if((*it)->qualita()=="Ottima"){
            k++;
        }
    }
    return k;
}
unsigned int Model::calcolaValori3() const{
    unsigned int k=0;
    for(auto it=cBegin(); it!=cEnd(); ++it){
        if((*it)->qualita()=="Buona"){
            k++;
        }
    }
    return k;
}
unsigned int Model::calcolaValori2() const{
    unsigned int k=0;
    for(auto it=cBegin(); it!=cEnd(); ++it){
        if((*it)->qualita()=="Sufficiente"){
            k++;
        }
    }
    return k;
}
unsigned int Model::calcolaValori1() const{
    unsigned int k=0;
    for(auto it=cBegin(); it!=cEnd(); ++it){
        if((*it)->qualita()=="Pessima"){
            k++;
        }
    }
    return k;
}



Container<Deepptr<Accessori>>::Iter Model::sBegin()
{
    return listSearch->begin();
}
Container<Deepptr<Accessori>>::Iter Model::sEnd()
{
    return listSearch->end();
}

Container<Deepptr<Accessori>>::ConstIter Model::cBegin()const
{
    return listSearch->cbegin();
}

Container<Deepptr<Accessori>>::ConstIter Model::cEnd()const
{
    return listSearch->cend();
}
