/********************************************************************************
** Form generated from reading UI file 'pqFileDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PQFILEDIALOG_H
#define UI_PQFILEDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QTreeView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "pqFileDialog.h"

QT_BEGIN_NAMESPACE

class Ui_pqFileDialog
{
public:
    QGridLayout *gridLayout;
    QHBoxLayout *hboxLayout;
    QLabel *label_3;
    QComboBox *Parents;
    QToolButton *NavigateBack;
    QToolButton *NavigateForward;
    QToolButton *NavigateUp;
    QToolButton *CreateFolder;
    QSplitter *mainSplitter;
    QSplitter *splitter;
    QListView *Favorites;
    QListView *Recent;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QTreeView *Files;
    QGridLayout *gridLayout1;
    QLabel *label_2;
    QLineEdit *FileName;
    QPushButton *OK;
    QLabel *label;
    pqFileComboBox *FileType;
    QPushButton *Cancel;

    void setupUi(QDialog *pqFileDialog)
    {
        if (pqFileDialog->objectName().isEmpty())
            pqFileDialog->setObjectName(QStringLiteral("pqFileDialog"));
        pqFileDialog->resize(683, 402);
        gridLayout = new QGridLayout(pqFileDialog);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        hboxLayout = new QHBoxLayout();
#ifndef Q_OS_MAC
        hboxLayout->setSpacing(6);
#endif
#ifndef Q_OS_MAC
        hboxLayout->setContentsMargins(0, 0, 0, 0);
#endif
        hboxLayout->setObjectName(QStringLiteral("hboxLayout"));
        label_3 = new QLabel(pqFileDialog);
        label_3->setObjectName(QStringLiteral("label_3"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy);
        label_3->setMinimumSize(QSize(100, 0));
        label_3->setMaximumSize(QSize(100, 16777215));
        label_3->setAlignment(Qt::AlignCenter);

        hboxLayout->addWidget(label_3);

        Parents = new QComboBox(pqFileDialog);
        Parents->setObjectName(QStringLiteral("Parents"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(Parents->sizePolicy().hasHeightForWidth());
        Parents->setSizePolicy(sizePolicy1);

        hboxLayout->addWidget(Parents);

        NavigateBack = new QToolButton(pqFileDialog);
        NavigateBack->setObjectName(QStringLiteral("NavigateBack"));
        NavigateBack->setAutoRaise(true);

        hboxLayout->addWidget(NavigateBack);

        NavigateForward = new QToolButton(pqFileDialog);
        NavigateForward->setObjectName(QStringLiteral("NavigateForward"));
        NavigateForward->setAutoRaise(true);

        hboxLayout->addWidget(NavigateForward);

        NavigateUp = new QToolButton(pqFileDialog);
        NavigateUp->setObjectName(QStringLiteral("NavigateUp"));
        NavigateUp->setAutoRaise(true);

        hboxLayout->addWidget(NavigateUp);

        CreateFolder = new QToolButton(pqFileDialog);
        CreateFolder->setObjectName(QStringLiteral("CreateFolder"));
        CreateFolder->setAutoRaise(true);

        hboxLayout->addWidget(CreateFolder);


        gridLayout->addLayout(hboxLayout, 0, 0, 1, 1);

        mainSplitter = new QSplitter(pqFileDialog);
        mainSplitter->setObjectName(QStringLiteral("mainSplitter"));
        mainSplitter->setOrientation(Qt::Horizontal);
        splitter = new QSplitter(mainSplitter);
        splitter->setObjectName(QStringLiteral("splitter"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(splitter->sizePolicy().hasHeightForWidth());
        splitter->setSizePolicy(sizePolicy2);
        splitter->setOrientation(Qt::Vertical);
        Favorites = new QListView(splitter);
        Favorites->setObjectName(QStringLiteral("Favorites"));
        QSizePolicy sizePolicy3(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy3.setHorizontalStretch(1);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(Favorites->sizePolicy().hasHeightForWidth());
        Favorites->setSizePolicy(sizePolicy3);
        Favorites->setMinimumSize(QSize(100, 0));
        splitter->addWidget(Favorites);
        Recent = new QListView(splitter);
        Recent->setObjectName(QStringLiteral("Recent"));
        sizePolicy3.setHeightForWidth(Recent->sizePolicy().hasHeightForWidth());
        Recent->setSizePolicy(sizePolicy3);
        Recent->setMinimumSize(QSize(100, 0));
        splitter->addWidget(Recent);
        mainSplitter->addWidget(splitter);
        widget = new QWidget(mainSplitter);
        widget->setObjectName(QStringLiteral("widget"));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        Files = new QTreeView(widget);
        Files->setObjectName(QStringLiteral("Files"));
        QSizePolicy sizePolicy4(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy4.setHorizontalStretch(2);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(Files->sizePolicy().hasHeightForWidth());
        Files->setSizePolicy(sizePolicy4);

        verticalLayout->addWidget(Files);

        gridLayout1 = new QGridLayout();
#ifndef Q_OS_MAC
        gridLayout1->setSpacing(6);
#endif
        gridLayout1->setContentsMargins(0, 0, 0, 0);
        gridLayout1->setObjectName(QStringLiteral("gridLayout1"));
        label_2 = new QLabel(widget);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout1->addWidget(label_2, 0, 0, 1, 1);

        FileName = new QLineEdit(widget);
        FileName->setObjectName(QStringLiteral("FileName"));

        gridLayout1->addWidget(FileName, 0, 1, 1, 1);

        OK = new QPushButton(widget);
        OK->setObjectName(QStringLiteral("OK"));

        gridLayout1->addWidget(OK, 0, 2, 1, 1);

        label = new QLabel(widget);
        label->setObjectName(QStringLiteral("label"));

        gridLayout1->addWidget(label, 1, 0, 1, 1);

        FileType = new pqFileComboBox(widget);
        FileType->setObjectName(QStringLiteral("FileType"));
        FileType->setSizeAdjustPolicy(QComboBox::AdjustToMinimumContentsLength);

        gridLayout1->addWidget(FileType, 1, 1, 1, 1);

        Cancel = new QPushButton(widget);
        Cancel->setObjectName(QStringLiteral("Cancel"));

        gridLayout1->addWidget(Cancel, 1, 2, 1, 1);


        verticalLayout->addLayout(gridLayout1);

        mainSplitter->addWidget(widget);

        gridLayout->addWidget(mainSplitter, 1, 0, 1, 1);

        QWidget::setTabOrder(FileName, FileType);
        QWidget::setTabOrder(FileType, OK);
        QWidget::setTabOrder(OK, Cancel);
        QWidget::setTabOrder(Cancel, Parents);
        QWidget::setTabOrder(Parents, NavigateBack);
        QWidget::setTabOrder(NavigateBack, NavigateForward);
        QWidget::setTabOrder(NavigateForward, NavigateUp);
        QWidget::setTabOrder(NavigateUp, CreateFolder);
        QWidget::setTabOrder(CreateFolder, Favorites);
        QWidget::setTabOrder(Favorites, Files);

        retranslateUi(pqFileDialog);
        QObject::connect(OK, SIGNAL(clicked()), pqFileDialog, SLOT(accept()));
        QObject::connect(Cancel, SIGNAL(clicked()), pqFileDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(pqFileDialog);
    } // setupUi

    void retranslateUi(QDialog *pqFileDialog)
    {
        pqFileDialog->setWindowTitle(QApplication::translate("pqFileDialog", "Dialog", Q_NULLPTR));
        label_3->setText(QApplication::translate("pqFileDialog", "Look in:", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        NavigateBack->setToolTip(QApplication::translate("pqFileDialog", "Navigate Back", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        NavigateBack->setText(QString());
#ifndef QT_NO_TOOLTIP
        NavigateForward->setToolTip(QApplication::translate("pqFileDialog", "Navigate Forward", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        NavigateForward->setText(QString());
#ifndef QT_NO_TOOLTIP
        NavigateUp->setToolTip(QApplication::translate("pqFileDialog", "Navigate Up", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        NavigateUp->setText(QString());
#ifndef QT_NO_TOOLTIP
        CreateFolder->setToolTip(QApplication::translate("pqFileDialog", "Create New Folder", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        CreateFolder->setText(QString());
        label_2->setText(QApplication::translate("pqFileDialog", "File name:", Q_NULLPTR));
        OK->setText(QApplication::translate("pqFileDialog", "OK", Q_NULLPTR));
        label->setText(QApplication::translate("pqFileDialog", "Files of type:", Q_NULLPTR));
        Cancel->setText(QApplication::translate("pqFileDialog", "Cancel", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class pqFileDialog: public Ui_pqFileDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PQFILEDIALOG_H
