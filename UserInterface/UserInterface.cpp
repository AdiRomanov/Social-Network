//
// Created by roman on 5/14/2022.
//

#include "UserInterface.h"

UserInterface::UserInterface(UserService *userService, MessageService *messageService, FriendshipService *friendshipService,
                             EventService* eventService, NetworkService *networkService) {
    this->userService = userService;
    this->messageService = messageService;
    this->friendshipService = friendshipService;
    this->eventService = eventService;
    this->networkService = networkService;
}

void UserInterface::showMainMenu() {
    int option = 1;
    while(option) {
        try {
            cout << "----MainMenu----" << endl;
            cout << "1. Login." << endl;
            cout << "2. Register." << endl;
            cout << "3. Moderator Menu." << endl;
            cout << "0. Exit." << endl;


            cout << "Enter option: ";
            cin >> option;
            cout << endl;
            string password;
            if (option == 3) {
                cout << "Enter password:";
                cin >> password;
                if (password != "admin")
                    option = 0;
            }

            switch (option) {
                case 1: {uiLogin(); break;}
                case 2: {uiRegister(); break;}
                case 3: {showModeratorMenu(); break;}
                case 0: {break;}
                default: {
                    cout << "Invalid option! Try again!" << endl;
                }
            }
        }
        catch(MyException& e) {
            cout << "You threw an exception: " << e.getMessage() << endl;
        }
    }
}

void UserInterface::showModeratorMenu() {
    int option = 1;
    while(option)
    {
        cout << "----ModeratorMenu----" << endl;
        cout << "1. User Menu." << endl;
        cout << "2. Message Menu." << endl;
        cout << "3. Friendship Menu." << endl;
        cout << "4. Event Menu." << endl;
        cout << "0. Exit." << endl;

        try{
            cout << "Enter option: ";
            cin >> option;
            cout << endl;
            switch (option) {
                case 1: {showUsersMenu(); break;}
                case 2: {showMessageMenu(); break;}
                case 3: {showFriendshipMenu(); break;}
                case 4: {showEventMenu(); break;}
                case 0: {break;}
                default: {cout << "Invalid option! Try again!" << endl;}
            }
        }
        catch(MyException& e) {
            cout << "You threw an exception: " << e.getMessage() << endl;
        }
    }
}


void UserInterface::showUsersMenu() {
    int option = 1;
    while(option)
    {
        cout << "----AdministratorMenu----" << endl;
        cout << "1. Add user." << endl;
        cout << "2. Delete user." << endl;
        cout << "3. Find user." << endl;
        cout << "4. Update user." << endl;
        cout << "5. Show all users." << endl;
        cout << "6. Show number o users." << endl;
        cout << "0. Exit." << endl;

        try{
            cout << "Enter option: ";
            cin >> option;
            cout << endl;
            switch (option) {
                case 1: {uiAddUser(); break;}
                case 2: {uiDeleteUser(); break;}
                case 3: {uiFindUser(); break;}
                case 4: {uiUpdateUser(); break;}
                case 5: {uiShowAllUsers(); break;}
                case 6: {uiShowNumberOfUsers(); break;}
                case 0: {break;}
                default: {cout << "Invalid option! Try again!" << endl;}
            }
        }
        catch(MyException& e) {
            cout << "You threw an exception: " << e.getMessage() << endl;
        }
    }
}

void UserInterface::uiAddUser() {
    try {
        string firstName, lastName, email;
        int id, age;
        cout << "Enter id:";
        cin >> id;
        cout << "Enter first name:";
        cin >> firstName;
        cout << "Enter last name:";
        cin >> lastName;
        cout << "Enter email:";
        cin >> email;
        cout << "Enter age:";
        cin >> age;
        this->userService->addUser(id, firstName, lastName, email, age);
    }
    catch(MyException& e) {
        cout << "You threw an exception: " << e.getMessage() << endl;
    }
}

void UserInterface::uiShowAllUsers() {
    List<User> allUsers = this->userService->getAllUsers();
    for(int i=0; i<this->userService->numberOfUsers(); i++)
    cout << allUsers[i];
}

void UserInterface::uiFindUser() {
    try {
        string firstName, lastName, email;
        int id, age;
        cout << "Enter id:";
        cin >> id;
        cout << "Enter first name:";
        cin >> firstName;
        cout << "Enter last name:";
        cin >> lastName;
        cout << "Enter email:";
        cin >> email;
        cout << "Enter age:";
        cin >> age;
        bool check;
        check = this->userService->findUser(id, firstName, lastName, email, age);
        if (check) cout << "User found!" << endl;
        else cout << "This user doesnt exist!" << endl;
    }
    catch(MyException& e) {
        cout << "You threw an exception: " << e.getMessage() << endl;
    }
}

void UserInterface::uiDeleteUser() {
    try {
        string firstName, lastName, email;
        int id, age;
        cout << "Enter id:";
        cin >> id;
        cout << "Enter first name:";
        cin >> firstName;
        cout << "Enter last name:";
        cin >> lastName;
        cout << "Enter email:";
        cin >> email;
        cout << "Enter age:";
        cin >> age;
        this->userService->deleteUser(id, firstName, lastName, email, age);
    }
    catch(MyException& e) {
        cout << "You threw an exception: " << e.getMessage() << endl;
    }
}

void UserInterface::uiUpdateUser() {
    try {
        string firstName, lastName, email, newFirstName, newLastName, newEmail;
        int id, age, newId, newAge;
        cout << "Enter id:";
        cin >> id;
        cout << "Enter first name:";
        cin >> firstName;
        cout << "Enter last name:";
        cin >> lastName;
        cout << "Enter email:";
        cin >> email;
        cout << "Enter age:";
        cin >> age;
        cout << endl;

        cout << "Enter new id:";
        cin >> newId;
        cout << "Enter new first name:";
        cin >> newFirstName;
        cout << "Enter new last name:";
        cin >> newLastName;
        cout << "Enter new age:";
        cin >> newAge;

        this->userService->updateUser(id, firstName, lastName, email, age,
                                      newId, newFirstName, newLastName, newEmail, newAge);
    }
    catch(MyException& e) {
        cout << "You threw an exception: " << e.getMessage() << endl;
    }
}

void UserInterface::uiShowNumberOfUsers() {
    cout << this->userService->numberOfUsers() << " registered users! " << endl;
}

void UserInterface::showMessageMenu() {
    int option = 1;
    while(option)
    {
        try{
            cout << "----AdministratorMenu----" << endl;
            cout << "1. Add message." << endl;
            cout << "2. Find message." << endl;
            cout << "3. Update message." << endl;
            cout << "4. Show all messages." << endl;
            cout << "0. Exit." << endl;


            cout << "Enter option: ";
            cin >> option;
            cout << endl;
            switch (option) {
                case 1: {uiAddMessage(); break;}
                case 2: {uiFindMessage(); break;}
                case 3: {uiUpdateMessage(); break;}
                case 4: {uiShowAllMessages(); break;}
                case 0: {break;}
                default: {cout << "Invalid option! Try again!" << endl;}
            }
        }
        catch(MyException& e) {
            cout << "You threw an exception: " << e.getMessage() << endl;
        }
    }
}

void UserInterface::uiAddMessage() {
    try {
        int id, idSender, idReceiver;
        string text;
        cout << "Enter id:";
        cin >> id;
        cout << "Enter sender id:";
        cin >> idSender;
        cout << "Enter receiver id:";
        cin >> idReceiver;
        cout << "Enter text:";
        cin >> text;

        messageService->addMessage(id, idSender, idReceiver, text);
    }
    catch(MyException& e) {
        cout << "You threw an exception: " << e.getMessage() << endl;
    }
}

void UserInterface::uiFindMessage() {
    try {
        int id, idSender, idReceiver;
        string text;
        cout << "Enter id:";
        cin >> id;
        cout << "Enter sender id:";
        cin >> idSender;
        cout << "Enter receiver id:";
        cin >> idReceiver;
        cout << "Enter text:";
        cin >> text;

        bool check;
        check = messageService->findMessage(id, idSender, idReceiver, text);

        if (check) cout << "Message found!" << endl;
        else cout << "Message was not found!" << endl;
    }
    catch(MyException& e) {
        cout << "You threw an exception: " << e.getMessage() << endl;
    }
}

void UserInterface::uiUpdateMessage() {
    try {
        int id, idSender, idReceiver;
        int newId, newIdSender, newIdReceiver;
        string text, newText;
        cout << "Enter id:";
        cin >> id;
        cout << "Enter sender id:";
        cin >> idSender;
        cout << "Enter receiver id:";
        cin >> idReceiver;
        cout << "Enter text:";
        cin >> text;

        cout << endl;
        cout << "Enter new id:";
        cin >> newId;
        cout << "Enter new sender's id:";
        cin >> newIdSender;
        cout << "Enter new receiver's id:";
        cin >> newIdReceiver;
        cout << "Enter new text:";
        cin >> newText;

        messageService->updateMessage(id, idSender, idReceiver, text, newId, newIdSender, newIdReceiver, newText);
    }
    catch(MyException& e) {
        cout << "You threw an exception: " << e.getMessage() << endl;
    }
}

void UserInterface::uiShowAllMessages() {
    List<Message> allMessages;
    allMessages = messageService->getAll();
    for(int i=0; i<messageService->numberOfMessages(); i++)
        cout << allMessages[i];
    cout << endl;
}

void UserInterface::showFriendshipMenu() {
    int option = 1;
    while(option)
    {
        try{
            cout << "----AdministratorMenu----" << endl;
            cout << "1. Add friendship." << endl;
            cout << "2. Find friendship." << endl;
            cout << "3. Update friendship." << endl;
            cout << "4. Delete friendship." << endl;
            cout << "5. Number of friendships." << endl;
            cout << "6. Show all friendships." << endl;
            cout << "0. Exit." << endl;


            cout << "Enter option: ";
            cin >> option;
            cout << endl;
            switch (option) {
                case 1: {uiAddFriendship(); break;}
                case 2: {uiFindFriendship(); break;}
                case 3: {uiUpdateFriendship(); break;}
                case 4: {uiDeleteFriendship(); break;}
                case 5: {uiShowNumberOfFriendships(); break;}
                case 6: {uiShowAllFriendships(); break;}
                case 0: {break;}
                default: {cout << "Invalid option! Try again!" << endl;}
            }
        }
        catch(MyException& e) {
            cout << "You threw an exception: " << e.getMessage() << endl;
        }
    }
}

void UserInterface::uiAddFriendship() {
    try{
        int id, idUser1, idUser2;
        bool areFriends;
        cout << "Enter id:";
        cin >> id;
        cout << "Enter first user id:";
        cin >> idUser1;
        cout << "Enter second user id:";
        cin >> idUser2;
        cout << "Enter are friends?:";
        cin >> areFriends;
        friendshipService->addFriendship(id, idUser1, idUser2, areFriends);
    }
    catch(MyException& e) {
        cout << "You threw an exception: " << e.getMessage() << endl;
    }
}

void UserInterface::uiDeleteFriendship() {
    try{
        int id, idUser1, idUser2;
        bool areFriends;
        cout << "Enter id:";
        cin >> id;
        cout << "Enter first user id:";
        cin >> idUser1;
        cout << "Enter second user id:";
        cin >> idUser2;
        cout << "Enter are friends?:";
        cin >> areFriends;
        friendshipService->deleteFriendship(id, idUser1, idUser2, areFriends);
    }
    catch(MyException& e) {
        cout << "You threw an exception: " << e.getMessage() << endl;
    }
}

void UserInterface::uiFindFriendship() {
    try {
        int id, idUser1, idUser2;
        bool areFriends;
        cout << "Enter id:";
        cin >> id;
        cout << "Enter first user id:";
        cin >> idUser1;
        cout << "Enter second user id:";
        cin >> idUser2;
        cout << "Enter are friends?:";
        cin >> areFriends;

        bool check;
        check = friendshipService->findFriendship(id, idUser1, idUser2, areFriends);

        if (check) cout << "Friendship found!" << endl;
        else cout << "Friendship was not found!" << endl;
    }
    catch(MyException& e) {
        cout << "You threw an exception: " << e.getMessage() << endl;
    }
}

void UserInterface::uiUpdateFriendship() {
    try {
        int id, idUser1, idUser2;
        int newId, newIdUser1, newIdUser2;
        bool areFriends, newAreFriends;
        cout << "Enter id:";
        cin >> id;
        cout << "Enter first user id:";
        cin >> idUser1;
        cout << "Enter second user id:";
        cin >> idUser2;
        cout << "Enter are friends?:";
        cin >> areFriends;

        cout << "Enter new id:";
        cin >> newId;
        cout << "Enter first user new id:";
        cin >> newIdUser1;
        cout << "Enter second user new id:";
        cin >> newIdUser2;
        cout << "Enter are friends?:";
        cin >> newAreFriends;

        friendshipService->updateFriendship(id, idUser1, idUser2, areFriends,
                                            newId, newIdUser1, newIdUser2, newAreFriends);
    }
    catch(MyException& e) {
        cout << "You threw an exception: " << e.getMessage() << endl;
    }
}

void UserInterface::uiShowNumberOfFriendships() {
    cout << this->friendshipService->numberOfFriendships();
}

void UserInterface::uiShowAllFriendships() {
    vector<Friendship> allFriendships;
    allFriendships = this->friendshipService->getAll();
    for(auto friendship: allFriendships)
        cout << friendship;
    cout << endl;
}

void UserInterface::showEventMenu() {
    int option = 1;
    while(option)
    {
        try{
            cout << "----AdministratorMenu----" << endl;
            cout << "1. Add event." << endl;
            cout << "2. Find event." << endl;
            cout << "3. Update event." << endl;
            cout << "4. Delete event." << endl;
            cout << "5. Show all events." << endl;
            cout << "6. Show number of events." << endl;
            cout << "0. Exit." << endl;


            cout << "Enter option: ";
            cin >> option;
            cout << endl;
            switch (option) {
                case 1: {uiAddEvent(); break;}
                case 2: {uiFindEvent(); break;}
                case 3: {uiUpdateEvent(); break;}
                case 4: {uiDeleteEvent(); break;}
                case 5: {uiShowAllEvents(); break;}
                case 6: {uiShowNumberOfEvents(); break;}
                case 0: {break;}
                default: {cout << "Invalid option! Try again!" << endl;}
            }
        }
        catch(MyException& e) {
            cout << "You threw an exception: " << e.getMessage() << endl;
        }
    }
}

void UserInterface::uiAddEvent() {
    try {
        int id;
        string name, text;
        cout << "Enter id:";
        cin >> id;
        cout << "Enter name:";
        cin >> name;
        cout << "Enter text:";
        cin >> text;

        this->eventService->addEvent(id, name, text);
    }
    catch(MyException& e) {
        cout << "You threw an exception: " << e.getMessage() << endl;
    }
}

void UserInterface::uiFindEvent() {
    try {
        int id;
        string name, text;
        cout << "Enter id:";
        cin >> id;
        cout << "Enter name:";
        cin >> name;
        cout << "Enter text:";
        cin >> text;

        if (this->eventService->findEvent(id, name, text))
            cout << "Event found!" << endl;
        else cout << "Event not found!" << endl;
    }
    catch(MyException& e) {
        cout << "You threw an exception: " << e.getMessage() << endl;
    }
}

void UserInterface::uiUpdateEvent() {
    try {
        int id, newId;
        string name, text;
        string newName, newText;
        cout << "Enter id:";
        cin >> id;
        cout << "Enter name:";
        cin >> name;
        cout << "Enter text:";
        cin >> text;

        cout << endl;
        cout << "Enter new id:";
        cin >> newId;
        cout << "Enter new name:";
        cin >> newName;
        cout << "Enter new text:";
        cin >> newText;

        this->eventService->updateEvent(id, name, text, newId, newName, newText);
    }
    catch(MyException& e) {
        cout << "You threw an exception: " << e.getMessage() << endl;
    }
}

void UserInterface::uiDeleteEvent() {
    try {
        int id;
        string name, text;
        cout << "Enter id:";
        cin >> id;
        cout << "Enter name:";
        cin >> name;
        cout << "Enter text:";
        cin >> text;

        this->eventService->deleteEvent(id, name, text);
    }
    catch(MyException& e) {
        cout << "You threw an exception: " << e.getMessage() << endl;
    }
}

void UserInterface::uiShowAllEvents() {
    List<Event> allEvents;
    allEvents = this->eventService->getAllEvents();
    for(int i = 0; i < this->eventService->numberOfEvents(); i++)
        cout << allEvents[i] << endl;

}

void UserInterface::uiShowNumberOfEvents() {
    cout << this->eventService->numberOfEvents() << endl;
}

void UserInterface::uiLogin() {
    try{
        string email;
        cout << "----Login----" << endl;
        cout << "Enter your email:" << endl;
        cin >> email;

        bool check = this->networkService->checkEmail(email);
        if(!check)
        {
            cout << "You logged in successfully!" << endl;
            uiManageAccount(email);
        }
        else
        {
            throw(MyException("Invalid email!"));
        }
    }
    catch(MyException& e) {
        cout << "You threw an exception: " << e.getMessage() << endl;
    }
}

void UserInterface::uiRegister() {
    try{
        string firstName, lastName, email;
        int age;
        cout << "----Register----" << endl;
        cout << "Enter your first name:";
        cin >> firstName;
        cout << "Enter your last name:";
        cin >> lastName;
        cout << "Enter your email:";
        cin >> email;
        cout << "Enter age:";
        cin >> age;

        bool check = this->networkService->checkEmail(email);
        if(check)
        {
            int id = userService->numberOfUsers() + 1;
            this->userService->addUser(id, firstName, lastName, email, age);
            cout << "Account created successfully!" << endl;
        }
        else
        {
            throw(MyException("Email already taken!"));
        }

    }
    catch(MyException& e) {
        cout << "You threw an exception: " << e.getMessage() << endl;
    }
}

void UserInterface::uiManageAccount(string email) {
    try{
        string userEmail = email;
        cout << endl;
        cout << "----Newsletter----" << endl;
        this->networkService->showAllEvents();

        int option = 1;
        while(option)
        {
            cout << "1.Add friends." << endl;
            cout << "2.Find people." << endl;
            cout << "3.Search events." << endl;
            cout << "4.See feed." << endl;
            cout << "5.List of friends." << endl;
            cout << "6.Delete friend." << endl;
            cout << "7.Send a message." << endl;
            cout << "8.See messages." << endl;
            cout << "0.Log out." << endl;

            cout << "Enter option:" << endl;
            cin >> option;
            switch(option){
                case 1: {uiAddFriends(userEmail); break;}
                case 2: {uiSearchPeople(); break;}
                case 3: {uiSearchEvents(); break;}
                case 4: {this->networkService->showAllEvents(); break;}
                case 5: {uiShowFriendList(userEmail); break;}
                case 6: {uiDeleteFriend(userEmail); break;}
                case 7: {uiSendMessage(userEmail); break;}
                case 8: {uiSeeYourMessages(userEmail); break;}
                case 0: {cout << "Logged out successfully!" << endl; break;}
                default:{ cout << "Invalid option! Try again!" << endl;}
            }
        }
    }
    catch(MyException& e) {
        cout << "You threw an exception: " << e.getMessage() << endl;
    }

}

void UserInterface::uiAddFriends(string userEmail) {
    try{
        User user;
        user = this->networkService->getUserByEmail(userEmail);
        this->uiShowAllUsers();
        int id = 0, idUser2;
        cout << "Enter id:" << endl;
        cin >> idUser2;

        if(this->networkService->checkFormerFriends(user.getId(), idUser2))
        {
            this->networkService->reconciliation(user.getId(), idUser2);
            this->networkService->reconciliation(idUser2, user.getId());
        }
        else
        {
            id = this->friendshipService->numberOfFriendships() + 1;
            this->friendshipService->addFriendship(id, user.getId(), idUser2, true);
            id++;
            this->friendshipService->addFriendship(id, idUser2, user.getId(), true);
            cout << "Friend request accepted!" << endl;
        }
    }
    catch(MyException& e) {
        cout << "You threw an exception: " << e.getMessage() << endl;
    }
}

void UserInterface::uiSearchPeople() {
    try{
        string firstName, lastName;
        cout << "Enter first name:";
        cin >> firstName;
        cout << "Enter last name:";
        cin >> lastName;
        int index = 0;
        List<User> users = this->networkService->getPeopleByName(firstName, lastName, index);
        for(int i = 0; i < index; i++)
            cout << users[i];
    }
    catch(MyException& e) {
        cout << "You threw an exception: " << e.getMessage() << endl;
    }
}

void UserInterface::uiSearchEvents() {
    try{
        string eventName;
        cout << "Enter event name:";
        cin >> eventName;
        int index = 0;
        List<Event> events = this->networkService->getEventsByName(eventName, index);
        for(int i = 0; i < index; i++)
            cout << events[i];
    }
    catch(MyException& e) {
        cout << "You threw an exception: " << e.getMessage() << endl;
    }
}

void UserInterface::uiShowFriendList(string userEmail) {
    try{
        User user;
        user = this->networkService->getUserByEmail(userEmail);
        int idUser = user.getId();
        vector<Friendship> friendList = this->networkService->getFriendList(idUser);
        cout <<  "----FriendList----" << endl;
        for(auto frdList: friendList)
        {
            cout << this->networkService->getUserFirstNameById(frdList.getIdUser2()) << " ";
            cout << this->networkService->getUserLastNameById(frdList.getIdUser2()) << endl;
        }
        cout << endl;
    }
    catch(MyException& e) {
        cout << "You threw an exception: " << e.getMessage() << endl;
    }
}

void UserInterface::uiDeleteFriend(string userEmail) {
    try{
        User user;
        user = this->networkService->getUserByEmail(userEmail);
        int idUser = user.getId();
        vector<Friendship> friendList = this->networkService->getFriendList(idUser);
        cout <<  "----FriendList----" << endl;
        for(auto frdList: friendList)
        {
            cout << frdList.getIdUser2() << " ";
            cout << this->networkService->getUserFirstNameById(frdList.getIdUser2()) << " ";
            cout << this->networkService->getUserLastNameById(frdList.getIdUser2()) << endl;
        }
        int option;
        cout << endl;
        cout << "Enter option:";
        cin >> option;
        this->networkService->unFriend(idUser, option);
        this->networkService->unFriend(option, idUser);

    }
    catch(MyException& e) {
        cout << "You threw an exception: " << e.getMessage() << endl;
    }
}

void UserInterface::uiSendMessage(string userEmail) {
    try{
        int option, messageId;
        User user;
        string message;

        user = this->networkService->getUserByEmail(userEmail);
        this->uiShowAllUsers();

        cout << "Enter option:";
        cin >> option;
        messageId = this->messageService->numberOfMessages() + 1;

        cout << "Enter message:";
        getline(cin, message);
        getline(cin, message);

        this->messageService->addMessage(messageId, user.getId(), option, message);
    }
    catch(MyException& e) {
        cout << "You threw an exception: " << e.getMessage() << endl;
    }
}

void UserInterface::uiSeeYourMessages(string userEmail) {
    try{
        int option, messageId;
        User user;

        user = this->networkService->getUserByEmail(userEmail);
        this->uiShowAllUsers();

        cout << "Enter option:";
        cin >> option;

        List<Message> allMessages;
        int index = 0;
        allMessages = this->networkService->getMessagesBetweenUsers(user.getId(), option, index);
        for(int i = 0; i < index; i++)
        {
            cout << this->networkService->getUserFirstNameById(allMessages[i].getIdSender()) << " ";
            cout << this->networkService->getUserLastNameById(allMessages[i].getIdSender()) << ":";
            cout << allMessages[i].getText();
            cout << endl;
        }
        cout << endl;
    }
    catch(MyException& e) {
        cout << "You threw an exception: " << e.getMessage() << endl;
    }
}
