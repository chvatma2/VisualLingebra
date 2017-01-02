#include "implementationwidget.h"

#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QPushButton>
#include <QLabel>
#include <QTextEdit>
#include <QLineEdit>
#include <QFileDialog>
#include <QStringListModel>
#include <QPalette>
#include <QListView>

CImplementationWidget::CImplementationWidget(QWidget *parent) : QWidget(parent)
{
    createUiElements();
    retranslateUi();

    connect(m_uploadSolutionButton, &QPushButton::clicked, this, &CImplementationWidget::onUploadSolutionClicked);
    connect(m_compileSolutionButton, &QPushButton::clicked, this, &CImplementationWidget::onCompileSolutionClicked);
    connect(m_loadInputsButton, &QPushButton::clicked, this, &CImplementationWidget::onLoadInputClicked);
}

void CImplementationWidget::retranslateUi()
{
    m_uploadSolutionButton->setText(tr("Select solution"));
    m_compileSolutionButton->setText(tr("Compile"));
    m_solutionLabel->setText(tr("Solution"));
    m_inputsLabel->setText(tr("Input dat"));
    m_loadInputsButton->setText(tr("Load inputs"));
    m_consoleLabel->setText(tr("Compiler output"));
}

void CImplementationWidget::onUploadSolutionClicked()
{
    QString filename = QFileDialog::getOpenFileName(this, tr("Open cpp solution file"), "../plugins/car/", tr("Source code (*.cpp)"));
    m_uploadSolutionLineEdit->setText(filename);
}

void CImplementationWidget::onCompileSolutionClicked()
{
    if(m_uploadSolutionLineEdit->text().isEmpty()) {
        m_console->setText("Error, input file path is empty");
        return;
    }
    m_console->setText(m_uploadSolutionLineEdit->text() + " Compiled");
    emit compiled();
}

void CImplementationWidget::onLoadInputClicked()
{
    QString filename = QFileDialog::getOpenFileName(this, tr("Select input file"));
    QFileInfo info(filename);
    if(!filename.isEmpty()) {
        m_inputs << info.fileName();
        m_stringModel->setStringList(m_inputs);
    }
}

void CImplementationWidget::createUiElements()
{
    QFont font;
    font.setPointSize(14);

    QHBoxLayout *mainLayout = new QHBoxLayout;

    QVBoxLayout *inputsLayout = new QVBoxLayout;
    QVBoxLayout *uploadSolutionLayout = new QVBoxLayout;
    m_uploadSolutionLineEdit = new QLineEdit;

    m_uploadSolutionButton = new QPushButton;
    m_compileSolutionButton = new QPushButton;
    m_solutionLabel = new QLabel;
    m_solutionLabel->setFont(font);
    m_uploadSolutionButton->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    m_compileSolutionButton->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    m_uploadSolutionLineEdit->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);

    m_console = new QTextEdit;
    m_consoleLabel = new QLabel;
    QPalette palette = m_console->palette();
    palette.setColor(QPalette::Base, Qt::black);
    palette.setColor(QPalette::Text, Qt::white);
    m_console->setPalette(palette);
    m_console->setReadOnly(true);

    uploadSolutionLayout->addWidget(m_solutionLabel);
    uploadSolutionLayout->addWidget(m_uploadSolutionButton);
    uploadSolutionLayout->addWidget(m_uploadSolutionLineEdit);
    uploadSolutionLayout->addWidget(m_compileSolutionButton);
    uploadSolutionLayout->addWidget(m_consoleLabel);
    uploadSolutionLayout->addWidget(m_console);

    m_inputsLabel = new QLabel;
    m_loadInputsButton = new QPushButton;
    m_inputsList = new QListView;
    m_stringModel = new QStringListModel;
    m_inputsList->setModel(m_stringModel);
    m_inputsLabel->setFont(font);

//    inputsLayout->addWidget(m_inputsLabel);
//    inputsLayout->addWidget(m_loadInputsButton);
//    inputsLayout->addWidget(m_inputsList);

    mainLayout->addLayout(uploadSolutionLayout, 2);
    QWidget *inputsWidget = new QWidget;
    inputsWidget->setLayout(inputsLayout);
    inputsWidget->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Expanding);
    mainLayout->addWidget(inputsWidget);

    setLayout(mainLayout);
}
