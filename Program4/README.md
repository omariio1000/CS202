A basic food ordering program made to practice OOP in Java

Menu File Format:

The first line of the file is the details of the restaurant
Each argument is separated by the '|' (pipe) character. Format is:
Restuarant Name|Cuisine|Address|Hours|Spice Level (integer)|Rating (integer)

Any line after that is an "item", and there are currently three types of items.

Customizable Items: These include toppings, which are also parsed on the same line using different charracters. Format:
Customizable|Item Name|Price (float)|Free Toppings (separated by ',' [comma])|Extra Toppings (separated by ',' [comma] and dash between name and price (float))

Spice Items: These have a maximum spice level, and any value from 0 to that level can be selected when ordering. Format:
Spice|Item Name|Price (float)|Spice Level (integer)

Catering Items: These can serve multiple people and have a discount when ordering in bulk. Format:
Catering|Item name|Price (float)|Servings (int)|Bulk Discount (float)