//
// Created by roman on 5/21/2022.
//

#include "Tests.h"
#include "../UserInterface/UserInterface.h"
#include <cassert>

void runTests(){
    testRepository();
    testService();
}

void testRepository(){
    RepositoryFile<User>* repoUser;
    UserValidator userValidator;

    RepositoryFile<Message>* repoMessage;
    MessageValidator messageValidator;

    RepositoryFile<Event>* repoEvent;
    EventValidator eventValidator;

    BstRepositoryFile<Friendship>* repoFriendship;


    repoUser = new RepositoryFileCSV<User>("..\\Checking\\tests.csv");
    UserService* userService = new UserService(repoUser, userValidator);

    repoMessage = new RepositoryFileCSV<Message>("..\\Checking\\tests.csv");
    MessageService* messageService = new MessageService(repoMessage, messageValidator);

    repoFriendship = new BstRepositoryFile<Friendship>("..\\Checking\\testBst.csv");
    FriendshipService* friendshipService = new FriendshipService(repoFriendship);

    repoEvent = new RepositoryFileCSV<Event>("..\\Checking\\tests.csv");
    EventService* eventService = new EventService(repoEvent, eventValidator);

    ofstream ofs;
    ofs.open("..\\Checking\\tests.csv", std::ofstream::out | std::ofstream::trunc);
    ofs.close();

    userService->addUser(1, "Andrei", "Alex", "email", 20);
    assert(userService->findUser(1, "Andrei", "Alex", "email", 20) == true);
    userService->updateUser(1, "Andrei", "Alex", "email", 20, 1, "Andrei", "Alex", "email", 21);
    assert(userService->findUser(1, "Andrei", "Alex", "email", 21) == true);
    assert(userService->numberOfUsers() == 1);
    List<User> users = userService->getAllUsers();
    assert(users[0].getId() == 1);
    assert(users[0].getFirstName() == "Andrei");
    assert(users[0].getLastName() == "Alex");
    assert(users[0].getEmail() == "email");
    assert(users[0].getAge() == 21);
    userService->deleteUser(1, "Andrei", "Alex", "email", 21);
    assert(userService->numberOfUsers() == 0);

    ofs.open("..\\Checking\\tests.csv", std::ofstream::out | std::ofstream::trunc);
    ofs.close();

    messageService->addMessage(1,1,2,"ceva");
    assert(messageService->findMessage(1,1,2,"ceva") == true);
    messageService->updateMessage(1,1,2,"ceva",1,1,2,"altceva");
    assert(messageService->findMessage(1,1,2,"altceva"));
    assert(messageService->numberOfMessages() == 1);
    List<Message> messages = messageService->getAll();
    assert(messages[0].getId() == 1);
    assert(messages[0].getIdSender() == 1);
    assert(messages[0].getIdReceiver() == 2);
    assert(messages[0].getText() == "altceva");
    messageService->deleteMessage(1,1,2,"altceva");
    assert(messageService->numberOfMessages() == 0);

    ofs.open("..\\Checking\\tests.csv", std::ofstream::out | std::ofstream::trunc);
    ofs.close();

    eventService->addEvent(1, "Stire", "text");
    assert(eventService->findEvent(1, "Stire", "text") == true);
    eventService->updateEvent(1, "Stire", "text", 1, "Stire", "alttext");
    assert(eventService->findEvent(1, "Stire", "alttext") == true);
    assert(eventService->numberOfEvents() == 1);
    List<Event> events = eventService->getAllEvents();
    assert(events[0].getId() == 1);
    assert(events[0].getName() == "Stire");
    assert(events[0].getText() == "alttext");
    eventService->deleteEvent(1, "Stire", "alttext");
    assert(eventService->numberOfEvents() == 0);

    ofs.open("..\\Checking\\tests.csv", std::ofstream::out | std::ofstream::trunc);
    ofs.close();

    assert(friendshipService->numberOfFriendships() == 2);
    friendshipService->addFriendship(1, 2, 3, true);
    assert(friendshipService->findFriendship(1, 2, 3, true) == true);
    friendshipService->updateFriendship(1, 2, 3, true, 1, 2, 3, false);
    assert(friendshipService->findFriendship(1, 2, 3, false));
    vector<Friendship> friendships = friendshipService->getAll();
    assert(friendships[0].getId() == 1);
    assert(friendships[0].getIdUser1() == 2);
    assert(friendships[0].getIdUser2() == 3);
    assert(friendships[0].getAreFriends() == false);
    friendshipService->deleteFriendship(1, 2, 3, false);
    assert(friendshipService->numberOfFriendships() == 2);

}

void testService(){
    RepositoryFile<User>* repoUser;
    UserValidator userValidator;

    RepositoryFile<Message>* repoMessage;
    MessageValidator messageValidator;

    RepositoryFile<Event>* repoEvent;
    EventValidator eventValidator;

    BstRepositoryFile<Friendship>* repoFriendship;


    repoUser = new RepositoryFileCSV<User>("..\\Checking\\tests.csv");
    UserService* userService = new UserService(repoUser, userValidator);

    repoMessage = new RepositoryFileCSV<Message>("..\\Checking\\tests.csv");
    MessageService* messageService = new MessageService(repoMessage, messageValidator);

    repoFriendship = new BstRepositoryFile<Friendship>("..\\Checking\\testBst.csv");
    FriendshipService* friendshipService = new FriendshipService(repoFriendship);

    repoEvent = new RepositoryFileCSV<Event>("..\\Checking\\tests.csv");
    EventService* eventService = new EventService(repoEvent, eventValidator);

    NetworkService* networkService = new NetworkService(repoUser, repoMessage, repoEvent, repoFriendship);

    ofstream ofs;
    ofs.open("..\\Checking\\tests.csv", std::ofstream::out | std::ofstream::trunc);
    ofs.close();

    userService->addUser(1,"Andrei", "Alex", "email", 20);
    assert(networkService->checkEmail("email") == false);
    assert(networkService->checkEmail("altemail") == true);

    User user = networkService->getUserByEmail("email");
    assert(user.getId() == 1);
    assert(user.getFirstName() == "Andrei");
    assert(user.getLastName() == "Alex");
    assert(user.getEmail() == "email");
    assert(user.getAge() == 20);

    int index = 0;
    List<User> users = networkService->getPeopleByName("Andrei", "Alex", index);
    assert(users[0].getId() == 1);
    assert(user.getFirstName() == "Andrei");
    assert(user.getLastName() == "Alex");
    assert(user.getEmail() == "email");
    assert(user.getAge() == 20);

    vector<Friendship> friendList = networkService->getFriendList(1);
    assert(friendList.empty());

    assert(networkService->getUserFirstNameById(1) == "Andrei");
    assert(networkService->getUserLastNameById(1) == "Alex");

    vector<Friendship> allFriendships;
    networkService->unFriend(4, 5);
    allFriendships = friendshipService->getAll();
    assert(allFriendships[0].getAreFriends() == false);
    assert(networkService->checkFormerFriends(4, 5) == true);
    networkService->reconciliation(4, 5);
    allFriendships = friendshipService->getAll();
    assert(allFriendships[0].getAreFriends() == true);

    int index2 = 0;
    List<Message> messages = networkService->getMessagesBetweenUsers(1, 2, index2);
    assert(index2 == 0);

    ofs.open("..\\Checking\\tests.csv", std::ofstream::out | std::ofstream::trunc);
    ofs.close();
}