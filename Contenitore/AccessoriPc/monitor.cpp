#include "monitor.h"

Monitor::Monitor(std::string n, std::string m, double c, unsigned int mU, unsigned int aU,
                 std::string tip, std::string tIn,
                 std::string r, std::string rapAspetto, double pol, unsigned int rR, unsigned int fR, bool fS, bool gS, std::string dR, bool speakers) :
    Accessori(n, m, c, mU, aU, tip, tIn),
    risoluzione(r), rapportoDAspetto(rapAspetto), pollici(pol), refreshRate(rR), frameRate(fR), freeSync(fS), gSync(gS), dynamicRange(dR), casse(speakers){}

bool Monitor::operator==(const Accessori &a) const
{
    Monitor* m= dynamic_cast<Monitor*> (const_cast<Accessori*>(&a));
    return Accessori::operator== (a) &&
             risoluzione == (m)->getRisoluzione() &&
             rapportoDAspetto == (m)->getRapportoDAspetto() &&
             pollici == (m)->getPollici() &&
             refreshRate == (m)->getRefreshRate() &&
             frameRate == (m)->getFrameRate() &&
             freeSync == (m)->getFreeSync() &&
             gSync == (m)->getGSync() &&
             dynamicRange == (m)->getDynamicRange() &&
             casse == (m)->getCasse();
}

Monitor *Monitor::clone() const
{
    return new Monitor(*this);
}

//stampa dati
std::string Monitor::getRisoluzione() const
{
    return risoluzione;
}

std::string Monitor::getRapportoDAspetto() const
{
    return rapportoDAspetto;
}

double Monitor::getPollici() const
{
    return pollici;
}

unsigned int Monitor::getRefreshRate() const
{
    return refreshRate;
}

unsigned int Monitor::getFrameRate() const
{
    return frameRate;
}

bool Monitor::getFreeSync() const
{
    return freeSync;
}

bool Monitor::getGSync() const
{
    return gSync;
}

std::string Monitor::getDynamicRange() const
{
    return dynamicRange;
}

bool Monitor::getCasse() const
{
    return casse;
}

//modifica dati
void Monitor::changeRisoluzione(std::string k)
{
    if(k!="")
        risoluzione=k;
}

void Monitor::changeRapportoDAspetto(std::string k)
{
    if(k!="")
        rapportoDAspetto=k;
}

void Monitor::changePollici(double k)
{
    if(k!=0)
        pollici=k;
}

void Monitor::changeRefreshRate(unsigned int k)
{
    if(k!=0)
        refreshRate=k;
}

void Monitor::changeFrameRate(unsigned int k)
{
    if(k!=0)
        frameRate=k;
}

void Monitor::changeFreeSync(bool k)
{
    freeSync=k;
}

void Monitor::changeGSync(bool k)
{
    gSync=k;
}

void Monitor::changeDynamicRange(std::string k)
{
    if(k!="")
        dynamicRange=k;
}

void Monitor::changeCasse(bool k)
{
    casse=k;
}

//Modalita' risoluzione schermo (HD,...)
std::string Monitor::modalita() const
{
    std::string ris=getRisoluzione(); std::string rappDAsp=getRapportoDAspetto(); unsigned int fR=getFrameRate();

    if(ris=="7680×4320" && rappDAsp=="16:9 " && fR>=50)
        return "8K";
    else if(ris=="4096×2160" && rappDAsp=="1,8962:1" && fR>=24)
        return "4K";
    else if(ris=="2048×1080" && rappDAsp=="1,8962:1" && fR>=24)
        return "2K";
    else if(ris=="1920×1080" && rappDAsp=="16:9" && fR>=50)
        return "FHD";
    else if((ris=="1280×720" || ris=="1360×768" || ris=="1366×768")&& rappDAsp=="16:9" && fR>=50)
        return "HD";
    else
        return "Standard";
}

//Valutazione Qualita'
int Monitor::qualitaRefreshRate(unsigned int rr) const
{
    if(rr<=1)
        return 5;
    else if(rr==2)
        return 4;
    else if(rr==3)
        return 3;
    else if(rr==4)
        return 2;
    else if(rr==5)
        return 1;
    else
        return 0;
}

int Monitor::qualitaFrameRate(unsigned int fR) const
{
    int ret=1;
    if(fR==240)
        ret=5;
    else if(fR==144)
        ret=4;
    else if(fR==120)
        ret=3;
    else if(fR==60)
        ret=2;
    else if(fR<60)
        ret=1;
    return ret;
}

double Monitor::val_FG_Sync(bool fs, bool gs) const
{
    if(gs)
        return 5;
    else if(fs)
        return 3.7;
    else
        return 2.5;
}

std::string Monitor::qualita() const
{
    double k=qualitaFrameRate(frameRate)+qualitaRefreshRate(refreshRate)+qualitaFrameRate(refreshRate)+val_FG_Sync(freeSync,gSync);
    std::string value;
    if(k/4>4)
        value= "Eccezionale";
    else if(k/4>3 && k/4<=4)
        value= "Ottima";
    else if(k/4>2 && k/4<=3)
        value= "Buona";
    else if(k/4>1 && k/4<=2)
        value= "Sufficiente";
    else if(k/4>0 && k/4<=1)
        value= "Pessima";

    return value;
}

//method rapporto Qualita' Prezzo
std::string Monitor::rapportoQualitaPrezzo() const
{
    std::string value;
    if(getCosto()<150)
        value="Economiche";
    else if(getCosto()>150 && getCosto()<400)
        value="Fascia Media";
    else
        value="Fascia Alta";
    return value;
}

void Monitor::scritturaDatiXML(QXmlStreamWriter &opXML) const
{
    Accessori::scritturaDatiXML(opXML);
    opXML.writeTextElement("risoluzione", QString::fromStdString(getRisoluzione()));
    opXML.writeTextElement("rapportoDAspetto", QString::fromStdString(getRapportoDAspetto()));
    opXML.writeTextElement("pollici", QString::number(getPollici()));
    opXML.writeTextElement("refreshRate", QString::number(getRefreshRate()));
    opXML.writeTextElement("frameRate", QString::number(getFrameRate()));
    opXML.writeTextElement("freeSync", getFreeSync()?"1":"0");
    opXML.writeTextElement("gSync", getGSync()?"1":"0");
    opXML.writeTextElement("dynamicRange", QString::fromStdString(getDynamicRange()));
    opXML.writeTextElement("casse", getCasse()?"1":"0");
}

Accessori * Monitor::readerXML(QXmlStreamReader &ipDataXML)
{
    std::string datanome, datamarca, datacosto, datameseUscita, dataannoUscita, datatipologia, datatipoInput;
    Accessori::letturaDatiXML(ipDataXML,datanome, datamarca, datacosto, datameseUscita, dataannoUscita, datatipologia, datatipoInput);

    std::string dataRis, dataRDA, dataP, dataRR, dataFR, dataFS, dataGS, dataDR, dataC;
    Monitor::letturaDatiXML(ipDataXML, dataRis, dataRDA, dataP, dataRR, dataFR, dataFS, dataGS, dataDR, dataC);
    bool fS = (dataFS == "1"? true : false);
    bool gS = (dataGS == "1"? true : false);
    bool c = (dataC == "1"? true : false);

    return new Monitor(datanome, datamarca, stod(datacosto), stoul(datameseUscita), stoul(dataannoUscita), datatipologia, datatipoInput,
                      dataRis, dataRDA, stod(dataP), stoul(dataRR), stoul(dataFR), fS, gS, dataDR, c);
}

void Monitor::letturaDatiXML(QXmlStreamReader &ipDataXML, std::string &ris, std::string &rDA, std::string &p, std::string &rR, std::string &fR, std::string &fS, std::string &gS, std::string &dR, std::string &c)
{
    readerXMLTag(ipDataXML, ris, "risoluzione");
    readerXMLTag(ipDataXML, rDA, "rapportoDAspetto");
    readerXMLTag(ipDataXML, p, "pollici");
    readerXMLTag(ipDataXML, rR, "refreshRate");
    readerXMLTag(ipDataXML, fR, "frameRate");
    readerXMLTag(ipDataXML, fS, "freeSync");
    readerXMLTag(ipDataXML, gS, "gSync");
    readerXMLTag(ipDataXML, dR, "dynamicRange");
    readerXMLTag(ipDataXML, c, "casse");
}
