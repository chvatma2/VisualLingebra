#include "assignementwidget.h"

#include <QFile>
#include <QLabel>
#include <QWebEngineView>
#include <QHBoxLayout>
#include <QVBoxLayout>

CAssignementWidget::CAssignementWidget(QWidget *parent) : QWidget(parent)
{
    createUiElements();
    retranslateUi();
    setHtmlFromFile("../plugins/test.html");
}

void CAssignementWidget::retranslateUi()
{
}

void CAssignementWidget::setHtmlFromFile(const QString &filename)
{
    QFile input(filename);
    input.open(QIODevice::ReadOnly);
    m_page->setHtml(input.readAll());
}

void CAssignementWidget::createUiElements()
{
    QHBoxLayout *mainLayout = new QHBoxLayout;

    m_page = new QWebEngineView;
    m_page->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding );
    mainLayout->addWidget(m_page);
    setLayout(mainLayout);
}
