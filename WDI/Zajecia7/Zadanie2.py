n = int(input("Podaj długość pręta:"))

tab = []
while n > 0:
    if n - 9 >= 0:
        n = n - 9
        tab.append(9)
    elif n - 6 >= 0:
        n = n - 6
        tab.append(6)
    elif n - 3 >= 0:
        n = n - 3
        tab.append(3)
    elif n == 2:
        n = n - 2
        tab.append(2)
    else:
        tab.append(1)
        n = n - 1

print("Najlepiej pociąć pręt na odcinki o długości:\n", tab)
