#include <vector>

void create_world(std::vector<std::vector<std::vector<int>>> &v) {
    for (int i = 0; i < 5; i++) {
        v[i].resize(5);
    }

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            int height;
            std::cout << "Enter the height of block:";
            std::cin >> height;
            while (height < 0 || height > 10) {
                std::cout << "Height must be > 0 and <= 10. Try again:";
                std::cin >> height;
            }
            v[i][j].resize(height, 1);
        }
    }
}

bool isValid(int l) {
    if (l < 0 || l > 10)
        return false;
    return true;
}

void make_slice(std::vector<std::vector<std::vector<int>>> &v, int l, bool (&s)[5][5]) {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            v[i][j].size() >= l ? s[i][j] = true : s[i][j] = false;
        }
    }
}

void show_slice(bool (&s)[5][5]) {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            std::cout << s[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

void task8() {

    std::vector<std::vector<std::vector<int>>> world(5);
    create_world(world);

    int landscapeLevel;
    std::cout << "Enter slice level:";
    std::cin >> landscapeLevel;
    while (!isValid(landscapeLevel)) {
        std::cout << "Slice level >= 0 and < 10. Try again:";
        std::cin >> landscapeLevel;
    }

    bool slice[5][5];
    make_slice(world, landscapeLevel, slice);
    show_slice(slice);
}

