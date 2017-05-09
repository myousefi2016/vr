/********************************************************************************
** Form generated from reading UI file 'pqAnimationSettings.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PQANIMATIONSETTINGS_H
#define UI_PQANIMATIONSETTINGS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_pqAnimationSettingsDialog
{
public:
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout;
    QDoubleSpinBox *frameRate;
    QSpinBox *spinBoxFramesPerTimestep;
    QLabel *label_3;
    QCheckBox *compression;
    QSpinBox *spinBoxNumberOfFrames;
    QDoubleSpinBox *animationDuration;
    QLabel *labelFrameRate;
    QLabel *labelFramesPerTimestep;
    QLabel *labelAnimationDuration;
    QLineEdit *width;
    QLabel *label;
    QComboBox *stereoMode;
    QLineEdit *height;
    QToolButton *lockAspect;
    QLabel *label_5;
    QLabel *labelTimeRange;
    QLineEdit *startTime;
    QLineEdit *endTime;
    QCheckBox *checkBoxDisconnect;
    QHBoxLayout *hboxLayout;
    QSpacerItem *spacerItem;
    QPushButton *okButton;
    QPushButton *cancelButton;
    QSpacerItem *spacerItem1;

    void setupUi(QDialog *pqAnimationSettingsDialog)
    {
        if (pqAnimationSettingsDialog->objectName().isEmpty())
            pqAnimationSettingsDialog->setObjectName(QStringLiteral("pqAnimationSettingsDialog"));
        pqAnimationSettingsDialog->resize(404, 367);
        verticalLayout = new QVBoxLayout(pqAnimationSettingsDialog);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        frameRate = new QDoubleSpinBox(pqAnimationSettingsDialog);
        frameRate->setObjectName(QStringLiteral("frameRate"));
        frameRate->setMinimum(1);
        frameRate->setMaximum(999999);
        frameRate->setValue(15);

        gridLayout->addWidget(frameRate, 1, 1, 1, 3);

        spinBoxFramesPerTimestep = new QSpinBox(pqAnimationSettingsDialog);
        spinBoxFramesPerTimestep->setObjectName(QStringLiteral("spinBoxFramesPerTimestep"));
        spinBoxFramesPerTimestep->setMinimum(1);
        spinBoxFramesPerTimestep->setMaximum(2147483647);

        gridLayout->addWidget(spinBoxFramesPerTimestep, 2, 1, 1, 3);

        label_3 = new QLabel(pqAnimationSettingsDialog);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout->addWidget(label_3, 4, 0, 1, 1);

        compression = new QCheckBox(pqAnimationSettingsDialog);
        compression->setObjectName(QStringLiteral("compression"));
        compression->setEnabled(true);
        compression->setLayoutDirection(Qt::LeftToRight);
        compression->setChecked(true);
        compression->setTristate(false);

        gridLayout->addWidget(compression, 7, 0, 1, 1);

        spinBoxNumberOfFrames = new QSpinBox(pqAnimationSettingsDialog);
        spinBoxNumberOfFrames->setObjectName(QStringLiteral("spinBoxNumberOfFrames"));
        spinBoxNumberOfFrames->setMaximum(2147483647);

        gridLayout->addWidget(spinBoxNumberOfFrames, 3, 1, 1, 3);

        animationDuration = new QDoubleSpinBox(pqAnimationSettingsDialog);
        animationDuration->setObjectName(QStringLiteral("animationDuration"));
        animationDuration->setMaximum(1e+99);

        gridLayout->addWidget(animationDuration, 0, 1, 1, 3);

        labelFrameRate = new QLabel(pqAnimationSettingsDialog);
        labelFrameRate->setObjectName(QStringLiteral("labelFrameRate"));

        gridLayout->addWidget(labelFrameRate, 1, 0, 1, 1);

        labelFramesPerTimestep = new QLabel(pqAnimationSettingsDialog);
        labelFramesPerTimestep->setObjectName(QStringLiteral("labelFramesPerTimestep"));

        gridLayout->addWidget(labelFramesPerTimestep, 2, 0, 1, 1);

        labelAnimationDuration = new QLabel(pqAnimationSettingsDialog);
        labelAnimationDuration->setObjectName(QStringLiteral("labelAnimationDuration"));

        gridLayout->addWidget(labelAnimationDuration, 0, 0, 1, 1);

        width = new QLineEdit(pqAnimationSettingsDialog);
        width->setObjectName(QStringLiteral("width"));

        gridLayout->addWidget(width, 4, 1, 1, 1);

        label = new QLabel(pqAnimationSettingsDialog);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 3, 0, 1, 1);

        stereoMode = new QComboBox(pqAnimationSettingsDialog);
        stereoMode->setObjectName(QStringLiteral("stereoMode"));

        gridLayout->addWidget(stereoMode, 6, 1, 1, 3);

        height = new QLineEdit(pqAnimationSettingsDialog);
        height->setObjectName(QStringLiteral("height"));

        gridLayout->addWidget(height, 4, 2, 1, 1);

        lockAspect = new QToolButton(pqAnimationSettingsDialog);
        lockAspect->setObjectName(QStringLiteral("lockAspect"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/pqWidgets/Icons/pqOctreeData16.png"), QSize(), QIcon::Normal, QIcon::Off);
        lockAspect->setIcon(icon);
        lockAspect->setIconSize(QSize(12, 12));
        lockAspect->setCheckable(true);

        gridLayout->addWidget(lockAspect, 4, 3, 1, 1);

        label_5 = new QLabel(pqAnimationSettingsDialog);
        label_5->setObjectName(QStringLiteral("label_5"));

        gridLayout->addWidget(label_5, 6, 0, 1, 1);

        labelTimeRange = new QLabel(pqAnimationSettingsDialog);
        labelTimeRange->setObjectName(QStringLiteral("labelTimeRange"));

        gridLayout->addWidget(labelTimeRange, 5, 0, 1, 1);

        startTime = new QLineEdit(pqAnimationSettingsDialog);
        startTime->setObjectName(QStringLiteral("startTime"));

        gridLayout->addWidget(startTime, 5, 1, 1, 1);

        endTime = new QLineEdit(pqAnimationSettingsDialog);
        endTime->setObjectName(QStringLiteral("endTime"));

        gridLayout->addWidget(endTime, 5, 2, 1, 1);


        verticalLayout->addLayout(gridLayout);

        checkBoxDisconnect = new QCheckBox(pqAnimationSettingsDialog);
        checkBoxDisconnect->setObjectName(QStringLiteral("checkBoxDisconnect"));
        checkBoxDisconnect->setEnabled(true);

        verticalLayout->addWidget(checkBoxDisconnect);

        hboxLayout = new QHBoxLayout();
        hboxLayout->setObjectName(QStringLiteral("hboxLayout"));
        spacerItem = new QSpacerItem(131, 31, QSizePolicy::Expanding, QSizePolicy::Minimum);

        hboxLayout->addItem(spacerItem);

        okButton = new QPushButton(pqAnimationSettingsDialog);
        okButton->setObjectName(QStringLiteral("okButton"));

        hboxLayout->addWidget(okButton);

        cancelButton = new QPushButton(pqAnimationSettingsDialog);
        cancelButton->setObjectName(QStringLiteral("cancelButton"));

        hboxLayout->addWidget(cancelButton);


        verticalLayout->addLayout(hboxLayout);

        spacerItem1 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(spacerItem1);

        QWidget::setTabOrder(okButton, cancelButton);
        QWidget::setTabOrder(cancelButton, animationDuration);
        QWidget::setTabOrder(animationDuration, frameRate);
        QWidget::setTabOrder(frameRate, spinBoxFramesPerTimestep);
        QWidget::setTabOrder(spinBoxFramesPerTimestep, spinBoxNumberOfFrames);
        QWidget::setTabOrder(spinBoxNumberOfFrames, width);
        QWidget::setTabOrder(width, height);
        QWidget::setTabOrder(height, startTime);
        QWidget::setTabOrder(startTime, endTime);
        QWidget::setTabOrder(endTime, lockAspect);
        QWidget::setTabOrder(lockAspect, stereoMode);
        QWidget::setTabOrder(stereoMode, compression);
        QWidget::setTabOrder(compression, checkBoxDisconnect);

        retranslateUi(pqAnimationSettingsDialog);
        QObject::connect(okButton, SIGNAL(clicked()), pqAnimationSettingsDialog, SLOT(accept()));
        QObject::connect(cancelButton, SIGNAL(clicked()), pqAnimationSettingsDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(pqAnimationSettingsDialog);
    } // setupUi

    void retranslateUi(QDialog *pqAnimationSettingsDialog)
    {
        pqAnimationSettingsDialog->setWindowTitle(QApplication::translate("pqAnimationSettingsDialog", "Animation Settings Dialog", Q_NULLPTR));
        label_3->setText(QApplication::translate("pqAnimationSettingsDialog", "Resolution (pixels)", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        compression->setToolTip(QApplication::translate("pqAnimationSettingsDialog", "When checked creates standard files, unchecked creates large files without any compression.", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        compression->setText(QApplication::translate("pqAnimationSettingsDialog", "Compression", Q_NULLPTR));
        labelFrameRate->setText(QApplication::translate("pqAnimationSettingsDialog", "Frame Rate (fps)", Q_NULLPTR));
        labelFramesPerTimestep->setText(QApplication::translate("pqAnimationSettingsDialog", "No. of Frames / timestep", Q_NULLPTR));
        labelAnimationDuration->setText(QApplication::translate("pqAnimationSettingsDialog", "Animation Duration (sec)", Q_NULLPTR));
        label->setText(QApplication::translate("pqAnimationSettingsDialog", "Number Of Frames", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        lockAspect->setToolTip(QApplication::translate("pqAnimationSettingsDialog", "Lock aspect", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        lockAspect->setStatusTip(QApplication::translate("pqAnimationSettingsDialog", "Lock aspect", Q_NULLPTR));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        lockAspect->setWhatsThis(QApplication::translate("pqAnimationSettingsDialog", "Lock aspect", Q_NULLPTR));
#endif // QT_NO_WHATSTHIS
        lockAspect->setText(QApplication::translate("pqAnimationSettingsDialog", "L", Q_NULLPTR));
        label_5->setText(QApplication::translate("pqAnimationSettingsDialog", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Helvetica'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-weight:600;\">Stereo Mode (if applicable)</span></p></body></html>", Q_NULLPTR));
        labelTimeRange->setText(QApplication::translate("pqAnimationSettingsDialog", "Time range", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        checkBoxDisconnect->setToolTip(QApplication::translate("pqAnimationSettingsDialog", "<html>Disconnect from the server before saving animation. The server will save the animation and then exit.</html>", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        checkBoxDisconnect->setStatusTip(QApplication::translate("pqAnimationSettingsDialog", "<html>Disconnect from the server before saving animation. The server will save the animation and then exit.</html>", Q_NULLPTR));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        checkBoxDisconnect->setWhatsThis(QApplication::translate("pqAnimationSettingsDialog", "<html>Disconnect from the server before saving animation. The server will save the animation and then exit.</html>", Q_NULLPTR));
#endif // QT_NO_WHATSTHIS
        checkBoxDisconnect->setText(QApplication::translate("pqAnimationSettingsDialog", "Disconnect before saving animation", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        okButton->setToolTip(QApplication::translate("pqAnimationSettingsDialog", "Generate and Save Animation", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        okButton->setText(QApplication::translate("pqAnimationSettingsDialog", "Save Animation", Q_NULLPTR));
        cancelButton->setText(QApplication::translate("pqAnimationSettingsDialog", "Cancel", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class pqAnimationSettingsDialog: public Ui_pqAnimationSettingsDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PQANIMATIONSETTINGS_H
