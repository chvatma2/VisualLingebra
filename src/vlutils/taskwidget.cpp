#include "taskwidget.h"

#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QFile>
#include <QListView>
#include <QFileDialog>
#include <QPropertyAnimation>

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

    m_uploadSolutionLineEdit.setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);

    QLabel *consoleLabel = new QLabel(tr("Compiler output"));
    QPalette palette = m_console.palette();
    palette.setColor(QPalette::Base, Qt::black);
    palette.setColor(QPalette::Text, Qt::white);
    m_console.setPalette(palette);
    m_console.setReadOnly(true);

    uploadSolutionLayout->addWidget(solutionLabel);
    uploadSolutionLayout->addWidget(uploadSolutionButton);
    uploadSolutionLayout->addWidget(&m_uploadSolutionLineEdit);
    uploadSolutionLayout->addWidget(compileSolutionButton);
    uploadSolutionLayout->addWidget(consoleLabel);
    uploadSolutionLayout->addWidget(&m_console);

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

    connect(uploadSolutionButton, &QPushButton::clicked, this, &CTaskWidget::onUploadSolutionClicked);
    connect(compileSolutionButton, &QPushButton::clicked, this, &CTaskWidget::onCompileSolutionClicked);
}

void CTaskWidget::setOutputWidget()
{
    QFont font;
    font.setPointSize(14);

    m_output = new QWidget;

    QVBoxLayout *leftLayout = new QVBoxLayout;
    QVBoxLayout *rightLayout = new QVBoxLayout;
    QVBoxLayout *toolsLayout = new QVBoxLayout;

    QLabel *leftLabel = new QLabel(tr("Student's implementation"));
    QLabel *rightLabel = new QLabel(tr("Reference implementation"));
    leftLayout->addWidget(leftLabel, 0, Qt::AlignTop | Qt::AlignCenter);
    rightLayout->addWidget(rightLabel, 0, Qt::AlignTop | Qt::AlignCenter);

    leftLabel->setFont(font);
    rightLabel->setFont(font);

    QPushButton *hideToolsButton = new QPushButton(">>");
    hideToolsButton->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);

    QPushButton *bothSolutionsButton = new QPushButton("B");
    QPushButton *studentSolutionsButton = new QPushButton("S");
    QPushButton *referenceSolutionsButton = new QPushButton("R");

    QHBoxLayout *showPartOfScreenButtonsLayout = new QHBoxLayout;
    showPartOfScreenButtonsLayout->addWidget(bothSolutionsButton);
    showPartOfScreenButtonsLayout->addWidget(studentSolutionsButton);
    showPartOfScreenButtonsLayout->addWidget(referenceSolutionsButton);
    showPartOfScreenButtonsLayout->addStretch();
    toolsLayout->addWidget(hideToolsButton);
    toolsLayout->addLayout(showPartOfScreenButtonsLayout);
    toolsLayout->addStretch();

    m_toolboxArea.setWidgetResizable(true);
    m_toolboxArea.setSizePolicy(QSizePolicy::Maximum, QSizePolicy::Expanding);
    m_toolboxArea.setFrameStyle(QFrame::Panel);
    m_toolboxArea.setLayout(toolsLayout);

    //QVBoxLayout *toolboxLayout = new QVBoxLayout;
    //toolboxLayout->addWidget(&m_toolboxArea);

    m_outputLayout.addLayout(leftLayout);
    m_outputLayout.addLayout(rightLayout);
    m_outputLayout.addWidget(&m_toolboxArea);

    m_output->setLayout(&m_outputLayout);

    connect(hideToolsButton, &QPushButton::clicked, this, &CTaskWidget::onHideButtonClicked);

    QPushButton *showToolboxButton = new QPushButton("<<");
    QVBoxLayout *minimizedToolboxLayout = new QVBoxLayout;
    QPushButton *bothSolutionsButton2 = new QPushButton("B");
    QPushButton *studentSolutionsButton2 = new QPushButton("S");
    QPushButton *referenceSolutionsButton2 = new QPushButton("R");
    showToolboxButton->setMaximumWidth(15);
    bothSolutionsButton2->setMaximumWidth(15);
    studentSolutionsButton2->setMaximumWidth(15);
    referenceSolutionsButton2->setMaximumWidth(15);
    minimizedToolboxLayout->addWidget(showToolboxButton);
    minimizedToolboxLayout->addStretch();
    minimizedToolboxLayout->addWidget(bothSolutionsButton2);
    minimizedToolboxLayout->addWidget(studentSolutionsButton2);
    minimizedToolboxLayout->addWidget(referenceSolutionsButton2);
    minimizedToolboxLayout->addStretch();
    m_minimizedToolbox.setFrameShape(QFrame::Panel);
    m_minimizedToolbox.setSizePolicy(QSizePolicy::Maximum, QSizePolicy::Expanding);
    m_minimizedToolbox.setLayout(minimizedToolboxLayout);

    connect(showToolboxButton, &QPushButton::clicked, this, &CTaskWidget::onShowButtonClicked);
}

void CTaskWidget::onUploadSolutionClicked()
{
    QString filename = QFileDialog::getOpenFileName(this, "Open cpp solution file");
    m_uploadSolutionLineEdit.setText(filename);
}

void CTaskWidget::onCompileSolutionClicked()
{
    m_console.setText(m_uploadSolutionLineEdit.text() + " Compiled");
}

void CTaskWidget::onHideButtonClicked()
{
    QPropertyAnimation *hideToolboxAnimation = new QPropertyAnimation(&m_toolboxArea, "maximumWidth");
    hideToolboxAnimation->setDuration(500);
    hideToolboxAnimation->setStartValue(m_toolboxArea.width());
    hideToolboxAnimation->setEndValue(40);
    connect(hideToolboxAnimation, &QPropertyAnimation::finished, this, &CTaskWidget::onHideAnimationFinished);
    hideToolboxAnimation->start(QAbstractAnimation::DeleteWhenStopped);
}

void CTaskWidget::onHideAnimationFinished()
{
    m_outputLayout.removeItem(m_outputLayout.itemAt(2));
    m_toolboxArea.setHidden(true);
    m_minimizedToolbox.setHidden(false);
    m_outputLayout.addWidget(&m_minimizedToolbox);
}

void CTaskWidget::onShowButtonClicked()
{
    m_outputLayout.removeItem(m_outputLayout.itemAt(2));
    m_minimizedToolbox.setHidden(true);
    m_toolboxArea.setHidden(false);
    m_outputLayout.addWidget(&m_toolboxArea);

    QPropertyAnimation *showToolboxAnimation = new QPropertyAnimation(&m_toolboxArea, "maximumWidth");
    showToolboxAnimation->setDuration(500);
    showToolboxAnimation->setStartValue(40);
    showToolboxAnimation->setEndValue(m_toolboxArea.sizeHint().width());
    //connect(showToolboxAnimation, &QPropertyAnimation::finished, this, &CTaskWidget::onShowAnimationFinished);
    showToolboxAnimation->start(QAbstractAnimation::DeleteWhenStopped);
}

void CTaskWidget::onShowAnimationFinished()
{

}
