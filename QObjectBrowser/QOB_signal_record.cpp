#include "QOB_signal_record.h"
#include <QSignalMapper>

QOB_signal_record::QOB_signal_record()
{
    m_sigmapper = nullptr;
    m_count = 0;
}

QOB_signal_record::~QOB_signal_record()
{
    if (m_sigmapper)
    {
        delete m_sigmapper;
    }
    m_sigmapper = nullptr;
}
