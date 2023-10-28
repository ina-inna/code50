pip install pyfiglet

from pyfiglet import Figlet

figlet = Figlet()
figlet.getFonts()
figlet.setFont(font=f)


if len(sys.argv) == 0:
        text = input ("Input: ")
        print(figlet.renderText(text))

elif len(sys.argv) == 2:


else:
         sys.exit("Incorrect usage")