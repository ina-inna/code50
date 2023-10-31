class Jar:
    def __init__(self, capacity=12):
        self.capacity = capacity
        self.cookies = 0
        if self.capacity < 0:
            raise ValueError("Not eligible")

    def __str__(self):
        n = 🍪
        return f"{[n]}"

    def deposit(self, n):
        if self.cookies > self.capacity:
            raise ValueError("Not eligible")
        self.cookies += n

    def withdraw(self, n):
        self.cookies -= n
        if self.cookies < 0:
            raise ValueError("Not eligible")

    @property
    def capacity(self):
        return self.capacity

    @property
    def size(self):
        return self.cookies