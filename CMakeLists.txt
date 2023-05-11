cmake_minimum_required(VERSION 3.22)
project(proiectSDA)

set(CMAKE_CXX_STANDARD 14)

add_executable(proiectSDA main.cpp Domain/User.cpp Domain/User.h Domain/List.h Checking/MyException.h Repository/RepositoryFile.h Repository/RepositoryFileCSV.h Repository/RepositoryFileTXT.h Service/UserService.cpp Service/UserService.h UserInterface/UserInterface.cpp UserInterface/UserInterface.h Repository/parseConfig.h Domain/BST.h Repository/BstRepositoryFile.h Domain/Message.cpp Domain/Message.h Service/MessageService.cpp Service/MessageService.h Domain/Friendship.cpp Domain/Friendship.h Service/FriendshipService.cpp Service/FriendshipService.h Domain/Event.cpp Domain/Event.h Service/EventService.cpp Service/EventService.h Checking/ValidatorUser.h Checking/ValidatorMessage.h Checking/ValidatorEvent.h Checking/ValidatorFriendship.h Checking/Tests.cpp Checking/Tests.h Service/NetworkService.cpp Service/NetworkService.h)
