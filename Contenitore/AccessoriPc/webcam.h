#ifndef WEBCAM_H
#define WEBCAM_H

#include "accessori.h"

class Webcam: public Accessori
{
private://dati Webcam
    unsigned int angoloDiVisione;//in gradi
    bool zoom;
    bool rotazione;
    unsigned int frameRate;
    bool autofocus;
    std::string microfono; //omnidirezionali o monodirezionali
    bool luceIntegrata;
    bool ripreseNotturne;

public:
    Webcam(std::string, std::string, double, unsigned int, unsigned int,
             std::string, std::string,
             unsigned int, bool, bool, unsigned int, bool, std::string, bool, bool);
    virtual bool operator==(const Accessori&) const;
    virtual Webcam* clone() const;
    virtual ~Webcam() override=default;

    //stampa dati
    unsigned int getAngoloDiVisione()const;
    bool getZoom()const;
    bool getRotazione()const;
    unsigned int getFrameRate()const;
    bool getAutofocus()const;
    std::string getMicrofono()const;
    bool getLuceIntegrata()const;
    bool getRipreseNotturne()const;

    //Valutazione Qualita'
    int qualitaOpzioni(bool, bool) const;//zoom & rotazione
    int qualitaFrameRate(unsigned int) const;
    int qualitaFuoco(bool) const; //autofocus?
    int qualitaMic (std::string) const;//microfono omnidirezionali o monodirezionali?
    int qualitaNotturna(bool, bool) const;//qualita riprese notturne

    std::string qualita() const;

    //modifica dati
        void changeAngoloDiVisione(unsigned int);
        void changeZoom(bool);
        void changeRotazione(bool);
        void changeFrameRate(unsigned int);
        void changeAutofocus(bool);
        void changeMicrofono(std::string);
        void changeLuceIntegrata(bool);
        void changeRipreseNotturne(bool);

    //method rapporto Qualita' Prezzo
    std::string rapportoQualitaPrezzo() const;

    virtual void scritturaDatiXML(QXmlStreamWriter&) const;

    static Accessori* readerXML(QXmlStreamReader&);
    static void letturaDatiXML(QXmlStreamReader&,
                               std::string&,std::string&,std::string&,std::string&,std::string&,std::string&,std::string&,std::string&);
};

#endif // WEBCAM_H
