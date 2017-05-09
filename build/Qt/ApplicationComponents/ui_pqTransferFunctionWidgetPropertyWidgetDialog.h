/********************************************************************************
** Form generated from reading UI file 'pqTransferFunctionWidgetPropertyWidgetDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PQTRANSFERFUNCTIONWIDGETPROPERTYWIDGETDIALOG_H
#define UI_PQTRANSFERFUNCTIONWIDGETPROPERTYWIDGETDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include "pqTransferFunctionWidget.h"

QT_BEGIN_NAMESPACE

class Ui_TransferFunctionWidgetPropertyWidgetDialog
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *Label;
    pqTransferFunctionWidget *TransferFunctionEditor;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QDoubleSpinBox *minX;
    QDoubleSpinBox *maxX;
    QSpacerItem *horizontalSpacer;
    QDialogButtonBox *ButtonBox;

    void setupUi(QDialog *TransferFunctionWidgetPropertyWidgetDialog)
    {
        if (TransferFunctionWidgetPropertyWidgetDialog->objectName().isEmpty())
            TransferFunctionWidgetPropertyWidgetDialog->setObjectName(QStringLiteral("TransferFunctionWidgetPropertyWidgetDialog"));
        TransferFunctionWidgetPropertyWidgetDialog->resize(400, 377);
        verticalLayout = new QVBoxLayout(TransferFunctionWidgetPropertyWidgetDialog);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        Label = new QLabel(TransferFunctionWidgetPropertyWidgetDialog);
        Label->setObjectName(QStringLiteral("Label"));

        verticalLayout->addWidget(Label);

        TransferFunctionEditor = new pqTransferFunctionWidget(TransferFunctionWidgetPropertyWidgetDialog);
        TransferFunctionEditor->setObjectName(QStringLiteral("TransferFunctionEditor"));
        TransferFunctionEditor->setMinimumSize(QSize(0, 80));

        verticalLayout->addWidget(TransferFunctionEditor);

        groupBox = new QGroupBox(TransferFunctionWidgetPropertyWidgetDialog);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setMinimumSize(QSize(0, 28));
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        minX = new QDoubleSpinBox(groupBox);
        minX->setObjectName(QStringLiteral("minX"));
        minX->setMinimum(-1e+7);
        minX->setMaximum(1e+7);

        gridLayout->addWidget(minX, 0, 0, 1, 1);

        maxX = new QDoubleSpinBox(groupBox);
        maxX->setObjectName(QStringLiteral("maxX"));
        maxX->setMinimum(-1e+7);
        maxX->setMaximum(1e+7);

        gridLayout->addWidget(maxX, 0, 2, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 0, 1, 1, 1);


        verticalLayout->addWidget(groupBox);

        ButtonBox = new QDialogButtonBox(TransferFunctionWidgetPropertyWidgetDialog);
        ButtonBox->setObjectName(QStringLiteral("ButtonBox"));
        ButtonBox->setOrientation(Qt::Horizontal);
        ButtonBox->setStandardButtons(QDialogButtonBox::Close);

        verticalLayout->addWidget(ButtonBox);

        verticalLayout->setStretch(1, 1);

        retranslateUi(TransferFunctionWidgetPropertyWidgetDialog);
        QObject::connect(ButtonBox, SIGNAL(accepted()), TransferFunctionWidgetPropertyWidgetDialog, SLOT(accept()));
        QObject::connect(ButtonBox, SIGNAL(rejected()), TransferFunctionWidgetPropertyWidgetDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(TransferFunctionWidgetPropertyWidgetDialog);
    } // setupUi

    void retranslateUi(QDialog *TransferFunctionWidgetPropertyWidgetDialog)
    {
        TransferFunctionWidgetPropertyWidgetDialog->setWindowTitle(QApplication::translate("TransferFunctionWidgetPropertyWidgetDialog", "Edit Transfer Function", Q_NULLPTR));
        Label->setText(QApplication::translate("TransferFunctionWidgetPropertyWidgetDialog", "<html><head/><body><p align=\"center\"><span style=\" font-weight:600;\">%1</span></p></body></html>", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("TransferFunctionWidgetPropertyWidgetDialog", "Piece wise ranges", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class TransferFunctionWidgetPropertyWidgetDialog: public Ui_TransferFunctionWidgetPropertyWidgetDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PQTRANSFERFUNCTIONWIDGETPROPERTYWIDGETDIALOG_H
