#ifndef HONDUROTA
#define HONDUROTA

    class Hondurota
    {
    public:
        Hondurota(double fuel, double odom, double capacity, double mpg);
    private:
        double m_Fuel;
        double m_Odometer;
        double m_TankCapacity;
        double m_MPG;
        double m_Speed;
    public:
        double addFeul(double gal);
        double getSpeed();
        double getMPG();
        double drive(double speed, int minutes);
        double getFeul();
        double getOdometer();
    };

#endif  /* HONDUROTA */
