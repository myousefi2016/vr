/********************************************************************************
** Form generated from reading UI file 'pqQueryClauseWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PQQUERYCLAUSEWIDGET_H
#define UI_PQQUERYCLAUSEWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_pqQueryClauseWidget
{
public:
    QVBoxLayout *verticalLayout;
    QFrame *line;
    QHBoxLayout *horizontalLayout;
    QComboBox *criteria;
    QComboBox *condition;
    QStackedWidget *valueStackedWidget;
    QWidget *singleValue;
    QHBoxLayout *horizontalLayout_4;
    QLineEdit *value;
    QWidget *range;
    QHBoxLayout *horizontalLayout_5;
    QLineEdit *value_min;
    QLabel *label_3;
    QLineEdit *value_max;
    QWidget *location;
    QHBoxLayout *horizontalLayout_7;
    QLineEdit *value_x;
    QLineEdit *value_y;
    QLineEdit *value_z;
    QWidget *multiBlock;
    QHBoxLayout *horizontalLayout_8;
    QLineEdit *value_block;
    QToolButton *showCompositeTree;
    QWidget *emptyValue;
    QHBoxLayout *horizontalLayout_9;
    QLabel *label_empty_value;
    QToolButton *helpButton;

    void setupUi(QWidget *pqQueryClauseWidget)
    {
        if (pqQueryClauseWidget->objectName().isEmpty())
            pqQueryClauseWidget->setObjectName(QStringLiteral("pqQueryClauseWidget"));
        pqQueryClauseWidget->resize(444, 38);
        verticalLayout = new QVBoxLayout(pqQueryClauseWidget);
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        line = new QFrame(pqQueryClauseWidget);
        line->setObjectName(QStringLiteral("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        criteria = new QComboBox(pqQueryClauseWidget);
        criteria->setObjectName(QStringLiteral("criteria"));
        criteria->setSizeAdjustPolicy(QComboBox::AdjustToContents);

        horizontalLayout->addWidget(criteria);

        condition = new QComboBox(pqQueryClauseWidget);
        condition->setObjectName(QStringLiteral("condition"));
        condition->setSizeAdjustPolicy(QComboBox::AdjustToContents);

        horizontalLayout->addWidget(condition);

        valueStackedWidget = new QStackedWidget(pqQueryClauseWidget);
        valueStackedWidget->setObjectName(QStringLiteral("valueStackedWidget"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(valueStackedWidget->sizePolicy().hasHeightForWidth());
        valueStackedWidget->setSizePolicy(sizePolicy);
        singleValue = new QWidget();
        singleValue->setObjectName(QStringLiteral("singleValue"));
        horizontalLayout_4 = new QHBoxLayout(singleValue);
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        value = new QLineEdit(singleValue);
        value->setObjectName(QStringLiteral("value"));

        horizontalLayout_4->addWidget(value);

        valueStackedWidget->addWidget(singleValue);
        range = new QWidget();
        range->setObjectName(QStringLiteral("range"));
        horizontalLayout_5 = new QHBoxLayout(range);
        horizontalLayout_5->setSpacing(3);
        horizontalLayout_5->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        value_min = new QLineEdit(range);
        value_min->setObjectName(QStringLiteral("value_min"));

        horizontalLayout_5->addWidget(value_min);

        label_3 = new QLabel(range);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout_5->addWidget(label_3);

        value_max = new QLineEdit(range);
        value_max->setObjectName(QStringLiteral("value_max"));

        horizontalLayout_5->addWidget(value_max);

        valueStackedWidget->addWidget(range);
        location = new QWidget();
        location->setObjectName(QStringLiteral("location"));
        horizontalLayout_7 = new QHBoxLayout(location);
        horizontalLayout_7->setSpacing(3);
        horizontalLayout_7->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        value_x = new QLineEdit(location);
        value_x->setObjectName(QStringLiteral("value_x"));

        horizontalLayout_7->addWidget(value_x);

        value_y = new QLineEdit(location);
        value_y->setObjectName(QStringLiteral("value_y"));

        horizontalLayout_7->addWidget(value_y);

        value_z = new QLineEdit(location);
        value_z->setObjectName(QStringLiteral("value_z"));

        horizontalLayout_7->addWidget(value_z);

        valueStackedWidget->addWidget(location);
        multiBlock = new QWidget();
        multiBlock->setObjectName(QStringLiteral("multiBlock"));
        horizontalLayout_8 = new QHBoxLayout(multiBlock);
        horizontalLayout_8->setSpacing(3);
        horizontalLayout_8->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        value_block = new QLineEdit(multiBlock);
        value_block->setObjectName(QStringLiteral("value_block"));

        horizontalLayout_8->addWidget(value_block);

        showCompositeTree = new QToolButton(multiBlock);
        showCompositeTree->setObjectName(QStringLiteral("showCompositeTree"));

        horizontalLayout_8->addWidget(showCompositeTree);

        valueStackedWidget->addWidget(multiBlock);
        emptyValue = new QWidget();
        emptyValue->setObjectName(QStringLiteral("emptyValue"));
        horizontalLayout_9 = new QHBoxLayout(emptyValue);
        horizontalLayout_9->setSpacing(3);
        horizontalLayout_9->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        label_empty_value = new QLabel(emptyValue);
        label_empty_value->setObjectName(QStringLiteral("label_empty_value"));

        horizontalLayout_9->addWidget(label_empty_value);

        valueStackedWidget->addWidget(emptyValue);

        horizontalLayout->addWidget(valueStackedWidget);

        helpButton = new QToolButton(pqQueryClauseWidget);
        helpButton->setObjectName(QStringLiteral("helpButton"));

        horizontalLayout->addWidget(helpButton);

        horizontalLayout->setStretch(2, 1);

        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(pqQueryClauseWidget);

        valueStackedWidget->setCurrentIndex(3);


        QMetaObject::connectSlotsByName(pqQueryClauseWidget);
    } // setupUi

    void retranslateUi(QWidget *pqQueryClauseWidget)
    {
        pqQueryClauseWidget->setWindowTitle(QApplication::translate("pqQueryClauseWidget", "Form", Q_NULLPTR));
        condition->clear();
        condition->insertItems(0, QStringList()
         << QApplication::translate("pqQueryClauseWidget", "is", Q_NULLPTR)
         << QApplication::translate("pqQueryClauseWidget", "is between", Q_NULLPTR)
         << QApplication::translate("pqQueryClauseWidget", "is one of", Q_NULLPTR)
         << QApplication::translate("pqQueryClauseWidget", "is >=", Q_NULLPTR)
         << QApplication::translate("pqQueryClauseWidget", "is <=", Q_NULLPTR)
        );
        label_3->setText(QApplication::translate("pqQueryClauseWidget", "and", Q_NULLPTR));
        showCompositeTree->setText(QApplication::translate("pqQueryClauseWidget", "...", Q_NULLPTR));
        label_empty_value->setText(QString());
        helpButton->setText(QApplication::translate("pqQueryClauseWidget", "?", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class pqQueryClauseWidget: public Ui_pqQueryClauseWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PQQUERYCLAUSEWIDGET_H
