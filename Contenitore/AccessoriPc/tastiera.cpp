#include "tastiera.h"

Tastiera::Tastiera(std::string n, std::string m, double c, unsigned int mU, unsigned int aU,
                   std::string tip, std::string tIn,
                   bool ri, std::string l,std::string conf, unsigned int pR, std::string cat, bool tp):
    Accessori(n, m, c, mU, aU, tip, tIn),
    retroilluminazione(ri), layout(l), confort(conf), pollingRate(pR), categoria(cat), trackpad(tp){}

bool Tastiera::operator==(const Accessori & a) const
{
    Tastiera* t= dynamic_cast<Tastiera*> (const_cast<Accessori*>(&a));
    return  Accessori::operator== (a) &&
        retroilluminazione == (t)->getRetroIlluminazione() &&
        layout == (t)->getLayout() &&
        confort == (t)->getConfort() &&
        pollingRate == (t)->getPollingRate() &&
        categoria == (t)->getCategoria() &&
        trackpad == (t)->getTrackPad();
}

Tastiera *Tastiera::clone() const
{
    return new Tastiera(*this);
}

//stampa dati
bool Tastiera::getRetroIlluminazione() const
{
    return retroilluminazione;
}

std::string Tastiera::getLayout() const
{
    return layout;
}

std::string Tastiera::getConfort() const
{
    return confort;
}

unsigned int Tastiera::getPollingRate() const
{
    return pollingRate;
}

std::string Tastiera::getCategoria() const
{
    return categoria;
}

bool Tastiera::getTrackPad() const
{
    return trackpad;
}

//modifica dati
void Tastiera::changeRetroIlluminazione(bool k)
{
    retroilluminazione=k;
}

void Tastiera::changeLayout(std::string k)
{
    if(k!="")
        layout=k;
}

void Tastiera::changeConfort(std::string k)
{
    if(k!="")
        confort=k;
}

void Tastiera::changePollingRate(unsigned int k)
{
    if(k!=0)
        pollingRate=k;
}

void Tastiera::changeCategoria(std::string k)
{
    if(k!="")
        categoria=k;
}

void Tastiera::changeTrackPad(bool k)
{
    trackpad=k;
}

//Valutazione Qualita'
int Tastiera::qualitaConfort(std::string v) const
{
    int i=1;
    if(v=="Eccezionale")
        i=5;
    else if(v=="Ottima")
        i=4;
    else if(v=="Buona")
        i=3;
    else if(v=="Sufficiente")
        i=2;
    else if(v=="Pessima")
        i=1;
    return i;
}

int Tastiera::qualitaVelocita(int k) const
{
    if(k>=500)
        return 5;
    else if(k>=400)
        return 4;
    else if(k>=300)
        return 3;
    else if(k>=100)
        return 2;
    else
        return 1;
}

std::string Tastiera::qualita() const
{
    double k=qualitaConfort(confort)+qualitaVelocita(pollingRate);
    std::string value;
    if(k/2>4)
        value= "Eccezionale";
    else if(k/2>3 && k/2<=4)
        value= "Ottima";
    else if(k/2>2 && k/2<=3)
        value= "Buona";
    else if(k/2>1 && k/2<=2)
        value= "Sufficiente";
    else if(k/2>0 && k/2<=1)
        value= "Pessima";

    return value;
}

//method rapporto Qualita' Prezzo
std::string Tastiera::rapportoQualitaPrezzo() const
{
    std::string value;
    if(getCosto()<30)
        value="Economiche";
    else if(getCosto()>30 && getCosto()<100)
        value="Fascia Media";
    else
        value="Fascia Alta";
    return value;
}

void Tastiera::scritturaDatiXML(QXmlStreamWriter& opXML) const
{
    Accessori::scritturaDatiXML(opXML);
    opXML.writeTextElement("retroilluminazione", getRetroIlluminazione()?"1":"0");
    opXML.writeTextElement("layout", QString::fromStdString(getLayout()));
    opXML.writeTextElement("confort", QString::fromStdString(getConfort()));
    opXML.writeTextElement("pollingRate", QString::number(getPollingRate()));
    opXML.writeTextElement("categoria", QString::fromStdString(getCategoria()));
    opXML.writeTextElement("trackpad", getTrackPad()?"1":"0");
}

Accessori *Tastiera::readerXML(QXmlStreamReader &ipDataXML)
{
    std::string datanome, datamarca, datacosto, datameseUscita, dataannoUscita, datatipologia, datatipoInput;
    Accessori::letturaDatiXML(ipDataXML,datanome, datamarca, datacosto, datameseUscita, dataannoUscita, datatipologia, datatipoInput);

    std::string datari, datal, dataconf, datapR, datacat, datatp;
    Tastiera::letturaDatiXML(ipDataXML, datari, datal, dataconf, datapR, datacat, datatp);
    bool ri = (datari == "1"? true : false);
    bool tp = (datatp == "1"? true : false);

    return new Tastiera(datanome, datamarca, stod(datacosto), stoul(datameseUscita), stoul(dataannoUscita), datatipologia, datatipoInput,
                      ri, datal, dataconf, stoul(datapR), datacat, tp);
}

void Tastiera::letturaDatiXML(QXmlStreamReader &ipDataXML, std::string &ri, std::string &l, std::string &conf, std::string &pR, std::string &cat, std::string &tp)
{
    readerXMLTag(ipDataXML, ri, "retroilluminazione");
    readerXMLTag(ipDataXML, l, "layout");
    readerXMLTag(ipDataXML, conf, "confort");
    readerXMLTag(ipDataXML, pR, "pollingRate");
    readerXMLTag(ipDataXML, cat, "categoria");
    readerXMLTag(ipDataXML, tp, "trackpad");
}
