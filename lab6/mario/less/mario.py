from cs50 import get_int


def main():
    height = get_h("Height: ")
    print_pyramid(height)


# get input 
def get_h(prompt):
    while True:
        h = get_int(prompt)
        # check for valid input 
        if h > 0 and h < 9:
            break
        else:
            print("Please enter a number between 1 and 8")
        
            
    return h


# print ## for pryamid 
def print_pyramid(rows):
    
    for row in range(1, rows + 1):
        #use the same method from c to print have pyramid
        print(" " * (rows - row) + "#" * row)


if __name__ == "__main__":
    main()