/********************************************************************************
** Form generated from reading UI file 'pqPresetDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PQPRESETDIALOG_H
#define UI_PQPRESETDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "pqSearchBox.h"

QT_BEGIN_NAMESPACE

class Ui_pqPresetDialog
{
public:
    QGridLayout *gridLayout;
    pqSearchBox *searchBox;
    QTableView *gradients;
    QLabel *label;
    QVBoxLayout *verticalLayout;
    QLabel *label_2;
    QFrame *line;
    QCheckBox *colors;
    QCheckBox *opacities;
    QCheckBox *annotations;
    QCheckBox *usePresetRange;
    QSpacerItem *verticalSpacer;
    QPushButton *apply;
    QPushButton *importPresets;
    QPushButton *exportPresets;
    QPushButton *remove;
    QPushButton *close;

    void setupUi(QWidget *pqPresetDialog)
    {
        if (pqPresetDialog->objectName().isEmpty())
            pqPresetDialog->setObjectName(QStringLiteral("pqPresetDialog"));
        pqPresetDialog->resize(547, 551);
        gridLayout = new QGridLayout(pqPresetDialog);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        searchBox = new pqSearchBox(pqPresetDialog);
        searchBox->setObjectName(QStringLiteral("searchBox"));
        searchBox->setMinimumSize(QSize(0, 10));
        searchBox->setProperty("settingKey", QVariant(QStringLiteral("")));
        searchBox->setProperty("advancedSearchEnabled", QVariant(false));

        gridLayout->addWidget(searchBox, 0, 0, 1, 1);

        gradients = new QTableView(pqPresetDialog);
        gradients->setObjectName(QStringLiteral("gradients"));
        gradients->setMinimumSize(QSize(300, 0));
        gradients->setEditTriggers(QAbstractItemView::AnyKeyPressed|QAbstractItemView::EditKeyPressed|QAbstractItemView::SelectedClicked);
        gradients->setProperty("showDropIndicator", QVariant(true));
        gradients->setSelectionBehavior(QAbstractItemView::SelectRows);
        gradients->setSortingEnabled(false);
        gradients->horizontalHeader()->setVisible(true);
        gradients->horizontalHeader()->setMinimumSectionSize(10);
        gradients->horizontalHeader()->setStretchLastSection(true);
        gradients->verticalHeader()->setVisible(false);

        gridLayout->addWidget(gradients, 1, 0, 1, 1);

        label = new QLabel(pqPresetDialog);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 2, 0, 1, 2);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label_2 = new QLabel(pqPresetDialog);
        label_2->setObjectName(QStringLiteral("label_2"));

        verticalLayout->addWidget(label_2);

        line = new QFrame(pqPresetDialog);
        line->setObjectName(QStringLiteral("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line);

        colors = new QCheckBox(pqPresetDialog);
        colors->setObjectName(QStringLiteral("colors"));
        colors->setChecked(true);

        verticalLayout->addWidget(colors);

        opacities = new QCheckBox(pqPresetDialog);
        opacities->setObjectName(QStringLiteral("opacities"));
        opacities->setEnabled(false);
        opacities->setChecked(true);

        verticalLayout->addWidget(opacities);

        annotations = new QCheckBox(pqPresetDialog);
        annotations->setObjectName(QStringLiteral("annotations"));
        annotations->setEnabled(false);
        annotations->setChecked(true);

        verticalLayout->addWidget(annotations);

        usePresetRange = new QCheckBox(pqPresetDialog);
        usePresetRange->setObjectName(QStringLiteral("usePresetRange"));

        verticalLayout->addWidget(usePresetRange);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        apply = new QPushButton(pqPresetDialog);
        apply->setObjectName(QStringLiteral("apply"));
        apply->setEnabled(false);

        verticalLayout->addWidget(apply);

        importPresets = new QPushButton(pqPresetDialog);
        importPresets->setObjectName(QStringLiteral("importPresets"));

        verticalLayout->addWidget(importPresets);

        exportPresets = new QPushButton(pqPresetDialog);
        exportPresets->setObjectName(QStringLiteral("exportPresets"));
        exportPresets->setEnabled(false);

        verticalLayout->addWidget(exportPresets);

        remove = new QPushButton(pqPresetDialog);
        remove->setObjectName(QStringLiteral("remove"));
        remove->setEnabled(false);

        verticalLayout->addWidget(remove);

        close = new QPushButton(pqPresetDialog);
        close->setObjectName(QStringLiteral("close"));

        verticalLayout->addWidget(close);


        gridLayout->addLayout(verticalLayout, 0, 1, 2, 1);


        retranslateUi(pqPresetDialog);
        QObject::connect(close, SIGNAL(clicked()), pqPresetDialog, SLOT(close()));

        QMetaObject::connectSlotsByName(pqPresetDialog);
    } // setupUi

    void retranslateUi(QWidget *pqPresetDialog)
    {
        pqPresetDialog->setWindowTitle(QApplication::translate("pqPresetDialog", "Choose Preset", Q_NULLPTR));
        label->setText(QApplication::translate("pqPresetDialog", "<html><head/><body><p><span style=\" font-weight:600;\">Tip: &lt;click&gt; to select, &lt;double-click&gt; to apply a preset.</span></p></body></html>", Q_NULLPTR));
        label_2->setText(QApplication::translate("pqPresetDialog", "<html><head/><body><p><span style=\" font-weight:600;\">Options to load:</span></p></body></html>", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        colors->setToolTip(QApplication::translate("pqPresetDialog", "<html><head/><body><p>Uncheck to not load colors from the selected preset.</p></body></html>", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        colors->setText(QApplication::translate("pqPresetDialog", "Colors", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        opacities->setToolTip(QApplication::translate("pqPresetDialog", "<html><head/><body><p>Uncheck to not load opacities from the selected preset.</p></body></html>", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        opacities->setText(QApplication::translate("pqPresetDialog", "Opacities", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        annotations->setToolTip(QApplication::translate("pqPresetDialog", "<html><head/><body><p>Uncheck to not load annotations from the selected preset.</p></body></html>", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        annotations->setText(QApplication::translate("pqPresetDialog", "Annotations", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        usePresetRange->setToolTip(QApplication::translate("pqPresetDialog", "<html><head/><body><p>Check to use data range specified in the preset.</p></body></html>", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        usePresetRange->setText(QApplication::translate("pqPresetDialog", "Use preset range", Q_NULLPTR));
        apply->setText(QApplication::translate("pqPresetDialog", "Apply", Q_NULLPTR));
        importPresets->setText(QApplication::translate("pqPresetDialog", "Import", Q_NULLPTR));
        exportPresets->setText(QApplication::translate("pqPresetDialog", "Export", Q_NULLPTR));
        remove->setText(QApplication::translate("pqPresetDialog", "Remove", Q_NULLPTR));
        close->setText(QApplication::translate("pqPresetDialog", "Close", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class pqPresetDialog: public Ui_pqPresetDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PQPRESETDIALOG_H
