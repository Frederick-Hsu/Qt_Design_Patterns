#include "suffolk_university_organization.h";
#include <QTextStream>
#include <QDebug>

static QTextStream cout(stdout);

double OrgUnit::getSalary()
{
    QList<OrgUnit*> childLst = findChildren<OrgUnit*>();
    double salaryTotal(m_Salary);
    if (!childLst.isEmpty())
    {
        foreach (OrgUnit* ouptr, childLst)
        {
            salaryTotal += ouptr->getSalary();
        }
    }
    return salaryTotal;
}

Person::Person(QString name, QObject* parent) : QObject(parent)
{
    setObjectName(name);
    cout << QString("Constructing Person : %1").arg(name) << endl;
}

Person::~Person()
{
    cout << QString("Destroying Person : %1").arg(objectName()) << endl;
}

void growBunch()
{
    qDebug() << "First we create a bunch of objects." << endl;
    QObject bunch;
    bunch.setObjectName("A Stack object");
    /* other objects are created on the heap */
    Person* mike = new Person("Mike", &bunch);
    Person* carol = new Person("Carol", &bunch);
    new Person("Greg", mike);
    new Person("Peter", mike);
    new Person("Bobby", mike);
    new Person("Marcia", carol);
    new Person("Jan", carol);
    new Person("Cindy", carol);
    new Person("Alice");

    qDebug() << "\nDisplay the list using QObject::dumpObjectTree()" << endl;
    bunch.dumpObjectTree();
    cout << "\nReady to return from growBunch() - Destroy all local stack objects." << endl;
}

void showTree(QObject* theparent)
{

}
