#ifndef QOB_SIGNAL_RECORD_H
#define QOB_SIGNAL_RECORD_H

    class QSignalMapper;

    class QOB_signal_record
    {
    public:
        QSignalMapper* m_sigmapper;
        long m_count;
    public:
        QOB_signal_record();
        virtual ~QOB_signal_record();
    };

#endif  /* QOB_SIGNAL_RECORD_H */
