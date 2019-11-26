## Program 5 - Card Game (Blackjack)
#### Due: idk, whenever Griffin says

### Overview

The card game Blackjack is a game in which players draw cards attempting to get
the sum total of their hand as close to 21 as possible. If the total of their
hand exceeds 21, they lose automatically. If neither player has a hand over 21
(a "bust") then the player closest to or at 21 is the winner. If both players
have the same sum, it is a tie. Face cards (jack, queen, king) are all worth
10 and the Ace can be treated as a 1 or an 11 at the player's discretion.

### Data Structure Representations
- Deck of Cards
  - Think of the deck as a stack of cards, you only "draw" (pop)
    off of the top of the stack
  - Each Node in the stack should hold a card. This would either be an int or,
    if you wrote one, the card class.
- Player Hand
  - The player's hand should be a doubly linked list
  - They can traverse forwards or backwards through to select a card

### Assignment

Create a visual game of Blackjack using the [TermGame.h](https://github.com/jeremyglebe/TermGame) library. Cards may be
represented as integers 0-51. There is not exact correct or incorrect output,
but the structures above should be implemented and used in the game. In
addition, the game should (regardless of implmentation) demonstrate the
following features:
  - The player's hand is visible, the cards look at least somewhat
    like cards (not just numbers) and are colored based on suit
  - The opponent's hand is displayed but obscured so that the player can see
    how many cards they have, but not what the cards are.
    - Try something like this: 
    ```
    ┌────┐
    │■■■■│
    │■■■■│
    └────┘
    ```
  - The player should press a button to draw another card from the deck
  - The player should press a button to "fold" (choose to keep their current
    hand and not draw again)
  - The player can select Aces and change their value from 1 to 11
    or back again.
  - The opponent should randomly choose whether to draw again or fold.
  - The opponent should randomly choose which value an Ace uses.
  - Once the player and opponent have folded, the game should tell the user
    who won.

### Hints
#### Project structure suggestion
While these classes aren't all required, you may consider a project structure that looks something like this:
  - Card.h
    - The `Card` class would be used to interpret card data. It may be stored
    as a simple integer (0-51), but it would still be nice to have all the card
    functions in one place.
    - Card methods might include interpreting the integer as a string
    and printing it, for example.
  - Deck.h
    - The `Deck` class would basically be a stack of cards, with any extra
    functionality you think a deck of cards should have.
  - Player.h
    - The `Player` class is a doubly-linked list that has the added feature of
    the player being able to control (select) cards in their hand.
    - You might consider something like a card pointer (Card*) to keep track of
    which card is selected.
  - Opponent.h
    - The `Opponent` class may be list-based or array-based, but it's main
    purpose would be to  keep track of the opponent's cards and to help the
    opponent make (random) decisions when its their turn.
#### How to interpret integers as cards?
Assuming `x` is an integer between 0 and 51
```cpp
    string faces[] = {"A", "2", "3", "4", "5", "6", "7","8","9", "T", "J", "Q", "K"};
    string suits[] = {"♥", "♦","♣", "♠"};

    string face = faces[x % 13];
    string suit = suits[x / 13];
```

### Requirements
  - Your code contains a Stack implementation (does not have to actually be
  called a "Stack" if you'd rather call it something like "Deck")
  - Code contains a Linked List implementation (again, call it what you like)
  - Game plays as described.
  - Game utilizes color and unicode characters for visuals.

#### Bonus Requirement:
  - The game has a menu, can be played multiple times, and tracks the players
  wins and losses.
  - The opponent makes slightly more intelligent decisions. (Weighted random)

### Deliverables

- Create a folder called `program_5` in your `assignments` folder.
- In this folder create a file called `blackjack.cpp` with c++ code that fulfills the requirements.
- Your `program_5` folder should contain:
    - `blackjack.cpp` 
    - `.h` files for your classes
- ANY file you use with your assignment should ALWAYS end up in your assignment folder.
- Comment your code! This is all the more important due to the lack of strict
requirements. We don't know what we're looking at if you don't explain it.
- Print a copy of your code and bring to class whenever Griffin says its due.
  - Stapled: Upper left corner (close to the corner).
  - Your name should be on each page ( NO HAND WRITING !! ).
