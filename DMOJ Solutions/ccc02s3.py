grid = [] #this will be a 2D list storing information about the yard

r = int(input())
c = int(input())

for i in range(r):
    row = [] #this will be one row of the yard

    #we will take the entire row as input
    #and then add each individual square to the row list
    line = input()
    for j in range(c):
        row.append(line[j])
    #now we can add the list containing the row to the 2D list
    grid.append(row)

m = int(input())

#we will store the commands in a list
commands=[]

for i in range(m):
    command = input().strip()
    commands.append(command)

#this function will check if a starting position will yield a valid ending position
def check(direction, commands, y, x, r, c, grid):
    #PARAMETERS DESCRIPTION:
    #direction: stores the direction that you will be moving
    #U is for up, D is for down, L is for left, R is for right
    #commands: commands list
    #y: y position you are at
    #x: x position you are at
    #r: number of rows in the grid
    #c: number of columns in the grid
    #grid: 2D list storing the yard

    for command in commands: #loop through each command
        if command == 'L':
            #these if statements will rotate you counter-clockwise
            #depending on what direction you are facing
            if direction == 'L':
                direction = 'D'
            elif direction == 'R':
                direction = 'U'
            elif direction == 'U':
                direction = 'L'
            else:
                direction = 'R'
        elif command == 'R':
            #these if statements will rotate you clockwise
            #depending on which direction you are facing
            if direction == 'L':
                direction = 'U'
            elif direction == 'R':
                direction = 'D'
            elif direction == 'U':
                direction = 'R'
            else:
                direction = 'L'
        else:
            if direction == 'L':
                x -= 1
            elif direction == 'R':
                x += 1
            elif direction == 'U':
                y -= 1
            else:
                y += 1

            if x<0 or y<0 or y>=r or x>=c:
                #this means you are out of the grid, so you can exit the function
                return
            elif grid[y][x] == 'X':
                #this means you reached an obstacle, so you can exit the function
                return

    #if you reach here, all the commands have been completed successfully
    #now just set the position you are at to be *
    grid[y][x] = '*'

#now, we loop through each possible starting point and see if it is valid
for i in range(r):
    for j in range(c):
        if grid[i][j] != 'X': #we cant start at an obstacle
            #for each starting square, we need to check all 4 possible directions
            check('L', commands, i, j, r, c, grid)
            check('R', commands, i, j, r, c, grid)
            check('U', commands, i, j, r, c, grid)
            check('D', commands, i, j, r, c, grid)

#now just print out the 2D list
for i in range(r):
    for j in range(c):
        print(grid[i][j],end='')
    print('')