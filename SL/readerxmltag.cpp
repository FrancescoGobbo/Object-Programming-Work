#include "readerxmltag.h"

void readerXMLTag(QXmlStreamReader& ipDataXml,std::string& valueIp ,const std::string tagName)
{
    ipDataXml.readNextStartElement();

    if (ipDataXml.name() != QString::fromStdString(tagName))
        throw exception_XML_Tag();
    valueIp = (ipDataXml.readElementText()).toStdString();
}
