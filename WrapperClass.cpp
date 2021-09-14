#include "WrapperClass.h"

WrapperClass::WrapperClass()
{
    loadFiles();
}
void WrapperClass::loadFiles()
{
    
    commandsFile.open("commands.csv", std::ios::in); // Opens the command.csv in write mode
    if (commandsFile.is_open())
    {
        std::string commandName, commandDescription;
        while (!commandsFile.eof())
        {
            std::getline(commandsFile, commandName, ',');
            if (commandName == "")
                break;
            std::getline(commandsFile, commandDescription, '\n');
            list.insertAtBeginning(commandName, commandDescription);
        }
    }
    profilesFile.open("profiles.csv", std::ios::in);
    if (profilesFile.is_open())
    {
        
        std::string playerName, playerPoints;
        while (!profilesFile.eof())
        {
            std::getline(profilesFile, playerName, ',');
            if (playerName == "")
                break;
            std::getline(profilesFile, playerPoints, '\n');
            profiles[numberOfProfiles].setPlayerName(playerName);
            profiles[numberOfProfiles].setPlayerPoinsts(std::stoi(playerPoints)); //std::stoi : parse string to int
            numberOfProfiles++;
        }
    }
    commandsFile.close();
    profilesFile.close();
}

void WrapperClass::runGame()
{
    int option = 0;
    do
    {
        do // input validation loop
        {
            this->menu();
            cin >> option;
            cin.clear();
            if (option < 1 || option>6)
                cout << "Invalid Number. Please Select from List.\n";
        } while (option < 1 || option > 6); // validate the input; option must be [1 - 6]
        //system("cls"); // not necessarily a portable/safe way to clear the screen
        // have obtained the option from the user; need to determine next operation
        this->performUserSelection(option);

    } while (option != 6); // 6 = exit the program
}

void WrapperClass::menu()
{
    cout << "1.\tGame Rule" << endl;
    cout << "2.\tPlay Game" << endl;
    cout << "3.\tLoad Previous Game" << endl;
    cout << "4.\tAdd Command" << endl;
    cout << "5.\tRemove Command" << endl;
    cout << "6.\tExit." << endl;
}
void WrapperClass::performUserSelection(int option)
{
    switch (option)
    {
    case 1:
        gameRules();
        break;
    case 2:
        playGame();
        break;
    case 3:
        loadPreviousGame();
        break;
    case 4:
        addCommand();
        break;
    case 5:
        removeCommand();
        break;
    case 6:
        writeChangesToFiles();
        break;
    default:
        break;
    }
}

void WrapperClass::gameRules()
{
    std::fstream f;
    f.open("GameRules.txt", std::ios::in);
    if (f.is_open())
    {
        std::string line;
        while (std::getline(f, line))
        {
            std::cout << line << endl;
        }
        cout << endl;
        f.close();
    }

}

void WrapperClass::playGame()
{
    int matchNumber = 0;

    cout << "Please enter your name: ";
    cin.clear();
    cin.ignore(22, '\n');
    std::getline(std::cin, playerName);
    do
    {
        cout << "how many commands/questions to generate for matching: ";
        cin >> matchNumber;
        if (matchNumber < 5 || matchNumber>30)
            cout << "Please enter a match number between 5 - 30\n";
    } while (matchNumber<5 || matchNumber>30);
    int counter = 0;
  
    LinkedList<int, std::string> trackList; // list to keep track of commands displayed to the user
    while (counter < matchNumber)
    {
        generateRandomCommand(trackList);
        counter++;
    }
}

void WrapperClass::generateRandomCommand(LinkedList<int, std::string>& trackList)
{
    if (list.getHeadNode() != nullptr)
    {
        int choice = 0;
        Node<std::string, std::string>* temp = list.getHeadNode();
        Node<int, std::string>* tempTrack = trackList.getHeadNode();
        Question questions[3];
        int counter = 1;
        generateAgain:
        int randCommandNum = rand() % 30 + 1;

        //to check if the command has laready displayed to the user
        while (tempTrack != nullptr)
        {
            if (tempTrack->getData1() == randCommandNum)
            {
                goto generateAgain;
                break;
            }
            else
            {
                tempTrack = tempTrack->getNextNode();
            }
        } // a distinct randCommandNum is generated

        while (counter < randCommandNum ) // traversing to the list to get to the desired random command
        {
            temp = temp->getNextNode();
            counter++;
        }
        trackList.insertAtBeginning(randCommandNum, temp->getData1());
        questions[0].setData(temp);

        //Generating two other commands to display to the user
        for (int i = 0; i < 2; i++)
        {
            counter = 1;
            temp = nullptr;
            temp = list.getHeadNode();
        x:
            int rand2 = rand() % 30 + 1;
            if (rand2 == randCommandNum)
                goto x;
            while (counter < rand2)
            {
                temp = temp->getNextNode();
                counter++;
            }
            questions[i + 1].setData(temp);
        }

        cout << questions[0].getCommand()->getData1()<<endl;
        cout << "------------------------------\n";

        //generating random order for questions to be displayed 
        for (int i = 0; i < 3; i++)
        {
            y:
            int r = rand() % 3 + 1;
            for (int j = 0; j < i ; j++)
            {
                if (questions[j].getQNumber() == r)
                    goto y;
            }
            questions[i].setQNumber(r);
        }

        //displaying the rindom answers 
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (questions[j].getQNumber() == i + 1)
                {
                    cout << i+1<<". " << questions[j].getCommand()->getData2()<<endl;
                }
            }
        }
        do
        {
            cout << "\nEnter Your Answer: ";
            cin >> choice;
            if (choice < 1 || choice>3)
            {
                cout << "Invalid Number Please Enter 1-3\n";
            }
        } while (choice < 1 || choice>3);

        //checking if the player already exist in prifiles.csv file 
        int i;
        bool profileFound = false;
        for (i = 0; i < numberOfProfiles; i++)
        {
            if (playerName == profiles[i].getPlayerName())
            {
                //player already exist 
                profileFound = true;
                break;
            }
        }
        if (!profileFound)
        {
            profiles[i].setPlayerName(playerName);
            profiles[i].setPlayerPoinsts(0);
            numberOfProfiles++;
        }
        


        if (choice == questions[0].getQNumber())
        {
            cout << "Correct. "<<questions[0].getCommand()->getData1()<<" - "<< questions[0].getCommand()->getData2()<<endl;
            profiles[i].incrementPoints();
            cout << "You have been awarded 1 point. Your point total is: "<<profiles[i].getPlayerPoints()<<endl;
        }
        else
        {
            cout << "Incorrect! " << questions[0].getCommand()->getData1() << " - " << questions[0].getCommand()->getData2()<<endl;
            profiles[i].decrementPoints();
            cout << "You have lost 1 point. Your point total is: "<<profiles[i].getPlayerPoints()<<endl;
        }

        cout << endl;
    }
    else
    {
        cout << "List is empty. Commands are not loaded to the LinkedList\n";
    }
    
}

void WrapperClass::loadPreviousGame()
{
    //Flushing the input stream
    cin.clear();
    cin.ignore(22, '\n');

    string pName;
    bool profileFound = false;
    cout << "Enter The Profile Name: ";
    std::getline(std::cin, pName);
    for (int i = 0; i < numberOfProfiles; i++)
    {
        if (profiles[i].getPlayerName() == pName)
        {
            cout << "Profile Found: \n";
            cout << "Profile Name: " << profiles[i].getPlayerName() << endl;
            cout << "Profile Points: " << profiles[i].getPlayerPoints() << endl;
            profileFound = true;
            break;
        }
    }
    if (!profileFound)
    {
        cout << "Profile Not Found.\nPlease Play The Game to Register You Profile.\n";
    }
    cout << endl;
}
void WrapperClass::addCommand()
{
    cin.clear();
    cin.ignore(22, '\n');

    string cName, cDescription;
    cout << "Pleae enter the command name to add to the current list of commands: ";
    std::getline(std::cin, cName);
    Node<string, string>* temp = list.getHeadNode();
    bool commandFound = false;
    while (temp != nullptr)
    {
        if (temp->getData1() == cName)
        {
            commandFound = true;
            cout << "The command you enter already exist in the current commands list\n\n";
            cout << temp->getData1() << ", " << temp->getData2()<<endl<<endl;
            string choice;
            do
            {
                cout << "Do you want to edit the existing command? (y/n)";
                cin >> choice;
                cin.clear();
                cin.ignore(22, '\n');
                
            } while (choice != "y" && choice != "n" && choice != "Y" && choice != "N");
            if (choice == "y" || choice == "Y")
            {
                s:
                cout << "Pleas enter the new description for " << temp->getData1()<<endl;
                cout << "The description must be inside \" \" and no comma (,) must be used in between" << endl<<endl;
                std::getline(std::cin, cDescription);
                if (cDescription.front() != '"' || cDescription.back() != '"')
                {
                    cout << "The description must be inside\" \"\n";
                    goto s;
                }
                if (cDescription.find(',') != std::string::npos)
                {
                    cout << "The description cannot contain comma (,).\n";
                    goto ss;
                }
                cDescription = " " + cDescription;
                temp->setData(temp->getData1(), cDescription);
                cout << "\nCommand Description Updated.\n\n";
                break;
            }
            else
            {
                cout << "\nCommand Description Not Updated.\n\n";
                break;
            }

        }
        temp = temp->getNextNode();
    }
    if (!commandFound)
    {
        ss:
        cout << "Pleas enter the description " << endl;
        cout << "The description must be inside \" \" and no comma (,) must be used in between" << endl << endl;
        std::getline(std::cin, cDescription);
        if (cDescription.front() != '"' || cDescription.back() != '"')
        {
            cout << "The description must be inside\" \"\n";
            goto ss;
        }
        if (cDescription.find(',') != std::string::npos)
        {
            cout << "The description cannot contain comma (,).\n";
            goto ss;
        }
        cDescription = " " + cDescription;
        list.insertAtBeginning(cName, cDescription);
        cout << "Description added to the list.\n";
    }
    
}

void WrapperClass::removeCommand()
{
    string command;
    cout << "Enter the command to delete: ";
    cin.clear();
    cin.ignore(22, '\n');
    std::getline(std::cin, command);
    list.deleteNode(command);

}

void WrapperClass::writeChangesToFiles()
{
    commandsFile.open("commands.csv", std::ios::out);
    profilesFile.open("profiles.csv", std::ios::out);
    if (commandsFile.is_open())
    {
        Node<string, string>* temp = list.getHeadNode();
        while (temp!= nullptr)
        {
            commandsFile << temp->getData1() << "," << temp->getData2() << endl;
            temp = temp->getNextNode();
        }
    }
    if (profilesFile.is_open())
    {
        for (int i = 0; i < numberOfProfiles; i++)
        {
            profilesFile << profiles[i].getPlayerName() << "," << profiles[i].getPlayerPoints() << endl;
        }
    }
    commandsFile.close();
    profilesFile.close();
}