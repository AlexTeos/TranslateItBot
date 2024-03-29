#include "tst_languagestorage.h"

void TestLanguageStorage::initTestCase()
{
    QVERIFY(m_languageStorage.state() == State::Initialized);
}

void TestLanguageStorage::cleanupTestCase() {}

void TestLanguageStorage::testLanguages()
{
    QVERIFY(m_languageStorage.languages().size());
}

void TestLanguageStorage::testSentenceStorage()
{
    QVector<QPair<QString, QString>> languages = m_languageStorage.languages();

    for (const auto& language : languages)
    {
        QVERIFY(m_languageStorage.sentenceStorage(language.first, language.second));
    }
}
