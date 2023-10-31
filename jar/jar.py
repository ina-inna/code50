def main():
       jar = Jar()
       print(str(jar.capacity))

class Jar:
    def __init__(self, capacity=12):
        self.capacity = capacity
        self.cookies = 0
        if self.capacity < 0:
            raise ValueError("Not eligible")

    def __str__(self):
        cookie = '🍪'
        n = self.cookies
        return f"{[cookie * n]}"

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


    if __name__ == "__main__":
        main()
