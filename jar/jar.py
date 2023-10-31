class Jar:
    def __init__(self, capacity=12):
        if self.capacity < 0:
            raise ValueError("Not eligible")

    def __str__(self):
        ...

    def deposit(self, n):
        ...

    def withdraw(self, n):
        ...

    @property
    def capacity(self):
        ...

    @property
    def size(self):
        ...