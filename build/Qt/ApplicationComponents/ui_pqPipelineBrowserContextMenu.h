/********************************************************************************
** Form generated from reading UI file 'pqPipelineBrowserContextMenu.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PQPIPELINEBROWSERCONTEXTMENU_H
#define UI_PQPIPELINEBROWSERCONTEXTMENU_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_pqPipelineBrowserContextMenu
{
public:
    QAction *actionPBChangeInput;
    QAction *actionPBDelete;
    QAction *actionPBHideAll;
    QAction *actionPBCopy;
    QAction *actionPBPaste;
    QAction *actionPBIgnoreTime;
    QAction *actionPBLinkSelection;
    QAction *actionPBOpen;
    QAction *actionPBCreateCustomFilter;
    QAction *actionPBReloadFiles;

    void setupUi(QWidget *pqPipelineBrowserContextMenu)
    {
        if (pqPipelineBrowserContextMenu->objectName().isEmpty())
            pqPipelineBrowserContextMenu->setObjectName(QStringLiteral("pqPipelineBrowserContextMenu"));
        pqPipelineBrowserContextMenu->resize(100, 30);
        actionPBChangeInput = new QAction(pqPipelineBrowserContextMenu);
        actionPBChangeInput->setObjectName(QStringLiteral("actionPBChangeInput"));
        actionPBDelete = new QAction(pqPipelineBrowserContextMenu);
        actionPBDelete->setObjectName(QStringLiteral("actionPBDelete"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/QtWidgets/Icons/pqDelete24.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionPBDelete->setIcon(icon);
        actionPBHideAll = new QAction(pqPipelineBrowserContextMenu);
        actionPBHideAll->setObjectName(QStringLiteral("actionPBHideAll"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/pqWidgets/Icons/pqEyeball16.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionPBHideAll->setIcon(icon1);
        actionPBCopy = new QAction(pqPipelineBrowserContextMenu);
        actionPBCopy->setObjectName(QStringLiteral("actionPBCopy"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/pqWidgets/Icons/pqCopy22.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionPBCopy->setIcon(icon2);
        actionPBPaste = new QAction(pqPipelineBrowserContextMenu);
        actionPBPaste->setObjectName(QStringLiteral("actionPBPaste"));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/pqWidgets/Icons/pqPaste22.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionPBPaste->setIcon(icon3);
        actionPBIgnoreTime = new QAction(pqPipelineBrowserContextMenu);
        actionPBIgnoreTime->setObjectName(QStringLiteral("actionPBIgnoreTime"));
        actionPBIgnoreTime->setCheckable(true);
        actionPBLinkSelection = new QAction(pqPipelineBrowserContextMenu);
        actionPBLinkSelection->setObjectName(QStringLiteral("actionPBLinkSelection"));
        actionPBOpen = new QAction(pqPipelineBrowserContextMenu);
        actionPBOpen->setObjectName(QStringLiteral("actionPBOpen"));
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/pqWidgets/Icons/pqOpen24.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionPBOpen->setIcon(icon4);
        actionPBOpen->setShortcutContext(Qt::WidgetShortcut);
        actionPBCreateCustomFilter = new QAction(pqPipelineBrowserContextMenu);
        actionPBCreateCustomFilter->setObjectName(QStringLiteral("actionPBCreateCustomFilter"));
        actionPBReloadFiles = new QAction(pqPipelineBrowserContextMenu);
        actionPBReloadFiles->setObjectName(QStringLiteral("actionPBReloadFiles"));

        pqPipelineBrowserContextMenu->addAction(actionPBOpen);
        pqPipelineBrowserContextMenu->addAction(actionPBHideAll);
        pqPipelineBrowserContextMenu->addAction(actionPBCopy);
        pqPipelineBrowserContextMenu->addAction(actionPBPaste);
        pqPipelineBrowserContextMenu->addAction(actionPBChangeInput);
        pqPipelineBrowserContextMenu->addAction(actionPBReloadFiles);
        pqPipelineBrowserContextMenu->addAction(actionPBIgnoreTime);
        pqPipelineBrowserContextMenu->addAction(actionPBDelete);
        pqPipelineBrowserContextMenu->addAction(actionPBCreateCustomFilter);
        pqPipelineBrowserContextMenu->addAction(actionPBLinkSelection);

        retranslateUi(pqPipelineBrowserContextMenu);

        QMetaObject::connectSlotsByName(pqPipelineBrowserContextMenu);
    } // setupUi

    void retranslateUi(QWidget *pqPipelineBrowserContextMenu)
    {
        actionPBChangeInput->setText(QApplication::translate("pqPipelineBrowserContextMenu", "Change &Input...", Q_NULLPTR));
        actionPBChangeInput->setIconText(QApplication::translate("pqPipelineBrowserContextMenu", "Change Input...", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        actionPBChangeInput->setToolTip(QApplication::translate("pqPipelineBrowserContextMenu", "Change a Filter's Input", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        actionPBChangeInput->setStatusTip(QApplication::translate("pqPipelineBrowserContextMenu", "Change a Filter's Input", Q_NULLPTR));
#endif // QT_NO_STATUSTIP
        actionPBDelete->setText(QApplication::translate("pqPipelineBrowserContextMenu", "&Delete", Q_NULLPTR));
#ifndef QT_NO_STATUSTIP
        actionPBDelete->setStatusTip(QApplication::translate("pqPipelineBrowserContextMenu", "Delete", Q_NULLPTR));
#endif // QT_NO_STATUSTIP
        actionPBHideAll->setText(QApplication::translate("pqPipelineBrowserContextMenu", "&Hide All", Q_NULLPTR));
#ifndef QT_NO_STATUSTIP
        actionPBHideAll->setStatusTip(QApplication::translate("pqPipelineBrowserContextMenu", "Hide all source outputs in the pipeline", Q_NULLPTR));
#endif // QT_NO_STATUSTIP
        actionPBCopy->setText(QApplication::translate("pqPipelineBrowserContextMenu", "&Copy", Q_NULLPTR));
#ifndef QT_NO_STATUSTIP
        actionPBCopy->setStatusTip(QApplication::translate("pqPipelineBrowserContextMenu", "Copy Properties", Q_NULLPTR));
#endif // QT_NO_STATUSTIP
        actionPBPaste->setText(QApplication::translate("pqPipelineBrowserContextMenu", "&Paste", Q_NULLPTR));
#ifndef QT_NO_STATUSTIP
        actionPBPaste->setStatusTip(QApplication::translate("pqPipelineBrowserContextMenu", "Paste Properties", Q_NULLPTR));
#endif // QT_NO_STATUSTIP
        actionPBIgnoreTime->setText(QApplication::translate("pqPipelineBrowserContextMenu", "Ignore Time", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        actionPBIgnoreTime->setToolTip(QApplication::translate("pqPipelineBrowserContextMenu", "Disregard this source/filter's time from animations", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        actionPBIgnoreTime->setStatusTip(QApplication::translate("pqPipelineBrowserContextMenu", "Disregard this source/filter's time from animations", Q_NULLPTR));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        actionPBIgnoreTime->setWhatsThis(QApplication::translate("pqPipelineBrowserContextMenu", "Disregard this source/filter's time from animations", Q_NULLPTR));
#endif // QT_NO_WHATSTHIS
        actionPBLinkSelection->setText(QApplication::translate("pqPipelineBrowserContextMenu", "Link with selection", Q_NULLPTR));
        actionPBLinkSelection->setIconText(QApplication::translate("pqPipelineBrowserContextMenu", "Link with selection", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        actionPBLinkSelection->setToolTip(QApplication::translate("pqPipelineBrowserContextMenu", "Link this source and current selected source as a selection link", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        actionPBLinkSelection->setStatusTip(QApplication::translate("pqPipelineBrowserContextMenu", "Link this source and current selected source as a selection link", Q_NULLPTR));
#endif // QT_NO_STATUSTIP
        actionPBOpen->setText(QApplication::translate("pqPipelineBrowserContextMenu", "&Open", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        actionPBOpen->setToolTip(QApplication::translate("pqPipelineBrowserContextMenu", "Open", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        actionPBOpen->setStatusTip(QApplication::translate("pqPipelineBrowserContextMenu", "Open", Q_NULLPTR));
#endif // QT_NO_STATUSTIP
        actionPBCreateCustomFilter->setText(QApplication::translate("pqPipelineBrowserContextMenu", "&Create Custom Filter...", Q_NULLPTR));
        actionPBReloadFiles->setText(QApplication::translate("pqPipelineBrowserContextMenu", "Reload Files", Q_NULLPTR));
        actionPBReloadFiles->setIconText(QApplication::translate("pqPipelineBrowserContextMenu", "Reload Files", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        actionPBReloadFiles->setToolTip(QApplication::translate("pqPipelineBrowserContextMenu", "Reload data files in case they were changed externally.", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        Q_UNUSED(pqPipelineBrowserContextMenu);
    } // retranslateUi

};

namespace Ui {
    class pqPipelineBrowserContextMenu: public Ui_pqPipelineBrowserContextMenu {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PQPIPELINEBROWSERCONTEXTMENU_H
