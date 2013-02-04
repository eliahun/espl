 
import sys
from random import choice
do=1
while do: 
  lines=[]
  lines = tuple(open("long-words.txt", 'r'))
  cur_word= choice(lines)
  guess=0
  while guess is not 'q': 
    guess=raw_input('Please enter a for answer, g for guessing or q for exit  ')
    if guess is 'g':
      letter=raw_input('Please enter a letter:')
      good=cur_word.find(letter) 
      if good is not -1:
	print "letter is in word"
      else: print "letter isn't in word"  
    if guess is 'a':
      a=raw_input('Please enter your guess:')
      if a.strip() == cur_word.strip():
	print "you got it"
	break;
      else: print "na ha" 
    if guess is 'q':
      print "bye"
      exit()
     
    
    

    

  
