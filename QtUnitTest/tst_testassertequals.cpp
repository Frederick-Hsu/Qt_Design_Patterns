#include <QtTest>

// add necessary includes here

class TestAssertEquals : public QObject
{
    Q_OBJECT

public:
    TestAssertEquals();
    ~TestAssertEquals();

private slots:
    void initTestCase();
    void cleanupTestCase();
    void test_case1();
    void test_case2();
    void test_case3();

};

TestAssertEquals::TestAssertEquals()
{

}

TestAssertEquals::~TestAssertEquals()
{

}

void TestAssertEquals::initTestCase()
{

}

void TestAssertEquals::cleanupTestCase()
{

}

void TestAssertEquals::test_case1()
{
    qDebug() << "Testing bools";
    bool booleanValue = true;
    QVERIFY(1);
    QVERIFY(true);
    QVERIFY(booleanValue);
    qDebug() << QString("We are in file: %1, Line: %2").arg(__FILE__).arg(__LINE__);
    QCOMPARE(booleanValue, true);

    /**********************************************************/

    qDebug() << "Testing QStrings";
    QString string1 = "apples";
    QString string2 = "oranges";
    QString string3 = "apples";
    QCOMPARE("apples", "apples");
    QCOMPARE(string1, QString("apples"));
    QCOMPARE(QString("oranges"), string2);
    QCOMPARE(string1, string3);
    QVERIFY(string2 != string3);
}

void TestAssertEquals::test_case2()
{
    qDebug() << "Testing QDates";
    QString datestr("2010-11-21");
    QDate dateobj = QDate::fromString(datestr, Qt::ISODate);
    QVERIFY(dateobj.isValid());
    QVariant variant(dateobj);
    QString message(QString("comparing datestr: %1, dateobj: %2 and variant: %3")
                    .arg(datestr)
                    .arg(dateobj.toString())
                    .arg(variant.toString()));
    qDebug() << message;
    QCOMPARE(variant, QVariant(dateobj));
    QCOMPARE(QVariant(dateobj), variant);
    QCOMPARE(variant.toString(), datestr);
    QCOMPARE(datestr, variant.toString());
    QEXPECT_FAIL("", "Keep going", Continue);
    QCOMPARE(datestr, dateobj.toString());
}
void TestAssertEquals::test_case3()
{
    qDebug() << "Testing ints and doubles";
    int i = 4;
    QCOMPARE(4, i);
    uint u(LONG_MAX + 1), v(u/2);;
    QCOMPARE(u, v*2);

    double d(2./3.), e(d/2);
    QVERIFY(d != e);
    QVERIFY(d == e*2);
    double f(1./3.);
    QEXPECT_FAIL("", "Keep going!", Continue);
    QVERIFY(f*3 == 2);

    qDebug() << "Testing pointers";
    void *nullpointer = 0;
    void *nonnullpointer = &d;
    QVERIFY(nullpointer != 0);
    qDebug() << "There is one more item left in the test.";
    QVERIFY(nonnullpointer != 0);
}

QTEST_APPLESS_MAIN(TestAssertEquals)

#include "tst_testassertequals.moc"
