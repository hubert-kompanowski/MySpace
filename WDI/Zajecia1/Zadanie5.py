n=int(input("Podaj liczbe n:\n"))

for j in range (n):
    for i in range(0,j+2):
        print ('  '*(n-i)+i*'x '+'x '+i*'x ')
input("Press Enter...")