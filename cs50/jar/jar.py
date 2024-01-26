def main():
       jar = Jar()
       print(str(jar.capacity))

class Jar:
    def __init__(self, capacity=12):
        self._capacity = capacity
        self.cookies = 0
        if self.capacity < 0:
            raise ValueError("Not eligible")

    def __str__(self):
        cookie = "\U0001F36A"
        n = self.cookies
        return f"{cookie * n}"

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
        return self._capacity

    @property
    def size(self):
        return self.cookies

def main():
       jar = Jar()
       print(str(jar.capacity))
       print(str(jar))
       jar.deposit(12)
       print(jar)
       jar.withdraw(1)
       print(jar)
       print(jar.size)


if __name__ == "__main__":
    main()
