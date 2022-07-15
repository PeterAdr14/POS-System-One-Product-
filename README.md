# POS System (Single Product)

This system is presents a menu of options, each one tied to a number. The first option adds a name and order quantity to a list. The second option allows for the user to fulfill the orders that were added to the list. The user enters the quantity made, and the earliest order that is equal to the quantity made will be fulfilled. If an order is less than the quantity made, that order will be fulfilled and the remaining quantity will be used to try and fulfill other orders. The following options (List the Orders, Search by Size, Backwards List, List Length, Show Save File[text file], Quit) are more self explanatory. Every 15 seconds, a separate thread will save the current list to the text file.

