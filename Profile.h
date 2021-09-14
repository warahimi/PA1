#pragma once
#include<iostream>


class Profile
{
public:
    Profile();
    Profile(std::string playerName, int playerPoints);
    void setPlayerName(const std::string playerName);
    std::string getPlayerName() const;
    void setPlayerPoinsts(const int playerPoints);
    int getPlayerPoints() const;
    void incrementPoints();
    void decrementPoints();

private:
    std::string playerName;
    int playerPoints;
};
