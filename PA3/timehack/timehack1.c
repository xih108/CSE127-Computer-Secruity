/*******************************************************
 CSE127 Project
 User routines file

  You can change anything in this file, just make sure 
  that when you have found the password, you call 
  hack_system() function on it.

 CSE127 Password guesser using timing

 *******************************************************/

#include <stdio.h>
#include <string.h>
#include <unistd.h>

// include our "system" header
#include "sysapp.h"

// Read cycle counter
#define rdtsc() ({ unsigned long a, d; asm volatile("rdtsc":"=a" (a), "=d" (d)) ; a; })

long double median(long arr[], int n){
    for (int i = 0; i < n-1; i++){
        for (int j = 0; j < n-i-1; j++){
            if (arr[j] > arr[j+1]){
                long double tmp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = tmp;
            }
        }
    }
    if (n % 2 == 0){
        return (arr[n/2-1] + arr[n/2]) /2;
    }
    else{
        return arr[(n-1)/2];
    }
}

long double partition(long double arr[]){}

int main(int argc, char **argv) {
    char guess[33];

    // set guess to zeros
    bzero(guess, sizeof(guess));

    //
    // do the guessing (this is where your code goes)
    //   we suggest a loop over the size of the possible
    //   password, each time trying all possible characters
    //   and looking for time deviations
    //

    int trials = 300; 
    for (int i = 0; i < 2; i++){
        // long double max = 0;
        // char tmp;
        // for (char c = 33; c <= 126; c++){
        //     guess[i] = c;
        //     long time[trials];
        //     bzero(time, sizeof(time));
        //     for (int n = 0; n < trials; n++){
        //         long time1 = rdtsc();
        //         check_pass(guess);               
        //         long time2 = rdtsc();
        //         time[n] = time2 - time1;
        //     }
        //     long double t = median(time, trials);
        //     // printf("%c %Lf %Lf\n",c, t, max);
        //     if (t > max){
        //         max = t;
        //         tmp = c;
        //     }

        long time[124][trials];
        bzero(time, sizeof(time));
        for (int n = 0; n < trials; n++){
            for (char c = 33; c <= 126; c++){
                long time1 = rdtsc();
                check_pass(guess);
                long time2 = rdtsc();
                time[c][n] = time2-time1;
            }
        }
        long double max = 0;
        char tmp;
        for (char c = 33; c <= 126; c++){
            long double median = median(time[c], n);
            if (median > max){
                max = median;
                tmp = c;
            }
        }
        guess[i] = tmp;
        if (check_pass(guess) == 1){
            break;
        }
    }
   

    if (check_pass(guess)) {
        printf("Password Found!\n");
        hack_system(guess);
    };

    printf("Could not get the password!  Last guess was %s\n", guess);
    return 1;
};



