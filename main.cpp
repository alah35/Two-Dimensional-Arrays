#include <iostream>
#include "Tasks/Tasks.h"
int main() {
   int n = 0;
   while (n != -1) {
       std::cout << "For exit enter -1. Choose Task:";
       std::cin >> n;
       switch (n) {
           case 1:
               task1();
               break;
           case 2:
               task2();
               break;
           case 3:
               task3();
               break;
           case 4:
               task4();
               break;
           case 5:
               task5();
               break;
           case 6:
               task6();
               break;
           case 7:
               task7();
               break;
           case 8:
               task8();
               break;
           case 9:
               task9();
               break;
           case -1:
               break;
           default:
               std::cout << "Wrong task number. Try again";
               std::cin >> n;
               break;

       }
   }
}