/********************************************************************************
** Form generated from reading UI file 'pqSaveSnapshotDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PQSAVESNAPSHOTDIALOG_H
#define UI_PQSAVESNAPSHOTDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include "pqIntRangeWidget.h"

QT_BEGIN_NAMESPACE

class Ui_SaveSnapshotDialog
{
public:
    QVBoxLayout *verticalLayout;
    QCheckBox *selectedViewOnly;
    QLabel *label;
    QHBoxLayout *hboxLayout;
    QLineEdit *width;
    QLabel *label_2;
    QLineEdit *height;
    QToolButton *lockAspect;
    QLabel *label_3;
    pqIntRangeWidget *quality;
    QLabel *label_4;
    QComboBox *palette;
    QLabel *label_5;
    QComboBox *stereoMode;
    QHBoxLayout *hboxLayout1;
    QSpacerItem *spacerItem;
    QPushButton *ok;
    QPushButton *cancel;

    void setupUi(QDialog *SaveSnapshotDialog)
    {
        if (SaveSnapshotDialog->objectName().isEmpty())
            SaveSnapshotDialog->setObjectName(QStringLiteral("SaveSnapshotDialog"));
        SaveSnapshotDialog->resize(294, 298);
        verticalLayout = new QVBoxLayout(SaveSnapshotDialog);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        selectedViewOnly = new QCheckBox(SaveSnapshotDialog);
        selectedViewOnly->setObjectName(QStringLiteral("selectedViewOnly"));
        selectedViewOnly->setChecked(true);

        verticalLayout->addWidget(selectedViewOnly);

        label = new QLabel(SaveSnapshotDialog);
        label->setObjectName(QStringLiteral("label"));
        label->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label);

        hboxLayout = new QHBoxLayout();
#ifndef Q_OS_MAC
        hboxLayout->setSpacing(6);
#endif
        hboxLayout->setContentsMargins(0, 0, 0, 0);
        hboxLayout->setObjectName(QStringLiteral("hboxLayout"));
        width = new QLineEdit(SaveSnapshotDialog);
        width->setObjectName(QStringLiteral("width"));

        hboxLayout->addWidget(width);

        label_2 = new QLabel(SaveSnapshotDialog);
        label_2->setObjectName(QStringLiteral("label_2"));

        hboxLayout->addWidget(label_2);

        height = new QLineEdit(SaveSnapshotDialog);
        height->setObjectName(QStringLiteral("height"));

        hboxLayout->addWidget(height);

        lockAspect = new QToolButton(SaveSnapshotDialog);
        lockAspect->setObjectName(QStringLiteral("lockAspect"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/pqWidgets/Icons/pqOctreeData16.png"), QSize(), QIcon::Normal, QIcon::Off);
        lockAspect->setIcon(icon);
        lockAspect->setIconSize(QSize(12, 12));
        lockAspect->setCheckable(true);

        hboxLayout->addWidget(lockAspect);


        verticalLayout->addLayout(hboxLayout);

        label_3 = new QLabel(SaveSnapshotDialog);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label_3);

        quality = new pqIntRangeWidget(SaveSnapshotDialog);
        quality->setObjectName(QStringLiteral("quality"));

        verticalLayout->addWidget(quality);

        label_4 = new QLabel(SaveSnapshotDialog);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label_4);

        palette = new QComboBox(SaveSnapshotDialog);
        palette->setObjectName(QStringLiteral("palette"));

        verticalLayout->addWidget(palette);

        label_5 = new QLabel(SaveSnapshotDialog);
        label_5->setObjectName(QStringLiteral("label_5"));

        verticalLayout->addWidget(label_5);

        stereoMode = new QComboBox(SaveSnapshotDialog);
        stereoMode->setObjectName(QStringLiteral("stereoMode"));

        verticalLayout->addWidget(stereoMode);

        hboxLayout1 = new QHBoxLayout();
#ifndef Q_OS_MAC
        hboxLayout1->setSpacing(6);
#endif
        hboxLayout1->setContentsMargins(0, 0, 0, 0);
        hboxLayout1->setObjectName(QStringLiteral("hboxLayout1"));
        spacerItem = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        hboxLayout1->addItem(spacerItem);

        ok = new QPushButton(SaveSnapshotDialog);
        ok->setObjectName(QStringLiteral("ok"));

        hboxLayout1->addWidget(ok);

        cancel = new QPushButton(SaveSnapshotDialog);
        cancel->setObjectName(QStringLiteral("cancel"));

        hboxLayout1->addWidget(cancel);


        verticalLayout->addLayout(hboxLayout1);


        retranslateUi(SaveSnapshotDialog);
        QObject::connect(ok, SIGNAL(clicked()), SaveSnapshotDialog, SLOT(accept()));
        QObject::connect(cancel, SIGNAL(clicked()), SaveSnapshotDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(SaveSnapshotDialog);
    } // setupUi

    void retranslateUi(QDialog *SaveSnapshotDialog)
    {
        SaveSnapshotDialog->setWindowTitle(QApplication::translate("SaveSnapshotDialog", "Save Screenshot Options", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        selectedViewOnly->setToolTip(QApplication::translate("SaveSnapshotDialog", "<html>When checked, only the active view will be saved, otherwise all views will be saved in the image as they are layed out presently.</html>", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        selectedViewOnly->setStatusTip(QApplication::translate("SaveSnapshotDialog", "<html>When checked, only the active view will be saved, otherwise all views will be saved in the image as they are layed out presently.</html>", Q_NULLPTR));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        selectedViewOnly->setWhatsThis(QApplication::translate("SaveSnapshotDialog", "<html>When checked, only the active view will be saved, otherwise all views will be saved in the image as they are layed out presently.</html>", Q_NULLPTR));
#endif // QT_NO_WHATSTHIS
        selectedViewOnly->setText(QApplication::translate("SaveSnapshotDialog", "Save only selected view", Q_NULLPTR));
        label->setText(QApplication::translate("SaveSnapshotDialog", "<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Sans Serif'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-weight:600;\">Select resolution for the image to save</span></p></body></html>", Q_NULLPTR));
        label_2->setText(QApplication::translate("SaveSnapshotDialog", "x", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        lockAspect->setToolTip(QApplication::translate("SaveSnapshotDialog", "Lock aspect ", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        lockAspect->setStatusTip(QApplication::translate("SaveSnapshotDialog", "Lock aspect ", Q_NULLPTR));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        lockAspect->setWhatsThis(QApplication::translate("SaveSnapshotDialog", "Lock aspect ", Q_NULLPTR));
#endif // QT_NO_WHATSTHIS
        lockAspect->setText(QApplication::translate("SaveSnapshotDialog", "L", Q_NULLPTR));
        label_3->setText(QApplication::translate("SaveSnapshotDialog", "<b>Select image quality (if applicable)</b><br/>0 - low quality, 100 - high quality", Q_NULLPTR));
        label_4->setText(QApplication::translate("SaveSnapshotDialog", "<b>Override Color Palette</b>", Q_NULLPTR));
        palette->clear();
        palette->insertItems(0, QStringList()
         << QApplication::translate("SaveSnapshotDialog", "Current Palette", Q_NULLPTR)
        );
        label_5->setText(QApplication::translate("SaveSnapshotDialog", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Helvetica'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-weight:600;\">Stereo Mode (if applicable)</span></p></body></html>", Q_NULLPTR));
        ok->setText(QApplication::translate("SaveSnapshotDialog", "Ok", Q_NULLPTR));
        cancel->setText(QApplication::translate("SaveSnapshotDialog", "Cancel", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class SaveSnapshotDialog: public Ui_SaveSnapshotDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PQSAVESNAPSHOTDIALOG_H
