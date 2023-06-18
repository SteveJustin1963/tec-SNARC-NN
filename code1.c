#include <stdio.h>

#define NUM_INPUT_NEURONS 8
#define NUM_HIDDEN_NEURONS 4
#define NUM_OUTPUT_NEURONS 1

#define LEARNING_RATE 100 // Learning rate (0.1 in integer format)

void initialize_weights(int weights[], int num_weights, int init_value) {
    for (int i = 0; i < num_weights; i++) {
        weights[i] = init_value;
    }
}

int dot_product(int vec1[], int vec2[], int len) {
    int result = 0;
    for (int i = 0; i < len; i++) {
        result += (vec1[i] * vec2[i]) / 1000;
    }
    return result;
}

void updateWeights(int weights[], int inputs[], int error, int num_weights) {
    for (int i = 0; i < num_weights; i++) {
        weights[i] += (LEARNING_RATE * error * inputs[i]) / 1000;
    }
}

void train_network(int input_pattern[], int target_output, int hidden_weights[], int output_weights[]) {
    int hidden_output[NUM_HIDDEN_NEURONS], final_output;
    
    // Forward pass
    for (int i = 0; i < NUM_HIDDEN_NEURONS; i++) {
        hidden_output[i] = dot_product(input_pattern, hidden_weights, NUM_INPUT_NEURONS);
    }
    final_output = dot_product(hidden_output, output_weights, NUM_HIDDEN_NEURONS);

    // Calculate error signal
    int error = target_output - final_output;

    // Update weights
    for (int i = 0; i < NUM_HIDDEN_NEURONS; i++) {
        updateWeights(hidden_weights, input_pattern, error, NUM_INPUT_NEURONS);
    }
    updateWeights(output_weights, hidden_output, error, NUM_HIDDEN_NEURONS);
}

int main() {
    int input_pattern[NUM_INPUT_NEURONS] = {1000, 500, 200, 800, 400, 600, 900, 300};
    int hidden_weights[NUM_HIDDEN_NEURONS];
    int output_weights[NUM_OUTPUT_NEURONS];

    initialize_weights(hidden_weights, NUM_HIDDEN_NEURONS, 1000); 
    initialize_weights(output_weights, NUM_OUTPUT_NEURONS, 500); 

    int target_output = 1000; // Target output (this would be given)

    train_network(input_pattern, target_output, hidden_weights, output_weights);

    return 0;
}
