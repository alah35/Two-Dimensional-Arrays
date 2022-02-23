
void input_matrix(float (&M)[4][4]) {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            std::cout << "Enter (" << i << ", " << j << ") element =";
            std::cin >> M[i][j];
        }
    }
}

void output_matrix(float M[][4]) {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            std::cout << M[i][j] << "\t";
        }
        std::cout << std::endl;
    }
}

void input_vector(float *vec) {
    for (int i = 0; i < 4; i++) {
        std::cout << "Enter " << i + 1 << " elem of vector:";
        std::cin >> vec[i];
    }
}

void output_vector(float *vec) {
    for (int i = 0; i < 4; i++) {
        std:: cout << vec[i] << " ";
    }
    std::cout << std::endl;
}

void multiply_vector_by_matrix(float *vec, float M[][4], float *result) {
    for (int i = 0; i < 4; i++) {
        float elem = 0;
        for (int j = 0; j < 4; j++) {
            elem += vec[j] * M[j][i];
        }
        result[i] = elem;
    }
}

void task6() {
    float vector[4];
    float Matrix[4][4];
    float resultVector[4];

    input_vector(vector);
    input_matrix(Matrix);
    std::cout << "Vector:" << std::endl;
    output_vector(vector);
    std::cout << "Matrix:" << std::endl;
    output_matrix(Matrix);
    multiply_vector_by_matrix(vector,Matrix, resultVector);
    std::cout << "Result vector:" << std::endl;
    output_vector(resultVector);
}