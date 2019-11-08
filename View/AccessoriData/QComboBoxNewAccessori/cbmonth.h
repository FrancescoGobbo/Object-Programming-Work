#ifndef CBMONTH_H
#define CBMONTH_H

#include <QComboBox>
#include <QWidget>

class CBMonth : public QComboBox
{
    Q_OBJECT
public:
    CBMonth(QWidget * = nullptr);
};

#endif // CBMONTH_H
