#ifndef CNEWTAB_H
#define CNEWTAB_H

#include <QWidget>
#include <QLabel>

class CNewTab : public QWidget
{
public:
    CNewTab(QWidget *parent = 0);

private:
    QLabel m_selectionLabel;
};

#endif // CNEWTAB_H
