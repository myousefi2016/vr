/********************************************************************************
** Form generated from reading UI file 'pqOutputWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PQOUTPUTWINDOW_H
#define UI_PQOUTPUTWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "pqConsoleWidget.h"

QT_BEGIN_NAMESPACE

class Ui_pqOutputWindow
{
public:
    QVBoxLayout *verticalLayout;
    QStackedWidget *stackedWidget;
    QWidget *stackedWidgetPage1;
    QVBoxLayout *verticalLayout_3;
    QTableView *tableView;
    QWidget *stackedWidgetPage2;
    QVBoxLayout *verticalLayout_2;
    pqConsoleWidget *consoleWidget;
    QHBoxLayout *hboxLayout;
    QCheckBox *checkBoxConsoleView;
    QSpacerItem *spacerItem;
    QPushButton *clearButton;
    QPushButton *filterButton;
    QPushButton *closeButton;

    void setupUi(QDialog *pqOutputWindow)
    {
        if (pqOutputWindow->objectName().isEmpty())
            pqOutputWindow->setObjectName(QStringLiteral("pqOutputWindow"));
        pqOutputWindow->resize(650, 400);
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(pqOutputWindow->sizePolicy().hasHeightForWidth());
        pqOutputWindow->setSizePolicy(sizePolicy);
        pqOutputWindow->setModal(false);
        verticalLayout = new QVBoxLayout(pqOutputWindow);
#ifndef Q_OS_MAC
        verticalLayout->setSpacing(6);
#endif
        verticalLayout->setContentsMargins(8, 8, 8, 8);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        stackedWidget = new QStackedWidget(pqOutputWindow);
        stackedWidget->setObjectName(QStringLiteral("stackedWidget"));
        stackedWidgetPage1 = new QWidget();
        stackedWidgetPage1->setObjectName(QStringLiteral("stackedWidgetPage1"));
        verticalLayout_3 = new QVBoxLayout(stackedWidgetPage1);
        verticalLayout_3->setSpacing(0);
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        tableView = new QTableView(stackedWidgetPage1);
        tableView->setObjectName(QStringLiteral("tableView"));
        tableView->setAlternatingRowColors(true);

        verticalLayout_3->addWidget(tableView);

        stackedWidget->addWidget(stackedWidgetPage1);
        stackedWidgetPage2 = new QWidget();
        stackedWidgetPage2->setObjectName(QStringLiteral("stackedWidgetPage2"));
        verticalLayout_2 = new QVBoxLayout(stackedWidgetPage2);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        consoleWidget = new pqConsoleWidget(stackedWidgetPage2);
        consoleWidget->setObjectName(QStringLiteral("consoleWidget"));

        verticalLayout_2->addWidget(consoleWidget);

        stackedWidget->addWidget(stackedWidgetPage2);

        verticalLayout->addWidget(stackedWidget);

        hboxLayout = new QHBoxLayout();
#ifndef Q_OS_MAC
        hboxLayout->setSpacing(6);
#endif
        hboxLayout->setContentsMargins(0, 0, 0, 0);
        hboxLayout->setObjectName(QStringLiteral("hboxLayout"));
        checkBoxConsoleView = new QCheckBox(pqOutputWindow);
        checkBoxConsoleView->setObjectName(QStringLiteral("checkBoxConsoleView"));

        hboxLayout->addWidget(checkBoxConsoleView);

        spacerItem = new QSpacerItem(131, 31, QSizePolicy::Expanding, QSizePolicy::Minimum);

        hboxLayout->addItem(spacerItem);

        clearButton = new QPushButton(pqOutputWindow);
        clearButton->setObjectName(QStringLiteral("clearButton"));

        hboxLayout->addWidget(clearButton);

        filterButton = new QPushButton(pqOutputWindow);
        filterButton->setObjectName(QStringLiteral("filterButton"));

        hboxLayout->addWidget(filterButton);

        closeButton = new QPushButton(pqOutputWindow);
        closeButton->setObjectName(QStringLiteral("closeButton"));

        hboxLayout->addWidget(closeButton);


        verticalLayout->addLayout(hboxLayout);


        retranslateUi(pqOutputWindow);
        QObject::connect(closeButton, SIGNAL(clicked()), pqOutputWindow, SLOT(accept()));

        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(pqOutputWindow);
    } // setupUi

    void retranslateUi(QDialog *pqOutputWindow)
    {
        pqOutputWindow->setWindowTitle(QApplication::translate("pqOutputWindow", "Dialog", Q_NULLPTR));
        checkBoxConsoleView->setText(QApplication::translate("pqOutputWindow", "Console View", Q_NULLPTR));
        clearButton->setText(QApplication::translate("pqOutputWindow", "Clear", Q_NULLPTR));
        filterButton->setText(QApplication::translate("pqOutputWindow", "Filter", Q_NULLPTR));
        closeButton->setText(QApplication::translate("pqOutputWindow", "Close", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class pqOutputWindow: public Ui_pqOutputWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PQOUTPUTWINDOW_H
