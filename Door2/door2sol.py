safe = 0
    
with open("Door2/input.txt") as file:
        while (line := file.readline()):
            levels = line.split()
            levels = [int(level) for level in levels]
    
            is_decreasing = False
            if levels[0] > levels[1]:
                is_decreasing = True
            
            removed = False
            for i in range(1, len(levels)):
                if is_decreasing:
                    if levels[i] >= levels[i-1] or levels[i] < levels[i-1] - 3:
                        if removed:
                            break
                        removed = True
                else:
                    if levels[i] <= levels[i-1] or levels[i] > levels[i-1] + 3:
                        if removed:
                            break
                        removed = True
            else:
                safe += 1
        
print(safe)