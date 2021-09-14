#include "Profile.h"

Profile::Profile()
{

}
Profile::Profile(std::string playerName, int playerPoints)
{
    this->playerName = playerName;
    this->playerPoints = playerPoints;
}
void Profile::setPlayerName(const std::string playerName)
{
    this->playerName = playerName;
}
std::string Profile::getPlayerName() const
{
    return this->playerName;
}
void Profile :: setPlayerPoinsts(const int playerPoints)
{
    this->playerPoints = playerPoints;
}
int Profile::getPlayerPoints() const
{
    return this->playerPoints;
}
void Profile::incrementPoints()
{
    this->playerPoints++;
}
void Profile::decrementPoints()
{
    this->playerPoints--;
}