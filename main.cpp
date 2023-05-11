#include "UserInterface/UserInterface.h"
#include "Repository/parseConfig.h"
#include "Service/UserService.h"
#include "Checking/MyException.h"
#include "Repository/RepositoryFile.h"
#include "Domain/User.h"
#include "Repository/BstRepositoryFile.h"
#include "Service/FriendshipService.h"
#include "Service/NetworkService.h"
#include "Checking/ValidatorUser.h"
#include "Checking/ValidatorEvent.h"
#include "Checking/ValidatorMessage.h"
#include "Checking/Tests.h"

int main(){

    try{
        runTests();

        /*Declararea si initializarea datelor*/
        RepositoryFile<User>* repoUser;
        UserValidator userValidator;

        RepositoryFile<Message>* repoMessage;
        MessageValidator messageValidator;

        RepositoryFile<Event>* repoEvent;
        EventValidator eventValidator;

        BstRepositoryFile<Friendship>* repoFriendship;


        repoUser = new RepositoryFileCSV<User>("..\\Data\\user.csv");
        UserService* userService = new UserService(repoUser, userValidator);

        repoMessage = new RepositoryFileCSV<Message>("..\\Data\\messages.csv");
        MessageService* messageService = new MessageService(repoMessage, messageValidator);

        repoFriendship = new BstRepositoryFile<Friendship>("..\\Data\\friendships.csv");
        FriendshipService* friendshipService = new FriendshipService(repoFriendship);

        repoEvent = new RepositoryFileCSV<Event>("..\\Data\\events.csv");
        EventService* eventService = new EventService(repoEvent, eventValidator);

        NetworkService* networkService = new NetworkService(repoUser, repoMessage, repoEvent, repoFriendship);

        UserInterface Ui(userService, messageService, friendshipService, eventService, networkService);
        Ui.showMainMenu();
    }
    catch(MyException &ex){
        cout << "Some prob: " << ex.getMessage() << endl;
    }

    return 0;
}
