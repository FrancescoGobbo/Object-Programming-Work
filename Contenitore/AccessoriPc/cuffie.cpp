#include "cuffie.h"

Cuffie::Cuffie(std::string n, std::string m, double c, unsigned int mU, unsigned int aU,
               std::string tip, std::string tIn,
               bool mic, unsigned int rIFC, unsigned int im, unsigned int rIFM, unsigned int sMic, bool cancRum, unsigned int sC, double kg):
               Accessori(n, m, c, mU, aU, tip, tIn),
               microfono(mic), rispostaInFrequenzaCuffie(rIFC), impedenza(im), rispostaInFrequenzaMic(rIFM), sensibilitaMic(sMic),
               cancellazioneRumore(cancRum), sensibilitaCuf(sC), peso(kg){}

bool Cuffie::operator==(const Accessori & a) const
{
    Cuffie* c= dynamic_cast<Cuffie*> (const_cast<Accessori*>(&a));

    return Accessori::operator== (a) &&
        microfono == (c)->getMicrofono() &&
        rispostaInFrequenzaCuffie == (c)->getRispInFreqC() &&
        impedenza == (c)->getImpedenza() &&
        rispostaInFrequenzaMic == (c)->getRispInFreqMic() &&
        sensibilitaMic == (c)->getSensMic() &&
        cancellazioneRumore == (c)->getCancRum() &&
        sensibilitaCuf == (c)->getSensCuff() &&
        peso == (c)->getPeso();
}

Cuffie *Cuffie::clone() const
{
    return new Cuffie(*this);
}

//stampa dati
bool Cuffie::getMicrofono() const
{
    return microfono;
}

unsigned int Cuffie::getRispInFreqC() const
{
    return rispostaInFrequenzaCuffie;
}

unsigned int Cuffie::getImpedenza() const
{
    return impedenza;
}

unsigned int Cuffie::getRispInFreqMic() const
{
    return rispostaInFrequenzaMic;
}

unsigned int Cuffie::getSensMic() const
{
    return sensibilitaMic;
}

bool Cuffie::getCancRum() const
{
    return cancellazioneRumore;
}

unsigned int Cuffie::getSensCuff() const
{
    return sensibilitaCuf;
}

double Cuffie::getPeso() const
{
    return peso;
}

//modifica dati
void Cuffie::changeMicrofono(bool k)
{
    microfono= k;
}

void Cuffie::changeRispInFreqC(unsigned int k)
{
    if(k!=0)
        rispostaInFrequenzaCuffie=k;
}

void Cuffie::changeImpedenza(unsigned int k)
{
    if(k!=0)
        impedenza=k;
}

void Cuffie::changeRispInFreqMic(unsigned int k)
{
    rispostaInFrequenzaMic=k;
}

void Cuffie::changeSensMic(unsigned int k)
{
    sensibilitaMic=k;
}

void Cuffie::changeCancRum(bool k)
{
    cancellazioneRumore=k;
}

void Cuffie::changeSensCuff(unsigned int k)
{
    if(k!=0)
        sensibilitaCuf=k;
}

void Cuffie::changePeso(double k)
{
    if(k!=0)
        peso=k;
}

//Valutazione Qualita'
int Cuffie::valImpedenza(int vi) const
{
    if(vi<250 && vi>=120)
        return 5;
    else if(vi<120 && vi>=80)
        return 4;
    else if(vi<80 && vi>=68)
        return 3;
    else if(vi<68 && vi>=56)
        return 2;
    else if(vi<56 && vi>=32)
        return 1;
    else
        return 0;
}

int Cuffie::valSensibilitaCuff(int sCuff) const
{
    if(sCuff<110 && sCuff>=105)
        return 5;
    else if(sCuff<105 && sCuff>=100)
        return 4;
    else if(sCuff<100 && sCuff>=95)
        return 3;
    else if(sCuff<95 && sCuff>=90)
        return 2;
    else if(sCuff<90 && sCuff>=85)
        return 1;
    else
        return 0;
}

int Cuffie::valSensibilitaMic(int sMic) const
{
    if(sMic<124 && sMic>=104)
        return 5;
    else if(sMic<104 && sMic>=84)
        return 4;
    else if(sMic<84 && sMic>=64)
        return 3;
    else if(sMic<64 && sMic>=44)
        return 2;
    else if(sMic<44 && sMic>=24)
        return 1;
    else
        return 0;
}

int Cuffie::valRumori(bool deletenoise) const
{
    if(deletenoise)
        return 5;
    else
        return 2.5;
}

std::string Cuffie::qualita() const
{
    double k= valImpedenza(impedenza)+valSensibilitaCuff(sensibilitaCuf)+valSensibilitaMic(sensibilitaMic)+valRumori(cancellazioneRumore);
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
std::string Cuffie::rapportoQualitaPrezzo() const
{
    std::string value;
    if(getCosto()<50)
        value="Economiche";
    else if(getCosto()>50 && getCosto()<150)
        value="Fascia Media";
    else
        value="Fascia Alta";
    return value;
}

void Cuffie::scritturaDatiXML(QXmlStreamWriter &opXML) const
{
    Accessori::scritturaDatiXML(opXML);
    opXML.writeTextElement("microfono", getMicrofono()?"1":"0");
    opXML.writeTextElement("rispostaInFrequenzaCuffie", QString::number(getRispInFreqC()));
    opXML.writeTextElement("impedenza", QString::number(getImpedenza()));
    opXML.writeTextElement("rispostaInFrequenzaMic", QString::number(getRispInFreqMic()));
    opXML.writeTextElement("sensibilitaMic", QString::number(getSensMic()));
    opXML.writeTextElement("cancellazioneRumore", getCancRum()?"1":"0");
    opXML.writeTextElement("sensibilitaCuf", QString::number(getSensCuff()));
    opXML.writeTextElement("peso", QString::number(getPeso()));
}

Accessori* Cuffie::readerXML(QXmlStreamReader &ipDataXML)
{
    std::string datanome, datamarca, datacosto, datameseUscita, dataannoUscita, datatipologia, datatipoInput;
    Accessori::letturaDatiXML(ipDataXML,datanome, datamarca, datacosto, datameseUscita, dataannoUscita, datatipologia, datatipoInput);

    std::string datamic, datarIFC, dataimp, datarIFM, datasM, datacR, datasC, datap;
    Cuffie::letturaDatiXML(ipDataXML, datamic, datarIFC, dataimp, datarIFM, datasM, datacR, datasC, datap);
    bool mic = (datamic == "1"? true : false);
    bool cR = (datacR == "1"? true : false);

    return new Cuffie(datanome, datamarca, stod(datacosto), stoul(datameseUscita), stoul(dataannoUscita), datatipologia, datatipoInput,
                      mic, stoul(datarIFC), stoul(dataimp), stoul(datarIFM), stoul(datasM), cR, stoul(datasC), stod(datap));
}

void Cuffie::letturaDatiXML(QXmlStreamReader &ipDataXML, std::string &mic, std::string &rIFC, std::string &imp, std::string &rIFM, std::string &sM, std::string &cR, std::string &sC, std::string &p)
{
    readerXMLTag(ipDataXML, mic, "microfono");
    readerXMLTag(ipDataXML, rIFC, "rispostaInFrequenzaCuffie");
    readerXMLTag(ipDataXML, imp, "impedenza");
    readerXMLTag(ipDataXML, rIFM, "rispostaInFrequenzaMic");
    readerXMLTag(ipDataXML, sM, "sensibilitaMic");
    readerXMLTag(ipDataXML, cR, "cancellazioneRumore");
    readerXMLTag(ipDataXML, sC, "sensibilitaCuf");
    readerXMLTag(ipDataXML, p, "peso");
}
