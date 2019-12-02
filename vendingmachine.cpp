#include <iostream>
#include <string>
#include <stdio.h>

using namespace std;

//Works like a vending machine

//Keeps track of the money inside the machine
class cashRegister{
  private: 
    int cashOnHand;
  public:
  //initializes the money
    cashRegister(){
      cashOnHand = 500;
    }
    //allows user to set cash value
    cashRegister(int x){
      cashOnHand = x;
    }
    //returns the balance
    int getCurrentBalance(){
      return cashOnHand;
    }
    //accepts a payment and increases the money
    void acceptAmount(int money){
      cashOnHand += money;
    }
};

class dispenserType{
  private: 
    int numberOfItems, cost;
  public:
    dispenserType(){
      numberOfItems = 50;
      cost = 50;
    }
    dispenserType(int n, int c){
      numberOfItems = n;
      cost = c;
    }
    int getNoOfItems(){
      return numberOfItems;
    }
    int getCost(){
      return cost;
    }
    void makeSale(){
      numberOfItems--;
    }
};

void showSelection(){
  cout << "Options are candy, chips, gum, or cookies" << endl;
  cout << "Press 1 for candy\nPress 2 for chips\nPress 3 for gum\nPress 4 for cookies\nOr 5 to exit" << endl;
  
}

void sellProduct(dispenserType& C, cashRegister& M){
  int payment,payment2;
  if(C.getNoOfItems() > 0){
    //ask customer for the money
    cout << "The cost is " << C.getCost() << " cents\nPlease insert: " << endl;
    cin >> payment;
    if(payment < C.getCost()){
      cout << "That is not enough. Please insert " << C.getCost() - payment << " more cents: ";
      cin >> payment2;
      payment += payment2;
    }
    if(payment == C.getCost()){
      cout << "Success. Please wait..\n";
      C.makeSale();
      M.acceptAmount(payment);

      cout << "Thank you for your purchase.\n";
      cout << "Pick up your item at the bottom.\n";
    }else if (payment > C.getCost()){
      cout << "Success. Please wait..\n";
      C.makeSale();
      cout << "Your change is " << payment - C.getCost() << " cents." << endl;
      M.acceptAmount(payment - C.getCost());

      cout << "Thank you for your purchase.\n";
      cout << "Pick up your item and change at the bottom.\n";
    }else{
      cout << "The amount is not enough. Collect what you entered and try again." << endl;
    }
    
    

  }else{
    cout << "Sorry this item is sold out" << endl;
  }

}


int main(){
  //Create the amount of items inside the vending machine and how much each of them cost
  //0 candybars, 50 chips 40 cents each, 40 gum 30 cents each, 55 cookies 45 cents each
  dispenserType candy(1, 35), chips(50, 40), gum(40, 30), cookies(55, 45);
  //Initiallizes money in register to be 500 cents ($5)
  cashRegister moneyInRegister;

  //To keep track of the users choice
  int choice;

  //Produces the list of options to select from the vending machine
  showSelection();

  cin >> choice;

  //Use choice 5 to exit the machine
  while (choice != 5){
    switch(choice){
      case 1:
        //picked candy
        sellProduct(candy, moneyInRegister);
        break;
      case 2:
        //picked chips
        sellProduct(chips, moneyInRegister);
        break;
      case 3:
        //picked gum
        sellProduct(gum, moneyInRegister);

        break;
      case 4: 
        //picked cookies
        sellProduct(cookies, moneyInRegister);

        break;
      default:
        cout << "Invalid Selection" << endl;
    }
    showSelection();
    cin >> choice;
  }

  return 0;
}

