#include "taskwidget.h"

#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QFile>
#include <QListView>
#include <QFileDialog>
#include <QPropertyAnimation>
#include <QSplitter>
#include <QStringListModel>

CTaskWidget::CTaskWidget(QWidget *parent) : /*QTabWidget(parent),*/ ITabs(parent)
{
    setAssignementWidget();
    setImplementationWidget();
    setOutputWidget();

    m_assignement->setName("Assignement");
    m_implementation->setName("Implementation");
    m_output->setName("Output");

    m_tabWidget.addTab(m_assignement, QIcon(), tr("Assignement"));
    m_tabWidget.addTab(m_implementation, QIcon(), tr("Implementation"));
    m_tabWidget.addTab(m_output, QIcon(), tr("Output"));

    m_tabWidget.setTabPosition(QTabWidget::TabPosition::South);
    QHBoxLayout *mainLayout = new QHBoxLayout;
    mainLayout->addWidget(&m_tabWidget);
    setLayout(mainLayout);
}

void CTaskWidget::retranslateUi()
{
    m_tabWidget.setTabText(m_tabWidget.indexOf(m_assignement), tr("Assignement"));
    m_tabWidget.setTabText(m_tabWidget.indexOf(m_implementation), tr("Implementation"));
    m_tabWidget.setTabText(m_tabWidget.indexOf(m_output), tr("Output"));

    m_uploadSolutionButton->setText(tr("Upload solution"));
    m_compileSolutionButton->setText(tr("Compile"));
    m_solutionLabel->setText(tr("Solution"));
    m_consoleLabel->setText(tr("Compiler output"));
    m_inputsLabel->setText(tr("Inputs"));
    m_loadInputsButton->setText(tr("Load inputs"));
    m_leftLabel->setText(tr("Student's implementation"));
    m_rightLabel->setText(tr("Reference implementation"));
}

void CTaskWidget::setAssignementWidget()
{
    QHBoxLayout *mainLayout = new QHBoxLayout;

    QFile input("../plugins/test.html");
    input.open(QIODevice::ReadOnly);

    m_assignement = new ITabs;
    m_page.setHtml(input.readAll());
    m_page.setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding );
    mainLayout->addWidget(&m_page);

    QWidget *indexWidget = new QWidget;
    QVBoxLayout *indexLayout = new QVBoxLayout;
    indexLayout->addWidget(new QLabel("Index"));

    QStringListModel *indexModel = new QStringListModel;
    QStringList list;
    list << "Introduction" << "Chapter I" << "Chapter II";
    indexModel->setStringList(list);
    m_index.setModel(indexModel);

    indexLayout->addWidget(&m_index);

    indexWidget->setLayout(indexLayout);
    indexWidget->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Expanding);
    mainLayout->addWidget(indexWidget);
    m_assignement->setLayout(mainLayout);
}

void CTaskWidget::setImplementationWidget()
{
    QFont font;
    font.setPointSize(14);

    m_implementation = new ITabs;

    QHBoxLayout *mainLayout = new QHBoxLayout;

    QVBoxLayout *inputsLayout = new QVBoxLayout;
    QVBoxLayout *uploadSolutionLayout = new QVBoxLayout;

    m_uploadSolutionButton = new QPushButton(tr("Upload solution"));
    m_compileSolutionButton = new QPushButton(tr("Compile"));
    m_solutionLabel = new QLabel(tr("Solution"));
    m_solutionLabel->setFont(font);
    m_uploadSolutionButton->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    m_compileSolutionButton->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);

    m_uploadSolutionLineEdit.setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);

    m_consoleLabel = new QLabel(tr("Compiler output"));
    QPalette palette = m_console.palette();
    palette.setColor(QPalette::Base, Qt::black);
    palette.setColor(QPalette::Text, Qt::white);
    m_console.setPalette(palette);
    m_console.setReadOnly(true);

    uploadSolutionLayout->addWidget(m_solutionLabel);
    uploadSolutionLayout->addWidget(m_uploadSolutionButton);
    uploadSolutionLayout->addWidget(&m_uploadSolutionLineEdit);
    uploadSolutionLayout->addWidget(m_compileSolutionButton);
    uploadSolutionLayout->addWidget(m_consoleLabel);
    uploadSolutionLayout->addWidget(&m_console);

    m_inputsLabel = new QLabel(tr("Inputs"));
    m_loadInputsButton = new QPushButton(tr("Load inputs"));
    m_inputsList = new QListView;
    m_stringModel = new QStringListModel;
    m_inputsList->setModel(m_stringModel);
    m_inputsLabel->setFont(font);

    inputsLayout->addWidget(m_inputsLabel);
    inputsLayout->addWidget(m_loadInputsButton);
    inputsLayout->addWidget(m_inputsList);

    mainLayout->addLayout(uploadSolutionLayout, 2);
    QWidget *inputsWidget = new QWidget;
    inputsWidget->setLayout(inputsLayout);
    inputsWidget->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Expanding);
    mainLayout->addWidget(inputsWidget);

    m_implementation->setLayout(mainLayout);

    connect(m_uploadSolutionButton, &QPushButton::clicked, this, &CTaskWidget::onUploadSolutionClicked);
    connect(m_compileSolutionButton, &QPushButton::clicked, this, &CTaskWidget::onCompileSolutionClicked);
    connect(m_loadInputsButton, &QPushButton::clicked, this, &CTaskWidget::onLoadInputClicked);
}

void CTaskWidget::setOutputWidget()
{
    QFont font;
    font.setPointSize(14);

    m_output = new ITabs;

    QVBoxLayout *leftLayout = new QVBoxLayout;
    QVBoxLayout *rightLayout = new QVBoxLayout;
    QVBoxLayout *toolsLayout = new QVBoxLayout;

    m_leftLabel = new QLabel(tr("Student's implementation"));
    m_rightLabel = new QLabel(tr("Reference implementation"));
    leftLayout->addWidget(m_leftLabel, 0, Qt::AlignTop | Qt::AlignCenter);
    rightLayout->addWidget(m_rightLabel, 0, Qt::AlignTop | Qt::AlignCenter);

    m_leftLabel->setFont(font);
    m_rightLabel->setFont(font);

    QPushButton *hideToolsButton = new QPushButton(">>");
    hideToolsButton->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);

    m_bothSolutionsButton = new QPushButton("B");
    m_studentSolutionsButton = new QPushButton("S");
    m_referenceSolutionsButton = new QPushButton("R");

    QHBoxLayout *showPartOfScreenButtonsLayout = new QHBoxLayout;
    showPartOfScreenButtonsLayout->addWidget(m_bothSolutionsButton);
    m_bothSolutionsButton->setDown(true);
    showPartOfScreenButtonsLayout->addWidget(m_studentSolutionsButton);
    showPartOfScreenButtonsLayout->addWidget(m_referenceSolutionsButton);

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

    m_referenceView = new QWidget;
    m_referenceView->setLayout(rightLayout);
    m_studentView = new QWidget;
    m_studentView->setLayout(leftLayout);

    m_outputLayout.addWidget(m_studentView);
    m_outputLayout.addWidget(m_referenceView);
    m_outputLayout.addWidget(&m_toolboxArea);

    m_output->setLayout(&m_outputLayout);

    connect(hideToolsButton, &QPushButton::clicked, this, &CTaskWidget::onHideButtonClicked);
    connect(m_bothSolutionsButton, &QPushButton::clicked, this, &CTaskWidget::onBothViewsSelected);
    connect(m_studentSolutionsButton, &QPushButton::clicked, this, &CTaskWidget::onStudentViewSelected);
    connect(m_referenceSolutionsButton, &QPushButton::clicked, this, &CTaskWidget::onReferenceViewSelected);

    QPushButton *showToolboxButton = new QPushButton("<<");
    QVBoxLayout *minimizedToolboxLayout = new QVBoxLayout;
    m_bothSolutionsButton2 = new QPushButton("B");
    m_studentSolutionsButton2 = new QPushButton("S");
    m_referenceSolutionsButton2 = new QPushButton("R");
    showToolboxButton->setMaximumWidth(15);
    m_bothSolutionsButton2->setMaximumWidth(15);
    m_studentSolutionsButton2->setMaximumWidth(15);
    m_referenceSolutionsButton2->setMaximumWidth(15);
    minimizedToolboxLayout->addWidget(showToolboxButton);
//    minimizedToolboxLayout->addStretch();
    minimizedToolboxLayout->addWidget(m_bothSolutionsButton2);
    m_bothSolutionsButton2->setDown(true);
    minimizedToolboxLayout->addWidget(m_studentSolutionsButton2);
    minimizedToolboxLayout->addWidget(m_referenceSolutionsButton2);
    minimizedToolboxLayout->addStretch();
    m_minimizedToolbox.setFrameShape(QFrame::Panel);
    m_minimizedToolbox.setSizePolicy(QSizePolicy::Maximum, QSizePolicy::Expanding);
    m_minimizedToolbox.setLayout(minimizedToolboxLayout);

    connect(showToolboxButton, &QPushButton::clicked, this, &CTaskWidget::onShowButtonClicked);
    connect(m_bothSolutionsButton2, &QPushButton::clicked, this, &CTaskWidget::onBothViewsSelected);
    connect(m_studentSolutionsButton2, &QPushButton::clicked, this, &CTaskWidget::onStudentViewSelected);
    connect(m_referenceSolutionsButton2, &QPushButton::clicked, this, &CTaskWidget::onReferenceViewSelected);
}

void CTaskWidget::onUploadSolutionClicked()
{
    QString filename = QFileDialog::getOpenFileName(this, tr("Open cpp solution file"));
    m_uploadSolutionLineEdit.setText(filename);
}

void CTaskWidget::onLoadInputClicked()
{
    QString filename = QFileDialog::getOpenFileName(this, tr("Select input file"));
    QFileInfo info(filename);
    m_inputs << info.fileName();
    m_stringModel->setStringList(m_inputs);
}

void CTaskWidget::onCompileSolutionClicked()
{
    m_console.setText(m_uploadSolutionLineEdit.text() + " Compiled");
}

void CTaskWidget::onHideButtonClicked()
{
    QPropertyAnimation *hideToolboxAnimation = new QPropertyAnimation(&m_toolboxArea, "maximumWidth");
    hideToolboxAnimation->setDuration(200);
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
    showToolboxAnimation->setDuration(200);
    showToolboxAnimation->setStartValue(40);
    showToolboxAnimation->setEndValue(m_toolboxArea.sizeHint().width());
    //connect(showToolboxAnimation, &QPropertyAnimation::finished, this, &CTaskWidget::onShowAnimationFinished);
    showToolboxAnimation->start(QAbstractAnimation::DeleteWhenStopped);
}

void CTaskWidget::onShowAnimationFinished()
{

}

void CTaskWidget::onBothViewsSelected()
{
    m_referenceView->setHidden(false);
    m_studentView->setHidden(false);
    m_bothSolutionsButton2->setDown(true);
    m_referenceSolutionsButton2->setDown(false);
    m_studentSolutionsButton2->setDown(false);
    m_bothSolutionsButton->setDown(true);
    m_referenceSolutionsButton->setDown(false);
    m_studentSolutionsButton->setDown(false);
}

void CTaskWidget::onStudentViewSelected()
{
    m_referenceView->setHidden(true);
    m_studentView->setHidden(false);
    m_bothSolutionsButton2->setDown(false);
    m_referenceSolutionsButton2->setDown(false);
    m_studentSolutionsButton2->setDown(true);
    m_bothSolutionsButton->setDown(false);
    m_referenceSolutionsButton->setDown(false);
    m_studentSolutionsButton->setDown(true);
}

void CTaskWidget::onReferenceViewSelected()
{
    m_referenceView->setHidden(false);
    m_studentView->setHidden(true);
    m_bothSolutionsButton2->setDown(false);
    m_referenceSolutionsButton2->setDown(true);
    m_studentSolutionsButton2->setDown(false);
    m_bothSolutionsButton->setDown(false);
    m_referenceSolutionsButton->setDown(true);
    m_studentSolutionsButton->setDown(false);
}
