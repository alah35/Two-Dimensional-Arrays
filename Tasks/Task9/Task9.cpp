// sea battle

char A[10][10], B[10][10]; // this is way easier access to fields

void create_fields() {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            A[i][j] = '.';
            B[i][j] = '.';
        }
    }
}

void show_fields() {// to do create coordinate axes
    std::cout << std::endl;
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j <10; j++) {
            std::cout << " ";
            std::cout << A[i][j];
        }
        std::cout << "\t\t";
        for (int j = 0; j < 10; j++) {
            std::cout << " ";
            std::cout << B[i][j];
        }
        std::cout << std::endl;
    }
}

bool is_valid_ship_size(int size, int y1, int x1, int y2, int x2) {
    int sizeY = std::abs(y1 - y2); // calculate ship size
    int sizeX = std::abs(x1 - x2); // calculate ship size
    if (sizeY > size - 1 || sizeX > size - 1) //the ship must be whole
        return false;
    if (sizeY < size - 1 && sizeX < size - 1)
        return false;// the ship must take (size) grade spaces

    return true;
}

bool is_valid_coordinates(char f[10][10], int y1, int x1, int y2, int x2) {

   if (y1 < 0 || y1 > 9 || y2 < 0 || y2 > 9 || x1 < 0 || x1 > 9 || x2 < 0 || x2 > 9)
       return false;

   for (int i = y1; i <= y2; i++) {
       for (int j = x1; j <= x2; j++) {
           if (f[i][j] == '#') // check if there is a ship on the field in this place
               return false;
       }

       if (y1 != y2 && x1 != x2) // you can't place ships diagonally
           return false;

   }
   return true;
}

void position_ship(char (&f)[10][10], int &y1, int &x1, int &y2, int &x2) {
    if (y1 > y2)
        std::swap(y1, y2);
    if (x1 > x2)
        std::swap(x1, x2);
    while (!is_valid_coordinates(f, y1, x1, y2, x2)) {
        std::cout << "Incorrect coordinates. Try again:";
        std::cin >> y1 >> x1 >> y2 >> x2;
    }

    for (int i = y1; i <= y2; i++) {
        for (int j = x1; j <= x2; j++) {
            f[i][j] = '#';
        }
    }

}

void position_small_ship(char (&f)[10][10], int &y, int &x) { // special function to position small ships
    while (y < 0 || y > 9 || x < 0 || x > 9 || f[y][x] == '#') {
        std::cout << "Incorrect coordinates. Try again:";
        std::cin >> y >> x;
    }
    f[y][x] = '#';
}

void arrange_ships(char (&f)[10][10]) {
    int huge = 1, big = 2, medium = 3, small = 4;

    while (small != 0) {
        int y, x;
        std::cout << "Position the small ship (1 grid spaces):";
        std::cin >> y >> x;
        position_small_ship(f, y, x);
        small--;
    }

    while (medium != 0) {
        int shipSize = 2;
        int y1, x1, y2, x2;
        std::cout << "Position the medium ship (2 grid spaces):";
        std::cin >> y1 >> x1 >> y2 >> x2;

        while (!is_valid_ship_size(shipSize, y1, x1, y2, x2)) {
            std::cout << "Invalid ship size. Try again:";
            std::cin >> y1 >> x1 >> y2 >> x2;
        }

        position_ship(f, y1, x1, y2, x2);
        medium--;
    }

    while (big != 0) {
        int shipSize = 3;
        int y1, x1, y2, x2;
        std::cout << "Position the big ship (3 grid spaces):";
        std::cin >> y1 >> x1 >> y2 >> x2;

        while (!is_valid_ship_size(shipSize, y1, x1, y2, x2)) {
            std::cout << "Invalid ship size. Try again:";
            std::cin >> y1 >> x1 >> y2 >> x2;
        }

        position_ship(f, y1, x1, y2, x2);
        big--;
    }

    while (huge != 0) {
        int shipSize = 4;
        int y1, x1, y2, x2;
        std::cout << "Position the huge ship (4 grid spaces):";
        std::cin >> y1 >> x1 >> y2 >> x2;

        while (!is_valid_ship_size(shipSize, y1, x1, y2, x2)) {
            std::cout << "Invalid ship size. Try again:";
            std::cin >> y1 >> x1 >> y2 >> x2;
        }

        position_ship(f, y1, x1, y2, x2);
        huge--;
    }

}

void task9() {
    create_fields();
    show_fields();
    arrange_ships(A);
    show_fields();
    arrange_ships(B);
}