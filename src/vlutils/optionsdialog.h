#ifndef COPTIONSDIALOG_H
#define COPTIONSDIALOG_H

#include <QDialog>

class COptionsDialog : public QDialog
{
    Q_OBJECT
public:
    COptionsDialog(QWidget *parent = Q_NULLPTR);

private slots:
    void onOkClicked();
    void onCancelClicked();
};

#endif // COPTIONSDIALOG_H
