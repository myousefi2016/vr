/********************************************************************************
** Form generated from reading UI file 'pqVRAddConnectionDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PQVRADDCONNECTIONDIALOG_H
#define UI_PQVRADDCONNECTIONDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QToolButton>

QT_BEGIN_NAMESPACE

class Ui_VRAddConnectionDialog
{
public:
    QFormLayout *formLayout;
    QLabel *label_2;
    QComboBox *connectionType;
    QLabel *label_3;
    QLineEdit *connectionName;
    QLabel *label_4;
    QLineEdit *connectionAddress;
    QLabel *portLabel;
    QSpinBox *connectionPort;
    QListWidget *listWidget;
    QHBoxLayout *horizontalLayout;
    QComboBox *inputType;
    QLineEdit *inputId;
    QLineEdit *inputName;
    QToolButton *insertInput;
    QToolButton *eraseInput;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *VRAddConnectionDialog)
    {
        if (VRAddConnectionDialog->objectName().isEmpty())
            VRAddConnectionDialog->setObjectName(QStringLiteral("VRAddConnectionDialog"));
        VRAddConnectionDialog->resize(640, 500);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(VRAddConnectionDialog->sizePolicy().hasHeightForWidth());
        VRAddConnectionDialog->setSizePolicy(sizePolicy);
        formLayout = new QFormLayout(VRAddConnectionDialog);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        formLayout->setFieldGrowthPolicy(QFormLayout::ExpandingFieldsGrow);
        label_2 = new QLabel(VRAddConnectionDialog);
        label_2->setObjectName(QStringLiteral("label_2"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label_2);

        connectionType = new QComboBox(VRAddConnectionDialog);
        connectionType->setObjectName(QStringLiteral("connectionType"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(connectionType->sizePolicy().hasHeightForWidth());
        connectionType->setSizePolicy(sizePolicy1);

        formLayout->setWidget(0, QFormLayout::FieldRole, connectionType);

        label_3 = new QLabel(VRAddConnectionDialog);
        label_3->setObjectName(QStringLiteral("label_3"));
        sizePolicy.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy);

        formLayout->setWidget(1, QFormLayout::LabelRole, label_3);

        connectionName = new QLineEdit(VRAddConnectionDialog);
        connectionName->setObjectName(QStringLiteral("connectionName"));

        formLayout->setWidget(1, QFormLayout::FieldRole, connectionName);

        label_4 = new QLabel(VRAddConnectionDialog);
        label_4->setObjectName(QStringLiteral("label_4"));

        formLayout->setWidget(2, QFormLayout::LabelRole, label_4);

        connectionAddress = new QLineEdit(VRAddConnectionDialog);
        connectionAddress->setObjectName(QStringLiteral("connectionAddress"));

        formLayout->setWidget(2, QFormLayout::FieldRole, connectionAddress);

        portLabel = new QLabel(VRAddConnectionDialog);
        portLabel->setObjectName(QStringLiteral("portLabel"));

        formLayout->setWidget(4, QFormLayout::LabelRole, portLabel);

        connectionPort = new QSpinBox(VRAddConnectionDialog);
        connectionPort->setObjectName(QStringLiteral("connectionPort"));
        connectionPort->setMaximum(99999);
        connectionPort->setValue(8555);

        formLayout->setWidget(4, QFormLayout::FieldRole, connectionPort);

        listWidget = new QListWidget(VRAddConnectionDialog);
        new QListWidgetItem(listWidget);
        listWidget->setObjectName(QStringLiteral("listWidget"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(1);
        sizePolicy2.setHeightForWidth(listWidget->sizePolicy().hasHeightForWidth());
        listWidget->setSizePolicy(sizePolicy2);

        formLayout->setWidget(5, QFormLayout::SpanningRole, listWidget);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        inputType = new QComboBox(VRAddConnectionDialog);
        inputType->setObjectName(QStringLiteral("inputType"));

        horizontalLayout->addWidget(inputType);

        inputId = new QLineEdit(VRAddConnectionDialog);
        inputId->setObjectName(QStringLiteral("inputId"));

        horizontalLayout->addWidget(inputId);

        inputName = new QLineEdit(VRAddConnectionDialog);
        inputName->setObjectName(QStringLiteral("inputName"));

        horizontalLayout->addWidget(inputName);

        insertInput = new QToolButton(VRAddConnectionDialog);
        insertInput->setObjectName(QStringLiteral("insertInput"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/QtWidgets/Icons/pqPlus16.png"), QSize(), QIcon::Normal, QIcon::Off);
        insertInput->setIcon(icon);

        horizontalLayout->addWidget(insertInput);

        eraseInput = new QToolButton(VRAddConnectionDialog);
        eraseInput->setObjectName(QStringLiteral("eraseInput"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/QtWidgets/Icons/pqMinus16.png"), QSize(), QIcon::Normal, QIcon::Off);
        eraseInput->setIcon(icon1);

        horizontalLayout->addWidget(eraseInput);

        horizontalLayout->setStretch(0, 1);
        horizontalLayout->setStretch(1, 1);

        formLayout->setLayout(6, QFormLayout::SpanningRole, horizontalLayout);

        buttonBox = new QDialogButtonBox(VRAddConnectionDialog);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        buttonBox->setCenterButtons(false);

        formLayout->setWidget(7, QFormLayout::SpanningRole, buttonBox);


        retranslateUi(VRAddConnectionDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), VRAddConnectionDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), VRAddConnectionDialog, SLOT(reject()));
        QObject::connect(inputId, SIGNAL(returnPressed()), inputName, SLOT(setFocus()));
        QObject::connect(inputName, SIGNAL(returnPressed()), insertInput, SLOT(click()));

        QMetaObject::connectSlotsByName(VRAddConnectionDialog);
    } // setupUi

    void retranslateUi(QDialog *VRAddConnectionDialog)
    {
        VRAddConnectionDialog->setWindowTitle(QApplication::translate("VRAddConnectionDialog", "Add VR Connection", Q_NULLPTR));
        label_2->setText(QApplication::translate("VRAddConnectionDialog", "Type:", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        connectionType->setToolTip(QApplication::translate("VRAddConnectionDialog", "<html><head/><body><p>Select the type of VR connection.</p></body></html>", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        label_3->setText(QApplication::translate("VRAddConnectionDialog", "Name:", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        connectionName->setToolTip(QApplication::translate("VRAddConnectionDialog", "<html><head/><body><p>Name of the connection.</p></body></html>", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        connectionName->setText(QApplication::translate("VRAddConnectionDialog", "vrconn", Q_NULLPTR));
        label_4->setText(QApplication::translate("VRAddConnectionDialog", "Address:", Q_NULLPTR));
        portLabel->setText(QApplication::translate("VRAddConnectionDialog", "Port:", Q_NULLPTR));

        const bool __sortingEnabled = listWidget->isSortingEnabled();
        listWidget->setSortingEnabled(false);
        QListWidgetItem *___qlistwidgetitem = listWidget->item(0);
        ___qlistwidgetitem->setText(QApplication::translate("VRAddConnectionDialog", "<add inputs>", Q_NULLPTR));
        listWidget->setSortingEnabled(__sortingEnabled);

        inputType->clear();
        inputType->insertItems(0, QStringList()
         << QApplication::translate("VRAddConnectionDialog", "Analog", Q_NULLPTR)
         << QApplication::translate("VRAddConnectionDialog", "Button", Q_NULLPTR)
         << QApplication::translate("VRAddConnectionDialog", "Tracker", Q_NULLPTR)
        );
        inputId->setPlaceholderText(QApplication::translate("VRAddConnectionDialog", "id", Q_NULLPTR));
        inputName->setPlaceholderText(QApplication::translate("VRAddConnectionDialog", "name", Q_NULLPTR));
        insertInput->setText(QString());
        eraseInput->setText(QApplication::translate("VRAddConnectionDialog", "...", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class VRAddConnectionDialog: public Ui_VRAddConnectionDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PQVRADDCONNECTIONDIALOG_H
