/********************************************************************************
** Form generated from reading UI file 'pqExampleVisualizationsDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PQEXAMPLEVISUALIZATIONSDIALOG_H
#define UI_PQEXAMPLEVISUALIZATIONSDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_pqExampleVisualizationsDialog
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *titleLabel;
    QLabel *label;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QWidget *widget_2;
    QVBoxLayout *verticalLayout_3;
    QPushButton *CanExampleButton;
    QLabel *CanExampleDescription;
    QWidget *widget_3;
    QVBoxLayout *verticalLayout_2;
    QPushButton *DiskOutRefExampleButton;
    QLabel *DiskOutRefExampleDescription;
    QWidget *widget_4;
    QVBoxLayout *verticalLayout_4;
    QPushButton *WaveletExampleButton;
    QLabel *WaveletExampleDescription;
    QSpacerItem *verticalSpacer;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *pqExampleVisualizationsDialog)
    {
        if (pqExampleVisualizationsDialog->objectName().isEmpty())
            pqExampleVisualizationsDialog->setObjectName(QStringLiteral("pqExampleVisualizationsDialog"));
        pqExampleVisualizationsDialog->resize(996, 390);
        verticalLayout = new QVBoxLayout(pqExampleVisualizationsDialog);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        titleLabel = new QLabel(pqExampleVisualizationsDialog);
        titleLabel->setObjectName(QStringLiteral("titleLabel"));
        QFont font;
        font.setPointSize(20);
        font.setItalic(false);
        font.setStrikeOut(false);
        font.setKerning(false);
        titleLabel->setFont(font);
        titleLabel->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(titleLabel);

        label = new QLabel(pqExampleVisualizationsDialog);
        label->setObjectName(QStringLiteral("label"));

        verticalLayout->addWidget(label);

        widget = new QWidget(pqExampleVisualizationsDialog);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setLayoutDirection(Qt::LeftToRight);
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(2, 2, 2, 2);
        widget_2 = new QWidget(widget);
        widget_2->setObjectName(QStringLiteral("widget_2"));
        verticalLayout_3 = new QVBoxLayout(widget_2);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(2, 2, 2, 2);
        CanExampleButton = new QPushButton(widget_2);
        CanExampleButton->setObjectName(QStringLiteral("CanExampleButton"));
        CanExampleButton->setEnabled(true);
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(CanExampleButton->sizePolicy().hasHeightForWidth());
        CanExampleButton->setSizePolicy(sizePolicy);
        CanExampleButton->setMinimumSize(QSize(300, 225));
        QFont font1;
        font1.setBold(false);
        font1.setWeight(50);
        CanExampleButton->setFont(font1);
        CanExampleButton->setAutoFillBackground(false);
        CanExampleButton->setStyleSheet(QStringLiteral(""));
        QIcon icon;
        icon.addFile(QStringLiteral(":/pqApplicationComponents/Thumbnails/CanExample.png"), QSize(), QIcon::Normal, QIcon::On);
        CanExampleButton->setIcon(icon);
        CanExampleButton->setIconSize(QSize(300, 225));
        CanExampleButton->setCheckable(false);
        CanExampleButton->setAutoDefault(true);
        CanExampleButton->setFlat(true);

        verticalLayout_3->addWidget(CanExampleButton);

        CanExampleDescription = new QLabel(widget_2);
        CanExampleDescription->setObjectName(QStringLiteral("CanExampleDescription"));
        CanExampleDescription->setFrameShape(QFrame::NoFrame);
        CanExampleDescription->setLineWidth(1);
        CanExampleDescription->setMidLineWidth(1);
        CanExampleDescription->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        CanExampleDescription->setWordWrap(true);
        CanExampleDescription->setMargin(0);
        CanExampleDescription->setIndent(-1);

        verticalLayout_3->addWidget(CanExampleDescription);


        horizontalLayout->addWidget(widget_2);

        widget_3 = new QWidget(widget);
        widget_3->setObjectName(QStringLiteral("widget_3"));
        verticalLayout_2 = new QVBoxLayout(widget_3);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(2, 2, 2, 2);
        DiskOutRefExampleButton = new QPushButton(widget_3);
        DiskOutRefExampleButton->setObjectName(QStringLiteral("DiskOutRefExampleButton"));
        DiskOutRefExampleButton->setMinimumSize(QSize(300, 225));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/pqApplicationComponents/Thumbnails/DiskOutRefExample.png"), QSize(), QIcon::Normal, QIcon::On);
        DiskOutRefExampleButton->setIcon(icon1);
        DiskOutRefExampleButton->setIconSize(QSize(300, 225));
        DiskOutRefExampleButton->setFlat(true);

        verticalLayout_2->addWidget(DiskOutRefExampleButton);

        DiskOutRefExampleDescription = new QLabel(widget_3);
        DiskOutRefExampleDescription->setObjectName(QStringLiteral("DiskOutRefExampleDescription"));
        DiskOutRefExampleDescription->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        DiskOutRefExampleDescription->setWordWrap(true);

        verticalLayout_2->addWidget(DiskOutRefExampleDescription);


        horizontalLayout->addWidget(widget_3);

        widget_4 = new QWidget(widget);
        widget_4->setObjectName(QStringLiteral("widget_4"));
        verticalLayout_4 = new QVBoxLayout(widget_4);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(2, 2, 2, 2);
        WaveletExampleButton = new QPushButton(widget_4);
        WaveletExampleButton->setObjectName(QStringLiteral("WaveletExampleButton"));
        WaveletExampleButton->setMinimumSize(QSize(300, 225));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/pqApplicationComponents/Thumbnails/WaveletExample.png"), QSize(), QIcon::Normal, QIcon::Off);
        WaveletExampleButton->setIcon(icon2);
        WaveletExampleButton->setIconSize(QSize(300, 225));
        WaveletExampleButton->setFlat(true);

        verticalLayout_4->addWidget(WaveletExampleButton);

        WaveletExampleDescription = new QLabel(widget_4);
        WaveletExampleDescription->setObjectName(QStringLiteral("WaveletExampleDescription"));
        WaveletExampleDescription->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        WaveletExampleDescription->setWordWrap(true);

        verticalLayout_4->addWidget(WaveletExampleDescription);


        horizontalLayout->addWidget(widget_4);


        verticalLayout->addWidget(widget);

        verticalSpacer = new QSpacerItem(20, 0, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        buttonBox = new QDialogButtonBox(pqExampleVisualizationsDialog);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Close);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(pqExampleVisualizationsDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), pqExampleVisualizationsDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), pqExampleVisualizationsDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(pqExampleVisualizationsDialog);
    } // setupUi

    void retranslateUi(QDialog *pqExampleVisualizationsDialog)
    {
        pqExampleVisualizationsDialog->setWindowTitle(QApplication::translate("pqExampleVisualizationsDialog", "ParaView Example Visualizations", Q_NULLPTR));
        titleLabel->setText(QApplication::translate("pqExampleVisualizationsDialog", "ParaView Example Visualizations", Q_NULLPTR));
        label->setText(QApplication::translate("pqExampleVisualizationsDialog", "<html><head/><body><p align=\"center\">Click on one of thumbnails below to load an example visualization</p></body></html>", Q_NULLPTR));
        CanExampleButton->setText(QString());
        CanExampleDescription->setText(QApplication::translate("pqExampleVisualizationsDialog", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'.SF NS Text'; font-size:13pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Exodus II file with timesteps, Clip filter<br /></p></body></html>", Q_NULLPTR));
        DiskOutRefExampleButton->setText(QString());
        DiskOutRefExampleDescription->setText(QApplication::translate("pqExampleVisualizationsDialog", "Exodus II file, Clip filter, Stream Tracer filter, Tube filter, Glyph filter", Q_NULLPTR));
        WaveletExampleButton->setText(QString());
        WaveletExampleDescription->setText(QApplication::translate("pqExampleVisualizationsDialog", "<html><head/><body><p>Wavelet with volume rendering and contours<br/></p></body></html>", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class pqExampleVisualizationsDialog: public Ui_pqExampleVisualizationsDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PQEXAMPLEVISUALIZATIONSDIALOG_H
