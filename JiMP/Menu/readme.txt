Kompilacja przy użyciu polecenia:
    gcc uniwersalne_menu.c -lncurses -lm

Menu graficzne (w konsoli), które można łatwo dostosować do dowolnego programu wymagającego wyboru przez użytkownika jakiejś opcji (zamiast pisać "jeśli chcesz coś zrobić to wybierz 1" ) zmieniając tylko kilka zmiennych, aby odpowiadały naszym preferencjom oraz w wyznaczonym miejscu dodać co dana opcja ma robić lub dodać swoją funkcję.
W menu można poruszać się za pomocą sztrzałek oraz zatwierdzając wybór Enterem.
W menu można zwiększyc ilość opcji analogicznie dodając następne oraz zmieniając wartość zmiennej ilosc_opcji.
Automatycznie na końcu dodana jest opcja "Wyjście" która kończy pracę programu oraz wyświetla końcowy komunikat.
