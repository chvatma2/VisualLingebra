#include "taskwidget.h"

#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QFile>
#include <QLineEdit>
#include <QTextEdit>
#include <QListView>

CTaskWidget::CTaskWidget(QWidget *parent) : QTabWidget(parent)
{
    //QHBoxLayout *mainLayout = new QHBoxLayout;

    //QFile input("../plugins/test.html");
    //input.open(QIODevice::ReadOnly);

    //m_page.setHtml(input.readAll());
    //m_page.setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding );
    //mainLayout->addWidget(&m_page);

    //QVBoxLayout *indexLayout = new QVBoxLayout;
    //indexLayout->addWidget(new QLabel("Index"));
    //indexLayout->addWidget(&m_index);

    //mainLayout->addLayout(indexLayout);

    setAssignementWidget();
    setImplementationWidget();
    setOutputWidget();

    addTab(m_assignement, QIcon(), tr("Assignement"));
    addTab(m_implementation, QIcon(), tr("Implementation"));
    addTab(m_output, QIcon(), tr("Output"));

    setTabPosition(TabPosition::South);
}

void CTaskWidget::setAssignementWidget()
{
    QHBoxLayout *mainLayout = new QHBoxLayout;

    QFile input("../plugins/test.html");
    input.open(QIODevice::ReadOnly);

    m_assignement = new QWidget;
    m_page.setHtml(input.readAll());
    m_page.setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding );
    mainLayout->addWidget(&m_page);

    QVBoxLayout *indexLayout = new QVBoxLayout;
    indexLayout->addWidget(new QLabel("Index"));
    indexLayout->addWidget(&m_index);

    mainLayout->addLayout(indexLayout);
    m_assignement->setLayout(mainLayout);
}

void CTaskWidget::setImplementationWidget()
{
    QFont font;
    font.setPointSize(14);

    m_implementation = new QWidget;

    QHBoxLayout *mainLayout = new QHBoxLayout;

    QVBoxLayout *inputsLayout = new QVBoxLayout;
    QVBoxLayout *uploadSolutionLayout = new QVBoxLayout;

    QPushButton *uploadSolutionButton = new QPushButton(tr("Upload solution"));
    QPushButton *compileSolutionButton = new QPushButton(tr("Compile"));
    QLabel *solutionLabel = new QLabel(tr("Solution"));
    solutionLabel->setFont(font);
    uploadSolutionButton->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    compileSolutionButton->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);

    QLineEdit* openFileLineEdit = new QLineEdit;
    openFileLineEdit->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);

    QLabel *consoleLabel = new QLabel(tr("Compiler output"));
    QTextEdit *console = new QTextEdit;
    QPalette palette = console->palette();
    palette.setColor(QPalette::Base, Qt::black);
    palette.setColor(QPalette::Text, Qt::white);
    console->setPalette(palette);
    console->setReadOnly(true);

    uploadSolutionLayout->addWidget(solutionLabel);
    uploadSolutionLayout->addWidget(uploadSolutionButton);
    uploadSolutionLayout->addWidget(openFileLineEdit);
    uploadSolutionLayout->addWidget(compileSolutionButton);
    uploadSolutionLayout->addWidget(consoleLabel);
    uploadSolutionLayout->addWidget(console);

    QLabel *inputsLabel = new QLabel(tr("Inputs"));
    QPushButton *loadInputsButton = new QPushButton(tr("Load inputs"));
    QListView *inputsList = new QListView;
    inputsLabel->setFont(font);

    inputsLayout->addWidget(inputsLabel);
    inputsLayout->addWidget(loadInputsButton);
    inputsLayout->addWidget(inputsList);

    mainLayout->addLayout(uploadSolutionLayout, 2);
    mainLayout->addLayout(inputsLayout, 1);

    m_implementation->setLayout(mainLayout);
}

void CTaskWidget::setOutputWidget()
{
    QFont font;
    font.setPointSize(14);

    m_output = new QWidget;

    QHBoxLayout *mainLayout = new QHBoxLayout;

    QVBoxLayout *leftLayout = new QVBoxLayout;
    QVBoxLayout *rightLayout = new QVBoxLayout;
    QVBoxLayout *toolsLayout = new QVBoxLayout;

    QLabel *leftLabel = new QLabel(tr("Student's implementation"));
    QLabel *rightLabel = new QLabel(tr("Reference implementation"));
    leftLayout->addWidget(leftLabel, 0, Qt::AlignTop | Qt::AlignCenter);
    rightLayout->addWidget(rightLabel, 0, Qt::AlignTop | Qt::AlignCenter);

    leftLabel->setFont(font);
    rightLabel->setFont(font);

    QPushButton *bothSolutionsButton = new QPushButton();
    QPushButton *studentSolutionsButton = new QPushButton();
    QPushButton *referenceSolutionsButton = new QPushButton();

    QHBoxLayout *showPartOfScreenButtonsLayout = new QHBoxLayout;
    showPartOfScreenButtonsLayout->addWidget(bothSolutionsButton);
    showPartOfScreenButtonsLayout->addWidget(studentSolutionsButton);
    showPartOfScreenButtonsLayout->addWidget(referenceSolutionsButton);
    toolsLayout->addLayout(showPartOfScreenButtonsLayout);
    toolsLayout->addStretch();

    mainLayout->addLayout(leftLayout);
    mainLayout->addLayout(rightLayout);
    mainLayout->addLayout(toolsLayout);

    m_output->setLayout(mainLayout);
}
