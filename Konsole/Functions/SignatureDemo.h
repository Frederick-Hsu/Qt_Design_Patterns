#ifndef SIGNATURE_DEMO_H
#define SIGNATURE_DEMO_H

    // #define FUNCTION_OVERLOAD

    class SignatureDemo
    {
    public:
        SignatureDemo(int val);
        void demo(int n);
        void demo(int n) const;
#if defined (FUNCTION_OVERLOAD)
        void demo(const int& n);
#endif
        void demo(short s);
        void demo(float f);
        void demo(float f) const;
        void demo(double d);
    private:
        int m_Val;
    };

    void testSignatureDemoFunctionOveload(void);

#endif  /* SIGNATURE_DEMO_H */
