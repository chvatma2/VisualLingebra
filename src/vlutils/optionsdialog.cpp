#include "optionsdialog.h"

#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>
#include <QGroupBox>
#include <QCheckBox>
#include <QComboBox>
#include <QDebug>

QString COptionsDialog::m_currentLanguage = "english";

COptionsDialog::COptionsDialog(QStringList languages, QWidget *parent)
    : QDialog(parent)
{
    setModal(true);

    QVBoxLayout *mainLayout = new QVBoxLayout;

    QHBoxLayout *lowerButtonsLayout = new QHBoxLayout;

    m_okButton = new QPushButton(tr("Ok"));
    m_cancelButton = new QPushButton(tr("Cancel"));
    lowerButtonsLayout->addStretch();
    lowerButtonsLayout->addWidget(m_okButton);
    lowerButtonsLayout->addWidget(m_cancelButton);

    m_optionsGroup = new QGroupBox(tr("Generic options group"));
    m_option1 = new QCheckBox(tr("Option 1"));
    m_option2 = new QCheckBox(tr("Option 2"));
    m_option3 = new QCheckBox(tr("Option 3"));

    QVBoxLayout *optionsLayout = new QVBoxLayout;
    optionsLayout->addWidget(m_option1);
    optionsLayout->addWidget(m_option2);
    optionsLayout->addWidget(m_option3);
    m_optionsGroup->setLayout(optionsLayout);

    m_languageGroup = new QGroupBox(tr("Language"));
    QVBoxLayout *languageLayout = new QVBoxLayout;
    QComboBox *languageBox = new QComboBox;
    for (QString language : languages) {
        languageBox->addItem(language);
    }
    languageBox->setCurrentIndex(languageBox->findText(m_currentLanguage));
    //m_currentLanguage = "english";
    m_newLanguage = "english";
    languageLayout->addWidget(languageBox);
    m_languageGroup->setLayout(languageLayout);

    mainLayout->addWidget(m_optionsGroup);
    mainLayout->addWidget(m_languageGroup);
    mainLayout->addStretch();
    mainLayout->addLayout(lowerButtonsLayout);
    setLayout(mainLayout);

    connect(m_okButton, &QPushButton::clicked, this, &COptionsDialog::onOkClicked);
    connect(m_cancelButton, &QPushButton::clicked, this, &COptionsDialog::onCancelClicked);
    connect(languageBox, &QComboBox::currentTextChanged, this, &COptionsDialog::onLanguageSelectionChanged);
}

void COptionsDialog::retranslateUi()
{
    qDebug() << "Retranslating";
    m_okButton->setText(tr("Ok"));
    m_cancelButton->setText(tr("Cancel"));
    m_optionsGroup->setTitle(tr("Generic options group"));
    m_option1->setText(tr("Option 1"));
    m_option2->setText(tr("Option 2"));
    m_option3->setText(tr("Option 3"));
    m_languageGroup->setTitle(tr("Language"));
}

void COptionsDialog::onOkClicked()
{
    //Save changes here
    if(m_newLanguage != m_currentLanguage) {
        emit languageChanged(m_newLanguage);
    }
    m_currentLanguage = m_newLanguage;
    accept();
}

void COptionsDialog::onCancelClicked()
{
    m_newLanguage = m_currentLanguage;
    reject();
}

void COptionsDialog::onLanguageSelectionChanged(const QString &language)
{
    m_newLanguage = language;
}
