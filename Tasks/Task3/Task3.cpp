
void output_array(int arr[][5]) {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            std::cout << arr[i][j] << "\t";
        }
        std::cout << std::endl;
    }
}

void snake_input(int (&arr)[5][5]) {
    int sequence = 0;
    for (int i = 0; i < 5; i++){
        int j, direction;
        i % 2 == 0 ? j = 0 : j = 4;
        j == 0 ? direction = 1 : direction = -1;
        for ( ; j >= 0 && j <= 4; j += direction ) {
            arr[i][j] = sequence;
            sequence++;
        }
    }
}

void snake_input2(int (&arr)[5][5]) {
    int sequence = 0;
    int direction = 1;
    int j = -1;

    for (int i = 0; i < 5; i++) {
        for (j += direction; j >= 0 && j <= 4; j += direction) {
            arr[i][j] = sequence;
            sequence++;
        }
        direction = -direction;
    }
}

void task3() {
    int snake[5][5];
    snake_input2(snake);
    output_array(snake);
}

