# Project.7_LotteryGenerator
refresher exercise for C++ programming concepts, aimed at reinforcing knowledge of random number generation, arrays, and modular programming techniques. The program generates suggested lottery numbers


## Description
This project is a refresher exercise for C++ programming concepts, aimed at reinforcing knowledge of random number generation, arrays, and modular programming techniques. The program generates suggested lottery numbers based on user input, ensuring no duplicate numbers in any generated ticket.

## Features
- Prompts the user for:
  - **Number of values per ticket** (3 to 7 inclusive)
  - **Range of possible numbers** (1-45 to 1-70 inclusive)
  - **Number of tickets** (1 to 100 inclusive)
- Validates user input to ensure it falls within the specified ranges.
- Ensures no duplicate numbers are generated for any single ticket.
- Outputs all generated lottery tickets in a readable format.

## Input Requirements
1. **Number of values per ticket:**  
   User must input a number between 3 and 7. Invalid inputs will prompt the user to re-enter the value.
   
2. **Range of random numbers:**  
   User specifies the maximum number in the range (between 45 and 70). The range always starts at 1. Invalid inputs will prompt re-entry.
   
3. **Number of tickets:**  
   User specifies how many tickets to generate (between 1 and 100). Invalid inputs will prompt re-entry.

## Output
The program echoes the user input and prints the generated lottery numbers in the following format:

```plaintext
Number of values per ticket: 6
Range of numbers: 1 to 49
Number of tickets: 3

Generated Lottery Numbers:
Ticket 1: 3, 15, 22, 34, 41, 49
Ticket 2: 7, 19, 25, 29, 36, 42
Ticket 3: 1, 8, 16, 20, 35, 48

