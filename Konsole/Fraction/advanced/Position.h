#ifndef POSITION_H
#define POSITION_H

    #include <string>

    class Position
    {
    public:
        Position(std::string name, std::string description);
        Position(const Position& pos);
        Position& operator=(const Position& pos);
        std::string toString();
    private:
        std::string m_Name;
        std::string m_Description;
    };

#endif  /* POSITION_H */
