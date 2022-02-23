
void delete_non_diagonal_elements(int (&a)[4][4]) {
    for (int i = 0; i < 4; i++) {
        for(int j = 0; j < 4; j++) {
            if (i != j)
                a[i][j] = 0;
        }
    }
}

void task5() {
    int M[4][4];
    input_matrix(M);
    std::cout << std::endl;
    output_matrix(M);
    delete_non_diagonal_elements(M);
    std::cout << std::endl;
    output_matrix(M);
}