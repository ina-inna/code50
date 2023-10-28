import sys

from pyfiglet import Figlet

figlet = Figlet()
list = figlet.getFonts()


if len(sys.argv) == 0:
        text = input ("Input: ")
        figlet.setFont(font=random(list))
        print(figlet.renderText(text))
elif len(sys.argv) == 2:
        if sys.argv[0]

else:
         sys.exit("Invalid usage")
