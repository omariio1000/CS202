A basic card game made to practice OOP

Instructions:

This game only supports two players as of now, but can easily be expanded.
Each player has health (30 to start), and energy (10 to start). In order to play cards, you need energy.
Every turn, the player can choose to either draw a card, use a card, hibernate to regenerate energy, 
skip their turn, or vote to end the game, which the other player has to accept. The deck stores cards, and there is
also a discard pile, which is reshuffled whenever the deck pile is empty (there has to be cards in the discard in order to
reshuffle). There are three types of cards, attack, spell, and defence. Attack cards turn energy into an attack that can 
lower a player's health. Spell cards turn energy into more energy, and can restore a player. Defence cards turn energy
into health, and can heal a player. The player can choose who they effect, so be careful not to attack yourself or use
spell or defence cards on your opponent! The deck of cards is read in from a file, and only one deck can be played at a time.
Cards can be found either once or multiple times in a deck, depending on their power and rarity.

Deck File Format:

Separated by the '|' (pipe) character. Format is: 
Card Type|Card Name|Card Information or Description|Energy Required|Card Power|Number of Cards in Deck

Ex. attack|Sword|Good old wack with a sword|2|3|4

IMPORTANT: 
Card types are case sensitive, they must be either 'attack', 'spell', or 'defence'. 
When inputting card name for use, it is also case sensitive. 
Energy required, card power, and number of cards in deck must be integers, or the program won't work as expected. 

MOST IMPORTANT: Enjoy!
