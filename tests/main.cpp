#include "tst_languagestorage.h"
#include "tst_sentencestorage.h"
#include "tst_usercache.h"
#include "tst_userstorage.h"
#include "tst_userstoragedb.h"

int main(int argc, char* argv[])
{
    QCoreApplication a(argc, argv);

    TESTLIB_SELFCOVERAGE_START(TestObject)
    TestSentenceStorage tst_sentenceStorage;
    TestLanguageStorage tst_languageStorage;
    TestUserStorageDB   tst_userstoragedb;
    TestUserCache       tst_usercache;
    TestUserStorage     tst_userstorage;
    QTEST_SET_MAIN_SOURCE_PATH
    return QTest::qExec(&tst_usercache, argc, argv) or QTest::qExec(&tst_userstoragedb, argc, argv) or
           QTest::qExec(&tst_userstorage, argc, argv) or QTest::qExec(&tst_sentenceStorage, argc, argv) or
           QTest::qExec(&tst_languageStorage, argc, argv);
}
