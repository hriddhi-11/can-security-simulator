#include "can_stuffing.h"

int bit_stuffing(uint8_t *input, int length, uint8_t *output) {
    // YOUR CODE HERE (you already wrote this!)
    int count = 1;
    int out_len = 0;
    
    // Add first bit
    output[out_len++] = input[0];
    
    for(int i = 1; i < length; i++) {
        if(input[i] == input[i-1]) {
            count++;
        } else {
            count = 1;
        }
        
        if(count == 5) {
            output[out_len++] = !input[i-1];
            count = 1;
        }
        
        output[out_len++] = input[i];
    }
    
    return out_len;
}