
import sys
words=[]
counter=0
sum=0
f=open(sys.argv[1])
for line in f:
  words=line.split(',',3)
  if counter>0:
    sum=sum+float(words[2])
  counter+=1
  print (counter, words[2])
if counter>0:
  average=sum/counter
print ("average: ", average)