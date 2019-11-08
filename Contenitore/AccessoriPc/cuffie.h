#ifndef CUFFIE_H
#define CUFFIE_H

#include "accessori.h"

class Cuffie: public Accessori
{
private://dati Cuffie
    bool microfono;
    unsigned int rispostaInFrequenzaCuffie;
    unsigned int impedenza;
    unsigned int rispostaInFrequenzaMic;
    unsigned int sensibilitaMic;
    bool cancellazioneRumore;
    unsigned int sensibilitaCuf;
    double peso;

public:
    Cuffie(std::string, std::string, double, unsigned int, unsigned int,
           std::string, std::string,
           bool, unsigned int, unsigned int, unsigned int, unsigned int, bool, unsigned int, double);
    virtual bool operator==(const Accessori&) const;
    virtual Cuffie* clone() const;
    virtual ~Cuffie() override=default;

    //stampa dati
    bool getMicrofono()const;
    unsigned int getRispInFreqC()const;
    unsigned int getImpedenza()const;
    unsigned int getRispInFreqMic()const;
    unsigned int getSensMic()const;
    bool getCancRum()const;
    unsigned int getSensCuff()const;
    double getPeso()const;

    //Valutazione Qualita'
    int valImpedenza(int) const;
    int valSensibilitaCuff(int) const;
    int valSensibilitaMic(int) const;
    int valRumori(bool) const;

    std::string qualita() const;

    //modifica dati
        void changeMicrofono(bool);
        void changeRispInFreqC(unsigned int);
        void changeImpedenza(unsigned int);
        void changeRispInFreqMic(unsigned int);
        void changeSensMic(unsigned int);
        void changeCancRum(bool);
        void changeSensCuff(unsigned int);
        void changePeso(double);

    //method rapporto Qualita' Prezzo
    std::string rapportoQualitaPrezzo() const;

    virtual void scritturaDatiXML(QXmlStreamWriter&) const;

    static Accessori* readerXML(QXmlStreamReader&);
    static void letturaDatiXML(QXmlStreamReader&,
                               std::string&,std::string&,std::string&,std::string&,std::string&,std::string&,std::string&,std::string&);
    //virtual Cuffie* readerTypeXML(QXmlStreamReader&);
};

#endif // CUFFIE_H
