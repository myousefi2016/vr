/********************************************************************************
** Form generated from reading UI file 'pqCylinderPropertyWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PQCYLINDERPROPERTYWIDGET_H
#define UI_PQCYLINDERPROPERTYWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>
#include "pqLineEdit.h"

QT_BEGIN_NAMESPACE

class Ui_CylinderPropertyWidget
{
public:
    QGridLayout *layout1;
    QCheckBox *show3DWidget;
    QGridLayout *gridLayout1;
    QCheckBox *outlineTranslation;
    QCheckBox *scaling;
    QGridLayout *gridLayout2;
    pqLineEdit *centerY;
    QLabel *radiusLabel;
    pqLineEdit *axisY;
    QLabel *axisLabel;
    pqLineEdit *axisX;
    pqLineEdit *radius;
    pqLineEdit *axisZ;
    QLabel *centerLabel;
    pqLineEdit *centerX;
    pqLineEdit *centerZ;
    QGridLayout *gridLayout3;
    QPushButton *useXAxis;
    QPushButton *useYAxis;
    QPushButton *useZAxis;
    QPushButton *useCameraAxis;
    QPushButton *resetCameraToAxis;
    QPushButton *resetBounds;

    void setupUi(QWidget *CylinderPropertyWidget)
    {
        if (CylinderPropertyWidget->objectName().isEmpty())
            CylinderPropertyWidget->setObjectName(QStringLiteral("CylinderPropertyWidget"));
        CylinderPropertyWidget->resize(372, 357);
        layout1 = new QGridLayout(CylinderPropertyWidget);
        layout1->setSpacing(2);
        layout1->setContentsMargins(0, 0, 0, 0);
        layout1->setObjectName(QStringLiteral("layout1"));
        show3DWidget = new QCheckBox(CylinderPropertyWidget);
        show3DWidget->setObjectName(QStringLiteral("show3DWidget"));
        show3DWidget->setChecked(true);

        layout1->addWidget(show3DWidget, 0, 0, 1, 2);

        gridLayout1 = new QGridLayout();
        gridLayout1->setSpacing(2);
        gridLayout1->setObjectName(QStringLiteral("gridLayout1"));
        outlineTranslation = new QCheckBox(CylinderPropertyWidget);
        outlineTranslation->setObjectName(QStringLiteral("outlineTranslation"));

        gridLayout1->addWidget(outlineTranslation, 0, 0, 1, 1);

        scaling = new QCheckBox(CylinderPropertyWidget);
        scaling->setObjectName(QStringLiteral("scaling"));

        gridLayout1->addWidget(scaling, 0, 1, 1, 1);


        layout1->addLayout(gridLayout1, 7, 0, 1, 2);

        gridLayout2 = new QGridLayout();
        gridLayout2->setSpacing(2);
        gridLayout2->setObjectName(QStringLiteral("gridLayout2"));
        centerY = new pqLineEdit(CylinderPropertyWidget);
        centerY->setObjectName(QStringLiteral("centerY"));

        gridLayout2->addWidget(centerY, 0, 2, 1, 1);

        radiusLabel = new QLabel(CylinderPropertyWidget);
        radiusLabel->setObjectName(QStringLiteral("radiusLabel"));

        gridLayout2->addWidget(radiusLabel, 2, 0, 1, 1);

        axisY = new pqLineEdit(CylinderPropertyWidget);
        axisY->setObjectName(QStringLiteral("axisY"));

        gridLayout2->addWidget(axisY, 1, 2, 1, 1);

        axisLabel = new QLabel(CylinderPropertyWidget);
        axisLabel->setObjectName(QStringLiteral("axisLabel"));

        gridLayout2->addWidget(axisLabel, 1, 0, 1, 1);

        axisX = new pqLineEdit(CylinderPropertyWidget);
        axisX->setObjectName(QStringLiteral("axisX"));

        gridLayout2->addWidget(axisX, 1, 1, 1, 1);

        radius = new pqLineEdit(CylinderPropertyWidget);
        radius->setObjectName(QStringLiteral("radius"));

        gridLayout2->addWidget(radius, 2, 1, 1, 1);

        axisZ = new pqLineEdit(CylinderPropertyWidget);
        axisZ->setObjectName(QStringLiteral("axisZ"));

        gridLayout2->addWidget(axisZ, 1, 3, 1, 1);

        centerLabel = new QLabel(CylinderPropertyWidget);
        centerLabel->setObjectName(QStringLiteral("centerLabel"));

        gridLayout2->addWidget(centerLabel, 0, 0, 1, 1);

        centerX = new pqLineEdit(CylinderPropertyWidget);
        centerX->setObjectName(QStringLiteral("centerX"));

        gridLayout2->addWidget(centerX, 0, 1, 1, 1);

        centerZ = new pqLineEdit(CylinderPropertyWidget);
        centerZ->setObjectName(QStringLiteral("centerZ"));

        gridLayout2->addWidget(centerZ, 0, 3, 1, 1);


        layout1->addLayout(gridLayout2, 5, 0, 1, 2);

        gridLayout3 = new QGridLayout();
        gridLayout3->setObjectName(QStringLiteral("gridLayout3"));
        useXAxis = new QPushButton(CylinderPropertyWidget);
        useXAxis->setObjectName(QStringLiteral("useXAxis"));

        gridLayout3->addWidget(useXAxis, 0, 0, 1, 1);

        useYAxis = new QPushButton(CylinderPropertyWidget);
        useYAxis->setObjectName(QStringLiteral("useYAxis"));

        gridLayout3->addWidget(useYAxis, 1, 0, 1, 1);

        useZAxis = new QPushButton(CylinderPropertyWidget);
        useZAxis->setObjectName(QStringLiteral("useZAxis"));

        gridLayout3->addWidget(useZAxis, 2, 0, 1, 1);

        useCameraAxis = new QPushButton(CylinderPropertyWidget);
        useCameraAxis->setObjectName(QStringLiteral("useCameraAxis"));

        gridLayout3->addWidget(useCameraAxis, 0, 1, 1, 1);

        resetCameraToAxis = new QPushButton(CylinderPropertyWidget);
        resetCameraToAxis->setObjectName(QStringLiteral("resetCameraToAxis"));

        gridLayout3->addWidget(resetCameraToAxis, 3, 0, 1, 2);

        resetBounds = new QPushButton(CylinderPropertyWidget);
        resetBounds->setObjectName(QStringLiteral("resetBounds"));

        gridLayout3->addWidget(resetBounds, 4, 0, 1, 2);


        layout1->addLayout(gridLayout3, 6, 0, 1, 2);

        QWidget::setTabOrder(show3DWidget, centerX);
        QWidget::setTabOrder(centerX, centerY);
        QWidget::setTabOrder(centerY, centerZ);
        QWidget::setTabOrder(centerZ, axisX);
        QWidget::setTabOrder(axisX, axisY);
        QWidget::setTabOrder(axisY, axisZ);
        QWidget::setTabOrder(axisZ, radius);
        QWidget::setTabOrder(radius, outlineTranslation);
        QWidget::setTabOrder(outlineTranslation, scaling);

        retranslateUi(CylinderPropertyWidget);

        QMetaObject::connectSlotsByName(CylinderPropertyWidget);
    } // setupUi

    void retranslateUi(QWidget *CylinderPropertyWidget)
    {
        CylinderPropertyWidget->setWindowTitle(QApplication::translate("CylinderPropertyWidget", "Form", Q_NULLPTR));
        show3DWidget->setText(QApplication::translate("CylinderPropertyWidget", "Show Cylinder", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        outlineTranslation->setToolTip(QApplication::translate("CylinderPropertyWidget", "Enable/disable the ability to translate the bounding box by moving it with the mouse", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        outlineTranslation->setText(QApplication::translate("CylinderPropertyWidget", "Outline Translation", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        scaling->setToolTip(QApplication::translate("CylinderPropertyWidget", "Enable/disable the ability to scale the widget with the mouse.", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        scaling->setText(QApplication::translate("CylinderPropertyWidget", "Scaling", Q_NULLPTR));
        radiusLabel->setText(QApplication::translate("CylinderPropertyWidget", "Radius", Q_NULLPTR));
        axisLabel->setText(QApplication::translate("CylinderPropertyWidget", "Axis", Q_NULLPTR));
        axisZ->setText(QString());
        centerLabel->setText(QApplication::translate("CylinderPropertyWidget", "Center", Q_NULLPTR));
        useXAxis->setText(QApplication::translate("CylinderPropertyWidget", "Along X Axis", Q_NULLPTR));
        useYAxis->setText(QApplication::translate("CylinderPropertyWidget", "Along Y Axis", Q_NULLPTR));
        useZAxis->setText(QApplication::translate("CylinderPropertyWidget", "Along Z Axis", Q_NULLPTR));
        useCameraAxis->setText(QApplication::translate("CylinderPropertyWidget", "Along Camera Axis", Q_NULLPTR));
        resetCameraToAxis->setText(QApplication::translate("CylinderPropertyWidget", "Reset Camera to Axis", Q_NULLPTR));
        resetBounds->setText(QApplication::translate("CylinderPropertyWidget", "Reset to Data Bounds", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class CylinderPropertyWidget: public Ui_CylinderPropertyWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PQCYLINDERPROPERTYWIDGET_H
