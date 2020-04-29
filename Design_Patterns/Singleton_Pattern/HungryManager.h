#ifndef HUNGRY_MANAGER_H
#define HUNGRY_MANAGER_H

    #include "CHungrySingleton.h"

    class HungryManager;

    class HungryManager : public CHungrySingleton<HungryManager>
    {
        friend class CHungrySingleton<HungryManager>;
    public:
        int Print(int basenum);
    protected:
        HungryManager();
        ~HungryManager();
    private:
        int m_count;
    };

#endif  /* HUNGRY_MANAGER_H */
