# A Simple C Game with Dynamic Reshuffling and Score Tracking using Stacks

This project is a simple C game that offers dynamic reshuffling functionality and score tracking using stacks. The game is designed to be very close to the real world, and is implemented entirely using stack data structures in C.

## Getting Started

To run this project, you will need to have a C compiler installed on your computer. You can use any C compiler that you prefer.

1. Clone the project repository to your local machine using the following command:

` git clone https://github.com/yourusername/your-project-name.git `

2. Compile the program using your C compiler.

`g++ 1.c -o game`

3. Run the game.

`./game`

## How to Play

The game is a simple card game where the objective is to match cards with the same number. The game starts by shuffling the deck of cards and dealing them out to the players. Players take turns to pick up cards from the deck and match them with cards they already have in their hand.

After every fixed number of alternative turns, the game offers the functionality of reshuffling of the remaining cards, so that players get a fresh set of cards to play with.

Players can exit the game at any point of time and the final score will be recorded for them. 

## Stack Implementation

The entire game has been implemented using stack data structures in C. The stack data structure is a collection of elements, with two main operations: push and pop. The push operation adds an element to the top of the stack, while the pop operation removes an element from the top of the stack. The stack implementation is done manually without using any available library. 
In this game, we use stacks to implement the deck of cards, the player's hand, and the reshuffling functionality. The stacks make it easy to add and remove cards from the deck and player's hand, and also enable us to implement the reshuffling functionality by simply popping all the remaining cards from the deck, shuffling them, and pushing them back onto the stack.

## Score Tracking

The game also offers the functionality of score tracking, where the final score is recorded for each player. This is implemented using a simple score variable, which is incremented every time a player matches two cards with the same number. The final score is displayed at the end of the game.

## Conclusion

This simple C game demonstrates the power and versatility of stack data structures, and how they can be used to implement complex functionality like dynamic reshuffling and score tracking. The game is easy to play and can be modified or extended to include additional features or rules.
