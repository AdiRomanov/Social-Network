//
// Created by roman on 5/14/2022.
//

#ifndef PROIECTSDA_USERINTERFACE_H
#define PROIECTSDA_USERINTERFACE_H
#include "../Service/UserService.h"
#include "../Service/MessageService.h"
#include "../Service/FriendshipService.h"
#include "../Service/EventService.h"
#include "../Service/NetworkService.h"

class UserInterface {
private:
    UserService* userService;
    MessageService* messageService;
    FriendshipService* friendshipService;
    EventService* eventService;
    NetworkService* networkService;
    void uiAddUser();
    void uiFindUser();
    void uiDeleteUser();
    void uiUpdateUser();
    void uiShowAllUsers();
    void uiShowNumberOfUsers();
    void showUsersMenu();
    void showMessageMenu();
    void uiAddMessage();
    void uiFindMessage();
    void uiUpdateMessage();
    void uiShowAllMessages();
    void showModeratorMenu();
    void showFriendshipMenu();
    void uiAddFriendship();
    void uiFindFriendship();
    void uiDeleteFriendship();
    void uiUpdateFriendship();
    void uiShowNumberOfFriendships();
    void uiShowAllFriendships();
    void showEventMenu();
    void uiAddEvent();
    void uiFindEvent();
    void uiDeleteEvent();
    void uiUpdateEvent();
    void uiShowAllEvents();
    void uiShowNumberOfEvents();
    void uiLogin();
    void uiRegister();
    void uiManageAccount(string email);
    void uiAddFriends(string userEmail);
    void uiSearchPeople();
    void uiSearchEvents();
    void uiShowFriendList(string Email);
    void uiDeleteFriend(string Email);
    void uiSendMessage(string Email);
    void uiSeeYourMessages(string Email);
public:
    UserInterface() = default;
    explicit UserInterface(UserService* userService, MessageService* messageService, FriendshipService* friendshipService,
                           EventService* eventService, NetworkService* networkService);
    ~UserInterface() = default;
    void showMainMenu();
};


#endif //PROIECTSDA_USERINTERFACE_H
