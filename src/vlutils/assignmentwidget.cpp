#include "assignmentwidget.h"

#include <QFile>
#include <QFileInfo>
#include <QLabel>
#include <QWebEngineView>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QDir>
#include <QMessageBox>

CAssignmentWidget::CAssignmentWidget(const QString &pluginpath, QWidget *parent) : QWidget(parent)
{
    createUiElements();
    retranslateUi();
    setHtmlFromFile("../plugins/" + pluginpath.mid(0, pluginpath.indexOf('.')) + "/" + pluginpath.mid(0, pluginpath.indexOf('.')) + ".html");
}

void CAssignmentWidget::retranslateUi()
{
}

void CAssignmentWidget::setHtmlFromFile(const QString &filename)
{
    QFile input(filename);
    if(!input.open(QIODevice::ReadOnly)) {
        QMessageBox msg;
        msg.setText("Selected task is not implemented in this demo version.");
        msg.exec();
        return;
    }
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
