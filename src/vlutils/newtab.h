#ifndef CNEWTAB_H
#define CNEWTAB_H

#include <QWidget>
#include <QLabel>
#include <QTextEdit>
#include <QTreeView>
#include <QPushButton>
#include <QVBoxLayout>

enum class Tasks {
    MOVEMENT2D,
    HAMMING,
    INDEPENDENCE
};

class CNewTab : public QWidget
{
    Q_OBJECT
public:
    CNewTab(QWidget *parent = 0);

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

private slots:
    void treeViewItemSelected();
    void openTaskClicked();

signals:
    void openTask(Tasks task);
};

#endif // CNEWTAB_H
