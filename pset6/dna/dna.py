from sys import argv
import csv

def dna_main():

    STRS = []
    ## check arguements
    if len(argv) != 3:
         print("Usage: python dna.py data.csv sequence.txt")

    csv_file = open(argv[1])
    text_file = open(argv[2])

    csv_file_reader = csv.DictReader(csv_file)
    #### need to get strs from the csv
    STRS = csv_file_reader.fieldnames[1:]
    ## get dna from text files 
    dna = text_file.read()
    text_file.close()
    
    dna_identifier = {}
    for STR in STRS:
        dna_identifier[STR] = dna_repeats(STR, dna)
        
        
    for row in csv_file_reader:
        if dna_match(STRS, dna_identifier, row):
            print(f"{row['name']}")
            csv_file.close()
            return 
        
    print("No match")
    csv_file.close()
        
        

    
    
    
    
# To know how many of each str group I have 
def dna_repeats(STR, dna):
   i=0
   while STR*(i+1) in dna:
       i+=1
   return i

def dna_match(STRS, dna_identifier, row):
    for STR in STRS:
        if dna_identifier[STR] != int(row[STR]):
         return False
    return True

if __name__ == "__main__":
    dna_main()