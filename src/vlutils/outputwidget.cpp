#include "outputwidget.h"

#include <QVBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QHBoxLayout>
#include <QScrollArea>
#include <QFrame>
#include <QPropertyAnimation>

COutputWidget::COutputWidget(TaskWidgets widgets, QWidget *parent) : QWidget(parent)
{
    m_referenceView = widgets.referenceWidget;
    m_studentView = widgets.studentWidget;
    m_taskControlPanel = widgets.controlPanel;
    createUiElements();
    retranslateUi();
}

void COutputWidget::retranslateUi()
{
    m_leftLabel->setText(tr("Student's implementation"));
    m_rightLabel->setText(tr("Reference implementation"));
    m_toolboxLabel->setText(tr("Toolbox"));
    if(m_missingStudentImplementationLabel) {
        m_missingStudentImplementationLabel->setText(tr("Implementation missing"));
    }
    if(m_missingImplementationLabel) {
        m_missingImplementationLabel->setText(tr("Implementation missing"));
    }
}

void COutputWidget::setReferenceView(QWidget *referenceView)
{
    m_referenceView = referenceView;
}

void COutputWidget::setStudentView(QWidget *studentView)
{
    m_studentView = studentView;
}

void COutputWidget::onStudentCodeCompiled()
{
    //delete m_leftLayout;
    while (QLayoutItem* item = m_leftLayout->takeAt(1)) {
        if (QWidget* widget = item->widget()) {
            widget->deleteLater();
        }
        delete item;
    }
    m_studentView->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    m_leftLayout->addWidget(m_leftLabel, 0, Qt::AlignTop | Qt::AlignCenter);
    m_leftLayout->addWidget(m_studentView);
    m_leftLayout->update();
}

void COutputWidget::createUiElements()
{
    QFont font;
    font.setPointSize(14);

    m_outputLayout = new QHBoxLayout;

    m_leftLayout = new QVBoxLayout;
    QVBoxLayout *rightLayout = new QVBoxLayout;
    QVBoxLayout *toolsLayout = new QVBoxLayout;

    m_leftLabel = new QLabel;
    m_rightLabel = new QLabel;
    m_leftLabel->setFont(font);
    m_rightLabel->setFont(font);

    m_leftLayout->addWidget(m_leftLabel, 0, Qt::AlignTop | Qt::AlignCenter);
    rightLayout->addWidget(m_rightLabel, 0, Qt::AlignTop | Qt::AlignCenter);

    QPushButton *hideToolsButton = new QPushButton(">>");
    hideToolsButton->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);

    m_bothSolutionsButton = new QPushButton(QIcon("../assets/bothwindows.png"), "");
    m_studentSolutionsButton = new QPushButton(QIcon("../assets/studentwindow.png"), "");
    m_referenceSolutionsButton = new QPushButton(QIcon("../assets/referencewindow.png"), "");
    m_bothSolutionsButton->setToolTip(tr("Both solutions"));
    m_studentSolutionsButton->setToolTip(tr("Student's solution"));
    m_referenceSolutionsButton->setToolTip(tr("Reference solution"));

    QHBoxLayout *showPartOfScreenButtonsLayout = new QHBoxLayout;
    showPartOfScreenButtonsLayout->addWidget(m_bothSolutionsButton);
    m_bothSolutionsButton->setDown(true);
    showPartOfScreenButtonsLayout->addWidget(m_studentSolutionsButton);
    showPartOfScreenButtonsLayout->addWidget(m_referenceSolutionsButton);
    showPartOfScreenButtonsLayout->addStretch();

    m_displayButtonsLabel = new QLabel("Display");
    QHBoxLayout *labelLayout = new QHBoxLayout;
    m_toolboxLabel = new QLabel;
    font.setPointSize(12);
    m_toolboxLabel->setFont(font);
    hideToolsButton->setMaximumWidth(40);
    labelLayout->addWidget(m_toolboxLabel);
    labelLayout->addWidget(hideToolsButton, 0, Qt::AlignRight);
    toolsLayout->addLayout(labelLayout);

    QFrame *displayFrame = new QFrame;
    QVBoxLayout* displayLayout = new QVBoxLayout;
    displayLayout->addWidget(m_displayButtonsLabel);
    displayLayout->addLayout(showPartOfScreenButtonsLayout);
    displayFrame->setLayout(displayLayout);
    displayFrame->setFrameStyle(QFrame::Panel | QFrame::Raised);
    displayFrame->setLineWidth(2);
    toolsLayout->addWidget(displayFrame);
    toolsLayout->addStretch();

    m_toolboxArea = new QScrollArea;
    m_toolboxArea->setWidgetResizable(true);
    m_toolboxArea->setSizePolicy(QSizePolicy::Maximum, QSizePolicy::Expanding);
    m_toolboxArea->setFrameStyle(QFrame::Panel);
    m_toolboxArea->setLayout(toolsLayout);
    m_toolboxArea->setFrameStyle(QFrame::Box | QFrame::Raised);
    m_toolboxArea->setLineWidth(1);


    if(m_referenceView != nullptr) {
        m_referenceView->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        rightLayout->addWidget(m_referenceView);
    } else {
        m_missingImplementationLabel = new QLabel(tr("Implementation missing"));
        m_missingImplementationLabel->setFont(font);
        rightLayout->addStretch();
        rightLayout->addWidget(m_missingImplementationLabel, 0, Qt::AlignCenter | Qt::AlignHCenter);
        rightLayout->addStretch();
    }

    m_missingStudentImplementationLabel = new QLabel(tr("Implementation missing"));
    m_missingStudentImplementationLabel->setFont(font);
    m_leftLayout->addStretch();
    m_leftLayout->addWidget(m_missingStudentImplementationLabel, 0, Qt::AlignCenter | Qt::AlignHCenter);
    m_leftLayout->addStretch();

    if(m_taskControlPanel != nullptr) {
        toolsLayout->addWidget(m_taskControlPanel);
    }

    m_referenceWidget = new QWidget;
    m_referenceWidget->setLayout(rightLayout);
    m_studentWidget = new QWidget;
    m_studentWidget->setLayout(m_leftLayout);

    m_outputLayout->addWidget(m_studentWidget, 1);
    m_outputLayout->addWidget(m_referenceWidget, 1);
    m_outputLayout->addWidget(m_toolboxArea);

    setLayout(m_outputLayout);

    connect(hideToolsButton, &QPushButton::clicked, this, &COutputWidget::onHideButtonClicked);
    connect(m_bothSolutionsButton, &QPushButton::clicked, this, &COutputWidget::onBothViewsSelected);
    connect(m_studentSolutionsButton, &QPushButton::clicked, this, &COutputWidget::onStudentViewSelected);
    connect(m_referenceSolutionsButton, &QPushButton::clicked, this, &COutputWidget::onReferenceViewSelected);

    retranslateUi();
    m_minimizedToolbox = new QFrame;
    QPushButton *showToolboxButton = new QPushButton("<<");
    QVBoxLayout *minimizedToolboxLayout = new QVBoxLayout;
    m_bothSolutionsButtonMinimized = new QPushButton(QIcon("../assets/bothwindows.png"), "");
    m_studentSolutionsButtonMinimized = new QPushButton(QIcon("../assets/studentwindow.png"), "");
    m_referenceSolutionsButtonMinimized = new QPushButton(QIcon("../assets/referencewindow.png"), "");
    showToolboxButton->setMaximumWidth(30);
    minimizedToolboxLayout->addWidget(showToolboxButton);
    minimizedToolboxLayout->addStretch();
    minimizedToolboxLayout->addWidget(m_bothSolutionsButtonMinimized);
    m_bothSolutionsButtonMinimized->setDown(true);
    minimizedToolboxLayout->addWidget(m_studentSolutionsButtonMinimized);
    minimizedToolboxLayout->addWidget(m_referenceSolutionsButtonMinimized);
    minimizedToolboxLayout->addStretch();
    m_minimizedToolbox->setFrameShape(QFrame::Panel);
    m_minimizedToolbox->setSizePolicy(QSizePolicy::Maximum, QSizePolicy::Expanding);
    m_minimizedToolbox->setLayout(minimizedToolboxLayout);

    connect(showToolboxButton, &QPushButton::clicked, this, &COutputWidget::onShowButtonClicked);
    connect(m_bothSolutionsButtonMinimized, &QPushButton::clicked, this, &COutputWidget::onBothViewsSelected);
    connect(m_studentSolutionsButtonMinimized, &QPushButton::clicked, this, &COutputWidget::onStudentViewSelected);
    connect(m_referenceSolutionsButtonMinimized, &QPushButton::clicked, this, &COutputWidget::onReferenceViewSelected);

    //    if(!m_hasStudentImplementation) {
    //        onReferenceViewSelected();
    //    }
}

void COutputWidget::onBothViewsSelected()
{
    m_referenceWidget->setHidden(false);
    m_studentWidget->setHidden(false);
    m_bothSolutionsButtonMinimized->setDown(true);
    m_referenceSolutionsButtonMinimized->setDown(false);
    m_studentSolutionsButtonMinimized->setDown(false);
    m_bothSolutionsButton->setDown(true);
    m_referenceSolutionsButton->setDown(false);
    m_studentSolutionsButton->setDown(false);
}

void COutputWidget::onStudentViewSelected()
{
    m_referenceWidget->setHidden(true);
    m_studentWidget->setHidden(false);
    m_bothSolutionsButtonMinimized->setDown(false);
    m_referenceSolutionsButtonMinimized->setDown(false);
    m_studentSolutionsButtonMinimized->setDown(true);
    m_bothSolutionsButton->setDown(false);
    m_referenceSolutionsButton->setDown(false);
    m_studentSolutionsButton->setDown(true);
}

void COutputWidget::onReferenceViewSelected()
{
    m_referenceWidget->setHidden(false);
    m_studentWidget->setHidden(true);
    m_bothSolutionsButtonMinimized->setDown(false);
    m_referenceSolutionsButtonMinimized->setDown(true);
    m_studentSolutionsButtonMinimized->setDown(false);
    m_bothSolutionsButton->setDown(false);
    m_referenceSolutionsButton->setDown(true);
    m_studentSolutionsButton->setDown(false);
}

void COutputWidget::onShowButtonClicked()
{
    m_outputLayout->removeItem(m_outputLayout->itemAt(2));
    m_minimizedToolbox->setHidden(true);
    m_toolboxArea->setHidden(false);
    m_outputLayout->addWidget(m_toolboxArea);

    QPropertyAnimation *showToolboxAnimation = new QPropertyAnimation(m_toolboxArea, "maximumWidth");
    showToolboxAnimation->setDuration(200);
    showToolboxAnimation->setStartValue(50);
    showToolboxAnimation->setEndValue(m_toolboxArea->sizeHint().width());
    showToolboxAnimation->start(QAbstractAnimation::DeleteWhenStopped);
}

void COutputWidget::onHideButtonClicked()
{
    QPropertyAnimation *hideToolboxAnimation = new QPropertyAnimation(m_toolboxArea, "maximumWidth");
    hideToolboxAnimation->setDuration(200);
    hideToolboxAnimation->setStartValue(m_toolboxArea->width());
    hideToolboxAnimation->setEndValue(50);
    connect(hideToolboxAnimation, &QPropertyAnimation::finished, this, &COutputWidget::onHideAnimationFinished);
    hideToolboxAnimation->start(QAbstractAnimation::DeleteWhenStopped);
}

void COutputWidget::onHideAnimationFinished()
{
    m_outputLayout->removeItem(m_outputLayout->itemAt(2));
    m_toolboxArea->setHidden(true);
    m_minimizedToolbox->setHidden(false);
    m_outputLayout->addWidget(m_minimizedToolbox);
}
