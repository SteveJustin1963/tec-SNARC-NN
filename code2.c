 // task, which is a binary string classification problem, I'll suggest using a simple binary cross-entropy loss for the error calculation 
// and a sigmoid activation function for the output of your neurons, which are common choices for binary classification problems.

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define NUM_INPUT_NEURONS 32
#define NUM_HIDDEN_NEURONS 16
#define NUM_OUTPUT_NEURONS 1
#define NUM_EPOCHS 100

#define LEARNING_RATE 0.01

void initialize_weights(double weights[], int num_weights) {
    for (int i = 0; i < num_weights; i++) {
        weights[i] = ((double) rand() / (RAND_MAX));
    }
}

double sigmoid(double x) {
    return 1.0 / (1.0 + exp(-x));
}

double dot_product(double vec1[], double vec2[], int len) {
    double result = 0.0;
    for (int i = 0; i < len; i++) {
        result += vec1[i] * vec2[i];
    }
    return result;
}

double binary_cross_entropy_loss(double predicted, double target) {
    return -target * log(predicted) - (1 - target) * log(1 - predicted);
}

void updateWeights(double weights[], double inputs[], double output, double error, int num_weights) {
    for (int i = 0; i < num_weights; i++) {
        double delta = LEARNING_RATE * error * inputs[i];
        weights[i] += delta;
    }
}

int main() {
    double input_pattern[NUM_INPUT_NEURONS] = {1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0};
    double hidden_weights[NUM_HIDDEN_NEURONS];
    double output_weights[NUM_OUTPUT_NEURONS];
    double hidden_output[NUM_HIDDEN_NEURONS], final_output;
    double expected_output = 1.0; // this should come from your dataset
    double error_signal;

    initialize_weights(hidden_weights, NUM_HIDDEN_NEURONS); 
    initialize_weights(output_weights, NUM_OUTPUT_NEURONS); 

    // Run training for multiple epochs
    for (int epoch = 0; epoch < NUM_EPOCHS; epoch++) {

        // Forward pass
        for (int i = 0; i < NUM_HIDDEN_NEURONS; i++) {
            hidden_output[i] = sigmoid(dot_product(input_pattern, hidden_weights, NUM_INPUT_NEURONS));
        }
        final_output = sigmoid(dot_product(hidden_output, output_weights, NUM_HIDDEN_NEURONS));

        // Calculate error signal or delta_out
        error_signal = binary_cross_entropy_loss(final_output, expected_output);

        // Update weights
        for (int i = 0; i < NUM_HIDDEN_NEURONS; i++) {
            updateWeights(hidden_weights, input_pattern, hidden_output[i], error_signal, NUM_INPUT_NEURONS);
        }
        updateWeights(output_weights, hidden_output, final_output, error_signal, NUM_HIDDEN_NEURONS);

        printf("Epoch: %d, Error: %.4f\n", epoch+1, error_signal);
    }

    return 0;
}
////////////////////////

