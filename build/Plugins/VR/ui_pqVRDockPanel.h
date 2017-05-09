/********************************************************************************
** Form generated from reading UI file 'pqVRDockPanel.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PQVRDOCKPANEL_H
#define UI_PQVRDOCKPANEL_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>
#include "pqAnimatablePropertiesComboBox.h"
#include "pqAnimatableProxyComboBox.h"

QT_BEGIN_NAMESPACE

class Ui_VRDockPanel
{
public:
    QGridLayout *gridLayout;
    QListWidget *connectionsTable;
    QFrame *line_3;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *saveState;
    QPushButton *restoreState;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *startButton;
    QPushButton *stopButton;
    QHBoxLayout *horizontalLayout;
    pqAnimatableProxyComboBox *proxyCombo;
    pqAnimatablePropertiesComboBox *propertyCombo;
    QComboBox *stylesCombo;
    QListWidget *stylesTable;
    QFrame *line_2;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *addConnection;
    QSpacerItem *horizontalSpacer;
    QPushButton *editConnection;
    QPushButton *removeConnection;
    QLabel *label;
    QFrame *line;
    QLabel *label_2;
    QLabel *debugLabel;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *addStyle;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *editStyle;
    QPushButton *removeStyle;

    void setupUi(QWidget *VRDockPanel)
    {
        if (VRDockPanel->objectName().isEmpty())
            VRDockPanel->setObjectName(QStringLiteral("VRDockPanel"));
        VRDockPanel->resize(479, 613);
        gridLayout = new QGridLayout(VRDockPanel);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        connectionsTable = new QListWidget(VRDockPanel);
        connectionsTable->setObjectName(QStringLiteral("connectionsTable"));

        gridLayout->addWidget(connectionsTable, 1, 0, 1, 1);

        line_3 = new QFrame(VRDockPanel);
        line_3->setObjectName(QStringLiteral("line_3"));
        line_3->setFrameShape(QFrame::HLine);
        line_3->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(line_3, 10, 0, 1, 1);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        saveState = new QPushButton(VRDockPanel);
        saveState->setObjectName(QStringLiteral("saveState"));

        horizontalLayout_3->addWidget(saveState);

        restoreState = new QPushButton(VRDockPanel);
        restoreState->setObjectName(QStringLiteral("restoreState"));

        horizontalLayout_3->addWidget(restoreState);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);

        startButton = new QPushButton(VRDockPanel);
        startButton->setObjectName(QStringLiteral("startButton"));

        horizontalLayout_3->addWidget(startButton);

        stopButton = new QPushButton(VRDockPanel);
        stopButton->setObjectName(QStringLiteral("stopButton"));

        horizontalLayout_3->addWidget(stopButton);


        gridLayout->addLayout(horizontalLayout_3, 11, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        proxyCombo = new pqAnimatableProxyComboBox(VRDockPanel);
        proxyCombo->setObjectName(QStringLiteral("proxyCombo"));
        proxyCombo->setSizeAdjustPolicy(QComboBox::AdjustToContents);

        horizontalLayout->addWidget(proxyCombo);

        propertyCombo = new pqAnimatablePropertiesComboBox(VRDockPanel);
        propertyCombo->setObjectName(QStringLiteral("propertyCombo"));
        propertyCombo->setSizeAdjustPolicy(QComboBox::AdjustToContents);

        horizontalLayout->addWidget(propertyCombo);

        stylesCombo = new QComboBox(VRDockPanel);
        stylesCombo->setObjectName(QStringLiteral("stylesCombo"));
        stylesCombo->setSizeAdjustPolicy(QComboBox::AdjustToContents);

        horizontalLayout->addWidget(stylesCombo);

        horizontalLayout->setStretch(0, 1);
        horizontalLayout->setStretch(1, 1);
        horizontalLayout->setStretch(2, 1);

        gridLayout->addLayout(horizontalLayout, 6, 0, 1, 1);

        stylesTable = new QListWidget(VRDockPanel);
        stylesTable->setObjectName(QStringLiteral("stylesTable"));

        gridLayout->addWidget(stylesTable, 5, 0, 1, 1);

        line_2 = new QFrame(VRDockPanel);
        line_2->setObjectName(QStringLiteral("line_2"));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(line_2, 8, 0, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        addConnection = new QPushButton(VRDockPanel);
        addConnection->setObjectName(QStringLiteral("addConnection"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/QtWidgets/Icons/pqPlus16.png"), QSize(), QIcon::Normal, QIcon::Off);
        addConnection->setIcon(icon);

        horizontalLayout_2->addWidget(addConnection);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        editConnection = new QPushButton(VRDockPanel);
        editConnection->setObjectName(QStringLiteral("editConnection"));

        horizontalLayout_2->addWidget(editConnection);

        removeConnection = new QPushButton(VRDockPanel);
        removeConnection->setObjectName(QStringLiteral("removeConnection"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/QtWidgets/Icons/pqDelete16.png"), QSize(), QIcon::Normal, QIcon::Off);
        removeConnection->setIcon(icon1);

        horizontalLayout_2->addWidget(removeConnection);


        gridLayout->addLayout(horizontalLayout_2, 2, 0, 1, 1);

        label = new QLabel(VRDockPanel);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        line = new QFrame(VRDockPanel);
        line->setObjectName(QStringLiteral("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(line, 3, 0, 1, 1);

        label_2 = new QLabel(VRDockPanel);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout->addWidget(label_2, 4, 0, 1, 1);

        debugLabel = new QLabel(VRDockPanel);
        debugLabel->setObjectName(QStringLiteral("debugLabel"));

        gridLayout->addWidget(debugLabel, 9, 0, 1, 1);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        addStyle = new QPushButton(VRDockPanel);
        addStyle->setObjectName(QStringLiteral("addStyle"));
        addStyle->setIcon(icon);

        horizontalLayout_4->addWidget(addStyle);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_3);

        editStyle = new QPushButton(VRDockPanel);
        editStyle->setObjectName(QStringLiteral("editStyle"));

        horizontalLayout_4->addWidget(editStyle);

        removeStyle = new QPushButton(VRDockPanel);
        removeStyle->setObjectName(QStringLiteral("removeStyle"));
        removeStyle->setIcon(icon1);

        horizontalLayout_4->addWidget(removeStyle);


        gridLayout->addLayout(horizontalLayout_4, 7, 0, 1, 1);

        QWidget::setTabOrder(connectionsTable, addConnection);
        QWidget::setTabOrder(addConnection, editConnection);
        QWidget::setTabOrder(editConnection, removeConnection);
        QWidget::setTabOrder(removeConnection, stylesTable);
        QWidget::setTabOrder(stylesTable, proxyCombo);
        QWidget::setTabOrder(proxyCombo, propertyCombo);
        QWidget::setTabOrder(propertyCombo, stylesCombo);
        QWidget::setTabOrder(stylesCombo, addStyle);
        QWidget::setTabOrder(addStyle, editStyle);
        QWidget::setTabOrder(editStyle, removeStyle);
        QWidget::setTabOrder(removeStyle, saveState);
        QWidget::setTabOrder(saveState, restoreState);

        retranslateUi(VRDockPanel);

        QMetaObject::connectSlotsByName(VRDockPanel);
    } // setupUi

    void retranslateUi(QWidget *VRDockPanel)
    {
        VRDockPanel->setWindowTitle(QString());
        saveState->setText(QApplication::translate("VRDockPanel", "Save VR State", Q_NULLPTR));
        restoreState->setText(QApplication::translate("VRDockPanel", "Restore VR State", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        startButton->setToolTip(QApplication::translate("VRDockPanel", "<html><head/><body><p>Start listening for VR events on the configured connections.</p></body></html>", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        startButton->setText(QApplication::translate("VRDockPanel", "Start", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        stopButton->setToolTip(QApplication::translate("VRDockPanel", "<html><head/><body><p>Stop listening for VR events.</p></body></html>", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        stopButton->setText(QApplication::translate("VRDockPanel", "Stop", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        proxyCombo->setToolTip(QApplication::translate("VRDockPanel", "<html><head/><body><p>Select an object for interaction.</p></body></html>", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        propertyCombo->setToolTip(QApplication::translate("VRDockPanel", "<html><head/><body><p>Select the object's property for interaction.</p></body></html>", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        stylesCombo->setToolTip(QApplication::translate("VRDockPanel", "<html><head/><body><p>Select the type of interaction.</p></body></html>", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        addConnection->setToolTip(QApplication::translate("VRDockPanel", "<html><head/><body><p>Add a new VR connection.</p></body></html>", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        addConnection->setText(QApplication::translate("VRDockPanel", "Add...", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        editConnection->setToolTip(QApplication::translate("VRDockPanel", "<html><head/><body><p>Edit the selected VR connection.</p></body></html>", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        editConnection->setText(QApplication::translate("VRDockPanel", "Edit...", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        removeConnection->setToolTip(QApplication::translate("VRDockPanel", "<html><head/><body><p>Remove the selected VR connection.</p></body></html>", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        removeConnection->setText(QApplication::translate("VRDockPanel", "Remove", Q_NULLPTR));
        label->setText(QApplication::translate("VRDockPanel", "VR Connections:", Q_NULLPTR));
        label_2->setText(QApplication::translate("VRDockPanel", "Interactions:", Q_NULLPTR));
        debugLabel->setText(QApplication::translate("VRDockPanel", "TextLabel", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        addStyle->setToolTip(QApplication::translate("VRDockPanel", "<html><head/><body><p>Add a new interaction.</p></body></html>", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        addStyle->setText(QApplication::translate("VRDockPanel", "Add...", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        editStyle->setToolTip(QApplication::translate("VRDockPanel", "<html><head/><body><p>Edit the selected interaction.</p></body></html>", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        editStyle->setText(QApplication::translate("VRDockPanel", "Edit...", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        removeStyle->setToolTip(QApplication::translate("VRDockPanel", "<html><head/><body><p>Remove the selected interaction.</p></body></html>", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        removeStyle->setText(QApplication::translate("VRDockPanel", "Remove", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class VRDockPanel: public Ui_VRDockPanel {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PQVRDOCKPANEL_H
