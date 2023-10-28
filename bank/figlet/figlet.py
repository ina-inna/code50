from pyfiglet import Figlet

figlet = Figlet()
list = figlet.getFonts()


if len(sys.argv) == 0:
        text = input ("Input: ")
        figlet.setFont(font=random(list))
        print(figlet.renderText(text))

else:
         sys.exit("Invalid usage")