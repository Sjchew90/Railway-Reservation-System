#include <iostream>
#include <string>
#include <vector>

// Structure to store information about a train
struct Train {
  int trainNumber;
  std::string trainName;
  std::vector<std::string> stations;
  std::vector<int> ticketPrices;
};

// Function to display menu and get user choice
int displayMenu() {
  std::cout << "Railway reservation system" << std::endl;
  std::cout << "1. Book ticket" << std::endl;
  std::cout << "2. View all trains" << std::endl;
  std::cout << "3. Exit" << std::endl;
  std::cout << "Enter your choice: ";

  int choice;
  std::cin >> choice;
  return choice;
}

// Function to book a ticket
void bookTicket(std::vector<Train>& trains) {
  std::cout << "Enter train number: ";
  int trainNumber;
  std::cin >> trainNumber;
}
  bool found = false;
  Train selectedTrain;

  // Search for the train with the given number
  for (Train train : trains) {
    if (train.trainNumber == trainNumber) {
      found = true;
      selectedTrain = train;
      break;
    }
  }

  if (found) {
    std::cout << "Train name: " << selectedTrain.trainName << std::endl;
    std::cout << "Stations: ";
    for (std::string station : selectedTrain.stations) {
      std::cout << station << " ";
    }
    std::cout << std::endl;

    std::cout << "Enter source station: ";
    std::string source;
    std::cin >> source;

    std::cout << "Enter destination station: ";
    std::string destination;
    std::cin >> destination;

    int sourceIndex = -1;
    int destinationIndex = -1;

    // Find the indices of the source and destination stations
    for (int i = 0; i < selectedTrain.stations.size(); i++) {
      if (selectedTrain.stations[i] == source) {
        sourceIndex = i;
      }
      if (selectedTrain.stations[i] == destination) {
        destinationIndex = i;
      }
    }

    if (sourceIndex == -1 || destinationIndex == -1) {
      std::cout << "Invalid source or destination" << std::endl;
      return;
    }

    if (sourceIndex > destinationIndex) {
      std::cout << "Source station must come before destination station" << std::endl;
      return;
    }

    int ticketPrice = 0;
    for (int i = sourceIndex; i <= destinationIndex; i++) {
      ticketPrice += selectedTrain.ticketPrices[i];
    }

    std::cout << "Ticket price: " << ticketPrice << std::endl;
    std::cout << "Ticket booked successfully" << std::endl;}
