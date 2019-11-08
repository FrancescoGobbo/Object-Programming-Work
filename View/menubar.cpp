#include "menubar.h"
#include <QMenu>
#include <QMenuBar>

MenuBar::MenuBar(QWidget *p):
    parent(p),
    file(new QMenu("&File", this)),
    help(new QMenu("&Aiuto", this)),
    save (new QAction(QIcon(":/img/IMG/save.png"),tr("&Save"), this)),
    load (new QAction(QIcon(":/img/IMG/load.png"), tr("&Load"), this)),
    exit (new QAction(QIcon(":/img/IMG/exit.png"), tr("&Exit"), this)),
    reportBug (new QAction(QIcon(":/img/IMG/reportbug.png"), tr("&Tracciamento Bug"), this)),
    about (new QAction(QIcon(":/img/IMG/help.png"), tr("&Contatti"), this)),
    inserisci(new QAction("&Inserisci",p))
{
    file->addAction(save);
    file->addAction(load);
    file->addSeparator();
    file->addAction(exit);

    addMenu(file);

    addAction(inserisci);

    help->addAction(reportBug);
    help->addAction(about);
    addMenu(help);

    connect(about,SIGNAL(triggered()), parent,SLOT(slotMSGBOXAboutDialog()));
    connect(reportBug, SIGNAL(triggered()), parent, SLOT(slotMSGBOXReportBug()));
    connect(inserisci, SIGNAL(triggered()), parent,SLOT(slotShowInserisci()));

}

QMenu *MenuBar::getMenu() const
{
    return file;
}

QMenu *MenuBar::getHelp() const
{
    return help;
}

QAction *MenuBar::getSave() const
{
    return save;
}

QAction *MenuBar::getLoad() const
{
    return load;
}

QAction *MenuBar::getExit() const
{
    return exit;
}

QAction *MenuBar::getReportBug() const
{
    return reportBug;
}

QAction *MenuBar::getAbout() const
{
    return about;
}
