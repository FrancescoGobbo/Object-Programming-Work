#ifndef ACCESSORI_H
#define ACCESSORI_H

#include <QXmlStreamReader>
#include "SL/readerxmltag.h"

class Accessori
{
private://dati Accessori generale
    std::string nome;
    std::string marca;
    double costo;
    unsigned int meseUscita;
    unsigned int annoUscita;

    std::string tipologia;
    std::string tipoInput;
public:
    Accessori(std::string, std::string, double, unsigned int, unsigned int,
              std::string, std::string);
    virtual bool operator==(const Accessori&) const;
    virtual Accessori* clone() const =0;
    virtual ~Accessori()=default;

    //stampa dati
    std::string getNome()const;
    std::string getMarca()const;
    double getCosto() const;
    unsigned int getMeseUscita()const;
    unsigned int getAnnoUscita()const;
    std::string getTipologia()const;
    std::string getTipoInput()const;


    virtual std::string qualita() const =0;

    //modifica dati
    void changeNome(std::string);
    void changeMarca(std::string);
    void changeCosto(double);
    void changeMeseUscita(unsigned int);
    void changeAnnoUscita(unsigned int);

    void changeTipoInput(std::string);

    //method valore dell'Usato
    double valoreAttualeUsato()const;
    //method rapporto Qualita' Prezzo
    virtual std::string rapportoQualitaPrezzo() const =0;

    virtual void scritturaDatiXML(QXmlStreamWriter&) const;
    void writerTypeXML(QXmlStreamWriter&) const;

    static void letturaDatiXML(QXmlStreamReader&,
                               std::string&,std::string&,std::string&,std::string&,std::string&,std::string&,std::string&);
    //virtual Accessori* readerTypeXML(QXmlStreamReader&);
};

#endif // ACCESSORI_H
