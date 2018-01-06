class Node:
 
    def __init__(self, nazwisko, punkty):
        self.nazwisko = nazwisko
        self.punkty = punkty
        self.next = None
        self.prev = None
 
    def __str__(self):
        return str(self.nazwisko)+" - "+str(self.punkty)
 
class SemidirectionalList:
 
    def __init__(self):
        self.head = None
        self.tail = None
        self.size = 0
 
 
    def add_start(self, nazwisko, punkty):
        if not self.head:
            n = Node(nazwisko, punkty)
            self.head = n            
            self.tail = n
            self.size+=1
        else:
            n = Node(nazwisko, punkty)
            next_one = self.head
            self.head = n            
            n.prev = None
            n.next = next_one         
            next_one.prev = n
            self.size+=1
            
            
    def add_end(self, nazwisko, punkty):
        if not self.tail:
            n = Node(nazwisko, punkty)
            self.head = n            
            self.tail = n
            self.size+=1
        else:
            n = Node(nazwisko, punkty)
            prev_one = self.tail
            self.tail = n
            n.next = None
            n.prev = prev_one
            prev_one.next = n   
            self.size+=1
            
            
    def add_in_pos(self, nazwisko, punkty, pozycja):
        if pozycja >= self.size+1:
            self.add_end(nazwisko, punkty)
            return 0            
        if pozycja <= 1:
            self.add_start(nazwisko, punkty)
            return 0
        if not self.head:
            n = Node(nazwisko, punkty)
            self.head = n            
            self.tail = n
            self.size+=1
        else:
            prev_one = self.head
            for i in range(1,pozycja-1):
                prev_one = prev_one.next
            next_one = prev_one.next
            n = Node(nazwisko, punkty)
            n.next = next_one
            n.prev = prev_one
            prev_one.next = n
            next_one.prev = n
            self.size +=1


    def del_last_one(self):
        n = self.tail
        prev_one = n.prev
        prev_one.next = None
        self.tail = prev_one
        n = None
        
        
    def del_first_one(self):
        n = self.head
        next_one = n.next
        next_one.prev = None
        self.head = next_one
        n = None
    
        
    def print_list_from_the_start(self):
        n = self.head
        while n:
            print (n)
            n = n.next
        print("\nRozmiar = ",self.size)

        
    def print_list_from_the_end(self):
        n = self.tail
        while n:
            print (n)
            n = n.prev
        print("\nRozmiar = ",self.size)
        
        
    def find_the_best(self):
        n = self.head
        max_punktow = 0  
        osoba = ""
        while n:
            if int(n.punkty) >= max_punktow:
                max_punktow = int(n.punkty)
                osoba = n.nazwisko
            n = n.next
        print("\nNajlepszy jest",osoba)
    
            
    
 
ll = SemidirectionalList()


ll.add_end("Kowalski", "91")
ll.add_end("Pawlak", "92")
ll.add_start("Jozwiak", "93")
ll.add_start("Stachursky", "94")
ll.add_in_pos("Ziolkowski", "95", 5)
ll.add_in_pos("Szczepanski", "96", 1)
ll.add_start("Kompanowski", "911")
#ll.del_first_one()
 
ll.print_list_from_the_start()

ll.find_the_best()