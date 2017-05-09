/********************************************************************************
** Form generated from reading UI file 'pqVRAddStyleDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PQVRADDSTYLEDIALOG_H
#define UI_PQVRADDSTYLEDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>

QT_BEGIN_NAMESPACE

class Ui_VRAddStyleDialog
{
public:
    QFormLayout *formLayout;
    QLabel *infoLabel;
    QDialogButtonBox *buttonBox;
    QFormLayout *inputForm;

    void setupUi(QDialog *VRAddStyleDialog)
    {
        if (VRAddStyleDialog->objectName().isEmpty())
            VRAddStyleDialog->setObjectName(QStringLiteral("VRAddStyleDialog"));
        VRAddStyleDialog->resize(286, 65);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(VRAddStyleDialog->sizePolicy().hasHeightForWidth());
        VRAddStyleDialog->setSizePolicy(sizePolicy);
        formLayout = new QFormLayout(VRAddStyleDialog);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        formLayout->setFieldGrowthPolicy(QFormLayout::ExpandingFieldsGrow);
        infoLabel = new QLabel(VRAddStyleDialog);
        infoLabel->setObjectName(QStringLiteral("infoLabel"));

        formLayout->setWidget(0, QFormLayout::SpanningRole, infoLabel);

        buttonBox = new QDialogButtonBox(VRAddStyleDialog);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        buttonBox->setCenterButtons(false);

        formLayout->setWidget(4, QFormLayout::SpanningRole, buttonBox);

        inputForm = new QFormLayout();
        inputForm->setObjectName(QStringLiteral("inputForm"));
        inputForm->setFieldGrowthPolicy(QFormLayout::ExpandingFieldsGrow);

        formLayout->setLayout(3, QFormLayout::SpanningRole, inputForm);


        retranslateUi(VRAddStyleDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), VRAddStyleDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), VRAddStyleDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(VRAddStyleDialog);
    } // setupUi

    void retranslateUi(QDialog *VRAddStyleDialog)
    {
        VRAddStyleDialog->setWindowTitle(QApplication::translate("VRAddStyleDialog", "Add VR Interaction", Q_NULLPTR));
        infoLabel->setText(QApplication::translate("VRAddStyleDialog", "TextLabel", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class VRAddStyleDialog: public Ui_VRAddStyleDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PQVRADDSTYLEDIALOG_H
