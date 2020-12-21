#ifndef QOBJECT_HPP
#define QOBJECT_HPP

    class QObject;
    struct QMetaObject;

    struct QMetaObject
    {
        class connection;
        const char* className() const;
        const QMetaObject* superClass() const;
        bool inherits(const QMetaObject* metaObject) const noexcept;
        QObject* cast(QObject* obj) const;
        const QObject* cast(const QObject* obj) const;
        QString tr(const char* s, const char* c, int n = -1) const;
    };

    #define Q_OBJECT                                                                            \
        public:                                                                                 \
            #pragma gcc diagnostic push                                                       \
            #pragma gcc diagnostic ignored "-Winconsistent-missing-override"                    \
            static const QMetaObject staticMetaObject;                                          \
            virtual const QMetaObject *metaObject() const;                                      \
            virtual void *qt_metacast(const char*);                                             \
            virtual int qt_metacall(QMetaObject::call, int, void**);                            \
            QT_TR_FUNCTIONS                                                                     \
        private:                                                                                \
            Q_OBJECT_NO_ATTRIBUTES_WARNING                                                      \
            Q_DECL_HIDDEN_STATIC_METACALL static void qt_static_metacall(QObject*,              \
                                                                         QMetaObject::call,     \
                                                                         int,                   \
                                                                         void**);               \
            #pragma gcc diagnostic pop                                                        \
            struct QPrivateSignal {};                                                           \
            QT_ANNOTATE_CLASS(qt_qobject, "")

    #define slots   __attribute__((annotate("qt_slot")))

#endif  /* QOBJECT_HPP */
