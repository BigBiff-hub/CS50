from cs50 import get_string


text = get_string("Text: ")
text_length = len(text)

word_count = 1
letter_count = 0  
sentence_count = 0

### Number of letters ###
for i in range(text_length):
    if(text[i].isalpha()):
       letter_count = letter_count + 1
    
    ## Get number of sentences when terminating characters ., ?, ! ###   
    if(text[i] == '.' or text[i] == '?' or text[i] == '!'):
        sentence_count +=1
    
    
    ## Number of word by detecting spaces 
    if (text[i].isspace()):
        word_count +=1
     ## calculate index   
calculation = (0.0588 * letter_count / word_count * 100) - (0.296 * sentence_count / word_count * 100) - 15.8
    
index = round(calculation)
if index<1:
    print("Before Grade 1")
elif index>16:
    print("Grade 16+")
else:
    print(f"Grade is {index}")