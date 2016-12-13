#include "optionsdialog.h"

#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>
#include <QGroupBox>
#include <QCheckBox>
#include <QComboBox>


COptionsDialog::COptionsDialog(QWidget *parent)
    : QDialog(parent)
{
    setModal(true);

    QVBoxLayout *mainLayout = new QVBoxLayout;

    QHBoxLayout *lowerButtonsLayout = new QHBoxLayout;

    QPushButton *okButton = new QPushButton(tr("Ok"));
    QPushButton *cancelButton = new QPushButton(tr("Cancel"));
    lowerButtonsLayout->addStretch();
    lowerButtonsLayout->addWidget(okButton);
    lowerButtonsLayout->addWidget(cancelButton);

    QGroupBox *optionsGroup = new QGroupBox(tr("Generic options group"));
    QCheckBox *option1 = new QCheckBox(tr("Option 1"));
    QCheckBox *option2 = new QCheckBox(tr("Option 2"));
    QCheckBox *option3 = new QCheckBox(tr("Option 3"));

    QVBoxLayout *optionsLayout = new QVBoxLayout;
    optionsLayout->addWidget(option1);
    optionsLayout->addWidget(option2);
    optionsLayout->addWidget(option3);
    optionsGroup->setLayout(optionsLayout);

    QGroupBox *languageGroup = new QGroupBox(tr("Language"));
    QVBoxLayout *languageLayout = new QVBoxLayout;
    QComboBox *languageBox = new QComboBox;
    languageBox->addItem("English");
    languageBox->addItem("Čeština");
    languageLayout->addWidget(languageBox);
    languageGroup->setLayout(languageLayout);

    mainLayout->addWidget(optionsGroup);
    mainLayout->addWidget(languageGroup);
    mainLayout->addStretch();
    mainLayout->addLayout(lowerButtonsLayout);
    setLayout(mainLayout);

    connect(okButton, &QPushButton::clicked, this, &COptionsDialog::onOkClicked);
    connect(cancelButton, &QPushButton::clicked, this, &COptionsDialog::onCancelClicked);
}

void COptionsDialog::onOkClicked()
{
    //Save changes here
    accept();
}

void COptionsDialog::onCancelClicked()
{
    reject();
}
