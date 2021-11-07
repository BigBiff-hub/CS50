#use get float to 
from cs50 import get_float



coins = 0


# use a while loop to iterate over change and to get a positive input
while True:
    coins_needed = get_float("How much coins do I owe you? ")
    if coins_needed > 0:
        break
    else:
        print("Please input a non negative value ")

#convert to int 
coins_needed = round(int(coins_needed * 100))

# same method from c file 

#quarter
coins = coins_needed // 25
coins_needed %= 25


#dimes
coins += coins_needed // 10
coins_needed %= 10

#nickles
coins += coins_needed // 5
coins_needed %= 5


#cents
coins += coins_needed // 1


print(coins)