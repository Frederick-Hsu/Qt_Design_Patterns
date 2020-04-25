#include "Ui_QObjectBrowser.h"

#include <QCoreApplication>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGridLayout>

#define REGION_TOP_HBOX                 1
#define REGION_BOTTOM_TABS_GROUP        2

void Ui_QObjectBrowser::setupUi(QWidget *qobjectbrowser)
{
    if (qobjectbrowser->objectName().isEmpty())
    {
        qobjectbrowser->setObjectName(QString::fromUtf8("qobjectbrowser"));
    }
    qobjectbrowser->setWindowTitle(QCoreApplication::translate("qobjectbrowser", "QObject Browser", nullptr));
    qobjectbrowser->resize(600, 480);

#ifdef REGION_TOP_HBOX
    QVBoxLayout* classLabelsVbox = new QVBoxLayout();
    classLabelsVbox->setObjectName(QString::fromUtf8("classLabelsVbox"));
    classLabelsVbox->setSpacing(6);
    classLabelsVbox->setContentsMargins(0, 0, 0, 0);

    /*========= Label ---> Class: =============*/
    QLabel* classLabel = new QLabel(qobjectbrowser);
    classLabel->setObjectName(QString::fromUtf8("classLabel"));
    classLabel->setText(QCoreApplication::translate("qobjectbrowser", "<b>Class:</b>", nullptr));
    classLabel->setAlignment(Qt::AlignRight | Qt::AlignTrailing | Qt::AlignCenter);

    /*========= Label ---> Base Class: =============*/
    QLabel* baseclassLabel = new QLabel(qobjectbrowser);
    baseclassLabel->setObjectName(QString::fromUtf8("baseclassLabel"));
    baseclassLabel->setText(QCoreApplication::translate("qobjectbrowser", "<b>Base Class:</b>", nullptr));
    baseclassLabel->setAlignment(Qt::AlignRight | Qt::AlignTrailing | Qt::AlignVCenter);

    /* Add classLabel and baseclassLabel into the classLabelVbox */
    classLabelsVbox->addWidget(classLabel);
    classLabelsVbox->addWidget(baseclassLabel);

    QVBoxLayout* classnameLabelsVbox = new QVBoxLayout();
    classnameLabelsVbox->setObjectName(QString::fromUtf8("classnameLabelsVbox"));
    classnameLabelsVbox->setSpacing(6);
    classnameLabelsVbox->setContentsMargins(0, 0, 0, 0);

    /*========= Label ---> [Class Name] =============*/
    classnameLabel = new QLabel(qobjectbrowser);
    classnameLabel->setObjectName(QString::fromUtf8("classnameLabel"));
    classnameLabel->setText(QCoreApplication::translate("qobjectbrowser", "[Class Name]", nullptr));

    /*========= Label ---> [Base Class Name] =============*/
    baseclassnameLabel = new QLabel(qobjectbrowser);
    baseclassnameLabel->setObjectName(QString::fromUtf8("baseclassnameLabel"));
    baseclassnameLabel->setText(QCoreApplication::translate("qobjectbrowser", "[Base Class Name]", nullptr));

    /* Add classnameLabel and baseclassnameLabel into classnameLabelsVbox */
    classnameLabelsVbox->addWidget(classnameLabel);
    classnameLabelsVbox->addWidget(baseclassnameLabel);

    QSpacerItem* topSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

    QVBoxLayout* parentVbox = new QVBoxLayout();
    parentVbox->setObjectName(QString::fromUtf8("parentVbox"));
    parentVbox->setSpacing(6);
    parentVbox->setContentsMargins(0, 0, 0, 0);

    /*================ Button --->  Up to prent ==============*/
    uptoprentButton = new QPushButton(qobjectbrowser);
    uptoprentButton->setObjectName(QString::fromUtf8("uptoparentButton"));
    uptoprentButton->setText(QCoreApplication::translate("qobjectbrowser", "Up to parent...", nullptr));

    QHBoxLayout* parentclassnameHbox = new QHBoxLayout();
    parentclassnameHbox->setObjectName(QString::fromUtf8("parentclassnameHbox"));
    parentclassnameHbox->setSpacing(6);
    parentclassnameHbox->setContentsMargins(0, 0, 0, 0);

    /*=============== Label ---> Parent: ================*/
    QLabel* parentclassLabel = new QLabel(qobjectbrowser);
    parentclassLabel->setObjectName(QString::fromUtf8("parentclassLabel"));
    parentclassLabel->setText(QCoreApplication::translate("qobjectbrowser", "<b>Parent:</b>", nullptr));

    /*=============== Label ---> [Parent Class Name] =================*/
    parentclassnameLabel = new QLabel(qobjectbrowser);
    parentclassnameLabel->setObjectName(QString::fromUtf8("parentclassnameLabel"));
    parentclassnameLabel->setText(QCoreApplication::translate("qobjectbrowser", "[Parent Class Name]", nullptr));

    /* Add parentclassLabel and parentclassnameLabel into parentclassnameHbox */
    parentclassnameHbox->addWidget(parentclassLabel);
    parentclassnameHbox->addWidget(parentclassnameLabel);

    /* Add the uptoparentButton and parentclassnameHbox into the parentVbox */
    parentVbox->addWidget(uptoprentButton);
    parentVbox->addLayout(parentclassnameHbox);

    /*================ Top HBox ===================*/
    QHBoxLayout* topHbox = new QHBoxLayout();
    topHbox->setObjectName(QString::fromUtf8("topHbox"));
    topHbox->setSpacing(6);
    topHbox->setContentsMargins(0, 0, 0, 0);

    topHbox->addLayout(classLabelsVbox);
    topHbox->addLayout(classnameLabelsVbox);

    /* Add classLabelsVbox, classnameLabelsVbox, topSpacer and parentVbox into topHbox */
    topHbox->addLayout(classLabelsVbox);
    topHbox->addLayout(classnameLabelsVbox);
    topHbox->addItem(topSpacer);
    topHbox->addLayout(parentVbox);
#endif  /* REGION_TOP_HBOX */

#ifdef REGION_BOTTOM_TABS_GROUP
    /* Create a tabs group to accommodate the bottom tab region */
    tabGroup = new QTabWidget(qobjectbrowser);
    tabGroup->setObjectName(QString::fromUtf8("tabGroup"));

    /*=========== Tab : Children =============*/
    QWidget* childrenTab = new QWidget();
    childrenTab->setObjectName(QString::fromUtf8("childrenTab"));
    tabGroup->setTabText(tabGroup->indexOf(childrenTab),
                         QCoreApplication::translate("qobjectbrowser", "Children", nullptr));

    QGridLayout* gridLayoutUnderChildrenTab = new QGridLayout(childrenTab);
    gridLayoutUnderChildrenTab->setObjectName(QString::fromUtf8("gridLayoutUnderChildrenTab"));
    gridLayoutUnderChildrenTab->setSpacing(6);
    gridLayoutUnderChildrenTab->setContentsMargins(9, 9, 9, 9);

    /*=========== Spacer : bottom spacer under childrenTab ==============*/
    QSpacerItem* bottomSpacerUnderChildrenTab = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);
    /*=========== Button : Update Children ===========*/
    updatechildrenButton = new QPushButton(childrenTab);
    updatechildrenButton->setObjectName(QString::fromUtf8("updatechildrenButton"));
    /*=========== Table : children table ============*/
    childrenTable = new QTableWidget(childrenTab);
    childrenTable->setObjectName(QString::fromUtf8("childrenTable"));

    /* Add childrenTable, updatechildrenButton and bottomSpacerUnderChildrenTabl into
     * the gridLayoutUnderChildrenTab
     */
    gridLayoutUnderChildrenTab->addWidget(childrenTable,              0, 0, 1, 2);
    gridLayoutUnderChildrenTab->addWidget(updatechildrenButton,       1, 0, 1, 1);
    gridLayoutUnderChildrenTab->addItem(bottomSpacerUnderChildrenTab, 1, 1, 1, 1);
    /* Add the childrenTab into the tabGroup */
    tabGroup->addTab(childrenTab, QString());

    /*=============== Tab : Properties ==================*/
    QWidget* propertiesTab = new QWidget();
    propertiesTab->setObjectName(QString::fromUtf8("properties"));
    tabGroup->setTabText(tabGroup->indexOf(propertiesTab), QCoreApplication::translate("qobjectbrowser", "Properties", nullptr));

    QGridLayout* gridLayoutUnderPropertiesTab = new QGridLayout(propertiesTab);
    gridLayoutUnderPropertiesTab->setObjectName(QString::fromUtf8("gridLayoutUnderPropertiesTab"));
    gridLayoutUnderPropertiesTab->setSpacing(6);
    gridLayoutUnderPropertiesTab->setContentsMargins(9, 9, 9, 9);

    /*================ Table : Properties ================*/
    propertiesTable = new QTableWidget(propertiesTab);
    propertiesTable->setObjectName(QString::fromUtf8("propertiesTable"));
    /*================ Button : Update Properties =================*/
    updatepropertiesButton = new QPushButton(propertiesTab);
    updatepropertiesButton->setObjectName(QString::fromUtf8("updatepropertiesButton"));
    updatepropertiesButton->setText(QCoreApplication::translate("qobjectbrowser", "Update Properties", nullptr));
    /*================ Spacer : bottom spacer under propertiesTab ==================*/
    QSpacerItem* bottomSpacerUnderPropertiesTab = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);
    /* Add propertiesTable, updatepropertiesButton and bottomSpacerUnderPropertiesTab
     * into gridLayoutUnderPropertiesTab
     */
    gridLayoutUnderPropertiesTab->addWidget(propertiesTable,              0, 0, 1, 2);
    gridLayoutUnderPropertiesTab->addWidget(updatepropertiesButton,       1, 0, 1, 1);
    gridLayoutUnderPropertiesTab->addItem(bottomSpacerUnderPropertiesTab, 1, 1, 1, 1);
    tabGroup->addTab(propertiesTab, QString());

    /*================ Tab : Signals =========================*/
    QWidget* signalsTab = new QWidget();
    signalsTab->setObjectName(QString::fromUtf8("signalsTab"));
    tabGroup->setTabText(tabGroup->indexOf(signalsTab), QCoreApplication::translate("qobjectbrowser", "Signals", nullptr));

    /*================ Table : Signals ======================*/
    signalsTable = new QTableWidget(signalsTab);
    signalsTable->setObjectName(QString::fromUtf8("signalsTable"));

    QVBoxLayout* vboxUnderSignalsTab = new QVBoxLayout(signalsTab);
    vboxUnderSignalsTab->setObjectName(QString::fromUtf8("vboxUnderSignalsTab"));
    vboxUnderSignalsTab->setSpacing(6);
    vboxUnderSignalsTab->setContentsMargins(9, 9, 9, 9);

    vboxUnderSignalsTab->addWidget(signalsTable);
    tabGroup->addTab(signalsTab, QString());

    /*=============== Tab : Slots =====================*/
    QWidget* slotsTab = new QWidget();
    slotsTab->setObjectName(QString::fromUtf8("slotsTab"));
    /*=============== Table : Slots =====================*/
    slotsTable = new QTableWidget(slotsTab);
    slotsTable->setObjectName(QString::fromUtf8("slotsTable"));

    QVBoxLayout* vboxUnderSlotsTab = new QVBoxLayout(slotsTab);
    vboxUnderSlotsTab->setObjectName(QString::fromUtf8("vboxUnderSlotsTab"));
    vboxUnderSlotsTab->setSpacing(6);
    vboxUnderSlotsTab->setContentsMargins(9, 9, 9, 9);

    vboxUnderSlotsTab->addWidget(slotsTable);
    tabGroup->addTab(slotsTab, QString());
    tabGroup->setTabText(tabGroup->indexOf(slotsTab), QCoreApplication::translate("qobjectbrowser", "Slots", nullptr));

    /*=============== Tab : Methods ==================*/
    QWidget* methodsTab = new QWidget();
    methodsTab->setObjectName(QString::fromUtf8("methodsTab"));
    /*=============== Table : Methods ================*/
    methodsTable = new QTableWidget(methodsTab);
    methodsTable->setObjectName(QString::fromUtf8("methodsTable"));

    QVBoxLayout* vboxUnderMethodsTab = new QVBoxLayout(methodsTab);
    vboxUnderMethodsTab->setObjectName(QString::fromUtf8("vboxUnderMethodsTab"));
    vboxUnderMethodsTab->setSpacing(6);
    vboxUnderMethodsTab->setContentsMargins(9, 9, 9, 9);

    vboxUnderMethodsTab->addWidget(methodsTable);
    tabGroup->addTab(methodsTab, QString());
    tabGroup->setTabText(tabGroup->indexOf(methodsTab), QCoreApplication::translate("qobjectbrowser", "Methods", nullptr));

    tabGroup->setCurrentIndex(2);
#endif  /* REGION_BOTTOM_TABS_GROUP */

    QMetaObject::connectSlotsByName(qobjectbrowser);
}
