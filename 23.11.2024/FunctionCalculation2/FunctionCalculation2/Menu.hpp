#include "Function.hpp"
#include "Action.hpp"
#include <iostream>

using namespace std;

class Menu 
{
private:
    Function** object;
    Action** action;
    int objCount;
    int actCount;
public:
   Menu(Function* object_arr[], Action* action_arr[], int objCount_, int actCount_)
      : object(object_arr), action(action_arr), objCount(objCount_), actCount(actCount_) 
   {
       object = new Function*[objCount + 1];

       for (int i = 0; i < objCount; ++i)
           object[i] = object_arr[i];

       object[objCount] = nullptr;

       action = new Action* [actCount + 1];

       for (int i = 0; i < actCount; ++i)
           action[i] = action_arr[i];

       action[actCount] = nullptr;
   }

   Function* SelectObject() const 
   {
      cout << "Select function:" << endl;
      int i;
      for (i = 0; i < objCount; ++i) {
         cout << i + 1 << ". " << object[i]->GetName() << endl;
      }
      cout << i + 1 << ". Exit." << endl;
      int choice = -1;
      while (choice <= 0 || choice > i + 1)
          cin >> choice;

      return object[choice - 1];
   }

   Action* SelectAction(Function* object_) const
   {
      cout << "Select one of the following Actions for function " << object_->GetName() << ":" << endl;
      int i;
      for (i = 0; i < actCount; ++i) 
      {
         cout << i + 1 << ". " << action[i]->GetName() << endl;
      }
      cout << i + 1<< ". Exit." << endl;
      int choice = -1;
      while (choice <= 0 || choice > i + 1)
          cin >> choice;

      return action[choice - 1];
   }
};