#include "webcam.h"

Webcam::Webcam(std::string n, std::string m, double c, unsigned int mU, unsigned int aU,
               std::string tip, std::string tIn,
               unsigned int aV, bool z, bool r, unsigned int fR, bool aF, std::string mic, bool lI, bool rN):
               Accessori(n, m, c, mU, aU, tip, tIn),
               angoloDiVisione(aV), zoom(z), rotazione(r), frameRate(fR), autofocus(aF), microfono(mic), luceIntegrata(lI), ripreseNotturne(rN){}

bool Webcam::operator==(const Accessori &a) const
{
    Webcam* w= dynamic_cast<Webcam*> (const_cast<Accessori*>(&a));
    return Accessori::operator== (a) &&
        angoloDiVisione == (w)->getAngoloDiVisione() &&
        zoom == (w)->getZoom() &&
        rotazione == (w)->getRotazione() &&
        frameRate == (w)->getFrameRate() &&
        autofocus == (w)->getAutofocus() &&
        microfono == (w)->getMicrofono() &&
        luceIntegrata == (w)->getLuceIntegrata() &&
        ripreseNotturne == (w)->getRipreseNotturne();
}

Webcam *Webcam::clone() const
{
    return new Webcam(*this);
}

//stampa dati
unsigned int Webcam::getAngoloDiVisione() const
{
    return angoloDiVisione;
}

bool Webcam::getZoom() const
{
    return zoom;
}

bool Webcam::getRotazione() const
{
    return rotazione;
}

unsigned int Webcam::getFrameRate() const
{
    return frameRate;
}

bool Webcam::getAutofocus() const
{
    return autofocus;
}

std::string Webcam::getMicrofono() const
{
    return microfono;
}

bool Webcam::getLuceIntegrata() const
{
    return luceIntegrata;
}

bool Webcam::getRipreseNotturne() const
{
    return ripreseNotturne;
}

//modifica dati
void Webcam::changeAngoloDiVisione(unsigned int k)
{
    if(k!=0)
        angoloDiVisione=k;
}

void Webcam::changeZoom(bool k)
{
    zoom=k;
}

void Webcam::changeRotazione(bool k)
{
    rotazione=k;
}

void Webcam::changeFrameRate(unsigned int k)
{
    if(k!=0)
        frameRate=k;
}

void Webcam::changeAutofocus(bool k)
{
    autofocus=k;
}

void Webcam::changeMicrofono(std::string k)
{
    if(k!="")
        microfono=k;
}

void Webcam::changeLuceIntegrata(bool k)
{
    luceIntegrata=k;
}

void Webcam::changeRipreseNotturne(bool k)
{
    ripreseNotturne=k;
}

//Valutazione Qualita'
int Webcam::qualitaOpzioni(bool z, bool r) const
{
   if(z && r)
       return 5;
   else if(z && !r)
       return 3.5;
   else if(!z && r)
       return 2.5;
   else
       return 1;
}

int Webcam::qualitaFrameRate(unsigned int fR) const
{
    if(fR>=120)
        return 5;
    else if(fR==60 && fR<120)
        return 3;
    else if(fR>=30 && fR<60)
        return 2;
    else
        return 1;
}

int Webcam::qualitaFuoco(bool aF) const
{
    if(aF)
        return 5;
    else
        return 2.5;
}

int Webcam::qualitaMic(std::string s) const
{
    double k=2.5;
    if(s=="omnidirezionale")
        k= 4.5;
    else if(s=="monodirezionale")
        k= 2.5;
    return k;
}

int Webcam::qualitaNotturna(bool luceI, bool ripreseN) const
{
    if(luceI || ripreseN)
        return 4.5;
    else
        return 2.5;
}

std::string Webcam::qualita() const
{
    double k=qualitaOpzioni(zoom, rotazione)+qualitaFrameRate(frameRate)+qualitaFuoco(autofocus)+qualitaMic(microfono)+qualitaNotturna(luceIntegrata,ripreseNotturne);
    std::string value;
    if(k/5>4)
        value= "Eccezionale";
    else if(k/5>3 && k/5<=4)
        value= "Ottima";
    else if(k/5>2 && k/5<=3)
        value= "Buona";
    else if(k/5>1 && k/5<=2)
        value= "Sufficiente";
    else if(k/5>0 && k/5<=1)
        value= "Pessima";
    return value;

}

//method rapporto Qualita' Prezzo
std::string Webcam::rapportoQualitaPrezzo() const
{
    std::string value;
    if(getCosto()<40)
        value="Economiche";
    else if(getCosto()>40 && getCosto()<90)
        value="Fascia Media";
    else
        value="Fascia Alta";
    return value;
}

void Webcam::scritturaDatiXML(QXmlStreamWriter &opXML) const
{
    Accessori::scritturaDatiXML(opXML);
    opXML.writeTextElement("angoloDiVisione", QString::number(getAngoloDiVisione()));
    opXML.writeTextElement("zoom", getZoom()?"1":"0");
    opXML.writeTextElement("rotazione", getRotazione()?"1":"0");
    opXML.writeTextElement("frameRate", QString::number(getFrameRate()));
    opXML.writeTextElement("autofocus", getAutofocus()?"1":"0");
    opXML.writeTextElement("microfono", QString::fromStdString(getMicrofono()));
    opXML.writeTextElement("luceIntegrata", getLuceIntegrata()?"1":"0");
    opXML.writeTextElement("ripreseNotturne", getRipreseNotturne()?"1":"0");
}

Accessori *Webcam::readerXML(QXmlStreamReader &ipDataXML)
{
    std::string datanome, datamarca, datacosto, datameseUscita, dataannoUscita, datatipologia, datatipoInput;
    Accessori::letturaDatiXML(ipDataXML,datanome, datamarca, datacosto, datameseUscita, dataannoUscita, datatipologia, datatipoInput);

    std::string dataaV, dataz, datar, datafR, dataaF, datamic, datalI, datarN;
    Webcam::letturaDatiXML(ipDataXML, dataaV, dataz, datar, datafR, dataaF, datamic, datalI, datarN);
    bool z = (dataz == "1"? true : false);
    bool r = (datar == "1"? true : false);
    bool aF = (dataaF == "1"? true : false);
    bool lI = (datalI == "1"? true : false);
    bool rN = (datarN == "1"? true : false);

    return new Webcam(datanome, datamarca, stod(datacosto), stoul(datameseUscita), stoul(dataannoUscita), datatipologia, datatipoInput,
                      stoul(dataaV), z, r, stoul(datafR), aF, datamic, lI, rN);
}

void Webcam::letturaDatiXML(QXmlStreamReader &ipDataXML, std::string &aV, std::string &z, std::string &r, std::string &fR, std::string &aF, std::string &mic, std::string &lI, std::string &rN)
{
    readerXMLTag(ipDataXML, aV, "angoloDiVisione");
    readerXMLTag(ipDataXML, z, "zoom");
    readerXMLTag(ipDataXML, r, "rotazione");
    readerXMLTag(ipDataXML, fR, "frameRate");
    readerXMLTag(ipDataXML, aF, "autofocus");
    readerXMLTag(ipDataXML, mic, "microfono");
    readerXMLTag(ipDataXML, lI, "luceIntegrata");
    readerXMLTag(ipDataXML, rN, "ripreseNotturne");
}
