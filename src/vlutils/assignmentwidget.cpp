#include "assignmentwidget.h"

#include <QFile>
#include <QLabel>
#include <QWebEngineView>
#include <QHBoxLayout>
#include <QVBoxLayout>

CAssignmentWidget::CAssignmentWidget(QWidget *parent) : QWidget(parent)
{
    createUiElements();
    retranslateUi();
    setHtmlFromFile("../plugins/test.html");
}

void CAssignmentWidget::retranslateUi()
{
}

void CAssignmentWidget::setHtmlFromFile(const QString &filename)
{
    QFile input(filename);
    input.open(QIODevice::ReadOnly);
    m_page->setHtml(input.readAll());
}

void CAssignmentWidget::createUiElements()
{
    QHBoxLayout *mainLayout = new QHBoxLayout;

    m_page = new QWebEngineView;
    m_page->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding );
    mainLayout->addWidget(m_page);
    setLayout(mainLayout);
}
