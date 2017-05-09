/********************************************************************************
** Form generated from reading UI file 'pqSampleScalarAddRangeDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PQSAMPLESCALARADDRANGEDIALOG_H
#define UI_PQSAMPLESCALARADDRANGEDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>

QT_BEGIN_NAMESPACE

class Ui_pqSampleScalarAddRangeDialog
{
public:
    QGridLayout *gridLayout;
    QCheckBox *log;
    QLabel *logWarning;
    QHBoxLayout *hboxLayout;
    QSpacerItem *spacerItem;
    QPushButton *okButton;
    QPushButton *cancelButton;
    QLabel *label_3;
    QLabel *label_2;
    QLabel *label;
    QLineEdit *from;
    QLineEdit *to;
    QLineEdit *steps;

    void setupUi(QDialog *pqSampleScalarAddRangeDialog)
    {
        if (pqSampleScalarAddRangeDialog->objectName().isEmpty())
            pqSampleScalarAddRangeDialog->setObjectName(QStringLiteral("pqSampleScalarAddRangeDialog"));
        pqSampleScalarAddRangeDialog->resize(315, 188);
        gridLayout = new QGridLayout(pqSampleScalarAddRangeDialog);
#ifndef Q_OS_MAC
        gridLayout->setSpacing(6);
#endif
#ifndef Q_OS_MAC
        gridLayout->setContentsMargins(9, 9, 9, 9);
#endif
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        log = new QCheckBox(pqSampleScalarAddRangeDialog);
        log->setObjectName(QStringLiteral("log"));
        log->setChecked(false);

        gridLayout->addWidget(log, 4, 1, 1, 1);

        logWarning = new QLabel(pqSampleScalarAddRangeDialog);
        logWarning->setObjectName(QStringLiteral("logWarning"));
        logWarning->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(logWarning, 3, 0, 1, 2);

        hboxLayout = new QHBoxLayout();
#ifndef Q_OS_MAC
        hboxLayout->setSpacing(6);
#endif
        hboxLayout->setContentsMargins(0, 0, 0, 0);
        hboxLayout->setObjectName(QStringLiteral("hboxLayout"));
        spacerItem = new QSpacerItem(131, 31, QSizePolicy::Expanding, QSizePolicy::Minimum);

        hboxLayout->addItem(spacerItem);

        okButton = new QPushButton(pqSampleScalarAddRangeDialog);
        okButton->setObjectName(QStringLiteral("okButton"));

        hboxLayout->addWidget(okButton);

        cancelButton = new QPushButton(pqSampleScalarAddRangeDialog);
        cancelButton->setObjectName(QStringLiteral("cancelButton"));

        hboxLayout->addWidget(cancelButton);


        gridLayout->addLayout(hboxLayout, 5, 0, 1, 2);

        label_3 = new QLabel(pqSampleScalarAddRangeDialog);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout->addWidget(label_3, 2, 0, 1, 1);

        label_2 = new QLabel(pqSampleScalarAddRangeDialog);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        label = new QLabel(pqSampleScalarAddRangeDialog);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        from = new QLineEdit(pqSampleScalarAddRangeDialog);
        from->setObjectName(QStringLiteral("from"));

        gridLayout->addWidget(from, 0, 1, 1, 1);

        to = new QLineEdit(pqSampleScalarAddRangeDialog);
        to->setObjectName(QStringLiteral("to"));

        gridLayout->addWidget(to, 1, 1, 1, 1);

        steps = new QLineEdit(pqSampleScalarAddRangeDialog);
        steps->setObjectName(QStringLiteral("steps"));

        gridLayout->addWidget(steps, 2, 1, 1, 1);

        QWidget::setTabOrder(from, to);
        QWidget::setTabOrder(to, steps);
        QWidget::setTabOrder(steps, okButton);
        QWidget::setTabOrder(okButton, cancelButton);

        retranslateUi(pqSampleScalarAddRangeDialog);
        QObject::connect(okButton, SIGNAL(clicked()), pqSampleScalarAddRangeDialog, SLOT(accept()));
        QObject::connect(cancelButton, SIGNAL(clicked()), pqSampleScalarAddRangeDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(pqSampleScalarAddRangeDialog);
    } // setupUi

    void retranslateUi(QDialog *pqSampleScalarAddRangeDialog)
    {
        pqSampleScalarAddRangeDialog->setWindowTitle(QApplication::translate("pqSampleScalarAddRangeDialog", "Add Range", Q_NULLPTR));
        log->setText(QApplication::translate("pqSampleScalarAddRangeDialog", "Use Logarithmic Scale", Q_NULLPTR));
        logWarning->setText(QApplication::translate("pqSampleScalarAddRangeDialog", "Can't use logarithmic scale when zero is in the range.", Q_NULLPTR));
        okButton->setText(QApplication::translate("pqSampleScalarAddRangeDialog", "OK", Q_NULLPTR));
        cancelButton->setText(QApplication::translate("pqSampleScalarAddRangeDialog", "Cancel", Q_NULLPTR));
        label_3->setText(QApplication::translate("pqSampleScalarAddRangeDialog", "Steps", Q_NULLPTR));
        label_2->setText(QApplication::translate("pqSampleScalarAddRangeDialog", "To", Q_NULLPTR));
        label->setText(QApplication::translate("pqSampleScalarAddRangeDialog", "From", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class pqSampleScalarAddRangeDialog: public Ui_pqSampleScalarAddRangeDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PQSAMPLESCALARADDRANGEDIALOG_H
