def handleArray(numbers,state):
    print("Initial numbers:", numbers)
    i = 0
    while(i < len(numbers)):
        temp = numbers[i]
        safe = False
        if (state == True): 
            del numbers[i]      
            print("After deletion:", numbers)
          
        if numbers == sorted(numbers) or numbers == sorted(numbers, reverse=True):
            for k in range(len(numbers) - 1):
                if abs((numbers[k] - numbers[k + 1])) <= 3 and abs(numbers[k] - numbers[k + 1]) > 0:
                    safe = True
                    continue
                else: 
                    print("not in range")
                    safe = False
                    break
              
        if (not safe): 
            if (state == True):
                print("Mistake found")
                numbers.insert(i, temp)
                print("After reinserting:", numbers)

        if(state == False): 
            i = -1
            state = True
        i += 1
        
                         
    return safe


result = 0
f = open('Door2/input.txt', 'r')
for line in f:   
    Numbers = list(map(int, line.split()))
    state = False
    if handleArray(Numbers,state):      
        result += 1
        print(result)
    else: 
        print("no")
        result += 0

        

print(result)






          
    
    
   