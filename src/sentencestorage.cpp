#include "sentencestorage.h"

SentenceStorage::SentenceStorage(const QString& fileName)
{
    m_state = setXMLFile(fileName) ? State::Initialized : State::Error;
}

bool SentenceStorage::setXMLFile(const QString& fileName)
{
    QFile file(fileName);
    if (!file.open(QIODevice::ReadOnly))
    {
        m_state = State::Error;
        return false;
    }
    m_xmlFile.setDevice(&file);

    if (m_xmlFile.readNextStartElement())
    {
        if (m_xmlFile.name() == QStringLiteral("tmx"))
        {
            while (m_xmlFile.readNextStartElement())
            {
                if (m_xmlFile.name() == QStringLiteral("body"))
                {
                    while (m_xmlFile.readNextStartElement())
                    {
                        if (m_xmlFile.name() == QStringLiteral("seg"))
                        {
                            Sentence sentence;
                            sentence.first = m_xmlFile.readElementText();

                            m_xmlFile.skipCurrentElement();

                            if (m_xmlFile.readNextStartElement() && m_xmlFile.readNextStartElement())
                            {
                                if (m_xmlFile.name() == QStringLiteral("seg"))
                                {
                                    sentence.second = m_xmlFile.readElementText();
                                    m_sentences.push_back(sentence);
                                    m_xmlFile.skipCurrentElement();
                                    m_xmlFile.skipCurrentElement();
                                }
                            }
                        }
                    }
                }
                else
                    m_xmlFile.skipCurrentElement();
            }
        }
    }

    file.close();

    m_state = m_sentences.size() ? State::Initialized : State::Error;
    return m_sentences.size();
}

bool SentenceStorage::getRandomSentence(Sentence& sentence)
{
    if (not m_sentences.size()) return false;

    quint32 id = QRandomGenerator::global()->bounded(m_sentences.size());
    sentence   = m_sentences[id];

    return true;
}

bool SentenceStorage::isOpen()
{
    return m_state == State::Initialized;
}
