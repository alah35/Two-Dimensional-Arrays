
void initialize_pimple(bool (&p)[12][12], bool val) {
    for (int i = 0; i < 12; i++) {
        for (int j = 0; j < 12; j++) {
            p[i][j] = val;
        }
    }
}

bool show_pimple(bool p[][12]) {
    bool pimpleSpent = true;
    for (int i = 0; i < 12; i++) {
        for (int j = 0; j < 12; j++) {
            if (p[i][j]) {
                std::cout << "O ";
                pimpleSpent = false;
            } else
                std::cout << "X ";
        }
        std::cout << std::endl;
    }
    return pimpleSpent;
}

bool burst_pimple(bool (&p)[12][12], int y1, int x1, int y2, int x2) {
    if (y1 > y2)
        std::swap(y1, y2);
    if (x1 > x2)
        std::swap (x1, x2);

    for (int i = y1; i <= y2; i++) {
        for (int j = x1; j <= x2; j++) {
            if (p[i][j])
            p[i][j] = false;
            std::cout << "Pop!" << std::endl;
        }
    }
    return true;
}

bool is_valid(int y, int x) {
    if (y < 0 || y > 11 || x < 0 || x > 11)
        return false;
    return true;
}

void task7() {
    bool pimple[12][12];
    initialize_pimple(pimple, true);
    show_pimple(pimple);
    bool pimpleSpent = false;

    while (!pimpleSpent) {
        int y1, x1, y2, x2;

        std::cout << "Enter burst area y1, x1:" << std::endl;
        std::cin >> y1 >> x1;
        while(!is_valid(y1, x1)) {
            std::cout << "Wrong coordinates. Try again:";
            std::cin >> y1 >> x1;
        }

        std::cout << "Enter burst area y2, x2:" << std::endl;
        std::cin >> y2 >> x2;
        while (!is_valid(y2, x2)) {
            std::cout << "Wrong coordinates. Try again:";
            std::cin >> y2 >> x2;
        }

        burst_pimple(pimple, y1, x1, y2, x2);
        pimpleSpent = show_pimple(pimple);
    }
    std::cout << "All pimples poped! You are great!";
}
