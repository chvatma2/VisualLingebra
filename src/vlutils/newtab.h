#ifndef CNEWTAB_H
#define CNEWTAB_H

#include "tabs.h"
#include "selectiontreemodel.h"

#include <QLabel>
#include <QTextEdit>
#include <QTreeView>
#include <QPushButton>
#include <QVBoxLayout>

class CNewTab : public ITabs
{
    Q_OBJECT
public:
    CNewTab(QWidget *parent = 0);
    void retranslateUi() override;
private:
    void setupLeftLayout();
    void setupCenterLayout();
    void setupRightLayout();

    QLabel m_selectionLabel;
    QTreeView * m_view = nullptr;
    QLabel m_selectionDescriptionLabel;
    QTextEdit m_selectionDescription;
    QPushButton m_openTaskButton;
    QLabel m_loadTaskTitle;
    QLabel m_loadTaskDescription;
    QPushButton m_loadTaskButton;
    QVBoxLayout m_leftLayout;
    QVBoxLayout m_centerLayout;
    QVBoxLayout m_rightLayout;
    bool m_isDescriptionPresent;
    CSelectionTreeModel* m_model = nullptr;

private slots:
    void treeViewItemSelected();
    void onOpenTaskClicked();
    void onLoadTaskClicked();

signals:
    void openTask(const QString &pluginpath, const QString &name);
};

#endif // CNEWTAB_H
