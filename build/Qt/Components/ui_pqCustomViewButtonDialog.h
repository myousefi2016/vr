/********************************************************************************
** Form generated from reading UI file 'pqCustomViewButtonDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PQCUSTOMVIEWBUTTONDIALOG_H
#define UI_PQCUSTOMVIEWBUTTONDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_pqCustomViewButtonDialog
{
public:
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_9;
    QLabel *label_3;
    QLineEdit *toolTip0;
    QPushButton *assignCurrentView0;
    QLabel *label_4;
    QLineEdit *toolTip1;
    QPushButton *assignCurrentView1;
    QLabel *label_5;
    QLineEdit *toolTip2;
    QPushButton *assignCurrentView2;
    QLabel *label_6;
    QLineEdit *toolTip3;
    QPushButton *assignCurrentView3;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *clearAll;
    QPushButton *importAll;
    QPushButton *exportAll;
    QSpacerItem *verticalSpacer;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *pqCustomViewButtonDialog)
    {
        if (pqCustomViewButtonDialog->objectName().isEmpty())
            pqCustomViewButtonDialog->setObjectName(QStringLiteral("pqCustomViewButtonDialog"));
        pqCustomViewButtonDialog->resize(437, 221);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(pqCustomViewButtonDialog->sizePolicy().hasHeightForWidth());
        pqCustomViewButtonDialog->setSizePolicy(sizePolicy);
        verticalLayout = new QVBoxLayout(pqCustomViewButtonDialog);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label_7 = new QLabel(pqCustomViewButtonDialog);
        label_7->setObjectName(QStringLiteral("label_7"));
        QFont font;
        font.setBold(true);
        font.setUnderline(true);
        font.setWeight(75);
        label_7->setFont(font);
        label_7->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_7, 0, 0, 1, 1);

        label_8 = new QLabel(pqCustomViewButtonDialog);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setFont(font);
        label_8->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_8, 0, 1, 1, 1);

        label_9 = new QLabel(pqCustomViewButtonDialog);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setFont(font);
        label_9->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_9, 0, 2, 1, 1);

        label_3 = new QLabel(pqCustomViewButtonDialog);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_3, 1, 0, 1, 1);

        toolTip0 = new QLineEdit(pqCustomViewButtonDialog);
        toolTip0->setObjectName(QStringLiteral("toolTip0"));

        gridLayout->addWidget(toolTip0, 1, 1, 1, 1);

        assignCurrentView0 = new QPushButton(pqCustomViewButtonDialog);
        assignCurrentView0->setObjectName(QStringLiteral("assignCurrentView0"));

        gridLayout->addWidget(assignCurrentView0, 1, 2, 1, 1);

        label_4 = new QLabel(pqCustomViewButtonDialog);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_4, 2, 0, 1, 1);

        toolTip1 = new QLineEdit(pqCustomViewButtonDialog);
        toolTip1->setObjectName(QStringLiteral("toolTip1"));

        gridLayout->addWidget(toolTip1, 2, 1, 1, 1);

        assignCurrentView1 = new QPushButton(pqCustomViewButtonDialog);
        assignCurrentView1->setObjectName(QStringLiteral("assignCurrentView1"));

        gridLayout->addWidget(assignCurrentView1, 2, 2, 1, 1);

        label_5 = new QLabel(pqCustomViewButtonDialog);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_5, 3, 0, 1, 1);

        toolTip2 = new QLineEdit(pqCustomViewButtonDialog);
        toolTip2->setObjectName(QStringLiteral("toolTip2"));

        gridLayout->addWidget(toolTip2, 3, 1, 1, 1);

        assignCurrentView2 = new QPushButton(pqCustomViewButtonDialog);
        assignCurrentView2->setObjectName(QStringLiteral("assignCurrentView2"));

        gridLayout->addWidget(assignCurrentView2, 3, 2, 1, 1);

        label_6 = new QLabel(pqCustomViewButtonDialog);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_6, 4, 0, 1, 1);

        toolTip3 = new QLineEdit(pqCustomViewButtonDialog);
        toolTip3->setObjectName(QStringLiteral("toolTip3"));

        gridLayout->addWidget(toolTip3, 4, 1, 1, 1);

        assignCurrentView3 = new QPushButton(pqCustomViewButtonDialog);
        assignCurrentView3->setObjectName(QStringLiteral("assignCurrentView3"));

        gridLayout->addWidget(assignCurrentView3, 4, 2, 1, 1);


        verticalLayout->addLayout(gridLayout);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        clearAll = new QPushButton(pqCustomViewButtonDialog);
        clearAll->setObjectName(QStringLiteral("clearAll"));

        horizontalLayout->addWidget(clearAll);

        importAll = new QPushButton(pqCustomViewButtonDialog);
        importAll->setObjectName(QStringLiteral("importAll"));

        horizontalLayout->addWidget(importAll);

        exportAll = new QPushButton(pqCustomViewButtonDialog);
        exportAll->setObjectName(QStringLiteral("exportAll"));

        horizontalLayout->addWidget(exportAll);


        verticalLayout->addLayout(horizontalLayout);

        verticalSpacer = new QSpacerItem(20, 17, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        buttonBox = new QDialogButtonBox(pqCustomViewButtonDialog);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(pqCustomViewButtonDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), pqCustomViewButtonDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), pqCustomViewButtonDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(pqCustomViewButtonDialog);
    } // setupUi

    void retranslateUi(QDialog *pqCustomViewButtonDialog)
    {
        pqCustomViewButtonDialog->setWindowTitle(QApplication::translate("pqCustomViewButtonDialog", "Configure custom view buttons", Q_NULLPTR));
        label_7->setText(QApplication::translate("pqCustomViewButtonDialog", "Button", Q_NULLPTR));
        label_8->setText(QApplication::translate("pqCustomViewButtonDialog", "Tool Tip", Q_NULLPTR));
        label_9->setText(QApplication::translate("pqCustomViewButtonDialog", "Assign", Q_NULLPTR));
        label_3->setText(QApplication::translate("pqCustomViewButtonDialog", "1", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        toolTip0->setToolTip(QApplication::translate("pqCustomViewButtonDialog", "This text will be set to the buttons tool tip.", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        assignCurrentView0->setText(QApplication::translate("pqCustomViewButtonDialog", "current view", Q_NULLPTR));
        label_4->setText(QApplication::translate("pqCustomViewButtonDialog", "2", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        toolTip1->setToolTip(QApplication::translate("pqCustomViewButtonDialog", "This text will be set to the buttons tool tip.", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        assignCurrentView1->setText(QApplication::translate("pqCustomViewButtonDialog", "current view", Q_NULLPTR));
        label_5->setText(QApplication::translate("pqCustomViewButtonDialog", "3", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        toolTip2->setToolTip(QApplication::translate("pqCustomViewButtonDialog", "This text will be set to the buttons tool tip.", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        assignCurrentView2->setText(QApplication::translate("pqCustomViewButtonDialog", "current view", Q_NULLPTR));
        label_6->setText(QApplication::translate("pqCustomViewButtonDialog", "4", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        toolTip3->setToolTip(QApplication::translate("pqCustomViewButtonDialog", "This text will be set to the buttons tool tip.", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        assignCurrentView3->setText(QApplication::translate("pqCustomViewButtonDialog", "current view", Q_NULLPTR));
        clearAll->setText(QApplication::translate("pqCustomViewButtonDialog", "clear all", Q_NULLPTR));
        importAll->setText(QApplication::translate("pqCustomViewButtonDialog", "import...", Q_NULLPTR));
        exportAll->setText(QApplication::translate("pqCustomViewButtonDialog", "export...", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class pqCustomViewButtonDialog: public Ui_pqCustomViewButtonDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PQCUSTOMVIEWBUTTONDIALOG_H
