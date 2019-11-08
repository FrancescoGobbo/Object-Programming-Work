#ifndef CBDR_H
#define CBDR_H

#include <QComboBox>
#include <QWidget>


class CBDR : public QComboBox
{
    Q_OBJECT
public:
    CBDR(QWidget * = nullptr);
};

#endif // CBDR_H
