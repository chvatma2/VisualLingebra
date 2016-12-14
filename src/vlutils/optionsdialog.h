#ifndef COPTIONSDIALOG_H
#define COPTIONSDIALOG_H

#include <QDialog>
#include <QGroupBox>
#include <QCheckBox>

class COptionsDialog : public QDialog
{
    Q_OBJECT
public:
    COptionsDialog(QStringList languages, QWidget *parent = Q_NULLPTR);
    void retranslateUi();

private:
    QPushButton *m_okButton = nullptr;
    QPushButton *m_cancelButton = nullptr;
    QGroupBox *m_optionsGroup = nullptr;
    QCheckBox *m_option1 = nullptr;
    QCheckBox *m_option2 = nullptr;
    QCheckBox *m_option3 = nullptr;
    QGroupBox *m_languageGroup = nullptr;

    static QString m_currentLanguage;
    QString m_newLanguage;

signals:
    void languageChanged(const QString &language);

private slots:
    void onOkClicked();
    void onCancelClicked();
    void onLanguageSelectionChanged(const QString &language);
};

#endif // COPTIONSDIALOG_H
