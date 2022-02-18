
void show_field(char f[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            std::cout << f[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

bool check_for_win(char f[3][3], int y, int x, char ch) {
    int _x = 0, _y = 0;
    for (int i = 0; i < 3; i++) {
        if (f[y][i] == ch)
            _y++;
    }
    if (_y == 3)
        return true;
    for (int j = 0; j < 3; j++) {
        if(f[j][x] == ch)
            _x++;
    }
    if (_x == 3)
        return true;
    return false;
}

bool is_full(char f[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if ( f[i][j] == ' ')
                return true;
        }
    }
    return false;
}

void task2() {
    const int SIZE = 3;
    char field[SIZE][SIZE] = { {' ', ' ', ' '},
                               {' ', ' ', ' '},
                               {' ', ' ', ' '}};

    bool winnerFound = false;
    char player;
    int counter = 0;
    int x, y;

    while(!winnerFound) {
        counter++;
        if (counter > 9)
            break;
        counter % 2 == 0 ? player = 'O': player = 'X';
        std::cout << "Now move " << player << std::endl;
        std::cout << "Enter column and line:";
        std::cin >> y >> x;

        bool isValid = x >= 0 && x < 3 && y >= 0 && y < 3 && field[y][x] == ' ';
        while (!isValid) {
            std::cout << "Incorrect coordinates. Try again" << std::endl;
            std::cin >> y >> x;
            isValid = x >= 0 && x <= 3 && y >= 0 && y <= 3 && field[y][x] == ' ';
        }
        field[y][x] = player;

        show_field(field);

        winnerFound = check_for_win(field, y, x, player);
    }
    if (winnerFound)
        std::cout << player << " WON!" << std::endl;
    else
        std::cout << "DRAW" << std::endl;
}


