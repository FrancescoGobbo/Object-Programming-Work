#include "xmlio.h"

#include <QFile>
#include <QSaveFile>
#include <QXmlStreamReader>
#include <QXmlStreamWriter>
#include <QDebug>



XmlIO::XmlIO(const QString& filepath) : filename(filepath) {}

Accessori *XmlIO::tagTypeXML(QXmlStreamReader &r, const string &tagName)
{
    if(tagName=="cuffie")
        return Cuffie::readerXML(r);
    else if(tagName=="monitor")
        return Monitor::readerXML(r);
    else if(tagName=="mouse")
        return Mouse::readerXML(r);
    else if(tagName=="tastiera")
        return Tastiera::readerXML(r);
    else if(tagName=="webcam")
        return Webcam::readerXML(r);
    else
        qWarning() << "Tag non riconosciuto";
    return nullptr;
}

Container<Deepptr<Accessori>> XmlIO::read() const{
    // Crea un container
    Container<Deepptr<Accessori>> goods;

    // Apre un file (QFile)
    QFile file(filename);

    //Apertura del file solo in lettura, se non riesce messaggio d'errore
    if(!file.open(QIODevice::ReadOnly)) {
        qWarning() << "Non è stato possibile aprire il file" << file.errorString();
        return  goods;
    }

    // Lettura da file XML
    QXmlStreamReader reader(&file); // QIODevice*

    if(reader.readNextStartElement() && reader.name() == "accessori") {
        while (reader.readNextStartElement()){
            //lettura tag
            std::string nameTag = (reader.name().toString()).toStdString();
            Accessori* acc = nullptr;
            try{
                acc = tagTypeXML(reader,nameTag);
                if(acc!=nullptr)
                    goods.push_back(acc);
                reader.skipCurrentElement();
            }catch(std::string error){
                qWarning() << "Lettura errata di qualche tag" << file.errorString();
            }
        }
    }
    // Chiude il file e ritorna la lista con i Todo letti
    file.close();
    return goods;
}


void XmlIO::write(const Container<Deepptr<Accessori>>& goods) const {
    // QSaveFile rispetto a QFile è più adatto per effettuare scritture su disco. Gestisce meglio
    // i casi di errore, garantendo che non vengano persi i dati del file in caso di errori in scrittura
    QSaveFile file(filename);

    // Apre un file. Se non si apre lancia una eccezione.
    if(!file.open(QIODevice::WriteOnly)) {
        throw std::exception();
        // NB: la cosa giusta da fare sarebbe creare un tipo eccezione. std::exception è troppo generica.
    }

    QXmlStreamWriter writer(&file);
    writer.setAutoFormatting(true); // Per leggibilità del file XML
    writer.writeStartDocument();    // Scrive le intestazioni XML
    writer.writeComment("File di salvataggio dell'applicazione. Non modificare a mano.");

    writer.writeStartElement("accessori");

    for(auto citer = goods.cbegin();citer!=goods.cend();++citer){
        (*citer)->writerTypeXML(writer);
    }

    writer.writeEndElement();                                        // </accessori>
    writer.writeEndDocument();  // chiude eventuali tag lasciati aperti e aggiunge una riga vuota alla fine

    file.commit(); // Scrive il file temporaneo su disco
}

