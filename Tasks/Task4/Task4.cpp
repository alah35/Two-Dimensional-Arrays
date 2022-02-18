
bool is_equal(int a[][4], int b[][4]) {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (a[i][j] != b[i][j])
                return false;
        }
    }
    return true;
}

void input_matrix(int (&a)[4][4]) {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            std::cout << "Enter element (" << i << ", " << j << ") =";
            std::cin >> a[i][j];
        }
    }
}

void fill_matrix(int (&a)[4][4], int n) {
    int sequence = n;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            a[i][j] = sequence;
            sequence++;
        }
    }
}

void output_matrix(int a[][4]) {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            std::cout << a[i][j] << "\t";
        }
        std::cout << std::endl;
    }
}

void task4() {
    int A[4][4], B[4][4];
    fill_matrix(A, 0);
    fill_matrix(B, 1);
    output_matrix(A);
    std::cout << std::endl;
    output_matrix(B);
    if (is_equal(A,B))
        std::cout << "Matrix are equal" << std::endl;
    else
        std::cout << "Matrix are NOT equal" << std::endl;
}