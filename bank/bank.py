text = input ("Greeting: ")

if "hello" in text.lower():
    print("$0")

elif text[0].lower() == "h":
    print("$20")
else:
    print("$100")
