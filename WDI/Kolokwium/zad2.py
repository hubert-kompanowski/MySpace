class Node:

    def __init__(self, dane, piorytet):
        self.dane = dane
        self.piorytet = piorytet
        self.next = None
        self.prev = None
        
    def __str__(self):
        return str(self.dane)+"  "+str(self.piorytet)
        
class Semidirctional_list:
    
    def __init__(self):
        self.head = None
        self.tail = None
        self.size = 0
    
    def add(self, dane, piorytet):
        if self.head == None:
            n = Node(dane, piorytet)
            self.head = n
            self.tail = n
            n.next = None
            n.prev = None
            self.size += 1
        else:
            n = Node(dane, piorytet)
            next_one = self.head
            self.head = n
            n.next = next_one
            n.prev = None
            next_one.prev = n
            self.size += 1
            
    def del_in_pos(self, pozycja):
        if self.head == None:
            return 0
        elif self.head and self.head == self.tail:
            n = self.head
            self.head == None
            self.tail == None
            n == None
            self.size -= 1
        elif pozycja == 1:
            n = self.head
            next_one = n.next
            self.head = next_one
            next_one.prev = None
            n = None
            self.size -= 1
        elif pozycja == self.size:
            n = self.tail
            prev_one = n.prev
            self.tail = prev_one
            prev_one.next = None
            n = None
            self.size -= 1
        else:
            n = self.head
            licznik = 1
            while licznik < pozycja:
                n = n.next
                licznik += 1
            prev_one = n.prev
            next_one = n.next
            prev_one.next = next_one
            next_one.prev = prev_one
            n = None            
            self.size -= 1
            
    def print_list(self):
        n = self.head
        while n:
            print(n)
            n = n.next
        print("\nRozmiar = ",self.size)
        
    def sort_list(self):
        n = self.head
        n2 = n.next
        for i in range(self.size - 1):
            flaga = 0
            for j in range(self.size-1-i):
                if n.piorytet > n2.piorytet:
                    n.piorytet, n2.piorytet = n2.piorytet, n.piorytet
                    n.dane, n2.dane = n2.dane, n.dane
                    flaga = 1
                n = n.next
                n2 = n2.next
            n = self.head
            n2 = n.next
            if flaga == 0:
                break
                
            

ll = Semidirctional_list()

ll.add("abc", 1)
ll.add("def", 4)
ll.add("ghi", 88)
ll.add("jkl", 2)
ll.add("mno", 9)
ll.add("prs", 4)

#ll.del_in_pos(6)

ll.sort_list()

ll.print_list()
            
        