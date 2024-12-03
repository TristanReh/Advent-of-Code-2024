from operator import mul
import re
result = 0
line = open('Door3/input.txt', 'r').read() 
  
dont_pos = line.find("don't()")
while(dont_pos != -1):
    do_pos = line.find("do()", dont_pos + 7)  
    if do_pos != -1: 
        line = line[:dont_pos] + line[do_pos + 4:]
    else:
        line = line[:dont_pos]
    dont_pos = line.find("don't()")
print(line)
matches = re.findall(r"mul\(\d+,\d+\)", line)
for elem in matches:
    numbers = re.findall(r"\d+", elem) 
    numberResult = list(map(int, numbers))
    result += mul(numberResult[0],numberResult[1])
    print(result)

           
            

   