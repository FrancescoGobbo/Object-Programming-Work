#ifndef MENUBAR_H
#define MENUBAR_H

#include <QApplication>
#include <qmenubar.h>
#include <qwidget.h>

class MenuBar : public QMenuBar
{
    Q_OBJECT
private:
        QWidget* parent;

        QMenu* file ;
        QMenu* help;

        QAction* save;
        QAction* load ;
        QAction* exit;

        QAction* reportBug;
        QAction* about;
        QAction* inserisci;
public:
    MenuBar(QWidget* = nullptr);
    QMenu *getMenu() const;
    QMenu *getHelp() const;
    QAction *getSave() const;
    QAction *getLoad() const;
    QAction *getExit() const;
    QAction *getReportBug() const;
    QAction *getAbout() const;
};

#endif // MENUBAR_H
