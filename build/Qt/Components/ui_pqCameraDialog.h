/********************************************************************************
** Form generated from reading UI file 'pqCameraDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PQCAMERADIALOG_H
#define UI_PQCAMERADIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include "pqCollapsedGroup.h"
#include "pqDoubleRangeWidget.h"

QT_BEGIN_NAMESPACE

class Ui_pqCameraDialog
{
public:
    QVBoxLayout *verticalLayout_3;
    pqCollapsedGroup *groupBox_2;
    QVBoxLayout *verticalLayout_2;
    QGroupBox *viewsGroup;
    QHBoxLayout *horizontalLayout_3;
    QToolButton *viewXPlus;
    QToolButton *viewXMinus;
    QToolButton *viewYPlus;
    QToolButton *viewYMinus;
    QToolButton *viewZPlus;
    QToolButton *viewZMinus;
    QSpacerItem *spacerItem;
    QGroupBox *customViewsGroup;
    QHBoxLayout *horizontalLayout_4;
    QToolButton *customView0;
    QToolButton *customView1;
    QToolButton *customView2;
    QToolButton *customView3;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *configureCustomViews;
    pqCollapsedGroup *groupBox;
    QVBoxLayout *verticalLayout;
    QGroupBox *centerGroup;
    QGridLayout *gridLayout;
    QLineEdit *CenterX;
    QLineEdit *CenterY;
    QLineEdit *CenterZ;
    QCheckBox *AutoResetCenterOfRotation;
    QGroupBox *RotationFactorGroup;
    QGridLayout *gridLayout1;
    pqDoubleRangeWidget *rotationFactor;
    QGroupBox *positionsGroup;
    QGridLayout *gridLayout2;
    QLabel *label_22;
    QLabel *label_17;
    QLabel *label_14;
    QLabel *label_23;
    QDoubleSpinBox *viewAngle;
    QLineEdit *position0;
    QLineEdit *position1;
    QLineEdit *position2;
    QLineEdit *focalPoint0;
    QLineEdit *focalPoint1;
    QLineEdit *focalPoint2;
    QLineEdit *viewUp0;
    QLineEdit *viewUp1;
    QLineEdit *viewUp2;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *loadCameraConfiguration;
    QPushButton *saveCameraConfiguration;
    pqCollapsedGroup *orientationsGroup;
    QGridLayout *gridLayout3;
    QLabel *label_20;
    QPushButton *azimuthButton;
    QPushButton *elevationButton;
    QPushButton *rollButton;
    QDoubleSpinBox *azimuthAngle;
    QDoubleSpinBox *elevationAngle;
    QDoubleSpinBox *rollAngle;
    QLabel *label_21;
    QLabel *label_16;
    pqCollapsedGroup *interactiveViewLinkGroup;
    QGridLayout *gridLayout4;
    QComboBox *interactiveViewLinkComboBox;
    QCheckBox *interactiveViewLinkBackground;
    QLabel *label_InteractiveViewLinkOpacity;
    pqDoubleRangeWidget *interactiveViewLinkOpacity;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *spacerItem1;
    QPushButton *closeButton;
    QSpacerItem *verticalSpacer;

    void setupUi(QDialog *pqCameraDialog)
    {
        if (pqCameraDialog->objectName().isEmpty())
            pqCameraDialog->setObjectName(QStringLiteral("pqCameraDialog"));
        pqCameraDialog->setWindowModality(Qt::NonModal);
        pqCameraDialog->resize(349, 712);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::MinimumExpanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(pqCameraDialog->sizePolicy().hasHeightForWidth());
        pqCameraDialog->setSizePolicy(sizePolicy);
        verticalLayout_3 = new QVBoxLayout(pqCameraDialog);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        groupBox_2 = new pqCollapsedGroup(pqCameraDialog);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        verticalLayout_2 = new QVBoxLayout(groupBox_2);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(-1, 0, -1, 4);
        viewsGroup = new QGroupBox(groupBox_2);
        viewsGroup->setObjectName(QStringLiteral("viewsGroup"));
        viewsGroup->setFlat(true);
        horizontalLayout_3 = new QHBoxLayout(viewsGroup);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        viewXPlus = new QToolButton(viewsGroup);
        viewXPlus->setObjectName(QStringLiteral("viewXPlus"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/pqWidgets/Icons/pqXPlus24.png"), QSize(), QIcon::Normal, QIcon::Off);
        viewXPlus->setIcon(icon);
        viewXPlus->setIconSize(QSize(24, 24));

        horizontalLayout_3->addWidget(viewXPlus);

        viewXMinus = new QToolButton(viewsGroup);
        viewXMinus->setObjectName(QStringLiteral("viewXMinus"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/pqWidgets/Icons/pqXMinus24.png"), QSize(), QIcon::Normal, QIcon::Off);
        viewXMinus->setIcon(icon1);
        viewXMinus->setIconSize(QSize(24, 24));

        horizontalLayout_3->addWidget(viewXMinus);

        viewYPlus = new QToolButton(viewsGroup);
        viewYPlus->setObjectName(QStringLiteral("viewYPlus"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/pqWidgets/Icons/pqYPlus24.png"), QSize(), QIcon::Normal, QIcon::Off);
        viewYPlus->setIcon(icon2);
        viewYPlus->setIconSize(QSize(24, 24));

        horizontalLayout_3->addWidget(viewYPlus);

        viewYMinus = new QToolButton(viewsGroup);
        viewYMinus->setObjectName(QStringLiteral("viewYMinus"));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/pqWidgets/Icons/pqYMinus24.png"), QSize(), QIcon::Normal, QIcon::Off);
        viewYMinus->setIcon(icon3);
        viewYMinus->setIconSize(QSize(24, 24));

        horizontalLayout_3->addWidget(viewYMinus);

        viewZPlus = new QToolButton(viewsGroup);
        viewZPlus->setObjectName(QStringLiteral("viewZPlus"));
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/pqWidgets/Icons/pqZPlus24.png"), QSize(), QIcon::Normal, QIcon::Off);
        viewZPlus->setIcon(icon4);
        viewZPlus->setIconSize(QSize(24, 24));

        horizontalLayout_3->addWidget(viewZPlus);

        viewZMinus = new QToolButton(viewsGroup);
        viewZMinus->setObjectName(QStringLiteral("viewZMinus"));
        QIcon icon5;
        icon5.addFile(QStringLiteral(":/pqWidgets/Icons/pqZMinus24.png"), QSize(), QIcon::Normal, QIcon::Off);
        viewZMinus->setIcon(icon5);
        viewZMinus->setIconSize(QSize(24, 24));

        horizontalLayout_3->addWidget(viewZMinus);

        spacerItem = new QSpacerItem(0, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(spacerItem);


        verticalLayout_2->addWidget(viewsGroup);

        customViewsGroup = new QGroupBox(groupBox_2);
        customViewsGroup->setObjectName(QStringLiteral("customViewsGroup"));
        customViewsGroup->setFlat(true);
        horizontalLayout_4 = new QHBoxLayout(customViewsGroup);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        customView0 = new QToolButton(customViewsGroup);
        customView0->setObjectName(QStringLiteral("customView0"));
        customView0->setMinimumSize(QSize(34, 33));
        customView0->setIconSize(QSize(24, 24));

        horizontalLayout_4->addWidget(customView0);

        customView1 = new QToolButton(customViewsGroup);
        customView1->setObjectName(QStringLiteral("customView1"));
        customView1->setMinimumSize(QSize(34, 33));
        customView1->setIconSize(QSize(24, 24));

        horizontalLayout_4->addWidget(customView1);

        customView2 = new QToolButton(customViewsGroup);
        customView2->setObjectName(QStringLiteral("customView2"));
        customView2->setMinimumSize(QSize(34, 33));
        customView2->setIconSize(QSize(24, 24));

        horizontalLayout_4->addWidget(customView2);

        customView3 = new QToolButton(customViewsGroup);
        customView3->setObjectName(QStringLiteral("customView3"));
        customView3->setMinimumSize(QSize(34, 33));
        customView3->setIconSize(QSize(24, 24));

        horizontalLayout_4->addWidget(customView3);

        horizontalSpacer_2 = new QSpacerItem(49, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_2);

        configureCustomViews = new QPushButton(customViewsGroup);
        configureCustomViews->setObjectName(QStringLiteral("configureCustomViews"));

        horizontalLayout_4->addWidget(configureCustomViews);


        verticalLayout_2->addWidget(customViewsGroup);


        verticalLayout_3->addWidget(groupBox_2);

        groupBox = new pqCollapsedGroup(pqCameraDialog);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        verticalLayout = new QVBoxLayout(groupBox);
        verticalLayout->setContentsMargins(6, 6, 6, 6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        centerGroup = new QGroupBox(groupBox);
        centerGroup->setObjectName(QStringLiteral("centerGroup"));
        centerGroup->setFlat(true);
        gridLayout = new QGridLayout(centerGroup);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        CenterX = new QLineEdit(centerGroup);
        CenterX->setObjectName(QStringLiteral("CenterX"));

        gridLayout->addWidget(CenterX, 0, 0, 1, 1);

        CenterY = new QLineEdit(centerGroup);
        CenterY->setObjectName(QStringLiteral("CenterY"));

        gridLayout->addWidget(CenterY, 0, 1, 1, 1);

        CenterZ = new QLineEdit(centerGroup);
        CenterZ->setObjectName(QStringLiteral("CenterZ"));

        gridLayout->addWidget(CenterZ, 0, 2, 1, 1);

        AutoResetCenterOfRotation = new QCheckBox(centerGroup);
        AutoResetCenterOfRotation->setObjectName(QStringLiteral("AutoResetCenterOfRotation"));

        gridLayout->addWidget(AutoResetCenterOfRotation, 1, 0, 1, 3);


        verticalLayout->addWidget(centerGroup);

        RotationFactorGroup = new QGroupBox(groupBox);
        RotationFactorGroup->setObjectName(QStringLiteral("RotationFactorGroup"));
        RotationFactorGroup->setFlat(true);
        gridLayout1 = new QGridLayout(RotationFactorGroup);
        gridLayout1->setObjectName(QStringLiteral("gridLayout1"));
        rotationFactor = new pqDoubleRangeWidget(RotationFactorGroup);
        rotationFactor->setObjectName(QStringLiteral("rotationFactor"));
        rotationFactor->setStrictRange(true);

        gridLayout1->addWidget(rotationFactor, 0, 0, 1, 1);


        verticalLayout->addWidget(RotationFactorGroup);

        positionsGroup = new QGroupBox(groupBox);
        positionsGroup->setObjectName(QStringLiteral("positionsGroup"));
        positionsGroup->setFlat(true);
        gridLayout2 = new QGridLayout(positionsGroup);
        gridLayout2->setSpacing(-1);
        gridLayout2->setContentsMargins(4, 4, 4, 4);
        gridLayout2->setObjectName(QStringLiteral("gridLayout2"));
        label_22 = new QLabel(positionsGroup);
        label_22->setObjectName(QStringLiteral("label_22"));

        gridLayout2->addWidget(label_22, 0, 0, 1, 1);

        label_17 = new QLabel(positionsGroup);
        label_17->setObjectName(QStringLiteral("label_17"));

        gridLayout2->addWidget(label_17, 1, 0, 1, 1);

        label_14 = new QLabel(positionsGroup);
        label_14->setObjectName(QStringLiteral("label_14"));

        gridLayout2->addWidget(label_14, 2, 0, 1, 1);

        label_23 = new QLabel(positionsGroup);
        label_23->setObjectName(QStringLiteral("label_23"));

        gridLayout2->addWidget(label_23, 3, 0, 1, 1);

        viewAngle = new QDoubleSpinBox(positionsGroup);
        viewAngle->setObjectName(QStringLiteral("viewAngle"));
        viewAngle->setMinimum(-360);
        viewAngle->setMaximum(360);

        gridLayout2->addWidget(viewAngle, 3, 1, 1, 1);

        position0 = new QLineEdit(positionsGroup);
        position0->setObjectName(QStringLiteral("position0"));

        gridLayout2->addWidget(position0, 0, 1, 1, 1);

        position1 = new QLineEdit(positionsGroup);
        position1->setObjectName(QStringLiteral("position1"));

        gridLayout2->addWidget(position1, 0, 2, 1, 1);

        position2 = new QLineEdit(positionsGroup);
        position2->setObjectName(QStringLiteral("position2"));

        gridLayout2->addWidget(position2, 0, 3, 1, 1);

        focalPoint0 = new QLineEdit(positionsGroup);
        focalPoint0->setObjectName(QStringLiteral("focalPoint0"));

        gridLayout2->addWidget(focalPoint0, 1, 1, 1, 1);

        focalPoint1 = new QLineEdit(positionsGroup);
        focalPoint1->setObjectName(QStringLiteral("focalPoint1"));

        gridLayout2->addWidget(focalPoint1, 1, 2, 1, 1);

        focalPoint2 = new QLineEdit(positionsGroup);
        focalPoint2->setObjectName(QStringLiteral("focalPoint2"));

        gridLayout2->addWidget(focalPoint2, 1, 3, 1, 1);

        viewUp0 = new QLineEdit(positionsGroup);
        viewUp0->setObjectName(QStringLiteral("viewUp0"));

        gridLayout2->addWidget(viewUp0, 2, 1, 1, 1);

        viewUp1 = new QLineEdit(positionsGroup);
        viewUp1->setObjectName(QStringLiteral("viewUp1"));

        gridLayout2->addWidget(viewUp1, 2, 2, 1, 1);

        viewUp2 = new QLineEdit(positionsGroup);
        viewUp2->setObjectName(QStringLiteral("viewUp2"));

        gridLayout2->addWidget(viewUp2, 2, 3, 1, 1);


        verticalLayout->addWidget(positionsGroup);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        loadCameraConfiguration = new QPushButton(groupBox);
        loadCameraConfiguration->setObjectName(QStringLiteral("loadCameraConfiguration"));

        horizontalLayout->addWidget(loadCameraConfiguration);

        saveCameraConfiguration = new QPushButton(groupBox);
        saveCameraConfiguration->setObjectName(QStringLiteral("saveCameraConfiguration"));

        horizontalLayout->addWidget(saveCameraConfiguration);


        verticalLayout->addLayout(horizontalLayout);


        verticalLayout_3->addWidget(groupBox);

        orientationsGroup = new pqCollapsedGroup(pqCameraDialog);
        orientationsGroup->setObjectName(QStringLiteral("orientationsGroup"));
        gridLayout3 = new QGridLayout(orientationsGroup);
        gridLayout3->setSpacing(4);
        gridLayout3->setContentsMargins(4, 4, 4, 4);
        gridLayout3->setObjectName(QStringLiteral("gridLayout3"));
        label_20 = new QLabel(orientationsGroup);
        label_20->setObjectName(QStringLiteral("label_20"));
        QSizePolicy sizePolicy1(QSizePolicy::MinimumExpanding, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label_20->sizePolicy().hasHeightForWidth());
        label_20->setSizePolicy(sizePolicy1);

        gridLayout3->addWidget(label_20, 0, 2, 1, 1);

        azimuthButton = new QPushButton(orientationsGroup);
        azimuthButton->setObjectName(QStringLiteral("azimuthButton"));
        QIcon icon6;
        icon6.addFile(QStringLiteral(""), QSize(), QIcon::Normal, QIcon::Off);
        azimuthButton->setIcon(icon6);
        azimuthButton->setIconSize(QSize(24, 24));

        gridLayout3->addWidget(azimuthButton, 2, 0, 1, 1);

        elevationButton = new QPushButton(orientationsGroup);
        elevationButton->setObjectName(QStringLiteral("elevationButton"));
        elevationButton->setIcon(icon6);
        elevationButton->setIconSize(QSize(24, 24));

        gridLayout3->addWidget(elevationButton, 1, 0, 1, 1);

        rollButton = new QPushButton(orientationsGroup);
        rollButton->setObjectName(QStringLiteral("rollButton"));
        rollButton->setIcon(icon6);
        rollButton->setIconSize(QSize(24, 24));

        gridLayout3->addWidget(rollButton, 0, 0, 1, 1);

        azimuthAngle = new QDoubleSpinBox(orientationsGroup);
        azimuthAngle->setObjectName(QStringLiteral("azimuthAngle"));
        azimuthAngle->setMinimum(-360);
        azimuthAngle->setMaximum(360);

        gridLayout3->addWidget(azimuthAngle, 2, 1, 1, 1);

        elevationAngle = new QDoubleSpinBox(orientationsGroup);
        elevationAngle->setObjectName(QStringLiteral("elevationAngle"));
        elevationAngle->setMinimum(-360);
        elevationAngle->setMaximum(360);

        gridLayout3->addWidget(elevationAngle, 1, 1, 1, 1);

        rollAngle = new QDoubleSpinBox(orientationsGroup);
        rollAngle->setObjectName(QStringLiteral("rollAngle"));
        rollAngle->setMinimum(-360);
        rollAngle->setMaximum(360);

        gridLayout3->addWidget(rollAngle, 0, 1, 1, 1);

        label_21 = new QLabel(orientationsGroup);
        label_21->setObjectName(QStringLiteral("label_21"));
        sizePolicy1.setHeightForWidth(label_21->sizePolicy().hasHeightForWidth());
        label_21->setSizePolicy(sizePolicy1);

        gridLayout3->addWidget(label_21, 1, 2, 1, 1);

        label_16 = new QLabel(orientationsGroup);
        label_16->setObjectName(QStringLiteral("label_16"));
        sizePolicy1.setHeightForWidth(label_16->sizePolicy().hasHeightForWidth());
        label_16->setSizePolicy(sizePolicy1);

        gridLayout3->addWidget(label_16, 2, 2, 1, 1);


        verticalLayout_3->addWidget(orientationsGroup);

        interactiveViewLinkGroup = new pqCollapsedGroup(pqCameraDialog);
        interactiveViewLinkGroup->setObjectName(QStringLiteral("interactiveViewLinkGroup"));
        gridLayout4 = new QGridLayout(interactiveViewLinkGroup);
        gridLayout4->setSpacing(4);
        gridLayout4->setContentsMargins(4, 4, 4, 4);
        gridLayout4->setObjectName(QStringLiteral("gridLayout4"));
        interactiveViewLinkComboBox = new QComboBox(interactiveViewLinkGroup);
        interactiveViewLinkComboBox->setObjectName(QStringLiteral("interactiveViewLinkComboBox"));

        gridLayout4->addWidget(interactiveViewLinkComboBox, 0, 0, 1, 2);

        interactiveViewLinkBackground = new QCheckBox(interactiveViewLinkGroup);
        interactiveViewLinkBackground->setObjectName(QStringLiteral("interactiveViewLinkBackground"));

        gridLayout4->addWidget(interactiveViewLinkBackground, 1, 0, 1, 2);

        label_InteractiveViewLinkOpacity = new QLabel(interactiveViewLinkGroup);
        label_InteractiveViewLinkOpacity->setObjectName(QStringLiteral("label_InteractiveViewLinkOpacity"));

        gridLayout4->addWidget(label_InteractiveViewLinkOpacity, 2, 0, 1, 1);

        interactiveViewLinkOpacity = new pqDoubleRangeWidget(interactiveViewLinkGroup);
        interactiveViewLinkOpacity->setObjectName(QStringLiteral("interactiveViewLinkOpacity"));
        interactiveViewLinkOpacity->setStrictRange(true);

        gridLayout4->addWidget(interactiveViewLinkOpacity, 2, 1, 1, 1);


        verticalLayout_3->addWidget(interactiveViewLinkGroup);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        spacerItem1 = new QSpacerItem(13, 24, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(spacerItem1);

        closeButton = new QPushButton(pqCameraDialog);
        closeButton->setObjectName(QStringLiteral("closeButton"));
        QSizePolicy sizePolicy2(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(closeButton->sizePolicy().hasHeightForWidth());
        closeButton->setSizePolicy(sizePolicy2);

        horizontalLayout_2->addWidget(closeButton);


        verticalLayout_3->addLayout(horizontalLayout_2);

        verticalSpacer = new QSpacerItem(20, 1, QSizePolicy::Minimum, QSizePolicy::MinimumExpanding);

        verticalLayout_3->addItem(verticalSpacer);

        QWidget::setTabOrder(closeButton, viewXPlus);
        QWidget::setTabOrder(viewXPlus, viewXMinus);
        QWidget::setTabOrder(viewXMinus, viewYPlus);
        QWidget::setTabOrder(viewYPlus, viewYMinus);
        QWidget::setTabOrder(viewYMinus, viewZPlus);
        QWidget::setTabOrder(viewZPlus, viewZMinus);
        QWidget::setTabOrder(viewZMinus, CenterX);
        QWidget::setTabOrder(CenterX, CenterY);
        QWidget::setTabOrder(CenterY, CenterZ);
        QWidget::setTabOrder(CenterZ, AutoResetCenterOfRotation);
        QWidget::setTabOrder(AutoResetCenterOfRotation, position0);
        QWidget::setTabOrder(position0, position1);
        QWidget::setTabOrder(position1, position2);
        QWidget::setTabOrder(position2, focalPoint0);
        QWidget::setTabOrder(focalPoint0, focalPoint1);
        QWidget::setTabOrder(focalPoint1, focalPoint2);
        QWidget::setTabOrder(focalPoint2, viewUp0);
        QWidget::setTabOrder(viewUp0, viewUp1);
        QWidget::setTabOrder(viewUp1, viewUp2);
        QWidget::setTabOrder(viewUp2, viewAngle);
        QWidget::setTabOrder(viewAngle, rollAngle);
        QWidget::setTabOrder(rollAngle, rollButton);
        QWidget::setTabOrder(rollButton, elevationAngle);
        QWidget::setTabOrder(elevationAngle, elevationButton);
        QWidget::setTabOrder(elevationButton, azimuthAngle);
        QWidget::setTabOrder(azimuthAngle, azimuthButton);

        retranslateUi(pqCameraDialog);
        QObject::connect(closeButton, SIGNAL(clicked()), pqCameraDialog, SLOT(close()));

        QMetaObject::connectSlotsByName(pqCameraDialog);
    } // setupUi

    void retranslateUi(QDialog *pqCameraDialog)
    {
        pqCameraDialog->setWindowTitle(QApplication::translate("pqCameraDialog", "Adjusting Camera", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        groupBox_2->setToolTip(QApplication::translate("pqCameraDialog", "Apply a preset camera configuration.", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        groupBox_2->setStatusTip(QString());
#endif // QT_NO_STATUSTIP
        groupBox_2->setTitle(QApplication::translate("pqCameraDialog", "Views", Q_NULLPTR));
        viewsGroup->setTitle(QApplication::translate("pqCameraDialog", "Standard", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        viewXPlus->setToolTip(QApplication::translate("pqCameraDialog", "Looking down X axis from (1, 0, 0)", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        viewXPlus->setText(QString());
#ifndef QT_NO_TOOLTIP
        viewXMinus->setToolTip(QApplication::translate("pqCameraDialog", "Looking down X axis from (-1, 0, 0)", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        viewXMinus->setText(QString());
#ifndef QT_NO_TOOLTIP
        viewYPlus->setToolTip(QApplication::translate("pqCameraDialog", "Looking down Y axis from (0, 1, 0)", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        viewYPlus->setText(QString());
#ifndef QT_NO_TOOLTIP
        viewYMinus->setToolTip(QApplication::translate("pqCameraDialog", "Looking down Y axis from (0, -1, 0)", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        viewYMinus->setText(QString());
#ifndef QT_NO_TOOLTIP
        viewZPlus->setToolTip(QApplication::translate("pqCameraDialog", "Looking down X axis from (0, 0, 1)", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        viewZPlus->setText(QString());
#ifndef QT_NO_TOOLTIP
        viewZMinus->setToolTip(QApplication::translate("pqCameraDialog", "Looking down Z axis from (0, 0, -1)", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        viewZMinus->setText(QString());
        customViewsGroup->setTitle(QApplication::translate("pqCameraDialog", "Custom", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        customView0->setToolTip(QApplication::translate("pqCameraDialog", "not configured", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        customView0->setText(QApplication::translate("pqCameraDialog", "1", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        customView1->setToolTip(QApplication::translate("pqCameraDialog", "not configured", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        customView1->setText(QApplication::translate("pqCameraDialog", "2", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        customView2->setToolTip(QApplication::translate("pqCameraDialog", "not configured", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        customView2->setText(QApplication::translate("pqCameraDialog", "3", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        customView3->setToolTip(QApplication::translate("pqCameraDialog", "not configured", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        customView3->setText(QApplication::translate("pqCameraDialog", "4", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        configureCustomViews->setToolTip(QApplication::translate("pqCameraDialog", "Configure custom view buttons.", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        configureCustomViews->setText(QApplication::translate("pqCameraDialog", "Configure...", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        groupBox->setToolTip(QApplication::translate("pqCameraDialog", "View, and edit the current camera configuration.", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        groupBox->setTitle(QApplication::translate("pqCameraDialog", "Configuration", Q_NULLPTR));
        centerGroup->setTitle(QApplication::translate("pqCameraDialog", "Center of Rotation", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        AutoResetCenterOfRotation->setToolTip(QApplication::translate("pqCameraDialog", "Reset center of rotation when camera is reset.", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        AutoResetCenterOfRotation->setText(QApplication::translate("pqCameraDialog", "Reset Center of Rotation When Camera is Reset", Q_NULLPTR));
        RotationFactorGroup->setTitle(QApplication::translate("pqCameraDialog", "Rotation Factor", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        rotationFactor->setToolTip(QApplication::translate("pqCameraDialog", "Define the rotation speed factor.", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        positionsGroup->setTitle(QApplication::translate("pqCameraDialog", "Camera Positions", Q_NULLPTR));
        label_22->setText(QApplication::translate("pqCameraDialog", "Position", Q_NULLPTR));
        label_17->setText(QApplication::translate("pqCameraDialog", "Focal Point", Q_NULLPTR));
        label_14->setText(QApplication::translate("pqCameraDialog", "View Up", Q_NULLPTR));
        label_23->setText(QApplication::translate("pqCameraDialog", "View Angle", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        loadCameraConfiguration->setToolTip(QApplication::translate("pqCameraDialog", "Load camera properties.", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        loadCameraConfiguration->setText(QApplication::translate("pqCameraDialog", "Load", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        saveCameraConfiguration->setToolTip(QApplication::translate("pqCameraDialog", "Save camera properties.", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        saveCameraConfiguration->setText(QApplication::translate("pqCameraDialog", "Save", Q_NULLPTR));
        orientationsGroup->setTitle(QApplication::translate("pqCameraDialog", "Apply Manipulation", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        label_20->setToolTip(QApplication::translate("pqCameraDialog", "Apply a manipulation to the current camera using the buttons on the left.", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        label_20->setText(QApplication::translate("pqCameraDialog", "degrees", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        azimuthButton->setToolTip(QApplication::translate("pqCameraDialog", "Rotate around center of screen", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        azimuthButton->setText(QApplication::translate("pqCameraDialog", "Azimuth", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        elevationButton->setToolTip(QApplication::translate("pqCameraDialog", "Rotate around horizontal axis", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        elevationButton->setText(QApplication::translate("pqCameraDialog", "Elevation", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        rollButton->setToolTip(QApplication::translate("pqCameraDialog", "Rotate around vertical axis", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        rollButton->setText(QApplication::translate("pqCameraDialog", "Roll", Q_NULLPTR));
        label_21->setText(QApplication::translate("pqCameraDialog", "degrees", Q_NULLPTR));
        label_16->setText(QApplication::translate("pqCameraDialog", "degrees", Q_NULLPTR));
        interactiveViewLinkGroup->setTitle(QApplication::translate("pqCameraDialog", "Interactive View Link", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        interactiveViewLinkComboBox->setToolTip(QApplication::translate("pqCameraDialog", "Select Interactive View Link to manage.", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        interactiveViewLinkBackground->setToolTip(QApplication::translate("pqCameraDialog", "Hide background from linked view.", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        interactiveViewLinkBackground->setText(QApplication::translate("pqCameraDialog", "Hide background from linked view.", Q_NULLPTR));
        label_InteractiveViewLinkOpacity->setText(QApplication::translate("pqCameraDialog", "Opacity:", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        interactiveViewLinkOpacity->setToolTip(QApplication::translate("pqCameraDialog", "Define the view link opacity.", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        closeButton->setText(QApplication::translate("pqCameraDialog", "Close", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class pqCameraDialog: public Ui_pqCameraDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PQCAMERADIALOG_H
